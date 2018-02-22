from ipywidgets import Button, Label, FloatSlider, HBox, VBox, Checkbox, IntText
import tornado
from tclab import Plotter, Historian, TCLab, TCLabModel
from tclab.gui import actionbutton, labelledvalue, slider
from tclab.clock import setnow, time

import matplotlib.pyplot as plt

class PID:
    def __init__(self):
        self.K = 1
        self.taui = 100
        self.taud = 0

        self.e = 0
        self.dedt = 0
        self.eint = 0
        self.output = 0

    def update(self, setpoint, mv):
        e = setpoint - mv
        self.dedt = self.e - e
        self.eint += e
        self.e = e

        self.output = self.K * (self.e + 1/self.taui*self.eint + self.taud*self.dedt)
        return self.output


class PIDGUI:
    def __init__(self):
        self.t = 0
        self.plotter = None

        self.pid = PID()

        self.timer = tornado.ioloop.PeriodicCallback(self.update, 1000)
        self.mode = 'manual'

        self.usemodel = Checkbox(description="Use model")

        # buttons
        self.start = actionbutton('Start', self.action_start)
        self.start.disabled = False
        self.manual = actionbutton('Manual', self.action_manual)
        self.auto = actionbutton('Auto', self.action_auto)
        self.stop = actionbutton('Stop', self.action_stop)
        buttons = HBox([self.usemodel,
                        self.start,
                        self.auto,
                        self.manual,
                        self.stop])

        # Sliders for heaters
        self.gain = slider('Gain', self.action_gain, maxvalue=10)
        self.gain.value = 1
        self.tau_i = slider(r'$\tau_I$', self.action_tau_i, minvalue=0)
        self.tau_i.value = 100
        self.tau_d = slider(r'$\tau_D$', self.action_tau_d, maxvalue=10)

        parameters = VBox([self.gain, self.tau_i, self.tau_d])

        # Setpoint
        self.setpoint = slider('Setpoint', self.action_setpoint,
                               minvalue=20, maxvalue=70)
        self.setpoint.value = 30
        self.Q1 = slider('Q1', self.action_Q1, disabled=False)
        self.gui = VBox([buttons,
                         parameters,
                         self.setpoint,
                         self.Q1
                        ])


    def update(self):
        self.t += 1
        setnow(self.t)
        self.plotter.update(self.t)
        if self.mode == 'auto':
            Q1 = self.pid.update(self.setpoint.value, self.lab.T1)
        else:
            Q1 = self.Q1.value

        self.lab.Q1(Q1)

    def action_start(self, w):
        if self.usemodel.value:
            self.lab = TCLabModel()
        else:
            self.lab = TCLab()

        self.historian = Historian([('T1', lambda: self.lab.T1),
                                    ('Q1', self.lab.Q1),
                                    ('setpoint', lambda: self.setpoint.value),
                                    ('error', lambda: self.pid.e),
                                    ('eint', lambda: self.pid.eint),
                                    ('dedt', lambda: self.pid.dedt),
                                    ('output', lambda: self.pid.output)
                                    ])
        if self.plotter:
            plt.close(self.plotter.fig)

        self.plotter = Plotter(self.historian, layout=(('T1', 'setpoint'),
                                                       ('error',),
                                                       ('eint',),
                                                       ('dedt',),
                                                       ('Q1', 'output') ))

        self.timer.start()
        self.t = 0


        self.start.disabled = True
        self.stop.disabled = False
        self.action_manual(w)

    def action_stop(self, w):
        self.timer.stop()
        self.lab.close()

        # FIXME: At the moment restarting requires all the axes to be rebuilt
        # So we can't allow start again.
        self.start.disabled = True
        self.auto.disabled = True
        self.manual.disabled = True
        self.stop.disabled = True

    def action_auto(self, w):
        self.mode = 'auto'
        self.manual.disabled = False
        self.auto.disabled = True

        self.Q1.disabled = True
        self.setpoint.disabled = False
        self.gain.disabled = False
        self.tau_i.disabled = False
        self.tau_d.disabled = False

    def action_manual(self, w):
        self.mode = 'manual'
        self.manual.disabled = True
        self.auto.disabled = False

        self.Q1.disabled = False
        self.setpoint.disabled = True
        self.gain.disabled = True
        self.tau_i.disabled = True
        self.tau_d.disabled = True

    def action_gain(self, w):
        self.pid.K = self.gain.value

    def action_tau_i(self, w):
        self.pid.taui = self.tau_i.value

    def action_tau_d(self, w):
        self.pid.taud = self.tau_d.value

    def action_setpoint(self, w):
        pass

    def action_Q1(self, w):
        pass


import matplotlib.pyplot as plt
import numpy as np

class PID:
    """ An implementation of a PID control class for use in process control simulations.
    """
    def __init__(self, name=None, SP=0, Kp=0.2, Ki=0, Kd=0, beta=0, gamma=0, Range=(0,100), DirectAction=False):
        self.name = name
        self.SP = SP
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.beta = beta
        self.gamma = gamma
        self.range = Range
        self.DirectAction = DirectAction
        self.mode = 'inManual'
        self._log = []
        
    def auto(self,t,PV,MV):
        """Change to automatic control mode.
        """
        self._lastT = t
        self.PV = PV
        self.MV = MV
        self._errorP0 = self.beta*self.SP - self.PV
        self._errorD0 = self.gamma*self.SP - self.PV
        self._errorD1 = self._errorD0
        self._mode = 'inAuto'
        
    def manual(self,t,PV,MV):
        """Change to manual control mode.
        """
        self._lastT = t
        self.PV = PV
        self.MV = MV
        self._mode = 'inManual'
        
    def _logger(self,t,PV,MV,SP):
        self._log.append([t,SP,PV,MV])
        
    def plot(self):
        """Create historical plot of SP,PV, and MV using the controller's internal log file.
        """
        dlog = np.asarray(self._log).T
        t,SP,PV,MV = dlog
        plt.subplot(2,1,1)
        plt.plot(t,PV,t,SP)
        plt.title('Process Variable')
        plt.xlabel('Time')
        plt.legend(['PV','SP'])
        plt.subplot(2,1,2)
        plt.plot(t,MV)
        plt.title('Manipulated Variable')
        plt.xlabel('Time')
        plt.tight_layout()
    
    @property
    def beta(self):
        """beta is the setpoint weighting for proportional control where the proportional error
        is given by error_proportional = beta*SP - PV. The default value is one.
        """
        return self._beta
        
    @beta.setter
    def beta(self,beta):
        self._beta = beta
        
    @property
    def DirectAction(self):
        """DirectAction is a logical variable setting the direction of the control. A True
        value means the controller output MV increases with increase in measured process 
        variable CV. If False the controller is reverse acting. The default value is False.
        """
        return self._DirectAction
    
    @DirectAction.setter
    def DirectAction(self,DirectAction):
        if DirectAction:
            self._DirectAction = True
        else:
            self._DirectAction = False
    
    @property
    def gamma(self):
        """gamma is the setpoint weighting for derivative control where the derivative error
        is given by gamma*SP - PV.  The default value is zero. 
        """
        return self._gamma
    
    @gamma.setter
    def gamma(self,gamma):
        self._gamma = max(0.0,min(1.0,gamma))
    
    @property
    def Kp(self):
        """Kp is the proportional control gain.
        """
        return self._Kp
    
    @Kp.setter
    def Kp(self,Kp):
        self._Kp = Kp
    
    @property
    def Ki(self):
        """Ki is the integral control gain.
        """
        return self._Ki
        
    @Ki.setter
    def Ki(self,Ki):
        self._Ki = Ki
    
    @property
    def Kd(self):
        """Kd is the derivative control gain.
        """
        return self._Kd
    
    @Kd.setter
    def Kd(self,Kd):
        self._Kd = Kd
    
    @property
    def range(self):
        """range is a tuple specifying the minimum and maximum controller output.
        Default value is (0,100).
        """
        return (self._min,self._max)
    
    @range.setter
    def range(self,Range):
        self._min = Range[0]
        self._max = Range[1]

    @property
    def SP(self):
        """SP is the setpoint for the measured process variable.
        """
        return self._SP
    
    @SP.setter
    def SP(self,SP):
        self._SP = SP
        
    @property
    def MV(self):
        """MV is the manipulated (or PID outpout) variable.
        """
        return self._MV
    
    @MV.setter
    def MV(self,MV):
        self._MV = max(self._min,min(self._max,MV))
        
    @property
    def PV(self):
        """PV is the measured process (or control) variable.
        """
        return self._PV
    
    @PV.setter
    def PV(self,PV):
        self._PV = PV

    def update(self,t,PV,MV):
        self.PV = PV
        self.MV = MV 
        if t > self._lastT and self._mode=='inAuto':
            dt = t - self._lastT
            self._lastT = t
            self._errorP1 = self._errorP0
            self._errorP0 = self.beta*self.SP - self.PV
            self._errorI0 = self.SP - self.PV
            self._errorD2 = self._errorD1
            self._errorD1 = self._errorD0
            self._errorD0 = self.gamma*self.SP - self.PV
            self._deltaMV = self.Kp*(self._errorP0 - self._errorP1) \
                + self.Ki*dt*self._errorI0 \
                + self.Kd*(self._errorD0 - 2*self._errorD1 + self._errorD2)/dt
            if self.DirectAction:
                self.MV -= self._deltaMV
            else:
                self.MV += self._deltaMV
        self._logger(t,self.PV,self.MV,self.SP)
        return self.MV 
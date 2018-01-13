#!/usr/bin/env python
import sys
import serial
import time
from serial.tools import list_ports
from math import ceil
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# For Later Development.  This should be a class (or subclass) that 
# provides a simulation with the same API as TCLab
        
class TCSim(object):
    
    def __init__(self, simulation=False, port=None, baud=9600):
        if not(simulation) :
            if (sys.platform == 'darwin') and not port:
                port = '/dev/tty.wchusbserial1410'
            else:
                port = self.findPort()
            print('Opening connection')
            self.sp = serial.Serial(port=port, baudrate=baud, timeout=2)
            time.sleep(3)
            print('TCLab connected via Arduino on port ' + port)
            self.read = self.readArduino
            self.write = self.writeArduino
        else :
            print('TCLab connected via Simulation')
            self.read = self.readSimulation
            self.write = self.writeSimulation
            self.T1sim = 20.0
            self.T2sim = 20.0
        self.start()
        
    def findPort(self):
        found = False
        for port in list(list_ports.comports()):
            # Arduino Uno
            if port[2].startswith('USB VID:PID=16D0:0613'):
                port = port[0]
                found = True
            # HDuino
            if port[2].startswith('USB VID:PID=1A86:7523'):
                port = port[0]
                found = True                
        if (not found):
            print('Arduino COM port not found')
            print('Please ensure that the USB cable is connected')
            print('--- Printing Serial Ports ---')            
            for port in list(serial.tools.list_ports.comports()):
                print(port[0] + ' ' + port[1] + ' ' + port[2])
            port = 'COM3'
        return port
    
    def start(self):
        self.tstart = time.time()
        self.tlog = 0
        self.tprev = 0
        self._Q1 = 0
        self._Q2 = 0
        self._log = []        
        return self.read('A')

    def stop(self):
        return self.read('X')
    
    @property
    def version(self):
        return self.read('version')
    
    @property
    def T1(self):
        self._T1 = float(self.read('T1'))
        self.updateLog('T1',self._T1)
        return self._T1
    
    @property
    def T2(self):
        self._T2 = float(self.read('T2'))
        self.updateLog('T2',self._T2)
        return self._T2
    
    @property
    def Q1(self):
        return self._Q1
    
    @Q1.setter
    def Q1(self,pwm):
        self._Q1 = int(self.write('Q1',pwm))
        self.updateLog('Q1',self._Q1)
    
    @property
    def Q2(self):
        return self._Q2
    
    @Q2.setter
    def Q2(self,pwm):
        self._Q2 = int(self.write('Q2',pwm))
        self.updateLog('Q2',self._Q2)
        
    @property
    def log(self):
        df = pd.DataFrame(self._log, columns = ['Time','var','val'])
        for key in ['Q1','Q2','T1','T2']:
            u = df.loc[df['var'] == key,'val']
            df.loc[u.index,key] = u
        df.drop('val', inplace=True, axis=1)
        df.drop('var', inplace=True, axis=1)
        df.set_index('Time',inplace=True)
        df = df.groupby(df.index).aggregate(np.mean)
        df.fillna(method='ffill',inplace=True)
        return df
    
    def updateLog(self,var,val):
        tnow = time.time()-self.tstart
        dt = tnow - self.tlog
        self.tlog = tnow if dt > 0.01 else self.tlog
        self._log.append([self.tlog, var, val])
 
    def plot(self):
        fig, axes = plt.subplots(nrows=2, ncols=1)
        self.log[['Q1','Q2']].plot(grid=True, kind='line', 
                drawstyle='steps-post', ax=axes[0])
        axes[0].set_ylabel('mV')
        self.log[['T1','T2']].plot(grid=True, kind='line', ax=axes[1])
        axes[1].set_ylabel('deg C')
        plt.tight_layout()
    
    def readArduino(self,cmd):
        cmd_str = self.build_cmd_str(cmd,'')
        try:
            self.sp.write(cmd_str.encode())
            self.sp.flush()
        except Exception:
            return None
        return self.sp.readline().decode('UTF-8').replace("\r\n", "")
    
    def writeArduino(self,cmd,pwm):
        pwm = max(0,min(255,pwm))        
        cmd_str = self.build_cmd_str(cmd,(pwm,))
        try:
            self.sp.write(cmd_str.encode())
            self.sp.flush()
        except:
            return None
        return self.sp.readline().decode('UTF-8').replace("\r\n", "")
    
    def build_cmd_str(self,cmd, args=None):
        """
        Build a command string that can be sent to the arduino.
    
        Input:
            cmd (str): the command to send to the arduino, must not
                contain a % character
            args (iterable): the arguments to send to the command
    
        @TODO: a strategy is needed to escape % characters in the args
        """
        if args:
            args = ' '.join(map(str, args))
        else:
            args = ''
        return "{cmd} {args}\n".format(cmd=cmd, args=args)

    def readSimulation(self,cmd):
        self.updateSimulation()
        return {
            'version': 'TCLab Simulation Version 0.1',
            'T1' : "{0:.2f}".format(self.T1sim).encode(),
            'T2' : "{0:.2f}".format(self.T2sim).encode(),
        }[cmd]
    
    def writeSimulation(self,cmd,pwm):
        self.updateSimulation()
        pwm = max(0,min(150,pwm))
        return "{pwm}".format(pwm=pwm).encode()
    
    def updateSimulation(self):
        tnow = time.time() - self.tstart
        n = ceil((tnow - self.tprev)/0.5)
        dt = (tnow - self.tprev)/n
        self.tprev = time.time() - self.tstart
        for k in range(0,n):
            dT1 = 0.1*dt*(self._Q1 - (self.T1sim - 20.0) - 0.2*(self.T2sim - 20.0))
            dT2 = 0.1*dt*(self._Q2 - (self.T2sim - 20.0) - 0.2*(self.T1sim - 20.0))
            self.T1sim += dT1
            self.T2sim += dT2
        
    def close(self):
        try:
            self.sp.close()
            print('Arduino disconnected succesfully')
        except:
            print('Problems disconnecting from Arduino.')
            print('Please unplug and replug Arduino.')
        return True

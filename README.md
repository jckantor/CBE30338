# Chemical Process Control

This repository comprises a collection of Jupyter/Python notebooks, Matlab scripts, and Simulink models in support of [**CBE 30338 Chemical Process Control**](https://sakailogin.nd.edu/portal/site/SP17-CBE-30338-01). 

These materials have been developed over time in multiple formats. The most recent collection are in the form of Jupyter/Python notebooks and are listed first.  In some cases materials are listed in mulitple formats, with links coded according to this table:

| Format   | Descripton                                |
| :------- | :---------------------------------------- |
| `.m`     | Matlab file or script                     |
| `.slx`   | Simulink model                            |
| `.pdf`   | PDF document produced with Matlab publish |
| `.ipynb` | Jupyter/Python notebook (via nbviewer)    |


## Jupyter/Python Notebooks

### 0. Getting Started ###
* [Getting Started with Python and Jupyter Notebooks](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Getting%20Started%20with%20Python.ipynb)
* [Introduction to Python - A Python Tutorial](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Introduction%20to%20Python%20-%20A%20Python%20Tutorial.ipynb)

### 1. First and Second Order Linear Systems

* [One Compartment Pharacokinetics](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/One%20Compartment%20Pharmacokinetics.ipynb)
[[view as slides](http://nbviewer.jupyter.org/format/slides/github/jckantor/CBE30338/blob/master/notebooks/One%20Compartment%20Pharmacokinetics.ipynb#/)]
* [Second Order Linear Systems](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Second%20Order%20Linear%20Systems.ipynb)
* [Manometer](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Manometer%20Models%20and%20Dynamics.ipynb)
* [Solution to Homework Problems](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Solution%20to%20Homework%20Problems/Solution%20to%20Homework%20Problems.ipynb)

### 2. Nonlinear Models

* [Hare and Lynx Population Dynamics](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/HareLynx/Hare%20and%20Lynx%20Population%20Dynamics.ipynb)[[view as slides](http://nbviewer.jupyter.org/format/slides/github/jckantor/CBE30338/blob/master/notebooks/HareLynx/Hare%20and%20Lynx%20Population%20Dynamics.ipynb#/)]
* Exothermic Stirred-Tank Reactor [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_E05_CSTR.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch02_E05_CSTR.pdf)][[.slx](https://github.com/jckantor/CBE30338/blob/master/simulink/ExothermicCSTR.slx)]
[[.ipynb](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Exothermic%20CSTR.ipynb)]
* Fed-Batch Bioreactor [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_Bioreactor_FedBatch.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch02_Bioreactor_FedBatch.pdf)] [[.ipynb](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Fed%20Batch%20Bioreactor.ipynb)]
* [Animation in Jupyter Notebooks](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Animation%20in%20Jupyter%20Notebooks.ipynb)

### 3. Linear Approximations

* [Linear Approximation of Process Models](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Linear%20Approximation%20of%20Process%20Models.ipynb?flush_cache=true)

### 4. Transfer Functions
* [Getting Started with Transfer Functions](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Getting%20Started%20with%20Transfer%20Functions.ipynb?flush_cache=true)
* [Block Diagrams](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Block%20Diagrams.ipynb)

### 5. PID Control
* [PI Control Tuning](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/PI%20Control%20Tuning.ipynb?flush_cache=true)
* [Implementing PID Control in Nonlinear Simulations](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Implementing%20PID%20Control%20in%20Nonlinear%20Simulations.ipynb?flush_cache=true)

### 6. Frequency Domain Control Design
* [Bode Plot](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Bode%20Plot.ipynb)
* [Controller Tuning Rules in Frequency Domain](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Controller%20Tuning%20Rules%20in%20Frequency%20Domain.ipynb)

### 7. Applications

* [Baroreflex as a Linear Control System](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Baroreflex%20as%20a%20Linear%20Control%20System.ipynb)

## Matlab/Simulink

### 8. Feedback Controllers ###
* Ch08_BallBeam [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch08_BallBeam.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch08_BallBeam.pdf)][[.ipynb](https://github.com/jckantor/Ball-and-Beam)]
* Ch08_Bioreactor_Continuous [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch08_Bioreactor_Continuous.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch08_Bioreactor_Continuous.pdf)] 
* Ch08_BlendingTankControl [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch08_BlendingTankControl,m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch08_BlendingTankControl.pdf)] 
* Gravity Tanks PID Control (Simulink) [[.slx](https://github.com/jckantor/CBE30338/blob/master/simulink/GravityTanksPID.slx)]

### 11. Closed-Loop Dynamics ###
* Ch11_ClosedLoopDemo_Full [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch11_ClosedLoopDemo_Full.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch11_ClosedLoopDemo_Full.pdf)] 
* Ch11_ClosedLoopDemo [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch11_ClosedLoopDemo.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch11_ClosedLoopDemo.pdf)] 

### 12. PID Control ###
* Ch12_PID [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch12_PID.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch12_PID.pdf)] 
* Ch12_PID_ModelError [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch12_PID_ModelError.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch12_PID_ModelError.pdf)] 
* Ch12_PID_TuningRules [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch12_PID_TuningRules.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch12_PID_TuningRules.pdf)] 
* Ch12_PID_2DOF [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch12_PID_2DOF.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch12_PID_2DOF.pdf)] 
* Ch12_PID_Simulink [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch12_PID_Simulink.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch12_PID_Simulink.pdf)] 
* Ch12_PID_Simulink_Model [[.slx](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch12_PID_Simulink_Model.slx)] 

### 14. Frequency Domain Control Design ###
* Ch14_BodePlot [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch14_BodePlot.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch14_BodePlot.pdf)][[.ipynb](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Bode%20Plot.ipynb)]
* Controller Tuning Rules in Frequency Domain [[.ipynb](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Controller%20Tuning%20Rules%20in%20Frequency%20Domain.ipynb)]

### 17. Sampling and Signal Reconstruction

* Zero Order Hold and Interpolation [[.ipynb](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/Zero%20Order%20Hold%20and%20Interpolation.ipynb)]

### 19. Real-Time Optimization ###
* Getting Started with CVXPY [[.ipynb](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/Getting%20Started%20with%20CVXPY.ipynb)]
* Ch19_E01 [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch19_E01.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch19_E01.pdf)] 
* Ch19_E03_cvx [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch19_E03_cvx.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch19_E03_cvx.pdf)] 
* Ch19_E03_sui [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch19_E03_sui.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch19_E03_sui.pdf)] 
* Ch19_Giapetto_cvx [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch19_Giapetto_cvx.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch19_Giapetto_cvx.pdf)] 
* Ch19_Giapetto_sui [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch19_Giapetto_sui.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch19_Giapetto_sui.pdf)] 

### 20. Model Predictive Control ###
* Ch20_E01 [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch20_E01.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch20_E01.pdf)] 

### 21. Process Monitoring ###
* Ch21_DataFitting [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch21_DataFitting.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch21_DataFitting.pdf)] 
* Ch21_E05 [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch21_E05.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch21_E05.pdf)] 

### 23. Biosystems Control ###
* Ch23_E01_bioreactor [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch23_E01_bioreactor.m)] 
* Ch23_E01_bioreactor_PID [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch23_E01_bioreactor_PID.m)] 
* Ch23_E01_bioreactor_mdl [[.mdl](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch23_E01_bioreactor_mdl.mdl)] 
* Ch23_E01_bioreactor_mdl_mpc [[.mdl](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch23_E01_bioreactor_mdl_mpc.mdl)] 

### 23. Dynamics and Control of Biological Systems ###
* Ch24_CircadianClock [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch24_CircadianClock.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch24_CircadianClock.pdf)] 
*  Ch24_EnzymeKinetics [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch24_EnzymeKinetics.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch24_EnzymeKinetics.pdf)] 


### Deprecated Models
* Bioreactor Linearization in Simulink [[.pdf](http://jckantor.github.io/CBE30338/pdf/Bioreactor.pdf)]. 
To run this example you will need to download [Bioreactor.slx](https://github.com/jckantor/CBE30338/blob/master/simulink/Bioreactor.slx), [Bioreactor_Script.m](https://github.com/jckantor/CBE30338/blob/master/simulink/Bioreactor_Script.m), and
[Bioreactor_schematic.png](https://github.com/jckantor/CBE30338/blob/master/simulink/Bioreactor_schematic.png).

* Hare and Lynx Population Dynamics [[.slx](https://github.com/jckantor/CBE30338/blob/master/simulink/HareLynx.slx)][[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch04_PredatorPrey.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch04_PredatorPrey.pdf)][[.ipynb](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/HareLynx/Hare%20and%20Lynx%20Population%20Dynamics.ipynb)]

* Ch02_BlendingTank [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_BlendingTank.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch02_BlendingTank.pdf)]
* Ch02_Braatz [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_Braatz.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch02_Braatz.pdf)] 
* Ch02_GravityTank [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_GravityTank.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch02_GravityTank.pdf)] 
* Ch02_Lorenz_chebfun [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_Lorenz_chebfun.m)]
* Ch02_Lorenz [[.m](https://github.com/jckantor/CBE30338/blob/master/matlab/Ch02_Lorenz.m)][[.pdf](http://jckantor.github.io/CBE30338/pdf/Ch02_Lorenz.pdf)] 
* Ball and Beam Model (Simulink) [[.slx](https://github.com/jckantor/CBE30338/blob/master/simulink/BallBeam.slx)]
* Gravity Tanks (Simulink) [[.slx](https://github.com/jckantor/CBE30338/blob/master/simulink/GravityTanks.slx)]



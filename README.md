# Chemical Process Control

This repository comprises a collection of Jupyter/Python notebooks in support of [**CBE 30338 Chemical Process Control**](https://sakailogin.nd.edu/portal/site/SP17-CBE-30338-01) taught at the University of Notre Dame. These materials have been developed over a period time, earlier versions having been created in Matlab/Simulink and available [here](REAME_DEPRECATED.md).

The links below display the notebooks as regular HTML web pages or, where indicated, as presentation slides. From there you can download the notebooks to execute on your laptop. To execute you will need to install a distributions of Jupyter and Python 3, such as the excellent [Anaconda distribution available from Continuum Analytics](https://www.continuum.io/downloads).

Please me know if you any thoughts or suggestions on how these notebooks could be improved for the purposes of teaching and learning the principles of Chemical Process Control.

## 1. Introduction

### Python for Process Control

* [Getting Started with Python and Jupyter Notebooks](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/python/Getting_Started_with_Python.ipynb)
* [Python Tutorial 1](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/python/Python_Tutorial_1.ipynb)
* [Python Tutorial 2](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/python/Python_Tutorial_2.ipynb)
* [Python Tutorial 3](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/python/Python_Tutorial_3.ipynb)
* Advanced Topic: [Animation in Jupyter Notebooks](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/python/Animation_in_Jupyter_Notebooks.ipynb)
* Advanced Topic: [Modular Approach to Simulation using Python Generators](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/python/Modular_Approach_to_Simulation_using_Python_Generators.ipynb)

### Temperature Control Lab (TCLab)

* [Overview of the Temperature Control Laboratory](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/0_TCLab_Overview.ipynb)
* [Empirical Methods for Feedback Control 2018](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/1_Empirical_Methods_for_Feedback_Control.ipynb)
* [Coding Controllers with Python Generators](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/2_Coding_Controllers_with_Python_Generators.ipynb)

## 2. Process Modeling

### Process Variables, Models, and Degrees of Freedom

* [Process Variables](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/modeling/Process_Variables.ipynb)

### Nonlinear Models and Dynamics

* [Gravity Drained Tank](https://colab.research.google.com/github/jckantor/CBE30338/blob/master/notebooks/modeling/Gravity%20Drained%20Tank.ipynb) 
* [Blending Tank Simulation](https://colab.research.google.com/github/jckantor/CBE30338/blob/master/notebooks/modeling/Blending%20Tank%20Simulation.ipynb)
* [Continuous Product Blending](https://colab.research.google.com/github/jckantor/CBE30338/blob/master/notebooks/modeling/Continuous_Product_Blending.ipynb)
* [Hare and Lynx Population Dynamics](https://colab.research.google.com/github/jckantor/CBE30338/blob/master/notebooks/modeling/HareLynx/Hare_and_Lynx_Population_Dynamics.ipynb)
* [Exothermic Stirred-Tank Reactor](https://colab.research.google.com/github/jckantor/CBE30338/blob/master/notebooks/modeling/Exothermic%20CSTR.ipynb)
* [Fed-Batch Bioreactor](https://colab.research.google.com/github/jckantor/CBE30338/blob/master/notebooks/modeling/Fed%20Batch%20Bioreactor.ipynb)

### Linear Approximation to Nonlinear Models

* [Fitting a Linear Model to the Step Response of a Gravity Drained Tank](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Fitting%20a%20Linear%20Model%20to%20the%20Step%20Response%20of%20a%20Gravity%20Drained%20Tank.ipynb)
* [Linear Approximation of a Process Model using Taylor Series](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Linear%20Approximation%20of%20a%20Process%20Model%20using%20Taylor%20Series.ipynb)
* [Linear Approximation of a Multivariable Model using Taylor Series](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Linear%20Approximation%20of%20a%20Multivariable%20Model%20using%20Taylor%20Series.ipynb)
* [Fitting First-Order plus Time-Delay (FOPTD) to Step Response Data](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Fitting%20First-Order%20plus%20Time-Delay%20%28FOPTD%29%20to%20Step%20Response%20Data.ipynb) [[view as slides]()]

### First and Second Order Linear Systems

* [One Compartment Pharacokinetics](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/One%20Compartment%20Pharmacokinetics.ipynb) [[view as slides](http://nbviewer.jupyter.org/format/slides/github/jckantor/CBE30338/blob/master/linear/notebooks/One%20Compartment%20Pharmacokinetics.ipynb#/)]
* [Second Order Linear Models 2018](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Second_Order_Models.ipynb)
* [Interacting Tanks](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Interacting%20Tanks.ipynb)
* [Manometer Models and Dynamics](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/linear/Manometer%20Models%20and%20Dynamics.ipynb)

### Linear State Space Models

* [Modeling Part 1 - Single Heater with Uniform Temperature](https://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/3_Modeling_Part_1.ipynb)
* [Modeling Part 2 - Dual Heaters with Uniform Temperature](https://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/3_Modeling_Part_2.ipynb)
* [Modeling Part 3 - Single Heater with Non-uniform Temperature](https://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/3_Modeling_Part_3.ipynb)
<!-- * [Modeling Part 4 - Dual Heater with Non-uniform Temperature](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/TCLab/3_Modeling_Part_4.ipynb) -->


## 3. Control

### PID Control
* [PID Control](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/01_PID_Control.ipynb)
* [Implementing PID Control with Python Yield Statement](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/02_Implementing_PID_Control_with_Python_Yield_Statement.ipynb)
* [PID Control with Setpoint Weighting](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/03_PID_Control_with_Setpoint_Weighting.ipynb)
* [PID Control with Bumpless Transfer](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/04_PID_Control_with_Bumpless_Transfer.ipynb)
* [PID Control with Anti-Reset Windup](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/05_PID_Control_with_Anti-Reset-Windup.ipynb)
* [Realizable PID Control](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/06_Realizable_PID_Control.ipynb)
* [PID Controller Tuning](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/07_PID_Controller_Tuning.ipynb)

### PID Control (Old)

* [Implementing PID Control in Nonlinear Simulations](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/Implementing%20PID%20Control%20in%20Nonlinear%20Simulations.ipynb?flush_cache=true)
* [Interactive PID Control Tuning with Ziegler-Nichols](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/Interactive%20PID%20Control%20Tuning%20with%20%20Ziegler-Nichols.ipynb)
* [Balancing a Ball on a Beam with Proportional-Derivative Control](http://nbviewer.jupyter.org/github/jckantor/Ball-and-Beam/blob/master/index.ipynb)
* [Zero Order Hold and Interpolation](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/pid/Zero%20Order%20Hold%20and%20Interpolation.ipynb)


### Frequency Domain Control Design

* [Getting Started with Transfer Functions](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/freqdomain/Getting%20Started%20with%20Transfer%20Functions.ipynb?flush_cache=true)
* [Closed-Loop Transfer Functions for Car Cruise Control](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/freqdomain/Closed-Loop%20Transfer%20Functions%20for%20Car%20Cruise%20Control.ipynb)
* [Creating Bode Plots](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/freqdomain/Creating%20Bode%20Plots.ipynb) [[view slides](http://nbviewer.jupyter.org/format/slides/github/jckantor/CBE30338/blob/master/notebooks/freqdomain/Creating%20Bode%20Plots.ipynb#/)]
* [Controller Tuning Rules in Frequency Domain](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/freqdomain/Controller%20Tuning%20Rules%20in%20Frequency%20Domain.ipynb)
* [Baroreflex as a Linear Control System](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/freqdomain/Baroreflex%20as%20a%20Linear%20Control%20System.ipynb)


## Optimization

### Spreadsheet Optimization

* [Production Planning with Constraints (Google Sheet)](https://docs.google.com/spreadsheets/d/1StL_Z-GnE23LuS93mr9fybxmcAopFuWVvGTauJgvxng/edit?usp=sharing)
* [SEMD Refinery (Google Sheet)](https://docs.google.com/spreadsheets/d/1x-DX4rnt6LCLiDpuSEwZDF0zs5mpVrpcjlU5kb2dmUA/edit?usp=sharing)

### Algebraic Models

* [Unconstrained Scalar Optimization](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/01_Unconstrained_Scalar_Optimization.ipynb)
* [Linear Production Model with Constraints](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/02_Linear_Production_Model_with_Constraints.ipynb)
* [Linear Programming](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/03_Linear_Programming.ipynb)
* [Getting Started with Pyomo](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/04_Getting_Started_with_Pyomo.ipynb)
* [Pyomo Examples](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/05_Pyomo_Examples.ipynb)
* [Linear Blending Problem](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/06_Linear_Blending_Problem.ipynb)
* [Design of a Cold Weather Fuel](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/07_Mixture_Design_Cold_Weather_Fuel.ipynb)
* [Gasoline Blending](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/optimization/08_Gasoline_Blending.ipynb)

### Differential-Algebraic Systems

* [Exothermic Stirred-Tank Reactor (Pyomo)](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/dae/Exothermic_CSTR_Pyomo.ipynb)
* [First Order System in Pyomo](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/dae/First_Order_System_in_Pyomo.ipynb)
* [Path Planning for a Simple Car](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/dae/Path_Planning_for_a_Simple_Car.ipynb)


### State-Task Networks

* [State-Task Networks](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/STN/State-Task_Networks.ipynb)

* [Scheduling State-Task Networks](http://nbviewer.ipython.org/github/jckantor/CBE30338/blob/master/notebooks/STN/Scheduling_Multipurpose_Batch_Processes_using_State-Task_Networks.ipynb)


## Student Projects

* [Wind Turbine Collective Blade Pitch Angle Control](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/02%20Wind%20Turbine%20Control/Wind%20Turbine%20Collective%20Blade%20Pitch%20Angle%20Control.ipynb)
* [Insulin Control for Treating Type I Diabetes](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/05%20Insulin%20Control/Insulin%20Control%20for%20Treating%20Type%20I%20Diabetes.ipynb)
* [Modeling the Blending of Different Types of Chocolate](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/06%20Chocolate%20Production/Chocolate%20Blending%20Final%20Project%20_Breier%2C%20Flavin%2C%20Mallette%2C%20Mikes_.ipynb)
* [Temperature Profile Optimization of the Brewing Process](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/09%20Beer%20Production/Temperature%20Profile%20Optimization%20of%20the%20Brewing%20Process.ipynb)
* [Municipal Wastewater Aeration](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/10%20Wastewater%20Treatment/Municipal%20Wastewater%20Aeration.ipynb)
* [T cell Therapy for Chronic Myelogenous Leukemia](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/18%20Cancer%20Treatment%20with%20T%20cells/T%20cell%20therapy%20of%20Chronic%20Myelogenous%20Leukemia.ipynb)
* [Control of a Reverse Osmosis Desalination Process](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/19%20Desalinization/Control%20of%20a%20Reverse%20Osmosis%20Desalination%20Process.ipynb)
* [Closed Loop Anesthesia Delivery (CLAD) System](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/23%20Anesthsia%20Delivery%20by%20Feedback%20Control/Closed%20Loop%20Anesthetic%20Delivery%20%28CLAD%29%20System.ipynb)
* [Autoregulation and Baroreflex Regulation in Mean Arterial Blood Pressure Maintenance](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/27%20Baroreflex%20and%20Autoregulation/Autoregulation%20and%20Baroreflex%20Regulation%20in%20Mean%20Arterial%20Blood%20Pressure%20Maintenance.ipynb)
* [Sailboat Mast Control](http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/projects/2017/28%20Sailboat%20Mast%20Control/Sailboat%20Mast%20Control.ipynb)

%% Closed Loop Control Demo
% This script demonstrates the simulation and tuning of a simple PID
% controller assuming the control structure outlined below. You can change
% Gd(s) and Gu(s) to 
%                              _______
%                             |       |
%                         d ->| Gd(s) |----+
%                             |_______|    |
%               ______         _______     |
%       +      |      |   u   |       |    v
%   r ---> --->| K(s) |------>| Gu(s) |---> -------> y
%         ^ -  |______|       |_______|        |
%         |                                    |
%         |                                    |
%         +------------------------------------+
%
% Closed loop transfer functions
%
%                Gu(s)K(s)              Gd(s)
%      y(s) =  ------------- r(s) + ------------- d(s)
%              1 + Gu(s)K(s)        1 + Gu(s)K(s)
%
%                  K(s)               K(s)Gd(s)
%      u(s) =  ------------- r(s) - ------------- d(s)
%              1 + Gu(s)K(s)        1 + Gu(s)K(s)
%

%% Systemn Transfer Functions
% These transfer functions model the system to be controlled.

Gd = tf(1,1,'TimeUnit','minutes');
Gu = tf([-0.5 1],[4 4 1],'TimeUnit','minutes');

%% Slider Controls
% The slider controls are used to adjust simulation parameters. The Kd, Ki,
% and Kd are functions created by the sliders. These functions will return
% the values of Kp, Ki, and Kd in the sliders.  The slider functions 
%  
%   suiSlider(Pmin, Pmax, P, label, location[optional]) 
%
% If you change the model, you may need the arguments to the sliders to
% provide an appropriate range of control gains.

[Kp,loc] = suiSlider(0.01, 5/dcgain(Gu), 0.8/dcgain(Gu), 'Kp');
[Ki,loc] = suiSlider(0.00,  4, 0.3, 'Ki',loc.Right);
[Kd,loc] = suiSlider(0.00,  5, 0.0, 'Kd',loc.Right);

%% Function to create a PID controller transfer function
% This function takes values of Kp, Ki, and Kd, and creates PID controller
% corresponding to those parameters. The controller transfer function is
% returned by the expression K() which uses the current slider settings.

K = @() tf([Kp()],[1],'TimeUnit','minutes') + ...
        tf([Ki()],[1, 0],'TimeUnit','minutes') + ...
        tf([Kd() 0],[0.1*Kd()/Kp(), 1],'TimeUnit','minutes');

%% Test Signals

r = @(t) (t >= 5);
d = @(t) (t >= 5);

%% Create Functions to do Simulations
% These functions compute values of y and u as functions of time. The
% simulation is done with lsim. lsim accepts a transfer function, and a
% vector the input and time grid.

if (order(Gu) < 3)
    Gu = Gu*tf([1],[1],'InputDelay',0.5/bandwidth(Gu),'TimeUnit','minutes');
end
yr = @(t) lsim(Gu*K()/(1+Gu*K()),r(t),t);
yd = @(t) lsim(Gd/(1+Gu*K()),d(t),t);
ur = @(t) lsim(K()/(1+Gu*K()),r(t),t);
ud = @(t) lsim(-K()*Gd/(1+Gu*K()),d(t),t);

%% Plot Initial Simulation Results
% Compute and plot the initial simulations. Handles to the plots are saved
% so that they can later be updated if the sliders are changed.

t = 0:.1:5*pi/bandwidth(Gu);

subplot(7,2,[1 3 5]);
plot(t,r(t),'r--','Linewidth',2);
hold on;
hyr = plot(t,yr(t),'Linewidth',2);
hold off;
axis([0 max(t) -1.5 2.5]);
title('Setpoint Response');
legend('y: Output','r: Setpoint');
ylabel('y');
grid;

subplot(7,2,[2 4 6]);
hyd = plot(t,yd(t),'Linewidth',2);
axis([0 max(t) -1.5 2.5]);
title('Disturbance Response d');
legend('y: Output');
ylabel('y');
grid;

subplot(7,2,[7 9 11]);
hur = plot(t,ur(t),'Linewidth',2);
axis([0 max(t) -1.5/dcgain(Gu) 2.5/dcgain(Gu)]);
legend('u: Control Action');
ylabel('u');
grid;

subplot(7,2,[8 10 12]);
hud = plot(t,ud(t),'Linewidth',2);
axis([0 max(t) -1.5/dcgain(Gu) 2.5/dcgain(Gu)]);
legend('u: Control Action');
ylabel('u');
grid;

%% Update Function
% The update function is used by the "Simple User Interface" (sui)
% to update the plots after any sliders has been adjusted. 

update = @() {
    suiPlot(hyr,t,yr(t));
    suiPlot(hyd,t,yd(t));
    suiPlot(hur,t,ur(t));
    suiPlot(hud,t,ud(t))};

suiUpdate(@()update());

%% Closed Loop Control Demo
%
% File: |Ch11_ClosedLoopDemo.m|
%
% This script is a simple demonstration of simulating closed-loop behavior
% of a simple linear control system. 

%% Feedback Control
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
%      u(s) =  ------------- r(s) + ------------- d(s)
%              1 + Gu(s)K(s)        1 + Gu(s)K(s)
%

%% System

Gd = tf(1,1);
Gu = tf([-0.5 1],[4 4 1]);

%% Controller

Kp = 2;
Ki = 0.3;
K = tf([Kp Ki],[1 0]);

%% Test Signals

t = 0:.1:40;
r = (t >= 5);
d = (t >= 5);

%% Simulation Results

subplot(2,2,1);
lsim(Gu*K/(1+Gu*K),r,t);
axis([0 max(t) -1 3]);
title('y Response to Setpoint r');
grid;

subplot(2,2,2);
lsim(Gd/(1+Gu*K),d,t);
axis([0 max(t) -1 3]);
title('y Response to Disturbance d');
grid;

subplot(2,2,3);
lsim(K/(1+Gu*K),r,t);
axis([0 max(t) -1 3]);
title('u Response to Setpoint r');
grid;

subplot(2,2,4);
lsim(-K*Gd/(1+Gu*K),d,t);
axis([0 max(t) -1 3]);
title('u Response to Disturbance d');
grid;


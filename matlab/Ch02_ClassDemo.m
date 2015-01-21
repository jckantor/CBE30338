%% Simulating Feedback Control
%
% This script demonstrates the simulation of a blending tank control
% system.
%
% Jeffrey Kantor
% January 20, 2015
%

%% Process Parameters

rho = 1.00    % kg/liter
V = 4000      % liters

%% Demo 1: Representing time dependent inputs with anonymous functions.
% Anonymous functions are very useful tools for representing simple
% functions within a Matlab script. 

x1 = @(t) 0.2*ones(size(t));     % A constant function of time
w1 = @(t) 100 + (t >= 50).*50;   % A step function from 100 to 150 at t=t0
w2 = @(t) 60*ones(size(t)); 

t = linspace(0,200,1000);
plot(t,w1(t),t,w2(t));
xlabel('Time');
ylabel('w_1')
ylim([0,200])

%% Demo 2: Simulation of the Blending Tank without control





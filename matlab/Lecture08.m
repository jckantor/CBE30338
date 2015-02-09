%% Lecture 08 Demonstration

%% Parameters for a single gravity drained tank.

Cv = 1.2;    % Outlet orifice constant (m^3/min at 1 meter head)
A = 2.0;     % Area (m^2)

%% Simulation 1. Constant input

qbar = 0.8;
f = @(t,h) (qbar - Cv*sqrt(h))/A ;
[t,h] = ode45(f,[0 20],0);

plot(t,h,'Linewidth',2);
ylim([0 1]);
xlabel('Time [min]');
ylabel('Height [m]');
title('Dynamics of a single gravity filled tank.');

print -dpng -r300 

%% Calculate Steady State

hbar = (qbar/Cv)^2;
hold on
plot(t,hbar*ones(size(t)),'r--','Linewidth',2);
hold off;
legend('Nonlinear Response,','Steady State');

%% Simulation 2. Response to a deviation in inflow

u = @(t) 0.1 * (t >= 12);
f = @(t,h) (qbar + u(t) - Cv*sqrt(h))/A ;

t = 0:.1:30;
[t,h] = ode15s(f,t,0);     % Need a stiff solver

plot(t,h,'Linewidth',2);
ylim([0 1]);
xlabel('Time [min]');
ylabel('Height [m]');
title('Dynamics of a single gravity filled tank.');
hold on
plot(t,hbar*ones(size(t)),'r--','Linewidth',2)
hold off;

%% Simulation 3 - Linear Approximation

g = @(t,x) u(t)/A - Cv*x/(2*A*sqrt(hbar));

hold on
[t,x] = ode45(g,t,-0.444)
plot(t,x+hbar,'Linewidth',2)
hold off
legend('Nonlinear','Steady State','Linear Approximation');

%% Parameters for two tanks in Series

% Tank 1
A1 = 2.0;
C1 = 1.2;
qbar = 0.8;

% Tank 2
A2 = 3.0;
C2 = 1.0;
dbar = 0.0;

f = @(t,h) [ ...
    (qbar - C1*sqrt(h(1)))/A1;
    (dbar + C1*sqrt(h(1)) - C2*sqrt(h(2)))/A2];

[t,h] = ode15s(f,t,[0 0])

plot(t,h,'Linewidth',2)

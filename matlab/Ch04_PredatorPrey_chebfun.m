%%

a = 3.2;
b = 0.6;
c = 50;
d = 0.56;
k = 125;
r = 1.6;

%% Model Equations

dH = @(H,L) r*H*(1-H/k) - a*H*L/(c+H);
dL = @(H,L) b*a*H*L/(c+H) - d*L;

%% Model in format suitable for ODE45

deriv = @(x) [dH(x(1),x(2)); dL(x(1),x(2))];

% Simulate

tspan = [0 70];
ic = [20;20];
y = ode45(@(t,x)deriv(x), domain(0,70), ic);
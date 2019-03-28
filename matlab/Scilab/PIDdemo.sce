
// Use this 'trick' to simplify entry of transfer functions

s = poly([0 1], 's', 'c');

// Process Model

G = 0.009/(s + 1.11);
Kd = 12.22;

Xss = 10;
Uss = 1111.1;
Dss = 100;

// Measurement Model, Pade Approximation for Time Delay

H = (1 - 0.167*s)/(1 + 0.167*s)

// PI Controller

K = (200 + 100*s)/s;

// closed loop linear models

XD = syslin('c', G*Kd/(1+G*K*H));
XR = syslin('c', G*K/(1+G*K*H));
UD = syslin('c', -K*H*G*Kd/(1+K*H*G));
UR = syslin('c', K/(1+K*H*G));

// plotting response to 10% changes in 
// disturbance and setpoint inputs

t = linspace(0,10);

scf(1);
clf(1);

subplot(2,2,1)
plot(t, Xss + 0.1*Dss*csim('step',t,XD))
title('Disturbance Response  D -> X')
xlabel('Time [hrs]')
ylabel('Outlet Conc. Change [ppm]')

subplot(2,2,2)
plot(t, Xss + 0.1*Xss*csim('step',t,XR))
title('Setpoint Response  R -> X')
xlabel('Time [hrs]')
ylabel('Outlet Conc. Change [ppm]')

subplot(2,2,3)
plot(t, Uss + 0.1*Dss*csim('step',t,UD))
title('Disturbance Response  D -> U')
xlabel('Time [hrs]')
ylabel('Flow Change [liters/hr]')

subplot(2,2,4)
plot(t, Uss + 0.1*Xss*csim('step',t,UR))
title('Setpoint Response  R -> U')
xlabel('Time [hrs]')
ylabel('Flow Change [liters/hr]')


// Root Locus

scf(2)
clf(2)

for K = linspace(1,1200)
    p = roots(denom(G*K/(1+G*K*H)));
    disp(p)
    plot(real(p),imag(p),'x');
end

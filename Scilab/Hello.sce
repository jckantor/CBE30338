clf

t = linspace(-20,20,10000)
g = exp(-t.^2)/sqrt(2*%pi)

subplot(4,1,1)
plot(t,g)
title('Blur')


y = sign(sin(3*t))
subplot(3,1,2)
set(gca(),"auto_clear","off")
plot(t,y,'b')
plot(t,conv(y,g,'same')/10.0)
set(gca(), "data_bounds", [-20,-3;20,3])
title('Signal')


y = sign(sin(5*t))
subplot(3,1,3)
set(gca(),"auto_clear","off")
plot(t,y,'b')
plot(t,conv(y,g,'same')/10.0)
set(gca(), "data_bounds", [-20,-3;20,3])
title('Signal')

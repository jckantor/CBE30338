

% Plot the results

figure(1)
subplot(221);
plot(t,G)
hold on
plot([0 max(t)],[80 80],'r--',[0 max(t)],[120 120],'r--');
hold off
axis([0 max(t) 0 max(200,max(G))]);
xlabel('Time [min]');
ylabel('[mg/dL]');
title('Glucose');

subplot(222);
plot(t,I);
xlabel('Time [min]');
ylabel('[mU/L]');
title('Insulin');

subplot(223);
plot(t,D(t));
xlabel('Time [min]');
ylabel('[mg/dL/min]');
title('Glucose Input D(t)');

subplot(224);
plot(t,U);
axis([0 max(t) 0 115]);
xlabel('Time [min]');
ylabel('[mU/min]');
title('Insulin Infusion U(t)');
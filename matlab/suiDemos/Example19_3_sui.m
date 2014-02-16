%% SEMD Example 19.3
%
% Determine the optimal production schedule for the following process.
%
%                             ____________
%                            |            |----> Gasoline ($36/bbl)
%     Crude 1 ($24/bbl) ---->|            |----> Kerosene ($24/bbl)
%                            |  Refinery  |----> Fuel Oil ($21/bbl)
%     Crude 2 ($15/bbl) ---->|            |----> Residual ($10/bbl)
%                            |____________|
%
%
%                           Volumetric Yield      Capacity
%                          Crude #1  Crude #2      bbl/day
%        Gasoline             80%       44%        24,000
%        Kerosine              5%       10%         2,000
%        Fuel Oil             10%       36%         6,000
%
%        Processing Cost   $0.50/bbl $1.00/bbl

%% Script Requirments
%
% * The |sui| toolset.

%% Reduction to Two Variables
%
% This example consists of six decision variables with four equality
% constraints. The four equalities can be used to eliminate four of the
% decision variables.  Normally this exercise is unnecessary since linear
% programming software is sufficiently reliable to do these calculations.
% But in this instance, reducing the problem to two variables will allow us
% to explore the solution graphically and gain some interesting insights.

%% Parameters

Y = [0.80 0.44; 0.05 0.10; 0.10 0.36; 0.05 0.10];

gcap = 24000;
kcap =  2000;
fcap =  6000;

lb = [0;0];

prod_price = [36 24 21 10];
crude_price = [24 15];
process_cost = [0.5 1.0];

%% Optimal Solution

fc = prod_price*Y - crude_price - process_cost;
A = [Y(1:3,:)];

format bank
c = linprog(-fc,Y(1:3,:),[gcap;kcap;fcap],[],[],lb)
profit = fc*c

%% Interactive Solution

clf;
subplot(8,1,1:7);
[C1,C2] = meshgrid(0:1000:40000,0:1000:40000);
hold on;
    gasoline = plot([gcap/Y(1,1) 0],[0 gcap/Y(1,2)],'b','LineWidth',2);
    kerosene = plot([kcap/Y(2,1) 0],[0 kcap/Y(2,2)],'r','LineWidth',2);
    fuel_oil = plot([fcap/Y(3,1) 0],[0 fcap/Y(3,2)],'g','LineWidth',2);
    optimum = plot(c(1),c(2),'r.','Markersize',30);
    contour(C1,C2,fc(1)*C1+fc(2)*C2,'ShowText','on');
hold off;
legend({'Gasoline','Kerosene','Fuel Oil','Optimum','Profit'});
axis([0 40000 0 40000]);
axis('square');
xlabel('c(1)');
ylabel('c(2)');
title('Refinery Example 19.3');

update = @(gcap,kcap,fcap) { ...
    suiPlot(gasoline,[gcap/Y(1,1) 0],[0 gcap/Y(1,2)]);
    suiPlot(kerosene,[kcap/Y(2,1) 0],[0 kcap/Y(2,2)]);
    suiPlot(fuel_oil,[fcap/Y(3,1) 0],[0 fcap/Y(3,2)]);
    suiPlot(optimum,linprog(-fc,A,[gcap;kcap;fcap],[],[],lb,[])')};

[gcap,loc] = suiSlider(0,30000,gcap,'Gasoline Cap.',[10,10],150);
[kcap,loc] = suiSlider(0,30000,kcap,'Kerosene Cap.',loc.Right,150);
[fcap,loc] = suiSlider(0,30000,fcap,'Fuel Oil Cap.',loc.Right,150);
suiButton(@()close('all'),'Done',loc.Right,50);

suiUpdate(@()update(gcap(),kcap(),fcap()));

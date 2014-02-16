%% Solution to Example 19.01 Using CVX
% 
% File: |Ch19_E01.m|
%
% Demonstrate the solution of a linear programming problem for process
% operation.

%% Software requirements
% This script requires CVX (download from http://cvxr.com) and access to
% the utility functions.

addpath('utilities')

%% Version 1
% This first version is a straight translation of the problem using the CVX
% modeling syntax.

cvx_quiet TRUE;
cvx_begin

    variables x(4)
    
    x >= 0;
    x <= [40000; 30000; 30000; 30000];
    
    sales = 0.4*x(3) + 0.33*x(4);
    feedstock = 0.15*x(1) + 0.2*x(2);
    operating = 0.15*x(3) + 0.05*x(4) + 350 + 200;
    
    profit = sales - feedstock - operating;
    
    x(1) == 0.667*x(3) + 0.5*x(4);
    x(2) == 0.333*x(3) + 0.5*x(4);
    
    maximize profit
    
cvx_end

displaytable(profit,'Maximum Profit = ');
displaytable(x,{'A','B','E','F'},{'Value'});

%% Version 2
% Sensitivity analysis determines the sensitivity of the objective to
% changes in parameters. In this case we are interested in the dependence
% of profit on the process capacity constraints. This information is
% important in many process situations.
%
% In CVX, sensititivities are computed as the dual variables corresponding
% to constraints as demonstrated below.

cvx_begin

    variables x(4)
    dual variable y
    
    x >= 0;
    
    sales = 0.4*x(3) + 0.33*x(4);
    feedstock = 0.15*x(1) + 0.2*x(2);
    operating = 0.15*x(3) + 0.05*x(4) + 350 + 200;
    
    profit = sales - feedstock - operating;
    
    x(1) == 0.667*x(3) + 0.5*x(4);
    x(2) == 0.333*x(3) + 0.5*x(4);
    
    ub = [40000; 30000; 30000; 30000];
    
    y: x <= ub
    
    maximize profit
    
cvx_end

displaytable(profit,'Maximum Profit = ');
displaytable([x,ub,ub-x,y],{'A','B','E','F'},{'Opt','UB','Slack','Sens.'});

%% Observations
% # There are two active constraints.
% # Profit could be increased by investing in a process expansion.
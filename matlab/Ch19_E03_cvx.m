%% Example 19.03 Refinery Optimization
%
% File: |Ch19_E03_cvx.m|
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
%                       Volumetric Yield      Capacity
%                      Crude #1  Crude #2      bbl/day
%     Gasoline            80%       44%         24,000
%     Kerosine             5%       10%          2,000
%     Fuel Oil            10%       36%          6,000
%
%     Processing Cost   $0.50/bbl $1.00/bbl

%% Script Requirments
%
% * |displaytable.m| 
% * CVX

addpath('utilities');

%% Decision Variables

clabels = {'Crude 1','Crude 2'};
plabels = {'Gasoline','Kerosene','Fuel Oil','Residual'};

%% CVX Optimization Model

cvx_begin

    % Decision Variables
    
    variables c(2) p(4)
    c >= 0; p <= 100000;
    p >= 0; p <= 100000;
    
    % Objective Function
    
    revenue = 36*p(1) + 24*p(2) + 21*p(3) + 10*p(4);
    rawmaterials = 24*c(1) + 15*c(2);
    processing = 0.5*c(1) + 1.0*c(2);
    profit = revenue - rawmaterials - processing;
    
    maximize(profit)
    
    % Refinery Yield Model
    
    Y = [0.80 0.44; 0.05 0.10; 0.10 0.36; 0.05 0.10];
    p == Y*c;
    
    % Refinery Production Capacity
    
    dual variable z
    Capacity = [24000; 2000; 6000; 100000];
    z : p <= Capacity;

cvx_end

%% Crude Utilization

displaytable(c,clabels,'bbl/day','%6.1f');

%% Production

displaytable(p,plabels,'bbl/day','%6.1f');

%% Process Utilization

displaytable( ...
    [p, Capacity, Capacity - p, z], plabels, ...
    {'Production','Capacity','Slack','Sensitivity'},'%6.1f');

%% Questions to Explore
%
% # Why is the sensitivity so high for Kerosene?
% # You're considering expanding the Kerosene and Fuel Oil capacities for
%   the plant. Each bbl of additional capacity has the same cost. Plot the
%   additional profit as a function of additional capacity.

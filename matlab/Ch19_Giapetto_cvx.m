%% Linear Programming: Giapetto's Workshop
%
% File: |Ch19_Giapetto_cvx.m|
%
% This file demonstrates the formulation and solution of simple linear
% programs in Matlab.  To use this demo you will need --
%
% # Optimization Toolbox: This is included in the version of Matlab
%   distributed to ND students.
% # CVX: This is an optimization modeling language. If you haven't already
%   done so, you'll need to download and install CVX from
%   <http://www.cvxr.com http://cvxr.com> .
% # |displaytable.m| This is a simple file for formatting data tables. It's
%   located in the course folder labelled 'Matlab Files'.

%% Installing |CVX|
%
% <html>
% Click here <a HREF="matlab:web -browser 'http://cvxr.com/cvx/download/'"> http://cvxr.com </a>
% </html>

%%
% Initialize the workspace to a known state.

close all
clear all
clc
addpath('utilities');

%% Giapetto's Workshop (from Winston, Operations Research)
%
% Giapetto's Workshop produces two types of wooden toys:
% 
% * Soldiers - Each sells for $27, and requires $10 of raw materials, and
%   $14 of labor consisting of 2 hours of finishing labor and 1 hour of
%   carpentry labor.
%
% * Trains - Each sells for $21, and requires $9 of raw
%   materials, and $10 of labor consisting of 1 hour of finishing labor,
%   and 1 hour of carpentry labor
%
% Weekly production is constrainted by the weekly availability of no more
% than 100 finishing hours and 80 carpentry hours. At most 40 toy soldiers
% will be sold each week.
%
% What is the maximum achievable weekly profit?

%% Analysis
%
% * The decisions variablse will be the number of soldiers produced, 
%   |x(1)|, and the number of trains produced, |x(2)|.
% * Each soldier sells for $27 and costs $24 to produce a $3 profit.
%   Each train sells for $21 and costs $19 to produce a $2 profit.
% * Both |x(1)| and |x(2)| must be non-negative. These form lower bounds on
%   the decision variables.
% * There are three constraints on |x(1)| and |x(2)| based on demand and
%   the availability of carpentry and finishing labor.

%% Solution using |CVX|
%
% CVX is a simple language embedded within Matlab for modeling and solving
% convex optimization problems. Linear programming is an example of convex
% optimization.

cvx_quiet TRUE                          % suppresses verbose output
cvx_begin                               % model starts with cvx_begin
    variables x(2) ;                    % creates 2 decision variables
    x(1) >= 0;                          % lower bound on x(1): Soldiers
    x(2) >= 0;                          % lower bound on x(2): Trains
    x(1) <= 40;                         % demand constraint on Soldiers
    x(1) + x(2) <= 80                   % carpentry labor bound
    2*x(1) + x(2) <= 100;               % finishing labor bound
    profit = 3*x(1) + 2*x(2);           % profit objective
    maximize profit;                    % objective
cvx_end                                 % cvx_end starts the calculation

disp('Solution to Giapetto''s Workshop using CVX.');
displaytable(x,{'Soldiers','Trains'});  % Display results as a table

%% Solution using |linprog|
%
% The Optimization Toolbox in Matlab provides a linear programming function
% call |linprog| to *minimize* linear objectives subject to linear
% constraints.  Check the documentation ('doc linprog') for usage.  It's
% quicker and more efficient than CVX, but requires you to create matrices
% and vectors containing the problem data.
%
% For the Giapetto's workshop problem, let |x| be a two element column
% representing Soldiers and Trains. Then
%
%              minimize f'*x
% subject to    
%                  x >= lb
%                A*x <= b

f = [-3 -2];
lb = [0; 0];
A = [1 0; 1 1; 2 1];
b = [40; 80; 100];

x = linprog(f,A,b,[],[],lb,[]);

disp('Solution to Giapetto''s Workshop using linprog.');
displaytable(x,{'Soldiers','Trains'});

%% CVX Again
%
% The matrices and vectors used for |linprog| can also be used in |CVX|.
% This produces a more succinct code.

cvx_quiet TRUE                          % suppresses verbose output
cvx_begin                               % model starts with cvx_begin
    variables x(2) ;                    % creates 2 decision variables
    x >= lb;                            % lower bounds
    A*x <= b;                           % constraints
    profit = -f*x;                      % profit objective
    maximize profit;                    % objective
cvx_end                                 % cvx_end starts the calculation

disp('Solution to Giapetto''s Workshop using CVX.');
displaytable(x,{'Soldiers','Trains'});



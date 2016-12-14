// Example 19.1, SEMD

// objective function coefficients

f = [0.15   0.20   -0.25  -0.28]';

// equality constraints

Aeq = [1 0 -0.6667 -0.5; 0 1 -0.3333 -0.5];
beq = [0 0]';

// bounds on decision variables

lb = [0 0 0 0]';
ub = [40000 30000 30000 30000]';

// define a version of linprog to provide a 'matlab-like' syntax

function [xopt,fopt,yopt,iter,yopt] = linprog(f,A,b,Aeq,beq,lb,ub)

    [xopt,fopt,exitflag,iter,yopt] = karmarkar(Aeq,beq,f,[],[],[],[],[],A,b,lb,ub)
    
endfunction

xopt = linprog(f,[],[],Aeq,beq,lb,ub)


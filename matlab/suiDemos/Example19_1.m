%% Example 19.1

%% Version 1

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

displaytable(x,{'A','B','E','F'});


%% Version 2

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

displaytable([x,ub,ub-x,y],{'A','B','E','F'},{'Opt','UB','Slack','Sens.'});
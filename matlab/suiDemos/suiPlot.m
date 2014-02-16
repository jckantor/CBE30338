% |suiPlot(h,x,y)| updates the contents of a plot. The first argument is a
% handle to the plot or title. suiPlot return a handle so it can be used
% in a cell array of anonymous functions.

function r = suiPlot(h,x,y)
    if nargin == 2
        set(h,'XData',x(:,1));
        set(h,'YData',x(:,2));
        if size(x,2) == 3
            set(h,'ZData',x(:,3));
        end
    elseif nargin == 3
        set(h,'XData',x);
        set(h,'Ydata',y);
    else
        error('Incorrect number of arguments for replot.');
    end
    r = h;
end

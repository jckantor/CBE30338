%%
% |suiPlot(h,x,y)|, and |suiTitle| are used to update the contents of a plot.
% The first argument is a handle to the plot or title. These return the
% handles so they can be used in anonymous functions.

function r = suiTitle(h,str)
    set(h,'String',str);
    r = h;
end
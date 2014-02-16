%%
% Create a simple pushbutton. The function fcn executes when the button
% is when pushed. Returns a handle to the pushbutton.

function [h,loc] = suiButton(fcn,String,pos,xlen)

    if nargin < 4
        xlen = 30;
    end
    if nargin < 3 || isempty(pos)
        pos = [10,10];
    end
    if nargin < 2 
        String = '';
    end
    xpos = pos(1);
    ypos = pos(2);
 
    h = uicontrol('Style','pushbutton', ...
        'Position',[xpos ypos xlen 30],'String',String);
    
    set(h,'Callback',@(hObj,event)fcn());
    
    loc.Position = [xpos ypos xlen 30];
    loc.Right = [xpos+xlen+10, ypos];
    loc.Above = [xpos, ypos+35];
    loc.Below = [xpos, ypos-35];
    
end

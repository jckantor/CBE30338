% |suiPopup(String,pos,xlen)| creates a simple popup menu. String is a cell
% array of strings to populate the dropdown menu. The popup is placed at
% postion pos with length xlen.  suiPopup returns a function giving the
% numeric value of the popup. loc returns the location of popup, and
% coordinates to located additional sui above, below, and to the right
% of the popup.  Selecting a menu item causes the suiUpdate to fire.

function [f,loc] = suiPopup(String,pos,xlen)

    if nargin < 3 || isempty(xlen)
        xlen = 160;
    end
    if nargin < 2 || isempty(pos)
        pos = [10,10];
    end

    xpos = pos(1);
    ypos = pos(2);
    
    hPopup = uicontrol('Style','popup', ...
        'String',String, ...
        'Position',[xpos ypos+15 xlen 15], ...
        'Callback',@callback);
  
    function callback(hObj,~)
        f = suiUpdate;
        f();
    end

    function [vout,s] = accessor(vin)
        if nargin == 1
            set(hPopup,'Value',vin);
        end
        vout = get(hPopup,'Value');
    end

    f = @accessor;
    loc.Position = [xpos ypos xlen 30];
    loc.Right = [xpos+xlen+10, ypos];
    loc.Above = [xpos, ypos+30+5];
    loc.Below = [xpos, ypos-30-5];
    
end
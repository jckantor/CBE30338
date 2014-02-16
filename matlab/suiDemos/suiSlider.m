% |suiSlider(vmin,vmax,v,String,pos,xlen)| creates a simple slider. Returns
% a function to get the value of the slider. loc returns the location of
% popup, and coordinates to located additional sui above, below, and to the
% right of the popup. Adjusting the slider causes the suiUpdate callback to
% fire.

function [f,loc] = suiSlider(vmin,vmax,v,String,pos,xlen)

    if nargin < 6 || isempty(xlen)
        xlen = 160;
    end
    if nargin < 5 || isempty(pos)
        pos = [10,10];
    end
    if nargin < 4 
        String = '';
    end
    xpos = pos(1);
    ypos = pos(2);
    
    hSlider = uicontrol('Style','slider', ...
        'Min',vmin,'Max',vmax,'Value',v, ...
        'Position',[xpos ypos xlen 15]);   
    hText = uicontrol('Style','text',...
        'Position',[xpos ypos+15 xlen 15], ...
        'String',sprintf('%s = %5.3f',String,v));
    set(hSlider,'Callback',@callback);
  
    function callback(hObj,~)
        set(hText,'String',sprintf('%s = %5.3f',String,get(hObj,'Value')));
        f = suiUpdate;
        f();
    end

    function [vout,s] = accessor(vin)
        if nargin == 1
            set(hSlider,'Value',vin);
            set(hText,'String',sprintf('%s = %5.3f',String,vin));
            f = suiUpdate;
            f();
        end
        vout = get(hSlider,'Value');

    end

    f = @accessor;
    loc.Position = [xpos ypos xlen 30];
    loc.Right = [xpos+xlen+10, ypos];
    loc.Above = [xpos, ypos+30+5];
    loc.Below = [xpos, ypos-30-5];
    
end
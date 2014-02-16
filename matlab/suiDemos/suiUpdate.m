% |fout = suiUpdate(fin) specifies sn update function that will be called
% by when suiSlider or suiPopup are adjusted. Returns a handle to the
% suiUpdate function.

function fout = suiUpdate(fin)
    persistent f
    if nargin == 1
        f = fin;
    end
    fout = f;
end
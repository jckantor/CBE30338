function addplot(varargin)
%
% ADDPLOT   Adds a plot to the current figure
%
%   ADDPLOT(X,Y, ...)  accepts the usual arguments of plot, and includes
%   the plot in the current figure. The provides a simple way to build up a
%   more complex figure without the hassle of issuing a lot of hold on an
%   hold off commands. Remember to use the clf to clear the figure window
%   when needed.
%
% EXAMPLES
%
%   1. Overlay damped sine and cosine plots on same axes
%
%          t = 0:.1:10;
%          addplot(t, exp(-.5*t).*sin(t),'b')
%          addplot(t, exp(-.5*t).*cos(t),'r')
%          legend('Damped Sine','Damped Cosine');
%
%   2. Show damped sinusoids as function of damping parameter
%
%          clf;
%          t = 0:.1:20;
%          for d = .1:.1:.8
%              addplot(t, exp(-d*t).*cos(t));
%          end
%
% Jeffrey Kantor
% December 16, 2011

    hold on;
    plot(varargin{:});
    hold off;

end
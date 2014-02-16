function str = displaytable(A,rnames,cnames,fmt,tableformat,fname)

% DISPLAYTABLE Convert a matrix to a printable table.
%
% STR = DISPLAYTABLE(A,RNAMES,CNAMES,FMT,TABLEFORMAT,FNAME) 
%    Formats a matrix as a table with row and column labels. The result is
%    a string that will print as a formatted table. Useful labeling and
%    annotating computational results.
%
% REQUIRED PARAMETERS
%
%           A: A matrix of numeric data.
%
% OPTIONAL PARAMETERS
%
%      rnames: An optional cell array of strings for row headers, one for 
%              each row of A. If there is only one string, the a row number
%              suffix is added to the string. An empty string produces no
%              row headers.
%      cnames: An optional cell array of strings for column headers, one
%              for each column of A. If there is only one string, the a row
%              number suffix is added to the string. An empty string
%              produces no column headers.
%         fmt: An optional data format (e.g., %8.3f) for displaying table
%              data. The default is '%9.5g'.
% tableformat: An optional text string denoting table format. The default
%              is 'mono'. Options are
%                'mono' -- monospaced font
%                'plain' -- tabs delimited columns
%                'latex' -- for latex
%                'html' -- for html
%                'csv' -- CSV formated file
%       fname: An optional file name (with suffix) to store the result.
%
% EXAMPLES
%
%   1. Annotate a simple result
%
%        >> displaytable(pi,'Pi = ');
%        Pi =   3.1416
%
%   2. Display a simple table
%
%        >> A = magic(4);
%        >> displaytable(A)
%        16   2   3  13
%         5  11  10   8
%         9   7   6  12
%         4  14  15   1
%
%   3. Display a table with row and column headings
%
%         >> displaytable(A,'Row','Col')
%                 Col(1)  Col(2)  Col(3)  Col(4)
%         Row(1)      16       2       3      13
%         Row(2)       5      11      10       8
%         Row(3)       9       7       6      12
%         Row(4)       4      14      15       1
%
%   4. Create a table of molecular weights (requires StoichTools)
%
%         >> s = {'CH4','C2H6','C3H8'}';
%         >> mw = molweight(s);
%         >> displaytable(mw,s,'Mol. Wt.');
%               Mol. Wt.
%         CH4     16.043
%         C2H6     30.07
%         C3H8    44.097
%
%   5. Create a spreadsheet of molecular weights (requires StoichTools)
%
%         >> displaytable(mw,w,'Mol. Wt.','','csv','MolWt.csv');
%
% DEPENDENCIES:  None
%
% I must have written a hundred adhoc versions of 'displaytable' in various
% projects. This is my attempt to get it right once and for all.
%
% Jeffrey Kantor
% December 13, 2011 -- Original
% December 18, 2011 -- reordered calling parameters to be more convenient.
% January 21, 2012  -- Update documentation, upload to Mathworks Central

    A = full(A);
    [I,J] = size(A);
    
    % The default table style is monospaced.
    if nargin < 5 
        tableformat = 'mono';
    elseif ~ischar(tableformat)
        error('Table format must be a string');
    end
    
    % Establish data format
   
    if nargin < 4 || isempty(fmt)
        fmt = '%9.5g';
    end
    
    % Parse the data format for width, decimal points, format
    fmtparse = regexp(fmt,'%(\d+)\.*(\d+)*([deEfFgG])','tokens');
    fmtparse = fmtparse{1};
    
    fmtwidth = fmtparse{1};
    fmtprec  = fmtparse{2};
    fmttype  = fmtparse{3};
    
    if isempty(fmttype)
        error('Data format must be d, e, D, f, F,g, or G');
    end
    
    % Row and column headings are specified as cell arrays with string
    % labels for each row and column, or by a single string that is
    % expanded below to generate unique headings. An empty string removes
    % the corresponding header. 

    if nargin < 3
        cnames = {''};
    elseif ischar(cnames)
        cnames = {cnames};
    elseif ~iscellstr(cnames) || (numel(cnames)>1 && numel(cnames)~= J)
        error('Column headings not consistent with table data.');
    end   
    iscolheader = ~isempty(cnames{1});

    if nargin < 2
        rnames = {''};
    elseif ischar(rnames)
        rnames = {rnames};
    elseif ~iscellstr(rnames) || (numel(rnames)>1 && numel(rnames)~= I)
        error('Row headings not consistent with table data.');
    end  
    isrowheader = ~isempty(rnames{1});

    % If a row or column heading is specified by a single string, it is
    % expanded to generate unique headings by appending row or column
    % numbers.

    if numel(rnames)==1 && I > 1 && isrowheader
        rfmt = ['%s(%',num2str(length(num2str(J))),'d)'];
        r = rnames{1};
        for i = 1:I
            rnames{i} = sprintf(rfmt,r,i);
        end
    end

    if numel(cnames)==1 && J > 1 && iscolheader
        cfmt = ['%s(%',num2str(length(num2str(J))),'d)'];
        c = cnames{1};
        for j = 1:J
            cnames{j} = sprintf(cfmt,c,j);
        end
    end
    
    % Setup table formating parameters
    %
    %   prefix -- table prefix
    %   rowpfx -- prefix to each row
    %   rowsfx -- suffix to each row
    %   rowsep -- separator between rnames
    %   colsep -- separator between columns
    %   suffix -- table suffix
    %   rnamefmt -- sprintf format for row headers
    %   cnamefmt -- sprintf format for column headers
    %   datafmt -- sprintf format for data cells
      
    trm = @(s)regexprep(s,'\s','');
    colwidth = max(max(arrayfun(@(x)length(trm(sprintf(fmt,x))),A)));
    
    rwidth = max(cellfun(@(x)size(x,2),rnames));
    cwidth = max(colwidth,max(cellfun(@(x)size(x,2),cnames)));
    dwidth = max(colwidth,max(cellfun(@(x)size(x,2),cnames)));
    
    datafmt = ['%',num2str(dwidth),'.',fmtprec,fmttype];
    
    switch tableformat
        case {'mono'}
            hline = '';
            prefix = '';
            rowpfx = '';
            rowsfx = '';
            rowsep = sprintf('\n');           
            colsep = '  ';
            suffix = '';
            rnamefmt = ['%-',num2str(rwidth),'s'];
            cnamefmt = ['%',num2str(cwidth),'s'];
           % datafmt = ['%',num2str(dwidth),'.',num2str(fmtprec),fmttype];
            
        case {'plain','tab'}
            hline = '';
            prefix = '';
            rowpfx = '';
            rowsfx = '';
            rowsep = sprintf('\n');           
            colsep = sprintf('\t');
            suffix = '';
            rnamefmt = ['%-',num2str(rwidth),'s'];
            cnamefmt = ['%',num2str(cwidth),'s'];
           % datafmt = ['%',num2str(dwidth),'.5g'];
 
        case {'latex','tex'}
            hline = sprintf('\\hline\r\n');
            if isrowheader
                prefix = sprintf('\\begin{tabular}{l%s}\r\n',repmat('r',1,J));
            else
                prefix = sprintf('\\begin{tabular}{%s}\r\n',repmat('r',1,J));
            end
            rowpfx = '';
            rowsfx = '';
            rowsep = sprintf(' \\\\\r\n');
            colsep = ' & ';
            suffix = sprintf('\\end{tabular}');
            rnamefmt = ['%',num2str(rwidth),'s'];
            cnamefmt = ['\\multicolumn{1}{c}{\\bf %s}'];
            %datafmt = ['%',num2str(dwidth),'.5g'];
            
        case 'html'
            hline = '';
            prefix = sprintf('<table border=0 cellpadding=4 cellspacing=4>');
            rowpfx = sprintf('\n  <tr bgcolor="#EFEFEF">');
            rowsfx = sprintf('\n  </tr>');
            rowsep = '';
            colsep = '';
            suffix = sprintf('\n</table>');
            rnamefmt = ['\n    <td align="left">%s</td>'];
            cnamefmt = ['\n    <th align="center">%s</th>'];
            datafmt = ['\n    <td align="right">',datafmt,'</td>']

        case 'csv'
            hline = '';
            prefix = '';
            rowpfx = '';
            rowsfx = '';
            rowsep = sprintf('\n');           
            colsep = ',';
            suffix = '';
            rnamefmt = ['"%s"'];
            cnamefmt = ['"%s"'];
           % datafmt = ['"%',num2str(dwidth),'.5g"'];
 
        otherwise
            error('Unrecognized table format.');
    end

    % Start building the table
    S = prefix;
    
    % Column headers
    if iscolheader
        S = [S,hline,rowpfx];
        if isrowheader
            S = [S,sprintf(rnamefmt,' '),colsep];
        end
        for j = 1:J-1
            S = [S,sprintf(cnamefmt,cnames{j}),colsep];
        end
        S = [S,sprintf(cnamefmt,cnames{J}),rowsfx,rowsep];
    end

    % Data table
    S = [S,hline];
    for i = 1:I
        S = [S,rowpfx];
        if isrowheader
            S = [S,sprintf(rnamefmt,rnames{i}),colsep];
        end
        for j = 1:J-1
            S = [S,sprintf(datafmt,A(i,j)),colsep];
        end
        S = [S,sprintf(datafmt,A(i,J)),rowsfx,rowsep];
    end

    % Add suffix
    S = [S,hline,suffix];

    % If no outputs, display to console
    if nargout == 0
        disp(S);
    else
        str = S;
    end
    
    % Print file
    if nargin >= 6 && ~isempty(fname)
        fid = fopen(fname,'w');
        fprintf(fid,'%s',S);
        fclose(fid);
    end

end
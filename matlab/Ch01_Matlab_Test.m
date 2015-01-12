%% Check Matlab Installation on Student Computers
%
% File: |Ch01_Matlab_Test.m|
%
% Please run this script, publish the results, and submit the results via
% Sakai. The purpose of this script is to verify installation of Matlab and
% so that we understand what computer platforms need to be supported.


%% Matlab Installation
% The University maintains a site license to Matlab for students and
% faculty. Instructions on how to download and activate Matlab are
% available on the OIT web site <http:://oit.nd.edu>.

%% Get Computer Host Name

[ret, name] = system('hostname');   

if ret ~= 0,
    if ispc
       name = getenv('COMPUTERNAME');
    else      
       name = getenv('HOSTNAME');      
    end
end

%% Report Results

clc;
disp(['Matlab Version: ',version]);
disp([' Computer Type: ',computer]);
disp([' Computer Name: ',name(1:end-1)]);

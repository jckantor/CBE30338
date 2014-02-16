/* Include files */

#include "Ch23_E01_bioreactor_mpc_mdl_sfun.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Ch23_E01_bioreactor_mpc_mdlMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Ch23_E01_bioreactor_mpc_mdl_initializer(void)
{
}

void Ch23_E01_bioreactor_mpc_mdl_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Ch23_E01_bioreactor_mpc_mdl_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  return 0;
}

unsigned int sf_Ch23_E01_bioreactor_mpc_mdl_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(276073853U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2372829788U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(999587761U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(700744499U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(405147856U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1585384934U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3189196977U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4072584383U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1764838350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3410240878U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(118138738U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(243351119U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1073450442U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3845218271U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2036754422U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2575146504U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Ch23_E01_bioreactor_mpc_mdl_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Ch23_E01_bioreactor_mpc_mdl_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void Ch23_E01_bioreactor_mpc_mdl_debug_initialize(void)
{
  _Ch23_E01_bioreactor_mpc_mdlMachineNumber_ = sf_debug_initialize_machine(
    "Ch23_E01_bioreactor_mpc_mdl","sfun",0,0,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_Ch23_E01_bioreactor_mpc_mdlMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_Ch23_E01_bioreactor_mpc_mdlMachineNumber_,0);
}

void Ch23_E01_bioreactor_mpc_mdl_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Ch23_E01_bioreactor_mpc_mdl_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Ch23_E01_bioreactor_mpc_mdl", "Ch23_E01_bioreactor_mpc_mdl");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Ch23_E01_bioreactor_mpc_mdl_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

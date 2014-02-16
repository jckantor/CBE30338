/* Include files */

#include "blascompat32.h"
#include "mpclib_sfun.h"
#include "c4_mpclib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mpclib_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[20] = { "nargin", "nargout", "ref",
  "md", "nv", "ny", "p", "yoff", "voff", "no_md", "no_ref", "v_temp", "r_temp",
  "md_temp", "time", "openloopflag", "rseq", "vseq", "v", "next_t" };

/* Function Declarations */
static void initialize_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void initialize_params_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void enable_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void disable_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_mpclib(SFc4_mpclibInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_mpclib(SFc4_mpclibInstanceStruct
  *chartInstance);
static void set_sim_state_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void sf_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void initSimStructsc4_mpclib(SFc4_mpclibInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_b_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_rseq, const char_T *c4_identifier, real_T c4_y[20]);
static void c4_c_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[20]);
static void c4_d_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_vseq, const char_T *c4_identifier, real_T c4_y[21]);
static void c4_e_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[21]);
static real_T c4_f_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_v, const char_T *c4_identifier);
static real_T c4_g_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_h_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_i_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_mpclib, const char_T *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_mpclibInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_mpclib = 0U;
}

static void initialize_params_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
  real_T c4_d0;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_dv0[21];
  int32_T c4_i0;
  real_T c4_dv1[20];
  int32_T c4_i1;
  real_T c4_d7;
  real_T c4_d8;
  sf_set_error_prefix_string(
    "Error evaluating data 'nv' in the parent workspace.\n");
  sf_mex_import_named("nv", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c4_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_nv = c4_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'ny' in the parent workspace.\n");
  sf_mex_import_named("ny", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c4_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_ny = c4_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'p' in the parent workspace.\n");
  sf_mex_import_named("p", sf_mex_get_sfun_param(chartInstance->S, 6, 0), &c4_d2,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_p = c4_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'yoff' in the parent workspace.\n");
  sf_mex_import_named("yoff", sf_mex_get_sfun_param(chartInstance->S, 10, 0),
                      &c4_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_yoff = c4_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'voff' in the parent workspace.\n");
  sf_mex_import_named("voff", sf_mex_get_sfun_param(chartInstance->S, 9, 0),
                      &c4_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_voff = c4_d4;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'no_md' in the parent workspace.\n");
  sf_mex_import_named("no_md", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c4_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_no_md = c4_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'no_ref' in the parent workspace.\n");
  sf_mex_import_named("no_ref", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c4_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_no_ref = c4_d6;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'v_temp' in the parent workspace.\n");
  sf_mex_import_named("v_temp", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      c4_dv0, 0, 0, 0U, 1, 0U, 1, 21);
  for (c4_i0 = 0; c4_i0 < 21; c4_i0++) {
    chartInstance->c4_v_temp[c4_i0] = c4_dv0[c4_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'r_temp' in the parent workspace.\n");
  sf_mex_import_named("r_temp", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      c4_dv1, 0, 0, 0U, 1, 0U, 1, 20);
  for (c4_i1 = 0; c4_i1 < 20; c4_i1++) {
    chartInstance->c4_r_temp[c4_i1] = c4_dv1[c4_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'md_temp' in the parent workspace.\n");
  sf_mex_import_named("md_temp", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c4_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_md_temp = c4_d7;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'openloopflag' in the parent workspace.\n");
  sf_mex_import_named("sf_mex_get_sfun_param", sf_mex_get_sfun_param
                      (chartInstance->S, 5, 0), &c4_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_openloopflag = (c4_d8 != 0.0);
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_mpclib(SFc4_mpclibInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_mpclib(SFc4_mpclibInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i2;
  real_T c4_b_u[20];
  const mxArray *c4_c_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  int32_T c4_i3;
  real_T c4_d_u[21];
  const mxArray *c4_e_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_next_t;
  real_T *c4_v;
  real_T (*c4_vseq)[21];
  real_T (*c4_rseq)[20];
  c4_next_t = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_vseq = (real_T (*)[21])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_rseq = (real_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(5), FALSE);
  c4_hoistedGlobal = *c4_next_t;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i2 = 0; c4_i2 < 20; c4_i2++) {
    c4_b_u[c4_i2] = (*c4_rseq)[c4_i2];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 20), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_b_hoistedGlobal = *c4_v;
  c4_c_u = c4_b_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  for (c4_i3 = 0; c4_i3 < 21; c4_i3++) {
    c4_d_u[c4_i3] = (*c4_vseq)[c4_i3];
  }

  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 1, 21), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_active_c4_mpclib;
  c4_e_u = c4_c_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv2[20];
  int32_T c4_i4;
  real_T c4_dv3[21];
  int32_T c4_i5;
  real_T *c4_next_t;
  real_T *c4_v;
  real_T (*c4_rseq)[20];
  real_T (*c4_vseq)[21];
  c4_next_t = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_vseq = (real_T (*)[21])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_rseq = (real_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_next_t = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 0)), "next_t");
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
                        "rseq", c4_dv2);
  for (c4_i4 = 0; c4_i4 < 20; c4_i4++) {
    (*c4_rseq)[c4_i4] = c4_dv2[c4_i4];
  }

  *c4_v = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
    "v");
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
                        "vseq", c4_dv3);
  for (c4_i5 = 0; c4_i5 < 21; c4_i5++) {
    (*c4_vseq)[c4_i5] = c4_dv3[c4_i5];
  }

  chartInstance->c4_is_active_c4_mpclib = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 4)), "is_active_c4_mpclib");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_mpclib(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
}

static void sf_c4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_hoistedGlobal;
  real_T c4_g_hoistedGlobal;
  real_T c4_h_hoistedGlobal;
  real_T c4_i_hoistedGlobal;
  real_T c4_j_hoistedGlobal;
  real_T c4_k_hoistedGlobal;
  boolean_T c4_l_hoistedGlobal;
  real_T c4_ref;
  real_T c4_md;
  real_T c4_b_nv;
  real_T c4_b_ny;
  real_T c4_b_p;
  real_T c4_b_yoff;
  real_T c4_b_voff;
  real_T c4_b_no_md;
  real_T c4_b_no_ref;
  int32_T c4_i10;
  real_T c4_b_v_temp[21];
  int32_T c4_i11;
  real_T c4_b_r_temp[20];
  real_T c4_b_md_temp;
  real_T c4_time;
  boolean_T c4_b_openloopflag;
  uint32_T c4_debug_family_var_map[20];
  real_T c4_nargin = 14.0;
  real_T c4_nargout = 4.0;
  real_T c4_rseq[20];
  real_T c4_vseq[21];
  real_T c4_v;
  real_T c4_next_t;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_e_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_f_u;
  const mxArray *c4_f_y = NULL;
  real_T c4_g_u;
  const mxArray *c4_g_y = NULL;
  real_T c4_h_u;
  const mxArray *c4_h_y = NULL;
  real_T c4_i_u;
  const mxArray *c4_i_y = NULL;
  int32_T c4_i12;
  real_T c4_j_u[21];
  const mxArray *c4_j_y = NULL;
  int32_T c4_i13;
  real_T c4_k_u[20];
  const mxArray *c4_k_y = NULL;
  real_T c4_l_u;
  const mxArray *c4_l_y = NULL;
  real_T c4_m_u;
  const mxArray *c4_m_y = NULL;
  boolean_T c4_n_u;
  const mxArray *c4_n_y = NULL;
  const mxArray *c4_m0 = NULL;
  const mxArray *c4_m1 = NULL;
  const mxArray *c4_m2 = NULL;
  const mxArray *c4_m3 = NULL;
  const mxArray *c4_b_rseq = NULL;
  const mxArray *c4_b_vseq = NULL;
  const mxArray *c4_b_v = NULL;
  const mxArray *c4_b_next_t = NULL;
  real_T c4_dv4[20];
  int32_T c4_i14;
  real_T c4_dv5[21];
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  real_T *c4_b_ref;
  real_T *c4_b_md;
  real_T *c4_c_v;
  real_T *c4_b_time;
  real_T *c4_c_next_t;
  real_T (*c4_c_rseq)[20];
  real_T (*c4_c_vseq)[21];
  c4_c_next_t = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_c_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_md = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_c_vseq = (real_T (*)[21])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_c_rseq = (real_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  for (c4_i6 = 0; c4_i6 < 20; c4_i6++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_rseq)[c4_i6], 0U);
  }

  for (c4_i7 = 0; c4_i7 < 21; c4_i7++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_vseq)[c4_i7], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_ref, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_md, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_c_v, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_nv, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_ny, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_p, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_yoff, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_voff, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_no_md, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_no_ref, 11U);
  for (c4_i8 = 0; c4_i8 < 21; c4_i8++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_v_temp[c4_i8], 12U);
  }

  for (c4_i9 = 0; c4_i9 < 20; c4_i9++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_r_temp[c4_i9], 13U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c4_md_temp, 14U);
  _SFD_DATA_RANGE_CHECK(*c4_b_time, 15U);
  _SFD_DATA_RANGE_CHECK(*c4_c_next_t, 16U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c4_openloopflag, 17U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_ref;
  c4_b_hoistedGlobal = *c4_b_md;
  c4_c_hoistedGlobal = chartInstance->c4_nv;
  c4_d_hoistedGlobal = chartInstance->c4_ny;
  c4_e_hoistedGlobal = chartInstance->c4_p;
  c4_f_hoistedGlobal = chartInstance->c4_yoff;
  c4_g_hoistedGlobal = chartInstance->c4_voff;
  c4_h_hoistedGlobal = chartInstance->c4_no_md;
  c4_i_hoistedGlobal = chartInstance->c4_no_ref;
  c4_j_hoistedGlobal = chartInstance->c4_md_temp;
  c4_k_hoistedGlobal = *c4_b_time;
  c4_l_hoistedGlobal = chartInstance->c4_openloopflag;
  c4_ref = c4_hoistedGlobal;
  c4_md = c4_b_hoistedGlobal;
  c4_b_nv = c4_c_hoistedGlobal;
  c4_b_ny = c4_d_hoistedGlobal;
  c4_b_p = c4_e_hoistedGlobal;
  c4_b_yoff = c4_f_hoistedGlobal;
  c4_b_voff = c4_g_hoistedGlobal;
  c4_b_no_md = c4_h_hoistedGlobal;
  c4_b_no_ref = c4_i_hoistedGlobal;
  for (c4_i10 = 0; c4_i10 < 21; c4_i10++) {
    c4_b_v_temp[c4_i10] = chartInstance->c4_v_temp[c4_i10];
  }

  for (c4_i11 = 0; c4_i11 < 20; c4_i11++) {
    c4_b_r_temp[c4_i11] = chartInstance->c4_r_temp[c4_i11];
  }

  c4_b_md_temp = c4_j_hoistedGlobal;
  c4_time = c4_k_hoistedGlobal;
  c4_b_openloopflag = c4_l_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_ref, 2U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_md, 3U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_nv, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_ny, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_p, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_yoff, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_voff, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_no_md, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_no_ref, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_b_v_temp, 11U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_b_r_temp, 12U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_md_temp, 13U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_time, 14U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_openloopflag, 15U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_rseq, 16U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_vseq, 17U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_v, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_next_t, 19U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_next_t = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  CV_EML_IF(0, 1, 0, TRUE);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_u = c4_ref;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_b_u = c4_md;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_c_u = c4_b_nv;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_d_u = c4_b_ny;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_e_u = c4_b_p;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_f_u = c4_b_yoff;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_g_u = c4_b_voff;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_h_u = c4_b_no_md;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_i_u = c4_b_no_ref;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c4_i12 = 0; c4_i12 < 21; c4_i12++) {
    c4_j_u[c4_i12] = c4_b_v_temp[c4_i12];
  }

  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_j_u, 0, 0U, 1U, 0U, 1, 21), FALSE);
  for (c4_i13 = 0; c4_i13 < 20; c4_i13++) {
    c4_k_u[c4_i13] = c4_b_r_temp[c4_i13];
  }

  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_k_u, 0, 0U, 1U, 0U, 1, 20), FALSE);
  c4_l_u = c4_b_md_temp;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_m_u = c4_time;
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y", &c4_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  c4_n_u = c4_b_openloopflag;
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_n_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("mpcblock_refmd_mex", 4U, 14U, 14, c4_y, 14, c4_b_y, 14,
                    c4_c_y, 14, c4_d_y, 14, c4_e_y, 14, c4_f_y, 14, c4_g_y, 14,
                    c4_h_y, 14, c4_i_y, 14, c4_j_y, 14, c4_k_y, 14, c4_l_y, 14,
                    c4_m_y, 14, c4_n_y, &c4_m3, &c4_m2, &c4_m1, &c4_m0);
  sf_mex_assign(&c4_b_rseq, sf_mex_dup(c4_m3), FALSE);
  sf_mex_assign(&c4_b_vseq, sf_mex_dup(c4_m2), FALSE);
  sf_mex_assign(&c4_b_v, sf_mex_dup(c4_m1), FALSE);
  sf_mex_assign(&c4_b_next_t, sf_mex_dup(c4_m0), FALSE);
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_rseq), "rseq", c4_dv4);
  for (c4_i14 = 0; c4_i14 < 20; c4_i14++) {
    c4_rseq[c4_i14] = c4_dv4[c4_i14];
  }

  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_vseq), "vseq", c4_dv5);
  for (c4_i15 = 0; c4_i15 < 21; c4_i15++) {
    c4_vseq[c4_i15] = c4_dv5[c4_i15];
  }

  c4_v = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_v), "v");
  c4_next_t = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_next_t),
    "next_t");
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c4_b_rseq);
  sf_mex_destroy(&c4_b_vseq);
  sf_mex_destroy(&c4_b_v);
  sf_mex_destroy(&c4_b_next_t);
  sf_mex_destroy(&c4_m0);
  sf_mex_destroy(&c4_m1);
  sf_mex_destroy(&c4_m2);
  sf_mex_destroy(&c4_m3);
  for (c4_i16 = 0; c4_i16 < 20; c4_i16++) {
    (*c4_c_rseq)[c4_i16] = c4_rseq[c4_i16];
  }

  for (c4_i17 = 0; c4_i17 < 21; c4_i17++) {
    (*c4_c_vseq)[c4_i17] = c4_vseq[c4_i17];
  }

  *c4_c_v = c4_v;
  *c4_c_next_t = c4_next_t;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_mpclibMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_mpclib(SFc4_mpclibInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_v;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_v = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_v), &c4_thisId);
  sf_mex_destroy(&c4_v);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i18;
  real_T c4_b_inData[21];
  int32_T c4_i19;
  real_T c4_u[21];
  const mxArray *c4_y = NULL;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i18 = 0; c4_i18 < 21; c4_i18++) {
    c4_b_inData[c4_i18] = (*(real_T (*)[21])c4_inData)[c4_i18];
  }

  for (c4_i19 = 0; c4_i19 < 21; c4_i19++) {
    c4_u[c4_i19] = c4_b_inData[c4_i19];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 21), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_vseq;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[21];
  int32_T c4_i20;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_vseq = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_vseq), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_vseq);
  for (c4_i20 = 0; c4_i20 < 21; c4_i20++) {
    (*(real_T (*)[21])c4_outData)[c4_i20] = c4_y[c4_i20];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i21;
  real_T c4_b_inData[20];
  int32_T c4_i22;
  real_T c4_u[20];
  const mxArray *c4_y = NULL;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i21 = 0; c4_i21 < 20; c4_i21++) {
    c4_b_inData[c4_i21] = (*(real_T (*)[20])c4_inData)[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 20; c4_i22++) {
    c4_u[c4_i22] = c4_b_inData[c4_i22];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 20), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_rseq;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[20];
  int32_T c4_i23;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_rseq = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_rseq), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_rseq);
  for (c4_i23 = 0; c4_i23 < 20; c4_i23++) {
    (*(real_T (*)[20])c4_outData)[c4_i23] = c4_y[c4_i23];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static boolean_T c4_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_openloopflag;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_b_openloopflag = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_openloopflag),
    &c4_thisId);
  sf_mex_destroy(&c4_b_openloopflag);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_mpclib_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c4_nameCaptureInfo;
}

static void c4_b_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_rseq, const char_T *c4_identifier, real_T c4_y[20])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_rseq), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_rseq);
}

static void c4_c_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[20])
{
  real_T c4_dv6[20];
  int32_T c4_i24;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv6, 1, 0, 0U, 1, 0U, 1, 20);
  for (c4_i24 = 0; c4_i24 < 20; c4_i24++) {
    c4_y[c4_i24] = c4_dv6[c4_i24];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_vseq, const char_T *c4_identifier, real_T c4_y[21])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_vseq), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_vseq);
}

static void c4_e_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[21])
{
  real_T c4_dv7[21];
  int32_T c4_i25;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv7, 1, 0, 0U, 1, 0U, 1, 21);
  for (c4_i25 = 0; c4_i25 < 21; c4_i25++) {
    c4_y[c4_i25] = c4_dv7[c4_i25];
  }

  sf_mex_destroy(&c4_u);
}

static real_T c4_f_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_v, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_v), &c4_thisId);
  sf_mex_destroy(&c4_v);
  return c4_y;
}

static real_T c4_g_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d9;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d9, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d9;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_h_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i26;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i26, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i26;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_mpclib, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_mpclib), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_mpclib);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_mpclibInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_mpclibInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_mpclib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3649413280U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4219606024U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2125313999U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(136884730U);
}

mxArray *sf_c4_mpclib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("FRVN9m80QhwriHe37X8ZXH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(20);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(21);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(20);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(21);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_mpclib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[119],T\"next_t\",},{M[1],M[21],T\"rseq\",},{M[1],M[19],T\"v\",},{M[1],M[20],T\"vseq\",},{M[8],M[0],T\"is_active_c4_mpclib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_mpclib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_mpclibInstanceStruct *chartInstance;
    chartInstance = (SFc4_mpclibInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_mpclibMachineNumber_,
          4,
          1,
          1,
          18,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_mpclibMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_mpclibMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_mpclibMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"rseq");
          _SFD_SET_DATA_PROPS(1,2,0,1,"vseq");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ref");
          _SFD_SET_DATA_PROPS(3,1,1,0,"md");
          _SFD_SET_DATA_PROPS(4,2,0,1,"v");
          _SFD_SET_DATA_PROPS(5,10,0,0,"nv");
          _SFD_SET_DATA_PROPS(6,10,0,0,"ny");
          _SFD_SET_DATA_PROPS(7,10,0,0,"p");
          _SFD_SET_DATA_PROPS(8,10,0,0,"yoff");
          _SFD_SET_DATA_PROPS(9,10,0,0,"voff");
          _SFD_SET_DATA_PROPS(10,10,0,0,"no_md");
          _SFD_SET_DATA_PROPS(11,10,0,0,"no_ref");
          _SFD_SET_DATA_PROPS(12,10,0,0,"v_temp");
          _SFD_SET_DATA_PROPS(13,10,0,0,"r_temp");
          _SFD_SET_DATA_PROPS(14,10,0,0,"md_temp");
          _SFD_SET_DATA_PROPS(15,1,1,0,"time");
          _SFD_SET_DATA_PROPS(16,2,0,1,"next_t");
          _SFD_SET_DATA_PROPS(17,10,0,0,"openloopflag");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,628);
        _SFD_CV_INIT_EML_IF(0,1,0,283,314,469,627);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 20;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 21;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 21;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 20;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)c4_d_sf_marshallIn);

        {
          real_T *c4_ref;
          real_T *c4_md;
          real_T *c4_v;
          real_T *c4_time;
          real_T *c4_next_t;
          real_T (*c4_rseq)[20];
          real_T (*c4_vseq)[21];
          c4_next_t = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_md = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_vseq = (real_T (*)[21])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_rseq = (real_T (*)[20])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_rseq);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_vseq);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_ref);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_md);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_v);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c4_nv);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c4_ny);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c4_p);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c4_yoff);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c4_voff);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c4_no_md);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c4_no_ref);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c4_v_temp);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c4_r_temp);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c4_md_temp);
          _SFD_SET_DATA_VALUE_PTR(15U, c4_time);
          _SFD_SET_DATA_VALUE_PTR(16U, c4_next_t);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c4_openloopflag);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_mpclibMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "897LfFcndN59KTyB4eoidC";
}

static void sf_opaque_initialize_c4_mpclib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_mpclibInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
  initialize_c4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_mpclib(void *chartInstanceVar)
{
  enable_c4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_mpclib(void *chartInstanceVar)
{
  disable_c4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_mpclib(void *chartInstanceVar)
{
  sf_c4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_mpclib(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_mpclib((SFc4_mpclibInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_mpclib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c4_mpclib(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_mpclib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_mpclib((SFc4_mpclibInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_mpclib(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_mpclib(S);
}

static void sf_opaque_set_sim_state_c4_mpclib(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_mpclib(S, st);
}

static void sf_opaque_terminate_c4_mpclib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_mpclibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_mpclib_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_mpclib((SFc4_mpclibInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_mpclib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_mpclib((SFc4_mpclibInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_mpclib(SimStruct *S)
{
  /* Actual parameters from chart:
     md_temp no_md no_ref nv ny openloopflag p r_temp v_temp voff yoff
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7",
    "p8", "p9", "p10", "p11" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for md_temp*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for no_md*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for no_ref*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for nv*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for ny*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for openloopflag*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_BOOLEAN);

  /* registration for p*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for r_temp*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for v_temp*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);

  /* registration for voff*/
  ssRegDlgParamAsRunTimeParam(S, 9, 9, rtParamNames[9], SS_DOUBLE);

  /* registration for yoff*/
  ssRegDlgParamAsRunTimeParam(S, 10, 10, rtParamNames[10], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mpclib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1556519172U));
  ssSetChecksum1(S,(2452066606U));
  ssSetChecksum2(S,(624806971U));
  ssSetChecksum3(S,(463784087U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_mpclib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_mpclib(SimStruct *S)
{
  SFc4_mpclibInstanceStruct *chartInstance;
  chartInstance = (SFc4_mpclibInstanceStruct *)malloc(sizeof
    (SFc4_mpclibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_mpclibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_mpclib;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_mpclib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_mpclib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_mpclib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_mpclib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_mpclib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_mpclib;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_mpclib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_mpclib;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_mpclib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_mpclib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c4_mpclib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_mpclib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_mpclib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_mpclib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_mpclib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

/*
 * File: ArduinoFirstTry.c
 *
 * Code generated for Simulink model 'ArduinoFirstTry'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * TLC version                    : 8.7 (Aug  5 2014)
 * C/C++ source code generated on : Tue Feb 17 15:08:13 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoFirstTry.h"
#include "ArduinoFirstTry_private.h"

/* Block states (auto storage) */
DW_ArduinoFirstTry_T ArduinoFirstTry_DW;

/* Real-time model */
RT_MODEL_ArduinoFirstTry_T ArduinoFirstTry_M_;
RT_MODEL_ArduinoFirstTry_T *const ArduinoFirstTry_M = &ArduinoFirstTry_M_;

/* Model output function */
void ArduinoFirstTry_output(void)
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_PulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (ArduinoFirstTry_DW.clockTickCounter <
                        ArduinoFirstTry_P.PulseGenerator_Duty) &&
    (ArduinoFirstTry_DW.clockTickCounter >= 0L) ?
    ArduinoFirstTry_P.PulseGenerator_Amp : 0.0;
  if (ArduinoFirstTry_DW.clockTickCounter >=
      ArduinoFirstTry_P.PulseGenerator_Period - 1.0) {
    ArduinoFirstTry_DW.clockTickCounter = 0L;
  } else {
    ArduinoFirstTry_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      rtb_PulseGenerator_0 = (uint8_T)rtb_PulseGenerator;
    } else {
      rtb_PulseGenerator_0 = 0U;
    }
  } else {
    rtb_PulseGenerator_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_digitalWrite(ArduinoFirstTry_P.DigitalOutput_pinNumber,
                  rtb_PulseGenerator_0);
}

/* Model update function */
void ArduinoFirstTry_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void ArduinoFirstTry_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ArduinoFirstTry_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&ArduinoFirstTry_DW, 0,
                sizeof(DW_ArduinoFirstTry_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  ArduinoFirstTry_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(ArduinoFirstTry_P.DigitalOutput_pinNumber);
}

/* Model terminate function */
void ArduinoFirstTry_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

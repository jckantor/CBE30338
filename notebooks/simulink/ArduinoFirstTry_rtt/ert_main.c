/*
 * File: ert_main.c
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
#include "Arduino.h"
#include "io_wrappers.h"
#define INIT_TIMER_VAL                 59286
#define SETUP_PRESCALER                TCCR1B |= ((1<<CS12)); TCCR1B &= ~((1<<CS11) | (1<<CS10))
#define INTERRUPT_VECTOR               TIMER1_OVF_vect
#define DISABLE_TIMER                  TIMSK1 &= ~(1<<TOIE1)
#define ENABLE_TIMER                   TIMSK1 |= (1<<TOIE1)
#define TIMER_NORMAL_MODE              TCCR1A &= ~((1<<WGM11) | (1<<WGM10)); TCCR1B &= ~((1<<WGM13) | (1<<WGM12))
#define RESET_TIMER                    TCNT1 = INIT_TIMER_VAL

volatile int IsrOverrun = 0;
boolean_T isRateRunning[1] = { 0 };

boolean_T need2runFlags[1] = { 0 };

/*
 * The timer interrupt handler (gets invoked on every counter overflow).
 */
ISR(INTERRUPT_VECTOR)
{
  RESET_TIMER;
  rt_OneStep();
}

/*
 * Configures the base rate interrupt timer
 */
static void arduino_Timer_Setup()
{
  // Sets up the timer overflow interrupt.
  RESET_TIMER;

  // Initially disable the overflow interrupt (before configuration).
  DISABLE_TIMER;

  // Set the timer to normal mode.
  TIMER_NORMAL_MODE;

  // Set the prescaler.
  SETUP_PRESCALER;

  // Everything configured, so enable the overflow interrupt.
  ENABLE_TIMER;
}

void rt_OneStep(void)
{
  boolean_T eventFlags[1];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  sei();

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  ArduinoFirstTry_output();

  /* Get model outputs here */
  ArduinoFirstTry_update();
  cli();
  isRateRunning[0]--;
  if (eventFlags[0]) {
    if (need2runFlags[0]++) {
      IsrOverrun = 1;
      need2runFlags[0]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[0]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[0]++;
    sei();
    switch (0) {
     default:
      break;
    }

    cli();
    need2runFlags[0]--;
    isRateRunning[0]--;
  }
}

int_T main(void)
{
  init();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 9600);
  Serial_write(0, "***starting the model***", 26);

#endif

  ArduinoFirstTry_initialize();
  arduino_Timer_Setup();

  /* The main step loop */
  while (rtmGetErrorStatus(ArduinoFirstTry_M) == (NULL)) {
  }

  ArduinoFirstTry_terminate();

  /* Disable Interrupts */
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

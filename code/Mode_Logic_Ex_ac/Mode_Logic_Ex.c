/*
 * File: Mode_Logic_Ex.c
 *
 * Code generated for Simulink model 'Mode_Logic_Ex'.
 *
 * Model version                  : 1.201
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Oct  8 02:54:35 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mode_Logic_Ex.h"
#include "Mode_Logic_Ex_private.h"

/* Named constants for Chart: '<Root>/Mode_Logic' */
#define Mode_Logic_E_IN_Accelerate_mode ((uint8_T)1U)
#define Mode_Logic_E_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Mode_Logic_Ex_EngOffRPM        (790.0)
#define Mode_Logic_Ex_EngOnRPM         (800.0)
#define Mode_Logic_Ex_IN_Brake_mode    ((uint8_T)1U)
#define Mode_Logic_Ex_IN_Cruise_mode   ((uint8_T)2U)
#define Mode_Logic_Ex_IN_Motion_mode   ((uint8_T)2U)
#define Mode_Logic_Ex_IN_Normal_mode   ((uint8_T)1U)
#define Mode_Logic_Ex_IN_Start_mode    ((uint8_T)2U)
#define Mode_Logic_Ex_IN_charge        ((uint8_T)1U)
#define Mode_Logic_Ex_IN_nocharge      ((uint8_T)2U)

/* Block signals (default storage) */
B_Mode_Logic_Ex_T Mode_Logic_Ex_B;

/* Block states (default storage) */
DW_Mode_Logic_Ex_T Mode_Logic_Ex_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mode_Logic_Ex_T Mode_Logic_Ex_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mode_Logic_Ex_T Mode_Logic_Ex_Y;

/* Real-time model */
static RT_MODEL_Mode_Logic_Ex_T Mode_Logic_Ex_M_;
RT_MODEL_Mode_Logic_Ex_T *const Mode_Logic_Ex_M = &Mode_Logic_Ex_M_;

/* Forward declaration for local functions */
static real_T Mode_Logic_Ex_oldspeed(void);

/* Function for Chart: '<Root>/Mode_Logic' */
static real_T Mode_Logic_Ex_oldspeed(void)
{
  real_T b_y;
  int32_T k;

  /* MATLAB Function 'oldspeed': '<S1>:6' */
  /* '<S1>:6:2' */
  memcpy(&Mode_Logic_Ex_B.dv[0], &Mode_Logic_Ex_DW.speed_buffer[0], 20U * sizeof
         (real_T));

  /* Inport: '<Root>/speed' */
  /* '<S1>:6:3' */
  Mode_Logic_Ex_DW.speed_buffer[0] = Mode_Logic_Ex_U.Speed;

  /* '<S1>:6:4' */
  b_y = Mode_Logic_Ex_DW.speed_buffer[0];
  for (k = 0; k < 20; k++) {
    Mode_Logic_Ex_DW.speed_buffer[k + 1] = Mode_Logic_Ex_B.dv[k];
    b_y += Mode_Logic_Ex_DW.speed_buffer[k + 1];
  }

  return b_y / 21.0;
}

/* Model step function */
void Mode_Logic_Ex_step(void)
{
  /* Chart: '<Root>/Mode_Logic' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/charge'
   *  Inport: '<Root>/engine_speed'
   */
  /* Gateway: Mode_Logic */
  /* During: Mode_Logic */
  if (Mode_Logic_Ex_DW.is_active_c1_Mode_Logic_Ex == 0U) {
    /* Entry: Mode_Logic */
    Mode_Logic_Ex_DW.is_active_c1_Mode_Logic_Ex = 1U;

    /* Entry Internal: Mode_Logic */
    /* Transition: '<S1>:18' */
    Mode_Logic_Ex_DW.is_c1_Mode_Logic_Ex = Mode_Logic_Ex_IN_Motion_mode;

    /* Entry Internal 'Motion_mode': '<S1>:9' */
    /* Transition: '<S1>:11' */
    Mode_Logic_Ex_DW.is_Motion_mode = Mode_Logic_Ex_IN_Start_mode;

    /* Outport: '<Root>/Gen_Enable' */
    /* Entry 'Start_mode': '<S1>:4' */
    Mode_Logic_Ex_Y.Gen_Enable = 1.0;

    /* Outport: '<Root>/Mot_Enable' */
    Mode_Logic_Ex_Y.Mot_Enable = 1.0;

    /* Outport: '<Root>/ICE_Enable' */
    Mode_Logic_Ex_Y.ICE_Enable = 0.0;
  } else if (Mode_Logic_Ex_DW.is_c1_Mode_Logic_Ex == Mode_Logic_Ex_IN_Brake_mode)
  {
    /* Outport: '<Root>/Gen_Enable' */
    Mode_Logic_Ex_Y.Gen_Enable = 0.0;

    /* Outport: '<Root>/ICE_Enable' */
    Mode_Logic_Ex_Y.ICE_Enable = 0.0;

    /* During 'Brake_mode': '<S1>:5' */
    if (Mode_Logic_Ex_U.Brake < 0.05) {
      /* Transition: '<S1>:17' */
      Mode_Logic_Ex_DW.is_c1_Mode_Logic_Ex = Mode_Logic_Ex_IN_Motion_mode;

      /* Entry Internal 'Motion_mode': '<S1>:9' */
      /* Transition: '<S1>:11' */
      Mode_Logic_Ex_DW.is_Motion_mode = Mode_Logic_Ex_IN_Start_mode;

      /* Outport: '<Root>/Gen_Enable' */
      /* Entry 'Start_mode': '<S1>:4' */
      Mode_Logic_Ex_Y.Gen_Enable = 1.0;

      /* Outport: '<Root>/Mot_Enable' */
      Mode_Logic_Ex_Y.Mot_Enable = 1.0;

      /* Outport: '<Root>/ICE_Enable' */
      Mode_Logic_Ex_Y.ICE_Enable = 0.0;
    }
  } else {
    /* During 'Motion_mode': '<S1>:9' */
    if (Mode_Logic_Ex_U.Brake >= 0.05) {
      /* Transition: '<S1>:16' */
      /* Exit Internal 'Motion_mode': '<S1>:9' */
      /* Exit Internal 'Normal_mode': '<S1>:1' */
      /* Exit Internal 'Cruise_mode': '<S1>:2' */
      Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
      Mode_Logic_Ex_DW.is_Normal_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
      Mode_Logic_Ex_DW.is_Motion_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
      Mode_Logic_Ex_DW.is_c1_Mode_Logic_Ex = Mode_Logic_Ex_IN_Brake_mode;

      /* Outport: '<Root>/Mot_Enable' */
      /* Entry 'Brake_mode': '<S1>:5' */
      Mode_Logic_Ex_Y.Mot_Enable = 1.0;

      /* Outport: '<Root>/Gen_Enable' */
      Mode_Logic_Ex_Y.Gen_Enable = 0.0;

      /* Outport: '<Root>/ICE_Enable' */
      Mode_Logic_Ex_Y.ICE_Enable = 0.0;
    } else if (Mode_Logic_Ex_DW.is_Motion_mode == Mode_Logic_Ex_IN_Normal_mode)
    {
      /* Outport: '<Root>/ICE_Enable' */
      Mode_Logic_Ex_Y.ICE_Enable = 1.0;

      /* During 'Normal_mode': '<S1>:1' */
      if (Mode_Logic_Ex_U.EngSpeed <= Mode_Logic_Ex_EngOffRPM) {
        /* Transition: '<S1>:12' */
        /* Exit Internal 'Normal_mode': '<S1>:1' */
        /* Exit Internal 'Cruise_mode': '<S1>:2' */
        Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
        Mode_Logic_Ex_DW.is_Normal_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
        Mode_Logic_Ex_DW.is_Motion_mode = Mode_Logic_Ex_IN_Start_mode;

        /* Outport: '<Root>/Gen_Enable' */
        /* Entry 'Start_mode': '<S1>:4' */
        Mode_Logic_Ex_Y.Gen_Enable = 1.0;

        /* Outport: '<Root>/Mot_Enable' */
        Mode_Logic_Ex_Y.Mot_Enable = 1.0;

        /* Outport: '<Root>/ICE_Enable' */
        Mode_Logic_Ex_Y.ICE_Enable = 0.0;
      } else if (Mode_Logic_Ex_DW.is_Normal_mode ==
                 Mode_Logic_E_IN_Accelerate_mode) {
        /* Outport: '<Root>/Gen_Enable' */
        Mode_Logic_Ex_Y.Gen_Enable = 0.0;

        /* During 'Accelerate_mode': '<S1>:3' */
        if (((Mode_Logic_Ex_U.Speed > 0.998 * Mode_Logic_Ex_oldspeed()) &&
             (Mode_Logic_Ex_U.Speed < 1.002 * Mode_Logic_Ex_oldspeed())) ||
            (Mode_Logic_Ex_U.Charge <= 30.0)) {
          /* Transition: '<S1>:10' */
          Mode_Logic_Ex_DW.is_Normal_mode = Mode_Logic_Ex_IN_Cruise_mode;

          /* Outport: '<Root>/Mot_Enable' */
          /* Entry 'Cruise_mode': '<S1>:2' */
          Mode_Logic_Ex_Y.Mot_Enable = 1.0;

          /* Entry Internal 'Cruise_mode': '<S1>:2' */
          /* Transition: '<S1>:13' */
          Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_Ex_IN_nocharge;

          /* Outport: '<Root>/Gen_Enable' */
          /* Entry 'nocharge': '<S1>:7' */
          Mode_Logic_Ex_Y.Gen_Enable = 0.0;
        }
      } else {
        /* During 'Cruise_mode': '<S1>:2' */
        if (((Mode_Logic_Ex_U.Speed < 0.998 * Mode_Logic_Ex_oldspeed()) ||
             (Mode_Logic_Ex_U.Speed > 1.002 * Mode_Logic_Ex_oldspeed())) &&
            (Mode_Logic_Ex_U.Charge > 32.0)) {
          /* Transition: '<S1>:15' */
          /* Exit Internal 'Cruise_mode': '<S1>:2' */
          Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
          Mode_Logic_Ex_DW.is_Normal_mode = Mode_Logic_E_IN_Accelerate_mode;

          /* Outport: '<Root>/Gen_Enable' */
          /* Entry 'Accelerate_mode': '<S1>:3' */
          Mode_Logic_Ex_Y.Gen_Enable = 0.0;

          /* Outport: '<Root>/Mot_Enable' */
          Mode_Logic_Ex_Y.Mot_Enable = 1.0;
        } else if (Mode_Logic_Ex_DW.is_Cruise_mode == Mode_Logic_Ex_IN_charge) {
          /* Outport: '<Root>/Gen_Enable' */
          Mode_Logic_Ex_Y.Gen_Enable = 1.0;

          /* During 'charge': '<S1>:8' */
          if (Mode_Logic_Ex_U.Charge > 100.0) {
            /* Transition: '<S1>:19' */
            Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_Ex_IN_nocharge;

            /* Outport: '<Root>/Gen_Enable' */
            /* Entry 'nocharge': '<S1>:7' */
            Mode_Logic_Ex_Y.Gen_Enable = 0.0;
          }
        } else {
          /* Outport: '<Root>/Gen_Enable' */
          Mode_Logic_Ex_Y.Gen_Enable = 0.0;

          /* During 'nocharge': '<S1>:7' */
          if (Mode_Logic_Ex_U.Charge < 30.0) {
            /* Transition: '<S1>:20' */
            Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_Ex_IN_charge;

            /* Outport: '<Root>/Gen_Enable' */
            /* Entry 'charge': '<S1>:8' */
            Mode_Logic_Ex_Y.Gen_Enable = 1.0;

            /* Outport: '<Root>/Mot_Enable' */
            Mode_Logic_Ex_Y.Mot_Enable = 0.0;
          }
        }
      }
    } else {
      /* Outport: '<Root>/Gen_Enable' */
      Mode_Logic_Ex_Y.Gen_Enable = 1.0;

      /* Outport: '<Root>/ICE_Enable' */
      Mode_Logic_Ex_Y.ICE_Enable = 0.0;

      /* During 'Start_mode': '<S1>:4' */
      if (Mode_Logic_Ex_U.EngSpeed > Mode_Logic_Ex_EngOnRPM) {
        /* Transition: '<S1>:21' */
        Mode_Logic_Ex_DW.is_Motion_mode = Mode_Logic_Ex_IN_Normal_mode;

        /* Outport: '<Root>/ICE_Enable' */
        /* Entry 'Normal_mode': '<S1>:1' */
        Mode_Logic_Ex_Y.ICE_Enable = 1.0;

        /* Entry Internal 'Normal_mode': '<S1>:1' */
        /* Transition: '<S1>:14' */
        Mode_Logic_Ex_DW.is_Normal_mode = Mode_Logic_E_IN_Accelerate_mode;

        /* Outport: '<Root>/Gen_Enable' */
        /* Entry 'Accelerate_mode': '<S1>:3' */
        Mode_Logic_Ex_Y.Gen_Enable = 0.0;

        /* Outport: '<Root>/Mot_Enable' */
        Mode_Logic_Ex_Y.Mot_Enable = 1.0;
      }
    }
  }

  /* End of Chart: '<Root>/Mode_Logic' */
}

/* Model initialize function */
void Mode_Logic_Ex_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Mode_Logic_Ex_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Mode_Logic_Ex_DW, 0,
                sizeof(DW_Mode_Logic_Ex_T));

  /* external inputs */
  (void)memset(&Mode_Logic_Ex_U, 0, sizeof(ExtU_Mode_Logic_Ex_T));

  /* external outputs */
  (void) memset((void *)&Mode_Logic_Ex_Y, 0,
                sizeof(ExtY_Mode_Logic_Ex_T));

  /* SystemInitialize for Chart: '<Root>/Mode_Logic' */
  Mode_Logic_Ex_DW.is_Motion_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
  Mode_Logic_Ex_DW.is_Normal_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
  Mode_Logic_Ex_DW.is_Cruise_mode = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
  Mode_Logic_Ex_DW.is_active_c1_Mode_Logic_Ex = 0U;
  Mode_Logic_Ex_DW.is_c1_Mode_Logic_Ex = Mode_Logic_E_IN_NO_ACTIVE_CHILD;
  memset(&Mode_Logic_Ex_DW.speed_buffer[0], 0, 21U * sizeof(real_T));

  /* SystemInitialize for Outport: '<Root>/Mot_Enable' incorporates:
   *  Chart: '<Root>/Mode_Logic'
   */
  Mode_Logic_Ex_Y.Mot_Enable = 0.0;

  /* SystemInitialize for Outport: '<Root>/Gen_Enable' incorporates:
   *  Chart: '<Root>/Mode_Logic'
   */
  Mode_Logic_Ex_Y.Gen_Enable = 0.0;

  /* SystemInitialize for Outport: '<Root>/ICE_Enable' incorporates:
   *  Chart: '<Root>/Mode_Logic'
   */
  Mode_Logic_Ex_Y.ICE_Enable = 0.0;
}

/* Model terminate function */
void Mode_Logic_Ex_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

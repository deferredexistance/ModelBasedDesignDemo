/*
 * File: Mode_Logic_Ex.h
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

#ifndef RTW_HEADER_Mode_Logic_Ex_h_
#define RTW_HEADER_Mode_Logic_Ex_h_
#include <string.h>
#include <stddef.h>
#ifndef Mode_Logic_Ex_COMMON_INCLUDES_
#define Mode_Logic_Ex_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mode_Logic_Ex_COMMON_INCLUDES_ */

#include "Mode_Logic_Ex_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T dv[20];
} B_Mode_Logic_Ex_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T speed_buffer[21];             /* '<Root>/Mode_Logic' */
  uint8_T is_active_c1_Mode_Logic_Ex;  /* '<Root>/Mode_Logic' */
  uint8_T is_c1_Mode_Logic_Ex;         /* '<Root>/Mode_Logic' */
  uint8_T is_Motion_mode;              /* '<Root>/Mode_Logic' */
  uint8_T is_Normal_mode;              /* '<Root>/Mode_Logic' */
  uint8_T is_Cruise_mode;              /* '<Root>/Mode_Logic' */
} DW_Mode_Logic_Ex_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Speed;                        /* '<Root>/speed' */
  real_T Brake;                        /* '<Root>/brake' */
  real_T Charge;                       /* '<Root>/charge' */
  real_T EngSpeed;                     /* '<Root>/engine_speed' */
} ExtU_Mode_Logic_Ex_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mot_Enable;                   /* '<Root>/Mot_Enable' */
  real_T Gen_Enable;                   /* '<Root>/Gen_Enable' */
  real_T ICE_Enable;                   /* '<Root>/ICE_Enable' */
} ExtY_Mode_Logic_Ex_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mode_Logic_Ex_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Mode_Logic_Ex_T Mode_Logic_Ex_B;

/* Block states (default storage) */
extern DW_Mode_Logic_Ex_T Mode_Logic_Ex_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mode_Logic_Ex_T Mode_Logic_Ex_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mode_Logic_Ex_T Mode_Logic_Ex_Y;

/* Model entry point functions */
extern void Mode_Logic_Ex_initialize(void);
extern void Mode_Logic_Ex_step(void);
extern void Mode_Logic_Ex_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mode_Logic_Ex_T *const Mode_Logic_Ex_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Mode_Logic_Ex'
 * '<S1>'   : 'Mode_Logic_Ex/Mode_Logic'
 */
#endif                                 /* RTW_HEADER_Mode_Logic_Ex_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

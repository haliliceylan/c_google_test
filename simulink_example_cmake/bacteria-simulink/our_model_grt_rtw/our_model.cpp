/*
 * our_model.cpp
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "our_model".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sun Feb 13 01:00:25 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "our_model.h"
#include "our_model_private.h"

int halil(int i){
  if(i > 3){
    i++;
  }
  return i + 1;
}
/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void our_modelModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 1 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  our_model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  our_model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  our_model_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void our_modelModelClass::step()
{
  if (rtmIsMajorTimeStep((&our_model_M))) {
    /* set solver stop time */
    if (!((&our_model_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&our_model_M)->solverInfo, (((&our_model_M)
        ->Timing.clockTickH0 + 1) * (&our_model_M)->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&our_model_M)->solverInfo, (((&our_model_M)
        ->Timing.clockTick0 + 1) * (&our_model_M)->Timing.stepSize0 +
        (&our_model_M)->Timing.clockTickH0 * (&our_model_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&our_model_M))) {
    (&our_model_M)->Timing.t[0] = rtsiGetT(&(&our_model_M)->solverInfo);
  }

  /* Integrator: '<Root>/Integrator' */
  our_model_B.Integrator = our_model_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep((&our_model_M))) {
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Product: '<Root>/Product'
   */
  our_model_B.Sum = our_model_P.Gain1_Gain * our_model_B.Integrator -
    our_model_B.Integrator * our_model_B.Integrator * our_model_P.Gain_Gain;
  if (rtmIsMajorTimeStep((&our_model_M))) {
    /* Matfile logging */
    rt_UpdateTXYLogVars((&our_model_M)->rtwLogInfo, ((&our_model_M)->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&our_model_M))) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal((&our_model_M))!=-1) &&
          !((rtmGetTFinal((&our_model_M))-((((&our_model_M)->Timing.clockTick1+(
                &our_model_M)->Timing.clockTickH1* 4294967296.0)) * 0.02)) >
            ((((&our_model_M)->Timing.clockTick1+(&our_model_M)
               ->Timing.clockTickH1* 4294967296.0)) * 0.02) * (DBL_EPSILON))) {
        rtmSetErrorStatus((&our_model_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&our_model_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&our_model_M)->Timing.clockTick0)) {
      ++(&our_model_M)->Timing.clockTickH0;
    }

    (&our_model_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&our_model_M)
      ->solverInfo);

    {
      /* Update absolute timer for sample time: [0.02s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.02, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&our_model_M)->Timing.clockTick1++;
      if (!(&our_model_M)->Timing.clockTick1) {
        (&our_model_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void our_modelModelClass::our_model_derivatives()
{
  XDot_our_model_T *_rtXdot;
  _rtXdot = ((XDot_our_model_T *) (&our_model_M)->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = our_model_B.Sum;
}

/* Model initialize function */
void our_modelModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&our_model_M)->solverInfo, &(&our_model_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&our_model_M)->solverInfo, &rtmGetTPtr((&our_model_M)));
    rtsiSetStepSizePtr(&(&our_model_M)->solverInfo, &(&our_model_M)
                       ->Timing.stepSize0);
    rtsiSetdXPtr(&(&our_model_M)->solverInfo, &(&our_model_M)->derivs);
    rtsiSetContStatesPtr(&(&our_model_M)->solverInfo, (real_T **) &(&our_model_M)
                         ->contStates);
    rtsiSetNumContStatesPtr(&(&our_model_M)->solverInfo, &(&our_model_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&our_model_M)->solverInfo, &(&our_model_M
      )->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&our_model_M)->solverInfo,
      &(&our_model_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&our_model_M)->solverInfo,
      &(&our_model_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&our_model_M)->solverInfo, (&rtmGetErrorStatus
      ((&our_model_M))));
    rtsiSetRTModelPtr(&(&our_model_M)->solverInfo, (&our_model_M));
  }

  rtsiSetSimTimeStep(&(&our_model_M)->solverInfo, MAJOR_TIME_STEP);
  (&our_model_M)->intgData.y = (&our_model_M)->odeY;
  (&our_model_M)->intgData.f[0] = (&our_model_M)->odeF[0];
  (&our_model_M)->intgData.f[1] = (&our_model_M)->odeF[1];
  (&our_model_M)->intgData.f[2] = (&our_model_M)->odeF[2];
  (&our_model_M)->contStates = ((X_our_model_T *) &our_model_X);
  rtsiSetSolverData(&(&our_model_M)->solverInfo, static_cast<void *>
                    (&(&our_model_M)->intgData));
  rtsiSetSolverName(&(&our_model_M)->solverInfo,"ode3");
  rtmSetTPtr((&our_model_M), &(&our_model_M)->Timing.tArray[0]);
  rtmSetTFinal((&our_model_M), 1.0);
  (&our_model_M)->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (nullptr);
    (&our_model_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&our_model_M)->rtwLogInfo, (nullptr));
    rtliSetLogXSignalPtrs((&our_model_M)->rtwLogInfo, (nullptr));
    rtliSetLogT((&our_model_M)->rtwLogInfo, "tout");
    rtliSetLogX((&our_model_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&our_model_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&our_model_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&our_model_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&our_model_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&our_model_M)->rtwLogInfo, 1);
    rtliSetLogY((&our_model_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&our_model_M)->rtwLogInfo, (nullptr));
    rtliSetLogYSignalPtrs((&our_model_M)->rtwLogInfo, (nullptr));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&our_model_M)->rtwLogInfo, 0.0, rtmGetTFinal
    ((&our_model_M)), (&our_model_M)->Timing.stepSize0, (&rtmGetErrorStatus
    ((&our_model_M))));

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  our_model_X.Integrator_CSTATE = our_model_P.Integrator_IC;
}

/* Model terminate function */
void our_modelModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
our_modelModelClass::our_modelModelClass() :
  our_model_B(),
  our_model_X(),
  our_model_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
our_modelModelClass::~our_modelModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_our_model_T * our_modelModelClass::getRTM()
{
  return (&our_model_M);
}

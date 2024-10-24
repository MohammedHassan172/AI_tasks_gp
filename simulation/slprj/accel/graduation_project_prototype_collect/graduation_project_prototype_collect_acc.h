#ifndef RTW_HEADER_graduation_project_prototype_collect_acc_h_
#define RTW_HEADER_graduation_project_prototype_collect_acc_h_
#ifndef graduation_project_prototype_collect_acc_COMMON_INCLUDES_
#define graduation_project_prototype_collect_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sl_fileio_rtw.h"
#include "simtarget/slSimTgtSlFileioRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "graduation_project_prototype_collect_acc_types.h"
#include <float.h>
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "simstruc_types.h"
typedef struct { real_T B_32_0_0 [ 4 ] ; real_T B_32_2_0 [ 16 ] ; real_T
B_32_3_0 [ 4 ] ; real_T B_32_4_0 ; real_T B_32_5_0 ; real_T B_32_9_0 [ 4 ] ;
real_T B_32_13_0 [ 2 ] ; real_T B_32_14_0 [ 2 ] ; real_T B_32_15_0 [ 4 ] ;
real_T B_32_16_0 [ 2 ] ; real_T B_32_17_0 [ 5 ] ; real_T B_32_17_1 [ 12 ] ;
real_T B_32_18_0 [ 2 ] ; real_T B_32_19_0 [ 2 ] ; real_T B_32_20_0 ; real_T
B_32_21_0 ; real_T B_32_22_0 [ 3 ] ; real_T B_32_24_0 ; real_T B_32_26_0 ;
real_T B_32_27_0 ; real_T B_32_28_0 ; real_T B_32_31_0 ; real_T B_32_33_0 ;
real_T B_32_35_0 ; real_T B_32_36_0 ; real_T B_32_39_0 ; real_T B_32_41_0 ;
real_T B_32_43_0 ; real_T B_32_45_0 ; real_T B_32_46_0 ; real_T B_32_47_0 ;
real_T B_32_50_0 ; real_T B_32_52_0 ; real_T B_32_54_0 ; real_T B_32_55_0 ;
real_T B_32_58_0 ; real_T B_32_60_0 ; real_T B_32_62_0 ; real_T B_32_64_0 ;
real_T B_32_65_0 ; real_T B_32_66_0 ; real_T B_32_69_0 ; real_T B_32_71_0 ;
real_T B_32_73_0 ; real_T B_32_74_0 ; real_T B_32_77_0 ; real_T B_32_79_0 ;
real_T B_32_81_0 ; real_T B_32_83_0 ; real_T B_32_84_0 ; real_T B_32_85_0 ;
real_T B_32_88_0 ; real_T B_32_90_0 ; real_T B_32_92_0 ; real_T B_32_93_0 ;
real_T B_32_96_0 ; real_T B_32_98_0 ; real_T B_32_100_0 ; real_T B_32_102_0 ;
real_T B_32_103_0 ; real_T B_32_104_0 ; real_T B_32_107_0 ; real_T B_32_109_0
; real_T B_32_111_0 ; real_T B_32_112_0 ; real_T B_32_115_0 ; real_T
B_32_117_0 ; real_T B_32_119_0 ; real_T B_32_121_0 ; real_T B_32_122_0 ;
real_T B_32_123_0 ; real_T B_32_124_0 [ 2 ] ; real_T B_32_125_0 [ 4 ] ;
real_T B_32_129_0 [ 2 ] ; real_T B_32_130_0 ; real_T B_32_131_0 [ 2 ] ;
real_T B_32_132_0 ; real_T B_32_133_0 [ 19 ] ; real_T B_32_136_0 ; real_T
B_32_139_0 [ 2 ] ; real_T B_32_140_0 ; real_T B_32_144_0 ; real_T B_32_145_0
; real_T B_32_149_0 ; real_T B_32_151_0 ; real_T B_32_152_0 ; real_T
B_32_153_0 ; real_T B_32_155_0 ; real_T B_32_156_0 ; real_T B_32_157_0 ;
real_T B_32_161_0 ; real_T B_32_163_0 ; real_T B_32_164_0 ; real_T B_32_186_0
[ 3 ] ; real_T B_32_188_0 ; real_T B_32_189_0 ; real_T B_32_193_0 ; real_T
B_32_197_0 [ 6 ] ; real_T B_32_198_0 [ 6 ] ; real_T B_32_199_0 [ 6 ] ; real_T
B_32_210_0 [ 16 ] ; real_T B_32_211_0 [ 16 ] ; real_T B_32_212_0 [ 16 ] ;
real_T B_32_213_0 [ 4 ] ; real_T B_32_214_0 [ 4 ] ; real_T B_32_215_0 [ 4 ] ;
real_T B_32_216_0 ; real_T B_32_217_0 ; real_T B_32_218_0 ; real_T B_32_219_0
; real_T B_32_220_0 ; real_T B_32_227_0 ; real_T B_32_229_0 ; real_T
B_32_231_0 ; real_T B_32_233_0 ; real_T B_32_235_0 ; real_T B_32_237_0 ;
real_T B_32_238_0 [ 3 ] ; real_T B_32_239_0 [ 3 ] ; real_T B_32_241_0 ;
real_T B_32_243_0 ; real_T B_32_245_0 ; real_T B_32_247_0 ; real_T B_32_254_0
[ 2 ] ; real_T B_32_255_0 [ 3 ] ; real_T B_32_274_0 ; real_T B_32_284_0 ;
real_T B_32_294_0 ; real_T B_32_2_0_m ; real_T B_32_3_0_c ; real_T B_32_4_0_k
; real_T B_32_5_0_c [ 16 ] ; real_T B_32_6_0 ; real_T B_32_7_0 [ 16 ] ;
real_T B_32_8_0 ; real_T B_32_9_0_b ; real_T B_32_14_0_p ; real_T B_32_15_0_c
; real_T B_32_16_0_f [ 2 ] ; real_T B_32_20_0_g ; real_T B_32_21_0_g ; real_T
B_32_24_0_m ; real_T B_32_26_0_n ; real_T B_32_31_0_p ; real_T B_32_32_0 ;
real_T B_32_34_0 ; real_T B_32_37_0 ; real_T B_32_39_0_l ; real_T B_32_40_0 ;
real_T B_32_47_0_j ; real_T B_32_48_0 ; real_T B_32_53_0 ; real_T B_32_58_0_d
; real_T B_32_73_0_g ; real_T B_32_74_0_l ; real_T B_31_0_0 ; real_T B_31_1_0
; real_T B_30_0_0 ; real_T B_30_1_0 ; real_T B_29_0_0 ; real_T B_29_1_0 ;
real_T B_28_0_0 ; real_T B_28_1_0 ; real_T B_27_1_0 ; real_T B_27_13_0 ;
real_T B_27_16_0 ; real_T B_27_18_0 ; real_T B_27_22_0 ; real_T B_27_24_0 ;
real_T B_27_25_0 ; real_T B_27_26_0 ; real_T B_27_27_0 ; real_T B_27_28_0 ;
real_T B_27_29_0 ; real_T B_27_30_0 ; real_T B_27_31_0 ; real_T B_27_32_0 ;
real_T B_27_33_0 ; real_T B_27_34_0 ; real_T B_27_35_0 ; real_T B_27_36_0 ;
real_T B_27_37_0 ; real_T B_27_0_0 ; real_T B_27_1_0_d ; real_T B_26_11_0 [ 3
] ; real_T B_26_12_0 ; real_T B_26_15_0 ; real_T B_26_17_0 ; real_T B_26_19_0
; real_T B_26_22_0 ; real_T B_26_23_0 ; real_T B_26_25_0 ; real_T B_26_28_0 ;
real_T B_26_31_0 ; real_T B_26_33_0 ; real_T B_26_35_0 ; real_T B_26_39_0 ;
real_T B_26_41_0 ; real_T B_26_42_0 ; real_T B_26_43_0 ; real_T B_26_44_0 [ 3
] ; real_T B_26_45_0 [ 3 ] ; real_T B_26_0_0 ; real_T B_26_1_0 ; real_T
B_26_2_0 ; real_T B_26_3_0 ; real_T B_26_4_0 ; real_T B_26_5_0 ; real_T
B_26_6_0 ; real_T B_26_7_0 ; real_T B_25_1_0 ; real_T B_23_1_0 ; real_T
B_21_0_0 ; real_T B_21_1_0 ; real_T B_10_0_0 ; real_T B_10_2_0 [ 4 ] ; real_T
B_10_3_0 [ 16 ] ; real_T B_10_4_0 [ 16 ] ; real_T B_10_0_0_d [ 2 ] ; real_T
B_10_1_0 [ 16 ] ; real_T B_9_0_0 ; real_T B_9_2_0 [ 4 ] ; real_T B_9_3_0 [ 16
] ; real_T B_9_4_0 [ 16 ] ; real_T B_9_0_0_l [ 2 ] ; real_T B_9_1_0 [ 16 ] ;
real_T B_8_1_0 ; real_T B_8_2_0 ; real_T B_8_3_0 ; real_T B_8_4_0 ; real_T
B_8_5_0 ; real_T B_8_5_1 ; real_T B_8_6_0 ; real_T B_8_6_1 ; real_T B_8_7_0 [
16 ] ; real_T B_8_8_0 [ 16 ] ; real_T B_8_0_0 [ 16 ] ; real_T B_8_1_0_o ;
real_T B_7_0_0 ; real_T B_7_1_0 ; real_T B_7_2_0 ; real_T B_7_3_0 ; real_T
B_6_0_0 ; real_T B_6_1_0 ; real_T B_6_2_0 ; real_T B_6_3_0 ; real_T B_5_0_0 ;
real_T B_5_1_0 ; real_T B_5_2_0 ; real_T B_5_3_0 ; real_T B_4_0_0 ; real_T
B_4_1_0 ; real_T B_4_2_0 ; real_T B_4_3_0 ; real_T B_3_0_0 ; real_T B_3_1_0 ;
real_T B_3_2_0 ; real_T B_3_3_0 ; real_T B_2_0_0 ; real_T B_2_1_0 ; real_T
B_2_2_0 ; real_T B_2_3_0 ; real_T B_1_0_0 ; real_T B_1_1_0 [ 3 ] ; real_T
B_1_3_0 ; real_T B_1_5_0 [ 2 ] ; real_T B_1_6_0 [ 2 ] ; real_T B_1_7_0 ;
real_T B_1_8_0 [ 2 ] ; real_T B_1_9_0 ; real_T B_1_11_0 ; real_T B_1_13_0 ;
real_T B_1_14_0 [ 16 ] ; real_T B_1_15_0 [ 16 ] ; real_T B_1_16_0 [ 16 ] ;
real_T B_1_17_0 [ 16 ] ; real_T B_1_18_0 [ 16 ] ; real_T B_1_19_0 ; real_T
B_1_20_0 ; real_T B_1_0_0_b ; real_T B_1_1_0_n [ 2 ] ; real_T B_1_2_0 [ 16 ]
; real_T B_1_3_0_b [ 16 ] ; real_T B_1_4_0 [ 2 ] ; real_T B_1_5_0_l [ 16 ] ;
real_T B_0_0_0 ; real_T B_32_165_0 [ 26 ] ; real_T B_32_298_0 [ 3 ] ; uint8_T
B_32_65_0_h ; uint8_T B_32_67_0 ; uint8_T B_32_70_0 ; uint8_T B_32_72_0 ;
int8_T B_32_49_0 ; int8_T B_32_50_0_b ; int8_T B_32_51_0 ; int8_T B_32_52_0_d
; int8_T B_32_54_0_e ; int8_T B_32_55_0_b ; int8_T B_32_56_0 ; int8_T
B_32_57_0 ; int8_T B_32_59_0 ; int8_T B_32_60_0_j ; int8_T B_32_61_0 ; int8_T
B_32_62_0_f ; boolean_T B_32_11_0 ; boolean_T B_32_12_0 ; boolean_T
B_32_13_0_a ; boolean_T B_32_17_0_j ; boolean_T B_32_18_0_j ; boolean_T
B_32_19_0_o ; boolean_T B_32_22_0_n ; boolean_T B_32_23_0 ; boolean_T
B_32_25_0 ; boolean_T B_32_41_0_i ; boolean_T B_32_42_0 ; boolean_T
B_32_43_0_o ; boolean_T B_32_44_0 ; boolean_T B_26_38_0 ; char_T
pad_B_26_38_0 [ 2 ] ; } B_graduation_project_prototype_collect_T ; typedef
struct { real_T Integrator_DSTATE ; real_T Integrator_DSTATE_f ; real_T
Integrator_DSTATE_p ; real_T UnitDelay_DSTATE [ 3 ] ; real_T
UnitDelay_DSTATE_l ; real_T UnitDelay_DSTATE_f ; real_T Memory_PreviousInput
; real_T Memory_PreviousInput_e ; real_T Memory_PreviousInput_d ; real_T
Memory_PreviousInput_m ; real_T Memory_PreviousInput_k ; real_T
Memory_PreviousInput_kj ; real_T Memory_PreviousInput_o ; real_T
Memory_PreviousInput_p ; real_T Memory_PreviousInput_j ; real_T
Memory_PreviousInput_f ; real_T Sum1_DWORK1 ; real_T inversion_DWORK1 [ 16 ]
; real_T inversion_DWORK3 [ 16 ] ; real_T inversion_DWORK4 [ 16 ] ; real_T
StateSpace_RWORK [ 2 ] ; struct { real_T modelTStart ; } TransportDelay_RWORK
; struct { real_T modelTStart ; } TransportDelay_RWORK_k ; struct { real_T
modelTStart ; } TransportDelay_RWORK_p ; struct { real_T modelTStart ; }
TransportDelay_RWORK_n ; struct { real_T modelTStart ; }
TransportDelay_RWORK_i ; struct { real_T modelTStart ; }
TransportDelay_RWORK_c ; struct { real_T modelTStart ; }
TransportDelay_RWORK_h ; struct { real_T modelTStart ; }
TransportDelay_RWORK_j ; struct { real_T modelTStart ; }
TransportDelay_RWORK_f ; struct { real_T modelTStart ; }
TransportDelay_RWORK_m ; void * StateSpace_PWORK [ 22 ] ; void * Scope_PWORK
; void * Scope1_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_p ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_l ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_a ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_h ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_ln ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_g ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_d ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_l5 ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_n ; struct { void * FilePtr ; } ToFile_PWORK ; struct {
void * FilePtr ; } ToFile1_PWORK ; void * Scope_PWORK_e ; void *
Scope1_PWORK_i ; void * Scope2_PWORK ; void * Scope3_PWORK ; void *
Scope4_PWORK ; void * Scope5_PWORK [ 2 ] ; void * Scope6_PWORK ; void *
Scope7_PWORK ; void * Scope8_PWORK ; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Demux_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Demux_at_outport_1_PWORK ; struct {
void * AQHandles ; }
TAQSigLogging_InsertedFor_dq0toAlphaBetaZero_at_outport_0_PWORK ; void *
Scope2_PWORK_m ; int32_T Subsystem1_sysIdxToRun ; int32_T
Subsystempi2delay_sysIdxToRun ; int32_T Subsystem1_sysIdxToRun_p ; int32_T
Subsystempi2delay_sysIdxToRun_i ; int32_T SVModulatorPattern2_sysIdxToRun ;
int32_T SVModulatorPattern1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch1Inport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch3Inport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch1Inport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_j ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_k ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_i ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_o ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_i3 ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_jq ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d4 ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_ie ; int32_T
sinthrcosthr1_sysIdxToRun ; int32_T sinthrcosthr_sysIdxToRun ; int32_T
sinbetacosbetasinthcosth_sysIdxToRun ; int32_T
Synchronousreferenceframe_sysIdxToRun ; int32_T
Stationaryreferenceframe_sysIdxToRun ; int32_T
Rotorreferenceframe_sysIdxToRun ; int32_T
Synchronousreferenceframe_sysIdxToRun_k ; int32_T
Stationaryreferenceframe_sysIdxToRun_a ; int32_T
Rotorreferenceframe_sysIdxToRun_a ; int32_T Saturation_sysIdxToRun ; int32_T
inversion_DWORK2 [ 4 ] ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_it ; uint32_T m_bpIndex ; uint32_T
m_bpIndex_m ; uint32_T m_bpIndex_i ; uint32_T m_bpIndex_mz ; uint32_T
m_bpIndex_e ; uint32_T m_bpIndex_c ; uint32_T m_bpIndex_eq ; uint32_T
DirectLookUpTablenD_NumIssuedWarnings ; uint32_T m_bpIndex_o ; int_T
StateSpace_IWORK [ 23 ] ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK ; struct
{ int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_j ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_m ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_jk ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_a ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_p ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_h ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_jc ; struct { int_T Tail ; int_T Head
; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_d ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_l ;
struct { int_T Count ; int_T Decimation ; } ToFile_IWORK ; struct { int_T
Count ; int_T Decimation ; } ToFile1_IWORK ; char StateSpace_MODE [ 28 ] ;
int_T Step1_MODE ; int_T Step_MODE ; int_T um1_MODE ; int_T Saturation_MODE [
6 ] ; int_T Saturation_MODE_p ; int_T HitCrossing_MODE ; int_T
Saturation_MODE_i ; int8_T Subsystem1_SubsysRanBC ; int8_T
Subsystempi2delay_SubsysRanBC ; int8_T Subsystem1_SubsysRanBC_c ; int8_T
Subsystempi2delay_SubsysRanBC_e ; int8_T SVModulatorPattern2_SubsysRanBC ;
int8_T SVModulatorPattern1_SubsysRanBC ; int8_T sinthrcosthr1_SubsysRanBC ;
int8_T sinthrcosthr_SubsysRanBC ; int8_T sinbetacosbetasinthcosth_SubsysRanBC
; int8_T Synchronousreferenceframe_SubsysRanBC ; int8_T
Stationaryreferenceframe_SubsysRanBC ; int8_T Rotorreferenceframe_SubsysRanBC
; int8_T Synchronousreferenceframe_SubsysRanBC_o ; int8_T
Stationaryreferenceframe_SubsysRanBC_c ; int8_T
Rotorreferenceframe_SubsysRanBC_k ; int8_T Saturation_SubsysRanBC ; boolean_T
RelationalOperator_Mode ; boolean_T RelationalOperator2_Mode ; boolean_T
Switch1_Mode ; boolean_T RelationalOperator_Mode_o ; boolean_T
RelationalOperator1_Mode ; boolean_T RelationalOperator2_Mode_p ; boolean_T
RelationalOperator3_Mode ; boolean_T RelationalOperator4_Mode ; boolean_T
RelationalOperator5_Mode ; boolean_T Switch_Mode ; boolean_T Subsystem1_MODE
; boolean_T Subsystempi2delay_MODE ; boolean_T Subsystem1_MODE_b ; boolean_T
Subsystempi2delay_MODE_m ; boolean_T SVModulatorPattern2_MODE ; boolean_T
SVModulatorPattern1_MODE ; boolean_T sinthrcosthr1_MODE ; boolean_T
sinthrcosthr_MODE ; boolean_T sinbetacosbetasinthcosth_MODE ; boolean_T
Synchronousreferenceframe_MODE ; boolean_T Stationaryreferenceframe_MODE ;
boolean_T Rotorreferenceframe_MODE ; boolean_T
Synchronousreferenceframe_MODE_d ; boolean_T Stationaryreferenceframe_MODE_b
; boolean_T Rotorreferenceframe_MODE_d ; boolean_T Saturation_MODE_k ; char_T
pad_Saturation_MODE_k [ 2 ] ; } DW_graduation_project_prototype_collect_T ;
typedef struct { real_T Integrator_CSTATE [ 4 ] ; real_T
Rotoranglethetam_CSTATE ; real_T Rotorspeedwm_CSTATE ; real_T
integrator_CSTATE ; real_T integrator_CSTATE_n ; real_T integrator_CSTATE_g ;
real_T integrator_CSTATE_j ; real_T integrator_CSTATE_h ; real_T
integrator_CSTATE_b ; real_T integrator_CSTATE_o ; real_T integrator_CSTATE_f
; real_T integrator_CSTATE_p ; real_T integrator_CSTATE_fq ; real_T
Integrator_CSTATE_a ; real_T Integrator_CSTATE_o ; }
X_graduation_project_prototype_collect_T ; typedef struct { real_T
Integrator_CSTATE [ 4 ] ; real_T Rotoranglethetam_CSTATE ; real_T
Rotorspeedwm_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_n ;
real_T integrator_CSTATE_g ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_h ; real_T integrator_CSTATE_b ; real_T integrator_CSTATE_o
; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_p ; real_T
integrator_CSTATE_fq ; real_T Integrator_CSTATE_a ; real_T
Integrator_CSTATE_o ; } XDot_graduation_project_prototype_collect_T ; typedef
struct { boolean_T Integrator_CSTATE [ 4 ] ; boolean_T
Rotoranglethetam_CSTATE ; boolean_T Rotorspeedwm_CSTATE ; boolean_T
integrator_CSTATE ; boolean_T integrator_CSTATE_n ; boolean_T
integrator_CSTATE_g ; boolean_T integrator_CSTATE_j ; boolean_T
integrator_CSTATE_h ; boolean_T integrator_CSTATE_b ; boolean_T
integrator_CSTATE_o ; boolean_T integrator_CSTATE_f ; boolean_T
integrator_CSTATE_p ; boolean_T integrator_CSTATE_fq ; boolean_T
Integrator_CSTATE_a ; boolean_T Integrator_CSTATE_o ; }
XDis_graduation_project_prototype_collect_T ; typedef struct { real_T
Integrator_CSTATE [ 4 ] ; real_T Rotoranglethetam_CSTATE ; real_T
Rotorspeedwm_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_n ;
real_T integrator_CSTATE_g ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_h ; real_T integrator_CSTATE_b ; real_T integrator_CSTATE_o
; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_p ; real_T
integrator_CSTATE_fq ; real_T Integrator_CSTATE_a ; real_T
Integrator_CSTATE_o ; } CStateAbsTol_graduation_project_prototype_collect_T ;
typedef struct { real_T Integrator_CSTATE [ 4 ] ; real_T
Rotoranglethetam_CSTATE ; real_T Rotorspeedwm_CSTATE ; real_T
integrator_CSTATE ; real_T integrator_CSTATE_n ; real_T integrator_CSTATE_g ;
real_T integrator_CSTATE_j ; real_T integrator_CSTATE_h ; real_T
integrator_CSTATE_b ; real_T integrator_CSTATE_o ; real_T integrator_CSTATE_f
; real_T integrator_CSTATE_p ; real_T integrator_CSTATE_fq ; real_T
Integrator_CSTATE_a ; real_T Integrator_CSTATE_o ; }
CXPtMin_graduation_project_prototype_collect_T ; typedef struct { real_T
Integrator_CSTATE [ 4 ] ; real_T Rotoranglethetam_CSTATE ; real_T
Rotorspeedwm_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_n ;
real_T integrator_CSTATE_g ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_h ; real_T integrator_CSTATE_b ; real_T integrator_CSTATE_o
; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_p ; real_T
integrator_CSTATE_fq ; real_T Integrator_CSTATE_a ; real_T
Integrator_CSTATE_o ; } CXPtMax_graduation_project_prototype_collect_T ;
typedef struct { real_T StateSpace_Sf0_ZC [ 7 ] ; real_T Step1_StepTime_ZC ;
real_T Step_StepTime_ZC ; real_T um1_UprLim_ZC ; real_T um1_LwrLim_ZC ;
real_T Saturation_UprLim_ZC [ 6 ] ; real_T Saturation_LwrLim_ZC [ 6 ] ;
real_T RelationalOperator_RelopInput_ZC ; real_T
RelationalOperator2_RelopInput_ZC ; real_T Saturation_UprLim_ZC_c ; real_T
Saturation_LwrLim_ZC_p ; real_T Switch1_SwitchCond_ZC ; real_T
RelationalOperator_RelopInput_ZC_i ; real_T RelationalOperator1_RelopInput_ZC
; real_T RelationalOperator2_RelopInput_ZC_i ; real_T
RelationalOperator3_RelopInput_ZC ; real_T RelationalOperator4_RelopInput_ZC
; real_T RelationalOperator5_RelopInput_ZC ; real_T HitCrossing_Input_ZC ;
real_T HitCrossing_Output_ZC ; real_T Saturation_UprLim_ZC_e ; real_T
Saturation_LwrLim_ZC_i ; real_T Switch_SwitchCond_ZC ; }
ZCV_graduation_project_prototype_collect_T ; typedef struct { ZCSigState
StateSpace_Sf0_ZCE [ 7 ] ; ZCSigState Step1_StepTime_ZCE ; ZCSigState
Step_StepTime_ZCE ; ZCSigState um1_UprLim_ZCE ; ZCSigState um1_LwrLim_ZCE ;
ZCSigState Saturation_UprLim_ZCE [ 6 ] ; ZCSigState Saturation_LwrLim_ZCE [ 6
] ; ZCSigState RelationalOperator_RelopInput_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE ; ZCSigState Saturation_UprLim_ZCE_b ;
ZCSigState Saturation_LwrLim_ZCE_m ; ZCSigState Switch1_SwitchCond_ZCE ;
ZCSigState RelationalOperator_RelopInput_ZCE_d ; ZCSigState
RelationalOperator1_RelopInput_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE_e ; ZCSigState
RelationalOperator3_RelopInput_ZCE ; ZCSigState
RelationalOperator4_RelopInput_ZCE ; ZCSigState
RelationalOperator5_RelopInput_ZCE ; ZCSigState HitCrossing_Input_ZCE ;
ZCSigState HitCrossing_Output_ZCE ; ZCSigState Saturation_UprLim_ZCE_o ;
ZCSigState Saturation_LwrLim_ZCE_a ; ZCSigState Switch_SwitchCond_ZCE ; }
PrevZCX_graduation_project_prototype_collect_T ; typedef struct { const
real_T B_32_1_0 ; const real_T B_32_2_0 ; const real_T B_32_3_0 ; }
ConstB_graduation_project_prototype_collect_T ;
#define graduation_project_prototype_collect_rtC(S) ((ConstB_graduation_project_prototype_collect_T *) _ssGetConstBlockIO(S))
struct P_graduation_project_prototype_collect_T_ { real_T P_0 ; real_T P_1 ;
real_T P_2 ; real_T P_3 ; real_T P_4 [ 2 ] ; real_T P_5 [ 2 ] ; real_T P_6 ;
real_T P_7 ; real_T P_8 [ 2 ] ; real_T P_9 [ 16 ] ; real_T P_10 [ 16 ] ;
real_T P_11 [ 2 ] ; real_T P_12 [ 16 ] ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T
P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 [ 16 ] ; real_T P_30 ; real_T
P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 [ 2 ] ; real_T P_35 [ 16 ] ;
real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 [ 2 ] ; real_T P_40 [
16 ] ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ;
real_T P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T
P_51 ; real_T P_52 [ 6 ] ; real_T P_53 [ 6 ] ; real_T P_54 ; real_T P_55 ;
real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T
P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ;
real_T P_67 ; real_T P_68 [ 126 ] ; real_T P_69 ; real_T P_70 ; real_T P_71 ;
real_T P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T
P_77 ; real_T P_78 [ 6 ] ; real_T P_79 [ 6 ] ; real_T P_80 [ 6 ] ; real_T
P_81 [ 6 ] ; real_T P_82 [ 6 ] ; real_T P_83 [ 6 ] ; real_T P_84 [ 6 ] ;
real_T P_85 [ 6 ] ; real_T P_86 [ 6 ] ; real_T P_87 [ 6 ] ; real_T P_88 ;
real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 [ 3 ] ; real_T P_93 [ 3
] ; real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ;
real_T P_99 ; real_T P_100 [ 2 ] ; real_T P_101 [ 2 ] ; real_T P_102 [ 2 ] ;
real_T P_103 [ 2 ] ; real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T
P_107 [ 4 ] ; real_T P_108 ; real_T P_109 ; real_T P_110 ; real_T P_111 ;
real_T P_112 [ 2 ] ; real_T P_113 [ 2 ] ; real_T P_114 [ 220 ] ; real_T P_115
[ 2 ] ; real_T P_116 [ 4 ] ; real_T P_117 [ 2 ] ; real_T P_119 [ 2 ] ; real_T
P_120 [ 880 ] ; real_T P_121 [ 2 ] ; real_T P_122 [ 12 ] ; real_T P_123 [ 2 ]
; real_T P_124 [ 6 ] ; real_T P_125 [ 2 ] ; real_T P_126 [ 6 ] ; real_T P_127
[ 2 ] ; real_T P_128 [ 6 ] ; real_T P_129 [ 2 ] ; real_T P_130 ; real_T P_131
[ 2 ] ; real_T P_132 ; real_T P_133 [ 2 ] ; real_T P_134 ; real_T P_135 [ 3 ]
; real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ; real_T P_140 ;
real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ; real_T P_145 ;
real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ; real_T P_150 ;
real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T P_155 ;
real_T P_156 ; real_T P_157 ; real_T P_158 ; real_T P_159 ; real_T P_160 ;
real_T P_161 ; real_T P_162 ; real_T P_163 ; real_T P_164 ; real_T P_165 ;
real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T P_169 ; real_T P_170 ;
real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T P_174 ; real_T P_175 ;
real_T P_176 ; real_T P_177 ; real_T P_178 ; real_T P_179 ; real_T P_180 ;
real_T P_181 ; real_T P_182 ; real_T P_183 ; real_T P_184 ; real_T P_185 ;
real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T P_189 ; real_T P_190 ;
real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T P_194 ; real_T P_195 ;
real_T P_196 ; real_T P_197 ; real_T P_198 [ 2 ] ; real_T P_199 ; real_T
P_200 ; real_T P_201 [ 19 ] ; real_T P_202 [ 9 ] ; real_T P_203 ; real_T
P_204 ; real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T
P_209 ; real_T P_210 ; real_T P_211 ; real_T P_212 ; real_T P_213 ; real_T
P_214 ; real_T P_215 ; real_T P_216 ; real_T P_217 ; real_T P_218 ; real_T
P_219 ; real_T P_220 ; real_T P_221 ; real_T P_222 ; real_T P_223 ; real_T
P_224 ; real_T P_225 ; real_T P_226 ; real_T P_227 ; real_T P_228 ; real_T
P_229 ; real_T P_230 ; real_T P_231 ; real_T P_232 ; real_T P_233 ; real_T
P_234 ; real_T P_235 ; real_T P_236 ; real_T P_237 ; real_T P_238 ; real_T
P_239 ; real_T P_240 ; real_T P_241 ; real_T P_242 ; real_T P_243 ; real_T
P_244 ; real_T P_245 ; real_T P_246 ; real_T P_247 ; real_T P_248 ; real_T
P_249 ; real_T P_250 ; real_T P_251 ; real_T P_252 ; real_T P_253 ; real_T
P_254 ; real_T P_255 ; real_T P_256 ; real_T P_257 ; real_T P_258 ; real_T
P_259 [ 9 ] ; real_T P_260 ; real_T P_261 ; real_T P_262 ; real_T P_263 ;
real_T P_264 ; real_T P_265 ; real_T P_266 ; real_T P_267 ; real_T P_268 ;
real_T P_269 ; real_T P_270 ; real_T P_271 ; real_T P_272 ; real_T P_273 ;
real_T P_274 ; real_T P_275 ; real_T P_276 ; real_T P_277 ; real_T P_278 ;
real_T P_279 ; real_T P_280 ; real_T P_281 ; real_T P_282 ; real_T P_283 ;
real_T P_284 ; real_T P_285 ; real_T P_286 ; real_T P_287 ; real_T P_288 ;
real_T P_289 ; real_T P_290 ; real_T P_291 ; real_T P_292 ; real_T P_293 ;
real_T P_294 [ 16 ] ; real_T P_295 ; real_T P_296 [ 16 ] ; real_T P_297 ;
real_T P_298 ; real_T P_299 ; real_T P_300 ; real_T P_301 [ 2 ] ; real_T
P_302 ; real_T P_303 ; real_T P_304 ; real_T P_305 ; real_T P_306 ; real_T
P_307 ; real_T P_308 ; real_T P_309 ; real_T P_310 ; real_T P_311 ; real_T
P_312 ; real_T P_313 ; real_T P_314 ; real_T P_315 ; real_T P_316 ; real_T
P_317 ; real_T P_318 ; real_T P_319 ; real_T P_320 ; real_T P_321 ; real_T
P_322 ; real_T P_323 ; real_T P_324 ; real_T P_325 ; real_T P_326 ; real_T
P_327 ; real_T P_328 ; boolean_T P_329 ; boolean_T P_330 ; boolean_T P_331 ;
boolean_T P_332 ; boolean_T P_333 ; boolean_T P_334 ; boolean_T P_335 ;
boolean_T P_336 ; boolean_T P_337 ; int8_T P_338 ; int8_T P_339 ; int8_T
P_340 ; int8_T P_341 ; int8_T P_342 ; int8_T P_343 ; int8_T P_344 ; int8_T
P_345 ; int8_T P_346 ; int8_T P_347 ; int8_T P_348 ; int8_T P_349 ; uint8_T
P_350 ; char_T pad_P_350 [ 2 ] ; } ; extern
P_graduation_project_prototype_collect_T
graduation_project_prototype_collect_rtDefaultP ; extern const
ConstB_graduation_project_prototype_collect_T
graduation_project_prototype_collect_rtInvariant ;
#endif

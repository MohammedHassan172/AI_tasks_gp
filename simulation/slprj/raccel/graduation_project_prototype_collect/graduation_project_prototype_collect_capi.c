#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "graduation_project_prototype_collect_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 24
#endif
#ifndef SS_INT64
#define SS_INT64 25
#endif
#else
#include "builtin_typeid_types.h"
#include "graduation_project_prototype_collect.h"
#include "graduation_project_prototype_collect_capi.h"
#include "graduation_project_prototype_collect_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Gain" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Uniform Random Number1" ) ,
TARGET_STRING ( "input torque" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 ,
TARGET_STRING ( "graduation_project_prototype_collect/Unit Delay" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Rad->Deg." ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Product" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Product1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Rad->Deg." ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Product" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Product1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Rad->Deg." ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Product" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Product1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Rad->Deg." ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Product" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Product1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Rad->Deg." ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Product" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Product1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Id" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 24 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Gain2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Tvds1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Tvds2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/lm" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 29 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Integrator" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Divide" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 4 } , { 31 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Subtract" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Subtract1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Subtract2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Sum1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Sum2" ) , TARGET_STRING (
"Vd" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Sum3" ) , TARGET_STRING (
"Vq" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Uniform Random Number" ) ,
TARGET_STRING ( "input_speed" ) , 0 , 0 , 0 , 0 , 1 } , { 38 , 0 ,
TARGET_STRING (
"graduation_project_prototype_collect/Three-Phase V-I Measurement/Kv1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Rad->Deg." ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Product" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Rad->Deg." ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Product" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Rad->Deg." ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Product" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Rad->Deg." ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Product" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Product1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Complex to Magnitude-Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Rad->Deg." ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Product" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Product1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 59 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 60 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/unit conversion"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/1\\p"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 63 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/1_2H"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 64 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/1_Tb2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 65 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/F"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 66 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 67 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/web_psb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 68 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Rotor angle thetam"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 69 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Rotor speed (wm)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 70 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/DC Voltage Source/Model/DC" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 72 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/PWM Generator (2-Level)/Cr_MinMax/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 73 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/PWM Generator (2-Level)/Cr_MinMax/Add4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 74 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1"
) , TARGET_STRING ( "Q1 Q3 Q5" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1"
) , TARGET_STRING ( "Q2 Q4 Q6" ) , 0 , 0 , 0 , 0 , 0 } , { 76 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1"
) , TARGET_STRING ( "Q1 Q3 Q5" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1"
) , TARGET_STRING ( "Q2 Q4 Q6" ) , 0 , 0 , 0 , 0 , 0 } , { 78 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1"
) , TARGET_STRING ( "Q1 Q3 Q5" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1"
) , TARGET_STRING ( "Q2 Q4 Q6" ) , 0 , 0 , 0 , 0 , 0 } , { 80 , 28 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 81 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 82 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 83 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 84 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 85 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 86 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Logical Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 87 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 88 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 89 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 90 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 91 , 31 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 92 , 31 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 93 , 32 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 94 , 32 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 95 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 96 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Two-Level Converter/Model/Data Type Conversion1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 97 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Two-Level Converter/Model/Product4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 98 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/Two-Level Converter/Model/Saturation" )
, TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 99 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 100 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 0 } , { 101 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 102 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation"
) , TARGET_STRING ( "" ) , 1 , 0 , 7 , 0 , 0 } , { 103 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation"
) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 104 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 105 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Sum1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 7 , 0 , 0 } , { 106 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 7 , 0 , 0 } , { 107 , 0 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 7 , 0 , 0 } , { 108 , 0 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 109 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 110 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 111 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 112 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 113 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 114 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 115 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 116 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 117 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 118 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 119 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 120 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 121 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/1_Vb"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 122 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 123 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 124 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 125 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 126 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 127 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 128 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 129 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 130 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 131 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 132 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 133 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 134 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 135 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 136 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/ib"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 137 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 138 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 139 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 140 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Sum3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 141 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 142 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 143 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 144 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 145 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 1 , 0 , 7 , 0 , 0 } , { 146 , 10 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 147 , 10 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)"
) , TARGET_STRING ( "" ) , 1 , 0 , 7 , 0 , 0 } , { 148 , 11 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 149 , 11 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1"
) , TARGET_STRING ( "" ) , 1 , 0 , 7 , 0 , 0 } , { 150 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 151 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 152 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 5 } , { 153 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 154 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/Memory" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 5 } , { 155 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 156 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 157 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 158 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 159 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 160 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 5 } , { 161 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 162 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/Memory" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 5 } , { 163 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 164 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 165 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 166 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 167 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 168 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 5 } , { 169 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 170 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/Memory" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 5 } , { 171 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 172 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 173 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 174 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 175 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 176 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 177 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 178 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 179 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 180 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 181 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/integrator" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 182 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 183 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 184 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/K1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 5 } , { 185 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 186 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 187 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 188 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 189 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/integrator" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 190 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 191 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 192 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Deg->Rad"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 193 , 22 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 194 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 195 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 196 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/0<m<1 "
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 197 , 22 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 198 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 199 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 200 , 26 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 201 , 24 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 202 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 203 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Logical Operator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 204 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Logical Operator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 205 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Logical Operator2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 206 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Logical Operator3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 207 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Logical Operator4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 208 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 209 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Multiport Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 210 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Multiport Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 211 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 212 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Relational Operator2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 213 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Rounding Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 214 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 215 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 216 , 29 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 217 , 29 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 218 , 30 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 219 , 30 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 220 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 221 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 3 } , { 222 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Compare To Constant1/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 3 } , { 223 , 31 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 224 , 31 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 225 , 32 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem1/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 226 , 32 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem1/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 227 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Three-Phase V-I Measurement/Model/U AB:/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 228 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Three-Phase V-I Measurement/Model/U BC:/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 229 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Three-Phase V-I Measurement/Model/U CA:/do not delete this gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 230 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 5 } , { 231 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 232 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 233 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 234 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 235 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 236 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 237 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 238 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 5 } , { 239 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 240 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 241 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 242 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 243 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 244 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 245 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 246 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 5 } , { 247 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 248 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 249 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 250 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 251 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 252 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 253 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 254 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 255 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 256 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 257 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 258 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 259 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/integrator" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 260 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 261 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 262 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/K1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 5 } , { 263 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 264 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 265 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 266 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/K1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 267 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/integrator" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 268 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 269 , 0 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 270 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "iqs -ids" ) , 0 , 0 , 2 , 0 , 0 } , { 271 , 0 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Electromagnetic Torque/Mult1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 272 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Electromagnetic Torque/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 273 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/1-D Lookup Table"
) , TARGET_STRING ( "Isat" ) , 0 , 0 , 0 , 0 , 0 } , { 274 , 1 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Product"
) , TARGET_STRING ( "Lm" ) , 0 , 0 , 0 , 0 , 0 } , { 275 , 2 , TARGET_STRING
(
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Product1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 7 , 0 , 0 } , { 276 , 2 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/inversion"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 7 , 0 , 0 } , { 277 , 2 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Switch"
) , TARGET_STRING ( "Lm" ) , 0 , 0 , 0 , 0 , 0 } , { 278 , 0 , TARGET_STRING
(
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/wbase"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 279 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 280 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 281 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 0 } , { 282 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vdr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 283 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vds"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 284 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 285 , 3 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 286 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vdr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 287 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vds"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 288 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 289 , 4 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 290 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vdr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 291 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vds"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 292 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 293 , 5 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 294 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/ira"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 295 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/irb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 296 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/isa"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 297 , 6 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/isb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 298 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/ira"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 299 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/irb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 300 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/isa"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 301 , 7 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/isb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 302 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/ira"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 303 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/irb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 304 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/isa"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 305 , 8 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/isb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 306 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/W(3,4)=1-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 307 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/W(4,3)=wr-1"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 308 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Gain2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 309 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/web_psb"
) , TARGET_STRING ( "th" ) , 0 , 0 , 0 , 0 , 0 } , { 310 , 9 , TARGET_STRING
(
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Sum"
) , TARGET_STRING ( "we-wr" ) , 0 , 0 , 0 , 0 , 0 } , { 311 , 9 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Sum1"
) , TARGET_STRING ( "beta" ) , 0 , 0 , 0 , 0 , 0 } , { 312 , 9 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 313 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 314 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 315 , 9 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function1"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 316 , 10 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/W(1,2)=wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 317 , 10 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/W(2,1)=-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 318 , 10 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 319 , 11 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/W(3,4)=-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 320 , 11 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/W(4,3)=wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 321 , 11 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 322 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) /1//Fc"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 323 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Determine the sector of U* based on alpha (rad). Also, determine if the sector number is odd/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 324 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Logical Operator"
) , TARGET_STRING ( "Q2 Q4 Q6" ) , 0 , 0 , 1 , 0 , 0 } , { 325 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 326 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Sum"
) , TARGET_STRING ( "Page" ) , 0 , 0 , 0 , 0 , 5 } , { 327 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Sum1"
) , TARGET_STRING ( "Column" ) , 0 , 0 , 0 , 0 , 0 } , { 328 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) , TARGET_STRING ( "Q1 Q3 Q5" ) , 0 , 0 , 1 , 0 , 0 } , { 329 , 28 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 330 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 331 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 332 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 333 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 334 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 335 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Saturation/Enabled/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 336 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 3 } , { 337 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 3 } , { 338 , 29 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 339 , 29 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 340 , 30 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 341 , 30 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 342 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Laq=Lad/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 343 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/Lm in rows[1,3] & col[1,3]"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 344 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/Lm in rows[2,4] & col[2,4]"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 345 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 7 , 0 , 0 } , { 346 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 347 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 348 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 349 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 350 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 351 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 352 , 2 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/Sum1"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 0 } , { 353 , 2 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/Sum2"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 0 } , { 354 , 27 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 355 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Constant2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 356 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Constant3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 357 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Constant4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 358 , 28 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Unit Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 359 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 360 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 361 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 362 , 0 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Unit Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 6 } , { 363 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/1//4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 364 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/Sum5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 365 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/Sum6"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 366 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/Sum7"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 367 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/Sum8"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 368 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/Sum9"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 369 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Constant2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 370 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Constant4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 371 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/1\\ib2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 372 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Hit  Crossing"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 5 } , { 373 , 27 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Unit Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 374 , TARGET_STRING (
"graduation_project_prototype_collect/DC Voltage Source" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 375 , TARGET_STRING (
"graduation_project_prototype_collect/PWM Generator (2-Level)" ) ,
TARGET_STRING ( "MinMax" ) , 0 , 9 , 0 } , { 376 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)" ) ,
TARGET_STRING ( "InputType" ) , 0 , 0 , 0 } , { 377 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)" ) ,
TARGET_STRING ( "SwitchingPattern" ) , 0 , 0 , 0 } , { 378 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)" ) ,
TARGET_STRING ( "Fc" ) , 0 , 0 , 0 } , { 379 , TARGET_STRING (
"graduation_project_prototype_collect/Gain" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 380 , TARGET_STRING (
"graduation_project_prototype_collect/Step" ) , TARGET_STRING ( "Time" ) , 0
, 0 , 0 } , { 381 , TARGET_STRING (
"graduation_project_prototype_collect/Step" ) , TARGET_STRING ( "Before" ) ,
0 , 0 , 0 } , { 382 , TARGET_STRING (
"graduation_project_prototype_collect/Step" ) , TARGET_STRING ( "After" ) , 0
, 0 , 0 } , { 383 , TARGET_STRING (
"graduation_project_prototype_collect/Uniform Random Number1" ) ,
TARGET_STRING ( "Minimum" ) , 0 , 0 , 0 } , { 384 , TARGET_STRING (
"graduation_project_prototype_collect/Uniform Random Number1" ) ,
TARGET_STRING ( "Maximum" ) , 0 , 0 , 0 } , { 385 , TARGET_STRING (
"graduation_project_prototype_collect/Uniform Random Number1" ) ,
TARGET_STRING ( "Seed" ) , 0 , 0 , 0 } , { 386 , TARGET_STRING (
"graduation_project_prototype_collect/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 387 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 388 , TARGET_STRING (
"graduation_project_prototype_collect/IA/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 389 , TARGET_STRING (
"graduation_project_prototype_collect/IA/cos(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 390 , TARGET_STRING (
"graduation_project_prototype_collect/IA/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 391 , TARGET_STRING (
"graduation_project_prototype_collect/IA/cos(wt)" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 392 , TARGET_STRING (
"graduation_project_prototype_collect/IA/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 393 , TARGET_STRING (
"graduation_project_prototype_collect/IA/sin(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 394 , TARGET_STRING (
"graduation_project_prototype_collect/IA/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 395 , TARGET_STRING (
"graduation_project_prototype_collect/IA/sin(wt)" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 396 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 397 , TARGET_STRING (
"graduation_project_prototype_collect/IB/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 398 , TARGET_STRING (
"graduation_project_prototype_collect/IB/cos(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 399 , TARGET_STRING (
"graduation_project_prototype_collect/IB/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 400 , TARGET_STRING (
"graduation_project_prototype_collect/IB/cos(wt)" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 401 , TARGET_STRING (
"graduation_project_prototype_collect/IB/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 402 , TARGET_STRING (
"graduation_project_prototype_collect/IB/sin(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 403 , TARGET_STRING (
"graduation_project_prototype_collect/IB/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 404 , TARGET_STRING (
"graduation_project_prototype_collect/IB/sin(wt)" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 405 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 406 , TARGET_STRING (
"graduation_project_prototype_collect/IC/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 407 , TARGET_STRING (
"graduation_project_prototype_collect/IC/cos(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 408 , TARGET_STRING (
"graduation_project_prototype_collect/IC/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 409 , TARGET_STRING (
"graduation_project_prototype_collect/IC/cos(wt)" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 410 , TARGET_STRING (
"graduation_project_prototype_collect/IC/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 411 , TARGET_STRING (
"graduation_project_prototype_collect/IC/sin(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 412 , TARGET_STRING (
"graduation_project_prototype_collect/IC/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 413 , TARGET_STRING (
"graduation_project_prototype_collect/IC/sin(wt)" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 414 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 415 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 416 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/cos(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 417 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 418 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 419 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 420 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/sin(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 421 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 422 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 423 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 424 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 425 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/cos(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 426 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 427 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 428 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 429 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/sin(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 430 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 431 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 432 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller" ) ,
TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 433 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 434 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 435 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 436 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 437 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller1" ) ,
TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 438 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller1" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 439 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller1" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 440 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller1" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 441 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller1" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 442 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller2" ) ,
TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 443 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller2" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 444 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller2" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 445 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller2" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 446 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/PID Controller2" ) ,
TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 447 ,
TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero" ) ,
TARGET_STRING ( "Alignment" ) , 0 , 0 , 0 } , { 448 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Id" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 449 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 450 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 451 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Rr" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 452 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Tvds1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 453 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Tvds2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 454 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/lm" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 455 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Integrator" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 456 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Step1" ) , TARGET_STRING (
"Time" ) , 0 , 0 , 0 } , { 457 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Step1" ) , TARGET_STRING (
"Before" ) , 0 , 0 , 0 } , { 458 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Step1" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 459 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Uniform Random Number" ) ,
TARGET_STRING ( "Minimum" ) , 0 , 0 , 0 } , { 460 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Uniform Random Number" ) ,
TARGET_STRING ( "Maximum" ) , 0 , 0 , 0 } , { 461 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/Uniform Random Number" ) ,
TARGET_STRING ( "Seed" ) , 0 , 0 , 0 } , { 462 , TARGET_STRING (
"graduation_project_prototype_collect/Three-Phase V-I Measurement/Kv1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 463 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 464 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 465 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/cos(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 466 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 467 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 468 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 469 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/sin(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 470 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 471 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 472 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 473 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 474 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/cos(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 475 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 476 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 477 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 478 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/sin(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 479 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 480 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 481 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 482 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 483 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/cos(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 484 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 485 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 486 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 487 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/sin(wt)" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 488 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 489 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 490 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 491 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 492 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/cos(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 493 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 494 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 495 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 496 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/sin(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 497 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 498 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 499 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Rad->Deg." ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 500 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/cos(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 501 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/cos(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 502 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/cos(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 503 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/cos(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 504 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/sin(wt)" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 505 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/sin(wt)" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 506 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/sin(wt)" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 507 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/sin(wt)" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 508 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs"
) , TARGET_STRING ( "Gain" ) , 0 , 9 , 0 } , { 509 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs1"
) , TARGET_STRING ( "Gain" ) , 0 , 9 , 0 } , { 510 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/unit conversion"
) , TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 511 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/1\\p"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 512 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/1_2H"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 513 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/1_Tb2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 514 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/F"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 515 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 516 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/web_psb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 517 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Rotor angle thetam"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 518 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Mechanical model/Rotor speed (wm)"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 519 ,
TARGET_STRING (
"graduation_project_prototype_collect/PWM Generator (2-Level)/Cr_MinMax/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 520 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 521 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 522 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 523 , TARGET_STRING (
"graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 524 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 525 , TARGET_STRING (
"graduation_project_prototype_collect/Subsystem/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 10 , 0 } , { 526 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0"
) , TARGET_STRING ( "Alignment" ) , 0 , 0 , 0 } , { 527 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 528 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Compare To Constant1"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 529 , TARGET_STRING (
 "graduation_project_prototype_collect/Two-Level Converter/Model/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 530 , TARGET_STRING (
"graduation_project_prototype_collect/Two-Level Converter/Model/Saturation" )
, TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 531 , TARGET_STRING (
"graduation_project_prototype_collect/Two-Level Converter/Model/Saturation" )
, TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 532 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P1" ) , 0 , 11 , 0 } , { 533 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P2" ) , 0 , 12 , 0 } , { 534 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P4" ) , 0 , 13 , 0 } , { 535 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P5" ) , 0 , 14 , 0 } , { 536 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P6" ) , 0 , 15 , 0 } , { 537 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P7" ) , 0 , 4 , 0 } , { 538 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P8" ) , 0 , 15 , 0 } , { 539 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P9" ) , 0 , 0 , 0 } , { 540 , TARGET_STRING (
"graduation_project_prototype_collect/powergui/EquivalentModel1/State-Space"
) , TARGET_STRING ( "P10" ) , 0 , 0 , 0 } , { 541 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 542 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 543 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 544 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 545 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 546 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 547 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Lm_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 548 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 549 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 550 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 551 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 552 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 553 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 554 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 555 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 556 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/1_Vb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 557 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 558 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 559 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 560 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 561 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 562 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/ib"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 563 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 564 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 565 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 566 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant3"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 567 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 568 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 569 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 570 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 571 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/Memory" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 572 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 573 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 574 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 575 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 576 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 577 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 578 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/Transport Delay" )
, TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 579 , TARGET_STRING (
"graduation_project_prototype_collect/IA/Mean value1/Model/Transport Delay" )
, TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 580 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 581 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 582 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 583 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/Memory" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 584 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 585 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 586 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 587 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 588 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 589 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 590 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/Transport Delay" )
, TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 591 , TARGET_STRING (
"graduation_project_prototype_collect/IB/Mean value1/Model/Transport Delay" )
, TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 592 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 593 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 594 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 595 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/Memory" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 596 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 597 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 598 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 599 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 600 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 601 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 602 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/Transport Delay" )
, TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 603 , TARGET_STRING (
"graduation_project_prototype_collect/IC/Mean value1/Model/Transport Delay" )
, TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 604 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 605 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 606 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 607 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 608 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 609 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 610 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 611 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 612 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 613 , TARGET_STRING
( "graduation_project_prototype_collect/I_alpha/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 614 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 615 , TARGET_STRING (
"graduation_project_prototype_collect/I_alpha/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 616 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/K1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 617 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 618 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 619 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 620 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 621 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 622 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 623 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 624 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 625 , TARGET_STRING
( "graduation_project_prototype_collect/I_beta/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 626 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 627 , TARGET_STRING (
"graduation_project_prototype_collect/I_beta/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 628 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 629 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 630 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 631 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Freq2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 632 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Deg->Rad"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 633 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/0<m<1 "
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 634 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/0<m<1 "
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 635 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Pulses"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 636 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Pulses"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 637 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 638 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 639 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 640 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Look-Up Table  Determine the sector of U* based on alpha (rad). "
) , TARGET_STRING ( "Table" ) , 0 , 15 , 0 } , { 641 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Look-Up Table  Determine the sector of U* based on alpha (rad). "
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 15 , 0 } , { 642 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 643 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Saturation"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 644 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 645 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 646 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 647 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 10 , 0 } , { 648 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay/alpha_beta"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 9 , 0 } , { 649 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/dq0 to Alpha-Beta-Zero/Subsystem1/alpha_beta"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 9 , 0 } , { 650 , TARGET_STRING (
 "graduation_project_prototype_collect/Three-Phase V-I Measurement/Model/U AB:/do not delete this gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 651 , TARGET_STRING (
 "graduation_project_prototype_collect/Three-Phase V-I Measurement/Model/U BC:/do not delete this gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 652 , TARGET_STRING (
 "graduation_project_prototype_collect/Three-Phase V-I Measurement/Model/U CA:/do not delete this gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 653 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 654 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/Gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 655 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 656 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 657 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 658 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 659 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 660 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 661 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 662 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 663 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 664 , TARGET_STRING (
"graduation_project_prototype_collect/VAB/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 665 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 666 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/Gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 667 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 668 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 669 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 670 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 671 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 672 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 673 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 674 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 675 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 676 , TARGET_STRING (
"graduation_project_prototype_collect/VAC/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 677 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 678 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/Gain" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 679 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 680 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 681 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 682 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 683 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 684 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 685 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 686 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 687 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 688 , TARGET_STRING (
"graduation_project_prototype_collect/VCA/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 689 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 690 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 691 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 692 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 693 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 694 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 695 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 696 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 697 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 698 , TARGET_STRING
( "graduation_project_prototype_collect/V_aplha/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 699 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 700 , TARGET_STRING (
"graduation_project_prototype_collect/V_aplha/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 701 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/K1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 702 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 703 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 704 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 705 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 706 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean/Model/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 707 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/K1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 708 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 709 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 710 , TARGET_STRING
( "graduation_project_prototype_collect/V_beta/Mean value1/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 711 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "DelayTime" ) , 0 , 0 , 0 } , { 712 , TARGET_STRING (
"graduation_project_prototype_collect/V_beta/Mean value1/Model/Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 713 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "Gain" ) , 0 , 9 , 0 } , { 714 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 715 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/R*Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 716 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Lm"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 717 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 718 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/u1"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 719 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 720 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 9 , 0 } , { 721 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/wbase"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 722 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 8 , 0 } , { 723 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqr,vdr"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 724 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqs,vds"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 725 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqr,vdr"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 726 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqs,vds"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 727 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqr,vdr"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 728 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqs,vds"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 729 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/transit/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 730 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/ira,irb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 731 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/isa,isb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 732 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/ira,irb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 733 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/isa,isb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 734 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/ira,irb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 735 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/isa,isb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 736 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/sin(beta),cos(beta), sin(th),cos(th)"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 737 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/W"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 738 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/u3"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 739 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/we"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 740 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 741 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/web_psb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 742 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/sin(thr),cos(thr)"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 743 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/W"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 744 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 745 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/u1"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 746 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 747 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/sin(thr),cos(thr)"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 748 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/W"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 749 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 750 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/u4"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 751 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 752 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) /Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 753 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) /Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 754 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) /Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 755 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) /Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 756 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) /Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 757 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Determine the sector of U* based on alpha (rad). Also, determine if the sector number is odd/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 758 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Determine the sector of U* based on alpha (rad). Also, determine if the sector number is odd/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 15 , 0 } , { 759 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Determine the sector of U* based on alpha (rad). Also, determine if the sector number is odd/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 15 , 0 } , { 760 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 761 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 762 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 763 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Saturation"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 764 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) , TARGET_STRING ( "Table" ) , 0 , 16 , 0 } , { 765 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) , TARGET_STRING ( "DiagnosticForOutOfRangeInput" ) , 2 , 0 , 0 } , { 766 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 15 , 0 } , { 767 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 15 , 0 } , { 768 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table1"
) , TARGET_STRING ( "Table" ) , 0 , 15 , 0 } , { 769 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table1"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 15 , 0 } , { 770 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table2"
) , TARGET_STRING ( "Table" ) , 0 , 15 , 0 } , { 771 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table2"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 15 , 0 } , { 772 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table3"
) , TARGET_STRING ( "Table" ) , 0 , 15 , 0 } , { 773 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table/1-D Lookup Table3"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 15 , 0 } , { 774 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 775 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 776 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 777 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 778 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 779 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 780 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 781 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 782 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 783 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 784 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 785 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 786 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 787 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller1/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 788 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Clamping_zero"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 789 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 790 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 791 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant2"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 792 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant3"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 793 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Anti-windup/Disc. Clamping Parallel/Constant4"
) , TARGET_STRING ( "Value" ) , 3 , 0 , 0 } , { 794 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/PID Controller2/Integrator/Discrete/Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 795 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/dq"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 9 , 0 } , { 796 , TARGET_STRING (
 "graduation_project_prototype_collect/Subsystem/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1/dq"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 9 , 0 } , { 797 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Laq=Lad/u2"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 798 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/u1"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 799 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/u5"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 800 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 801 , TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 802 ,
TARGET_STRING (
 "graduation_project_prototype_collect/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/u1"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 803 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Constant7"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 804 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 805 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 806 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 807 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/1\\ib1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 808 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 17 , 0 } , { 809 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 17 , 0 } , { 810 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 811 ,
TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 812 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 813 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 814 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/1\\ib1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 815 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 17 , 0 } , { 816 , TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 17 , 0 } , { 817 ,
TARGET_STRING (
 "graduation_project_prototype_collect/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 818 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/  1//2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 819 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/ 1//2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 820 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/ 1//2 "
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 821 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem/1//4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 822 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 823 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 824 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/1\\ib2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 825 , TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Hit  Crossing"
) , TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 826 ,
TARGET_STRING (
 "graduation_project_prototype_collect/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ;
static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] =
{ { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . oos02mulbx , & rtB . fhvflvwza1 ,
& rtB . keuka0tnsj [ 0 ] , & rtB . cvwhe0o4l5 , & rtB . nuslqv1hu3 , & rtB .
noaevnvad5 , & rtB . jamzcwmmle , & rtB . lwgehlowol , & rtB . eottc0nam0 , &
rtB . np1alqdz3a , & rtB . oitq0dyyxq , & rtB . iuj5gmvi4z , & rtB .
kq3a25vp1t , & rtB . h0jnp5f2jt , & rtB . i2logf3b0u , & rtB . cerlaaotg0 , &
rtB . catlonbcbi , & rtB . ceokmgrhue , & rtB . a0ej4izxmc , & rtB .
oedc1fdrfk , & rtB . ihat2vhadn , & rtB . cz5sft0noc , & rtB . g3vgstm4g3 , &
rtB . chi5cvjtrg , & rtB . ajo05qm4im [ 0 ] , & rtB . lcbaxswo3g , & rtB .
o2afpo1bhs , & rtB . i1xraoyix0 , & rtB . c1fvynnlgz , & rtB . iwb53udxj5 , &
rtB . f2ugkkglxw , & rtB . eeupqxoz5b , & rtB . hg1vb33xgp , & rtB .
plbonf3utg , & rtB . j4fgww4j5y , & rtB . be1pucxfq1 , & rtB . ppupegzif3 , &
rtB . h02nughqqj , & rtB . bxla0ijbnx [ 0 ] , & rtB . fkcxmmbe1m , & rtB .
nfg250xpij , & rtB . fi4qdoampk , & rtB . doqjlf042m , & rtB . ft0ojvmr3d , &
rtB . jtybpuhqxe , & rtB . os2nnlp2pp , & rtB . df0cmfia1b , & rtB .
aielcdsx3w , & rtB . jnri2xzqr1 , & rtB . a4dnylvh3l , & rtB . iyg2tqjmdz , &
rtB . onk2xfeqbq , & rtB . ekqf4q1gna , & rtB . d1pbnqivxe , & rtB .
izhprxpjsm , & rtB . ne44lffdfq , & rtB . fqpkborrky , & rtB . oxh2yi0xax , &
rtB . ezgqz4jw0k , & rtB . bkjh3cqkl2 [ 0 ] , & rtB . gmjkz1ru3e [ 0 ] , &
rtB . kximrirdrr [ 0 ] , & rtB . kjuzzavjpl , & rtB . gix1mhi00r , & rtB .
nqpue0vrt0 , & rtB . hexyp2merm , & rtB . lrjennhdrg [ 0 ] , & rtB .
jgoahoiiwq , & rtB . mmzyuzpya5 , & rtB . bh5r34wuaf , & rtB . cesjksggsq , &
rtB . l3ac5c0agd , & rtB . pfyk5opzbk , & rtB . frvvone4ou , & rtB .
jvh3y2egpp [ 0 ] , & rtB . mfd5oml2yu [ 0 ] , ( & rtB . jvh3y2egpp [ 0 ] + 1
) , ( & rtB . mfd5oml2yu [ 0 ] + 1 ) , ( & rtB . jvh3y2egpp [ 0 ] + 2 ) , ( &
rtB . mfd5oml2yu [ 0 ] + 2 ) , & rtB . daadcvq5ip , & rtB . hj3pppg4ca , &
rtB . o3ucuznyew , & rtB . d5jm5jif10 , & rtB . oayglxn5na , & rtB .
ne01ep3k2r , & rtB . cutsqo2kl1 , & rtB . cljjziqnd4 [ 0 ] , & rtB .
ps552cz0bj , & rtB . mc3efl4ere [ 0 ] , & rtB . kslnozwwn1 [ 0 ] , & rtB .
ixb5i1gxbi , & rtB . pdzungbvef , & rtB . cesnq2edok , & rtB . lhh0icro53 , &
rtB . gezi3je1ax [ 0 ] , & rtB . nbdtcwkcia , & rtB . lqblxwjpsf [ 0 ] , &
rtB . bavsokmria [ 0 ] , & rtB . ixygus4gig [ 0 ] , & rtB . d4mrz35apo [ 0 ]
, & rtB . gsiib3kxqi [ 0 ] , & rtB . j43pra0fjc [ 0 ] , & rtB . c5t4qjdezn ,
& rtB . oou541cdqq [ 0 ] , & rtB . jbjxf4fbvv [ 0 ] , & rtB . e01tql3zqc [ 0
] , & rtB . pn00oodbzx [ 0 ] , & rtB . f34xubnxxx , & rtB . fbtrroc4tc , &
rtB . epnsrer0xl , & rtB . j05g4trf2p , & rtB . h5yhxbn4px , & rtB .
cykvppzmth , & rtB . pga5vgtdul , & rtB . ksughnfgxc , & rtB . jqstbgs3lg , &
rtB . o35ndtztd5 , & rtB . hcisopw4hm , & rtB . h2x44eodmu , & rtB .
g1znqce5i5 , & rtB . lplpxpfnwl [ 0 ] , & rtB . ibgue2cpyy [ 0 ] , & rtB .
dz1tf2zjkk [ 0 ] , & rtB . iszvqzgoks , & rtB . igw1banhll , & rtB .
b40g41vhmi , & rtB . gstors223z , & rtB . h4ii1v3x2l , & rtB . hhv3om52d4 , &
rtB . hq1hjdyctc , & rtB . hr21gsmfog , & rtB . jbmdw2obhh , & rtB .
m5tmssdiaa , & rtB . kdz3ok45hn , & rtB . jbrkgvertf , & rtB . ijcgfhotzs [ 0
] , & rtB . ll1hepiqdn [ 0 ] , & rtB . lbvb3aac5c [ 0 ] , & rtB . a1bn0vlzu1
, & rtB . cug10ebvvj , & rtB . ibo3pkvy5m , & rtB . fvrzvsctu4 , & rtB .
lwve3sazoa , & rtB . kofpvmyce4 , & rtB . fgelopovmv [ 0 ] , & rtB .
lap03yb1fu [ 0 ] , & rtB . lupb5ha3ql [ 0 ] , & rtB . iqwmzgljmq [ 0 ] , &
rtB . mi0ekbk5ob [ 0 ] , & rtB . lphsusogsg [ 0 ] , & rtB . mv5do4ms5k [ 0 ]
, & rtB . iwbarhb2bk , & rtB . iuzsr2u15r , & rtB . irn5y20ak4 , & rtB .
ncggwvkkn3 , & rtB . pxgtca1lve , & rtB . lf3on5hnoi , & rtB . gqf15p1dz0 , &
rtB . b4oqwejrjm , & rtB . j5hf1yjxzh , & rtB . ht15qzeugk , & rtB .
earnmg21lv , & rtB . ph3fm2po3m , & rtB . h1zjrhs5pq , & rtB . k5ynav5c1v , &
rtB . dkviwiihcv , & rtB . c4ge52qtah , & rtB . nckd2vp2ym , & rtB .
dffy4sxqlu , & rtB . fjlaoktgvw , & rtB . pgmwnifwz3 , & rtB . aslmadskrn , &
rtB . kenqtxpydf , & rtB . a4uuznjjc2 , & rtB . niohbq3yce , & rtB .
gf0fpqrdqz , & rtB . izyhdgeynx , & rtB . cvum4m4ht1 , & rtB . hjnbkrerrl , &
rtB . huihntarbz , & rtB . jg2b2dwyto , & rtB . oaoknim5qe , & rtB .
mrqhtw4shc , & rtB . isbb5qelgc , & rtB . cnhfoscleb , & rtB . p1eir1uv2l , &
rtB . iv21gxj12o , & rtB . nuwd3levpa , & rtB . l0cxlqoy1l , & rtB .
mzaijat5sc , & rtB . az44tiyauw , & rtB . k4tiewitj2 , & rtB . avkcjx0v1l , &
rtB . bkaifibb5p , & rtB . g4gzzvmdow , & rtB . iey5kdl1ol , & rtB .
itqccb1njg , & rtB . kj0to1gwpp , & rtB . lqot4te0ia , & rtB . c1k1izbcfq , &
rtB . dfe30dxipq , & rtB . dx2akq1xtx , & rtB . it2dxs52rp , & rtB .
euxny4cm0f , & rtB . hj3pppg4ca , & rtB . d5jm5jif10 , & rtB . ne01ep3k2r , &
rtB . daadcvq5ip , & rtB . o3ucuznyew , & rtB . oayglxn5na , & rtB .
o0xe05teth , & rtB . anvn3apjgt , & rtB . dpjx2gq00q , & rtB . iqd12ao5xp , &
rtB . ct2rnibmo1 , & rtB . jigs1ibcqf , & rtB . crfhlgloss , & rtB .
f1jaub25mr , & rtB . grfglidrso , & rtB . ep5va441s2 [ 0 ] , & rtB .
h5tueg3xan , & rtB . p1kjyoe3no , & rtB . ixb5i1gxbi , & rtB . pdzungbvef , &
rtB . cesnq2edok , & rtB . lhh0icro53 , & rtB . im2qnp2pzf , & rtB .
jtcbm2s0cm , & rtB . aexbreubkh , & rtB . kq3rj1qk1x , & rtB . pw0ttdltfa , &
rtB . f10c2vxlm4 , & rtB . mm3qy5yws1 , & rtB . hprqcepoik , & rtB .
nkqijph0dz , & rtB . hvffwddyll , & rtB . dlvtusb3ds , & rtB . otpmxpc0wg , &
rtB . j3w2ppirfg , & rtB . fn55vobl5y , & rtB . ppgcpq3dna , & rtB .
e3txj5nydu , & rtB . lega1ivx25 , & rtB . bb1wxb01g1 , & rtB . cmpudvfmfg , &
rtB . m4flle1xhi , & rtB . harp5juvjj , & rtB . dkl2brqq4l , & rtB .
nc4x0kjslh , & rtB . jou3thgpuf , & rtB . o3pcbr3dln , & rtB . pbcsdqvwkh , &
rtB . b5ye5zig1f , & rtB . it5w03bouy , & rtB . mjybhqhfeo , & rtB .
czqd02arxc , & rtB . ccuzfsqrqm , & rtB . arksco3tqi , & rtB . fkv0bugyi2 , &
rtB . jt2jb5lz2j , & rtB . ptdm3aefua , & rtB . di1q4wwsjy , & rtB .
ls5tb5izhr , & rtB . mgj5ibadgb , & rtB . aafngiz0b5 , & rtB . psd5sjin1n , &
rtB . nycjraukwt , & rtB . iigfhvktts , & rtB . g04fxja0ze , & rtB .
ljisofhn3l [ 0 ] , & rtB . d4cb5huedc [ 0 ] , & rtB . f2h5smzqv0 , & rtB .
bhdtmizrl1 , & rtB . nnql2kngph , & rtB . j43pra0fjc [ 0 ] , & rtB .
gsiib3kxqi [ 0 ] , & rtB . c5t4qjdezn , & rtB . p5fuazzeck [ 0 ] , & rtB .
lvinmjfvue [ 0 ] , & rtB . e0iay3fvgj [ 0 ] , & rtB . kqyqit0nkm [ 0 ] , &
rtB . epnsrer0xl , & rtB . h5yhxbn4px , & rtB . fbtrroc4tc , & rtB .
j05g4trf2p , & rtB . pga5vgtdul , & rtB . jqstbgs3lg , & rtB . cykvppzmth , &
rtB . ksughnfgxc , & rtB . hcisopw4hm , & rtB . g1znqce5i5 , & rtB .
o35ndtztd5 , & rtB . h2x44eodmu , & rtB . iszvqzgoks , & rtB . igw1banhll , &
rtB . b40g41vhmi , & rtB . gstors223z , & rtB . h4ii1v3x2l , & rtB .
hhv3om52d4 , & rtB . hq1hjdyctc , & rtB . hr21gsmfog , & rtB . jbmdw2obhh , &
rtB . m5tmssdiaa , & rtB . kdz3ok45hn , & rtB . jbrkgvertf , & rtB .
p5qlvh0c4k [ 0 ] , & rtB . fgelopovmv [ 0 ] , & rtB . bby3homfma , & rtB .
azpq5sqbrr , & rtB . i3l5pe4ri1 , & rtB . g423dacc0p , & rtB . lwve3sazoa , &
rtB . kofpvmyce4 , & rtB . ibo3pkvy5m , & rtB . fvrzvsctu4 , & rtB .
kwvb2tc1zn [ 0 ] , & rtB . lupb5ha3ql [ 0 ] , & rtB . knm2iibxks , & rtB .
pvcnmwvky5 [ 0 ] , & rtB . mi0ekbk5ob [ 0 ] , & rtB . jgpgocp4rw , & rtB .
fk2cnu24qv [ 0 ] , & rtB . jmyxmowcn2 , & rtB . mfd5oml2yu [ 0 ] , & rtB .
hh2tjxynco , & rtB . jur3xn53mn , & rtB . mywbrwb1sh , & rtB . jvh3y2egpp [ 0
] , & rtB . arflpyz22b , & rtB . igcmbgwamd , & rtB . mbw2hxuhtx , & rtB .
ptcp5bkpa4 , & rtB . ebqopdsodw , & rtB . oucx2re132 , & rtB . lgfuqct11r , &
rtB . f031aucpiu , & rtB . ftwcud3ono , & rtB . jigs1ibcqf , & rtB .
crfhlgloss , & rtB . f1jaub25mr , & rtB . grfglidrso , & rtB . pgtvimm3it , &
rtB . bu3w4zj2id [ 0 ] , & rtB . ittgezz3ha [ 0 ] , & rtB . axtcj0djba [ 0 ]
, & rtB . eiu3o0vwjw , & rtB . apdoomhepj , & rtB . ijuzr44wbo , & rtB .
lagrdxsyvj [ 0 ] , & rtB . acqoql0tnx [ 0 ] , & rtB . l3gd1q0nba [ 0 ] , &
rtB . izag1mey0r , & rtB . gmgalikong , & rtB . o2b21cd15g , & rtB .
axajzwngcd , & rtB . e5ebrc2y0h , & rtB . ijmxijodjl , & rtB . ehh4nt3lzv , &
rtB . gg2xbhafea , & rtB . pm50du5olg , & rtB . fzzwpeohtj , & rtB .
ccuoohcoby , & rtB . pu4jkio2sc , & rtB . l0fe2bbef5 , & rtB . gqd3i5ascl , &
rtB . bj2rkj3gai , & rtB . cla100jmpw , & rtB . noq4u5d0w3 , & rtB .
ofc0eizjlw , & rtB . nnzbfrntvj , & rtB . d0buvrjicm , & rtB . jh0n0dq2us , &
rtB . hwncbff0ek , & rtP . DCVoltageSource_Amplitude , & rtP .
PWMGenerator2Level_MinMax [ 0 ] , & rtP . SVPWMGenerator2Level_InputType , &
rtP . SVPWMGenerator2Level_SwitchingPattern , & rtP . SVPWMGenerator2Level_Fc
, & rtP . Gain_Gain_cxvgc2lug0 , & rtP . Step_Time , & rtP . Step_Y0 , & rtP
. Step_YFinal , & rtP . UniformRandomNumber1_Minimum , & rtP .
UniformRandomNumber1_Maximum , & rtP . UniformRandomNumber1_Seed , & rtP .
UnitDelay_InitialCondition_pzx2rrfnsh , & rtP . RadDeg_Gain , & rtP .
coswt_Amp , & rtP . coswt_Bias , & rtP . coswt_Freq , & rtP . coswt_Phase , &
rtP . sinwt_Amp , & rtP . sinwt_Bias , & rtP . sinwt_Freq , & rtP .
sinwt_Phase , & rtP . RadDeg_Gain_pbfubgjltx , & rtP . coswt_Amp_lotbg3ady4 ,
& rtP . coswt_Bias_pkdfrvyfzo , & rtP . coswt_Freq_gy4rrmly2r , & rtP .
coswt_Phase_cks54w344c , & rtP . sinwt_Amp_kaj303prng , & rtP .
sinwt_Bias_eo2tvogysi , & rtP . sinwt_Freq_jmsdc1qfap , & rtP .
sinwt_Phase_e40hoaxtc0 , & rtP . RadDeg_Gain_lmooslmjbr , & rtP .
coswt_Amp_nzlxg1xukb , & rtP . coswt_Bias_bkkdttcimg , & rtP .
coswt_Freq_jyp404ctqb , & rtP . coswt_Phase_ixgxpt4zk5 , & rtP .
sinwt_Amp_ppjhta5ade , & rtP . sinwt_Bias_flwl1uwydj , & rtP .
sinwt_Freq_i0s1emiimc , & rtP . sinwt_Phase_faj42pj3vn , & rtP .
RadDeg_Gain_ohc4yyajzb , & rtP . coswt_Amp_fze0rt25nj , & rtP .
coswt_Bias_gotsz450pe , & rtP . coswt_Freq_dsg35iutco , & rtP .
coswt_Phase_b05d3ayxrf , & rtP . sinwt_Amp_edycohfw2n , & rtP .
sinwt_Bias_ojeuz3kiwy , & rtP . sinwt_Freq_p0h2fsybis , & rtP .
sinwt_Phase_f2jjaw3e2f , & rtP . RadDeg_Gain_f1lmapvdap , & rtP .
coswt_Amp_mbtvjxxxmt , & rtP . coswt_Bias_n2y5xckms2 , & rtP .
coswt_Freq_hjpnxaqkas , & rtP . coswt_Phase_hny4a0wyr1 , & rtP .
sinwt_Amp_jtggovxcvv , & rtP . sinwt_Bias_k03a0l4ngu , & rtP .
sinwt_Freq_mtnxy0sium , & rtP . sinwt_Phase_oxelmkkwq3 , & rtP .
PIDController_P , & rtP . PIDController_I , & rtP .
PIDController_InitialConditionForIntegrator , & rtP .
PIDController_UpperSaturationLimit , & rtP .
PIDController_LowerSaturationLimit , & rtP . PIDController1_P , & rtP .
PIDController1_I , & rtP . PIDController1_InitialConditionForIntegrator , &
rtP . PIDController1_UpperSaturationLimit , & rtP .
PIDController1_LowerSaturationLimit , & rtP . PIDController2_P , & rtP .
PIDController2_I , & rtP . PIDController2_InitialConditionForIntegrator , &
rtP . PIDController2_UpperSaturationLimit , & rtP .
PIDController2_LowerSaturationLimit , & rtP . dq0toAlphaBetaZero_Alignment ,
& rtP . Id_Value , & rtP . Gain_Gain_jm4wsubqhp , & rtP .
Gain2_Gain_k40ujjpy24 , & rtP . Rr_Gain , & rtP . Tvds1_Gain , & rtP .
Tvds2_Gain , & rtP . lm_Gain , & rtP . Integrator_IC_pgbn5sd1dy , & rtP .
Step1_Time , & rtP . Step1_Y0 , & rtP . Step1_YFinal , & rtP .
UniformRandomNumber_Minimum , & rtP . UniformRandomNumber_Maximum , & rtP .
UniformRandomNumber_Seed , & rtP . Kv1_Gain , & rtP . RadDeg_Gain_iw201mxnns
, & rtP . coswt_Amp_o1ltt5pdlh , & rtP . coswt_Bias_fzasbs01jq , & rtP .
coswt_Freq_bucy43teey , & rtP . coswt_Phase_hdytwcvkdv , & rtP .
sinwt_Amp_lejb5q1drx , & rtP . sinwt_Bias_fsysvjnpdv , & rtP .
sinwt_Freq_h2yfwpywe4 , & rtP . sinwt_Phase_b12v44pwkf , & rtP .
RadDeg_Gain_nld5rtcto2 , & rtP . coswt_Amp_cgelhat4ym , & rtP .
coswt_Bias_lbadqe1qoz , & rtP . coswt_Freq_l2gy35fupw , & rtP .
coswt_Phase_pzlkopbzti , & rtP . sinwt_Amp_hbhrn0c3l5 , & rtP .
sinwt_Bias_ngasuri14f , & rtP . sinwt_Freq_izus5nrqgj , & rtP .
sinwt_Phase_lnfnv4ci0i , & rtP . RadDeg_Gain_hxdev00ox2 , & rtP .
coswt_Amp_cbakb1lpf4 , & rtP . coswt_Bias_bs13bmejzz , & rtP .
coswt_Freq_k3ksg4tv2k , & rtP . coswt_Phase_igwni2bbwk , & rtP .
sinwt_Amp_fd1g3e1jxz , & rtP . sinwt_Bias_ekchsxspnw , & rtP .
sinwt_Freq_er04gzhbyo , & rtP . sinwt_Phase_lthjgr3htm , & rtP .
RadDeg_Gain_cudxpld3hb , & rtP . coswt_Amp_bdpzf3qm5d , & rtP .
coswt_Bias_ohxwdhvdqt , & rtP . coswt_Freq_hzptxtkujv , & rtP .
coswt_Phase_dmdizmz41l , & rtP . sinwt_Amp_bidhycowh3 , & rtP .
sinwt_Bias_ktj1onprva , & rtP . sinwt_Freq_bz3l0yj4ws , & rtP .
sinwt_Phase_j5lu4omqjx , & rtP . RadDeg_Gain_eu3zhqsrha , & rtP .
coswt_Amp_j0sfpf0zu0 , & rtP . coswt_Bias_pcausyepjz , & rtP .
coswt_Freq_jyz3mepj5h , & rtP . coswt_Phase_ce20mbimlk , & rtP .
sinwt_Amp_dj2zfovxcb , & rtP . sinwt_Bias_kdvg0mkwaw , & rtP .
sinwt_Freq_ebv0m2croj , & rtP . sinwt_Phase_kxnh30c4dj , & rtP .
GainVr_Vs_Gain [ 0 ] , & rtP . GainVr_Vs1_Gain [ 0 ] , & rtP .
unitconversion_Gain [ 0 ] , & rtP . up_Gain , & rtP . u_2H_Gain , & rtP .
u_Tb2_Gain , & rtP . F_Gain , & rtP . Gain_Gain_cxgdozlfu4 [ 0 ] , & rtP .
web_psb_Gain_btyrplnn0r , & rtP . Rotoranglethetam_IC , & rtP .
Rotorspeedwm_IC , & rtP . Gain1_Gain_njsoa1aqa3 , & rtP .
Constant_Value_m4r2isv0lu , & rtP . Constant1_Value_i0rprf1eid , & rtP .
Constant2_Value_gx2k4auir2 , & rtP . Constant3_Value_fj15ghwvge , & rtP .
Gain1_Gain_evezn5cjq0 , & rtP . Gain3_Gain_hixkjfmrfb [ 0 ] , & rtP .
AlphaBetaZerotodq0_Alignment , & rtP . CompareToConstant_const_cslc2daqzm , &
rtP . CompareToConstant1_const_fyrikjwbdg , & rtP . CompareToConstant_const ,
& rtP . Saturation_UpperSat_gv1zxpeeyy , & rtP .
Saturation_LowerSat_cylf2nmiga , & rtP . StateSpace_P1 [ 0 ] , & rtP .
StateSpace_P2 [ 0 ] , & rtP . StateSpace_P4 [ 0 ] , & rtP . StateSpace_P5 [ 0
] , & rtP . StateSpace_P6 [ 0 ] , & rtP . StateSpace_P7 [ 0 ] , & rtP .
StateSpace_P8 [ 0 ] , & rtP . StateSpace_P9 , & rtP . StateSpace_P10 , & rtP
. Constant_Value_hut4tpkugj , & rtP . Constant1_Value_alqf2d4lc5 , & rtP .
Constant2_Value_afsuawgxbn [ 0 ] , & rtP . Constant3_Value_kr2bwtxikm , & rtP
. Constant4_Value_cmnkab0z4n [ 0 ] , & rtP . Constant5_Value , & rtP .
Lm_nosat_Value , & rtP . Switch_Threshold , & rtP .
Switch1_Threshold_ljw0dhgvwc , & rtP . Switch2_Threshold , & rtP .
Constant_Value_lmhwhmdz2u , & rtP . Constant1_Value_kxhc2gs4cl , & rtP .
Constant2_Value_kloxydkm3r , & rtP . Constant3_Value_ouvvljqkp0 , & rtP .
Constant4_Value_bjg2igozv4 , & rtP . u_Vb_Gain , & rtP .
Constant_Value_ohxe4e5ozd , & rtP . Constant1_Value_lrv1fami4q , & rtP .
Constant2_Value_aynpxkeryg , & rtP . Constant3_Value_nltabvbh3t , & rtP .
Constant4_Value_mu2mphswby , & rtP . ib_Gain , & rtP .
Constant_Value_bgkx1lk1ww , & rtP . Constant1_Value_fqdgvdsuvx , & rtP .
Constant2_Value_ppglw0fzdq , & rtP . Constant3_Value_nnvdkzivgm , & rtP .
Constant4_Value_pcedlnlqne , & rtP . K1_Value_ov3o541dnz , & rtP . Gain_Gain
, & rtP . integrator_IC_pxswvytdjq , & rtP .
Memory_InitialCondition_dfom2ivv2x , & rtP . TransportDelay_Delay_iftrtv2wmm
, & rtP . TransportDelay_InitOutput_p4uagmfvhi , & rtP . K1_Value , & rtP .
Gain_Gain_ntv32ixjsb , & rtP . integrator_IC , & rtP .
Memory_InitialCondition , & rtP . TransportDelay_Delay , & rtP .
TransportDelay_InitOutput , & rtP . K1_Value_pyzcnp1pqw , & rtP .
Gain_Gain_kdjuq5oq42 , & rtP . integrator_IC_lzn3twtmfq , & rtP .
Memory_InitialCondition_b51wvn1d1u , & rtP . TransportDelay_Delay_pxdogt32xz
, & rtP . TransportDelay_InitOutput_fxl4x2td5w , & rtP . K1_Value_bxuatcgplg
, & rtP . Gain_Gain_g2icy1o3o0 , & rtP . integrator_IC_daivqm451l , & rtP .
Memory_InitialCondition_b1tbqmdmu3 , & rtP . TransportDelay_Delay_m3jer2omf0
, & rtP . TransportDelay_InitOutput_khq4eszvey , & rtP . K1_Value_db0rzpphrj
, & rtP . Gain_Gain_l54bghzo2b , & rtP . integrator_IC_l4ka2yceym , & rtP .
Memory_InitialCondition_fs1cnfterh , & rtP . TransportDelay_Delay_jzjbaa5ctl
, & rtP . TransportDelay_InitOutput_nzlobmll1z , & rtP . K1_Value_nx2o2avvt1
, & rtP . Gain_Gain_nh05nfscsi , & rtP . integrator_IC_edp35d5ha1 , & rtP .
Memory_InitialCondition_dhreheujjz , & rtP . TransportDelay_Delay_hlxb35zgen
, & rtP . TransportDelay_InitOutput_l33qxj3afz , & rtP . K1_Value_hmcgbsqevk
, & rtP . Gain_Gain_lwuakiuuwu , & rtP . integrator_IC_ko1mnjsolw , & rtP .
Memory_InitialCondition_jhgewnvceq , & rtP . TransportDelay_Delay_h14bgqkqpr
, & rtP . TransportDelay_InitOutput_gg1pjv5uee , & rtP . K1_Value_kqgpjqxtl5
, & rtP . Gain_Gain_cajgqbeys5 , & rtP . integrator_IC_id3oqyw3zs , & rtP .
Memory_InitialCondition_o5eo5ilqbn , & rtP . TransportDelay_Delay_gfzlso442t
, & rtP . TransportDelay_InitOutput_fw1555jo3i , & rtP . K1_Value_pyqikfqppy
, & rtP . Gain_Gain_prdbqwyfl2 , & rtP . integrator_IC_jdszf3kxnh , & rtP .
Memory_InitialCondition_mvhozmflc4 , & rtP . TransportDelay_Delay_aexlf55zxy
, & rtP . TransportDelay_InitOutput_n4vngowuli , & rtP . K1_Value_b4nj0ralat
, & rtP . Gain_Gain_p0mgrtime2 , & rtP . integrator_IC_nb45zgdscp , & rtP .
Memory_InitialCondition_i42hzhwjo1 , & rtP . TransportDelay_Delay_cchjdc4px3
, & rtP . TransportDelay_InitOutput_k0khfjf43s , & rtP .
Constant_Value_cfcvmx1ib5 , & rtP . Constant1_Value_mlwtrpfhot , & rtP .
Constant2_Value_bxpoo4u2no , & rtP . Freq2_Value , & rtP . DegRad_Gain , &
rtP . um1_UpperSat , & rtP . um1_LowerSat , & rtP . Pulses_Y0 , & rtP .
Pulses_Y0_e01g3l1335 , & rtP . Constant1_Value_gwx2lfu1ss , & rtP .
Constant2_Value_amq3dw2414 , & rtP . gain_Gain , & rtP .
LookUpTableDeterminethesectorofUbasedonalpharad_tableData [ 0 ] , & rtP .
LookUpTableDeterminethesectorofUbasedonalpharad_bp01Data [ 0 ] , & rtP .
Saturation_UpperSat_k1rxbymieb , & rtP . Saturation_LowerSat_mv1pu1c1rk , &
rtP . CompareToConstant_const_mvnovccirx , & rtP . CompareToConstant1_const ,
& rtP . Gain1_Gain_ijdqjn0kfn , & rtP . Gain3_Gain_m1jkoow2cm [ 0 ] , & rtP .
alpha_beta_Y0 [ 0 ] , & rtP . alpha_beta_Y0_e2bzecmzah [ 0 ] , & rtP .
donotdeletethisgain_Gain , & rtP . donotdeletethisgain_Gain_efmuktoi1o , &
rtP . donotdeletethisgain_Gain_a1h5gsmnfr , & rtP . K1_Value_c1qrkgo1fj , &
rtP . Gain_Gain_dy4nztqf1d , & rtP . integrator_IC_ncyu5pbaoa , & rtP .
Memory_InitialCondition_b42g11iz1j , & rtP . TransportDelay_Delay_pc4gepyzmt
, & rtP . TransportDelay_InitOutput_lqybx2ceon , & rtP . K1_Value_bxl5tjjpfj
, & rtP . Gain_Gain_njlxfjpdzs , & rtP . integrator_IC_ldr34cyjtu , & rtP .
Memory_InitialCondition_c2ko1vmglg , & rtP . TransportDelay_Delay_hrdpjxjsd4
, & rtP . TransportDelay_InitOutput_igffedrstf , & rtP . K1_Value_f1lpdnkhvu
, & rtP . Gain_Gain_ae2yavqvxr , & rtP . integrator_IC_l5ejhzps5h , & rtP .
Memory_InitialCondition_jf304lqcyd , & rtP . TransportDelay_Delay_ismcjoc5z4
, & rtP . TransportDelay_InitOutput_ljxb0g2t0w , & rtP . K1_Value_ivxx02dqsm
, & rtP . Gain_Gain_oeci4mtbun , & rtP . integrator_IC_hqxshbmp2i , & rtP .
Memory_InitialCondition_gojis3bbhc , & rtP . TransportDelay_Delay_girtnzjasw
, & rtP . TransportDelay_InitOutput_keykqs4qqg , & rtP . K1_Value_gliuqzqkch
, & rtP . Gain_Gain_m3ggziievm , & rtP . integrator_IC_cizf3vyqy3 , & rtP .
Memory_InitialCondition_oim4fgjrfl , & rtP . TransportDelay_Delay_c3kuhq1tmk
, & rtP . TransportDelay_InitOutput_iqikl5qisq , & rtP . K1_Value_h3cyeq05s4
, & rtP . Gain_Gain_eipj0ixpdz , & rtP . integrator_IC_im3nxf22pz , & rtP .
Memory_InitialCondition_ae1hl2beri , & rtP . TransportDelay_Delay_li0srt1jom
, & rtP . TransportDelay_InitOutput_mrt2fgbd11 , & rtP . K1_Value_fnpvaryrmh
, & rtP . Gain_Gain_nryawodyby , & rtP . integrator_IC_khrfhstbkp , & rtP .
Memory_InitialCondition_hpseoczdt5 , & rtP . TransportDelay_Delay_ibovbpaddz
, & rtP . TransportDelay_InitOutput_jvi0rc1ban , & rtP . K1_Value_cc52jr1tbm
, & rtP . Gain_Gain_m5k1emz3of , & rtP . integrator_IC_neqimkjluh , & rtP .
Memory_InitialCondition_ctgd1u34sx , & rtP . TransportDelay_Delay_hiakiljn1l
, & rtP . TransportDelay_InitOutput_jrvgibmfbn , & rtP . K1_Value_lr14e3s4vd
, & rtP . Gain_Gain_cfbswsdzpb , & rtP . integrator_IC_e55mjrbt3j , & rtP .
Memory_InitialCondition_e3wnoecesu , & rtP . TransportDelay_Delay_m5fcpiszzc
, & rtP . TransportDelay_InitOutput_n5imkxppa5 , & rtP . K1_Value_d0vsxao1ah
, & rtP . Gain_Gain_nl2p143gvq , & rtP . integrator_IC_likdocw2zb , & rtP .
Memory_InitialCondition_jio3sjealx , & rtP . TransportDelay_Delay_cojmyky0yl
, & rtP . TransportDelay_InitOutput_ok0odgcuyt , & rtP . u1_Gain [ 0 ] , &
rtP . Linv_Y0 , & rtP . RLinv_Y0 , & rtP . Lm_Y0 , & rtP . Constant1_Value ,
& rtP . u1_Value_l1ozppsjwf [ 0 ] , & rtP . uDLookupTable_tableData [ 0 ] , &
rtP . uDLookupTable_bp01Data [ 0 ] , & rtP . wbase_Gain , & rtP .
Integrator_IC_fibe0df1qk [ 0 ] , & rtP . vqrvdr_Y0 , & rtP . vqsvds_Y0 , &
rtP . vqrvdr_Y0_igenqlxbjq , & rtP . vqsvds_Y0_jyddusdce4 , & rtP .
vqrvdr_Y0_ci1nok5evm , & rtP . vqsvds_Y0_folfbhqlef , & rtP . Constant6_Value
[ 0 ] , & rtP . irairb_Y0 , & rtP . isaisb_Y0 , & rtP . irairb_Y0_aqn0f44xqv
, & rtP . isaisb_Y0_dys2dzsaka , & rtP . irairb_Y0_mhfktw5wtk , & rtP .
isaisb_Y0_bklcb1cddp , & rtP . sinbetacosbetasinthcosth_Y0 , & rtP . W_Y0 , &
rtP . u3_Value [ 0 ] , & rtP . we_Value , & rtP . Gain2_Gain , & rtP .
web_psb_Gain , & rtP . sinthrcosthr_Y0 , & rtP . W_Y0_iyd2ain4kp , & rtP .
Constant_Value [ 0 ] , & rtP . u1_Value_cmhxktmqup [ 0 ] , & rtP . Gain1_Gain
, & rtP . sinthrcosthr_Y0_max1mqskqy , & rtP . W_Y0_hsnegedwrg , & rtP .
Constant_Value_jvcgu1tp21 [ 0 ] , & rtP . u4_Value [ 0 ] , & rtP . Gain3_Gain
, & rtP . Constant_Value_b2vvpg1mtn , & rtP . Constant1_Value_hfyugvi3wh , &
rtP . Constant2_Value_nyckbncwg1 , & rtP . Constant8_Value , & rtP .
Switch1_Threshold , & rtP . Constant1_Value_etg4zkjytm , & rtP .
uDLookupTable_tableData_b0ryx234pb [ 0 ] , & rtP .
uDLookupTable_bp01Data_g1ex22b024 [ 0 ] , & rtP . Constant2_Value_ntcdbysvye
, & rtP . Constant3_Value , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . DirectLookUpTablenD_table [ 0 ] , & rtP .
DirectLookUpTablenD_DiagnosticForOutOfRangeInput , & rtP .
uDLookupTable_tableData_mhqtrk0ebo [ 0 ] , & rtP .
uDLookupTable_bp01Data_o3m2ufmxqy [ 0 ] , & rtP . uDLookupTable1_tableData [
0 ] , & rtP . uDLookupTable1_bp01Data [ 0 ] , & rtP .
uDLookupTable2_tableData [ 0 ] , & rtP . uDLookupTable2_bp01Data [ 0 ] , &
rtP . uDLookupTable3_tableData [ 0 ] , & rtP . uDLookupTable3_bp01Data [ 0 ]
, & rtP . Clamping_zero_Value , & rtP . Constant_Value_k53mpkuj3j , & rtP .
Constant1_Value_kzsvvkd5vs , & rtP . Constant2_Value_by52il1jgp , & rtP .
Constant3_Value_grljrwbpot , & rtP . Constant4_Value_b04bju3fbb , & rtP .
Integrator_gainval_ld4rkk4vwq , & rtP . Clamping_zero_Value_dfpkmwfljw , &
rtP . Constant_Value_aclrvnnu5g , & rtP . Constant1_Value_aw0ko2cv3j , & rtP
. Constant2_Value_p1rcfpbgwg , & rtP . Constant3_Value_mx5ig4v2ee , & rtP .
Constant4_Value_kgjmor5mx0 , & rtP . Integrator_gainval , & rtP .
Clamping_zero_Value_lqrk3a3k1y , & rtP . Constant_Value_kk01qmg3bh , & rtP .
Constant1_Value_fzkk0bnp3j , & rtP . Constant2_Value_ldbseppdqu , & rtP .
Constant3_Value_fjwlskc5lo , & rtP . Constant4_Value_bgnwcz5wwl , & rtP .
Integrator_gainval_hw1ypy1hgp , & rtP . dq_Y0 [ 0 ] , & rtP .
dq_Y0_beojh2gwon [ 0 ] , & rtP . u2_Value [ 0 ] , & rtP . u1_Value [ 0 ] , &
rtP . u5_Value [ 0 ] , & rtP . uTT1e6s_Gain , & rtP . Integrator_IC , & rtP .
u1_Value_ck1yzahv2t [ 0 ] , & rtP . Constant7_Value , & rtP .
Constant2_Value_gsdutk4fzo , & rtP . Constant3_Value_lq5snj5m3d , & rtP .
Constant4_Value_atiw15czaq , & rtP . uib1_Gain , & rtP .
uDLookupTable_tableData_kmohmp0ajl [ 0 ] , & rtP .
uDLookupTable_bp01Data_efxgdt3xpj [ 0 ] , & rtP .
UnitDelay_InitialCondition_oiissgtaqz , & rtP . Constant2_Value_dzk2imfsc3 ,
& rtP . Constant3_Value_mb13l0gxqo , & rtP . Constant4_Value_mv2wi233zc , &
rtP . uib1_Gain_fac4etu01m , & rtP . uDLookupTable_tableData_a4ltqu4xb4 [ 0 ]
, & rtP . uDLookupTable_bp01Data_p3xuy2fusr [ 0 ] , & rtP .
UnitDelay_InitialCondition_dttkzptqzp , & rtP . u2_Gain_ce3c4l405s , & rtP .
u2_Gain_pvrujwybik , & rtP . u2_Gain , & rtP . u4_Gain , & rtP .
Constant2_Value , & rtP . Constant4_Value , & rtP . uib2_Gain , & rtP .
HitCrossing_Offset , & rtP . UnitDelay_InitialCondition , } ; static int32_T
* rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof (
uint8_T ) , ( uint8_T ) SS_UINT8 , 0 , 0 , 0 } , { "signed char" , "int8_T" ,
0 , 0 , sizeof ( int8_T ) , ( uint8_T ) SS_INT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 20 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 22 , 2
, 0 } , { rtwCAPI_VECTOR , 24 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 26 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 28 , 2 , 0 } , { rtwCAPI_VECTOR , 30 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 32 , 3 , 0 } , { rtwCAPI_VECTOR , 35
, 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 3 , 1 , 2
, 1 , 19 , 1 , 6 , 1 , 5 , 1 , 12 , 1 , 4 , 4 , 4 , 1 , 1 , 2 , 3 , 3 , 20 ,
11 , 1 , 4 , 20 , 44 , 2 , 6 , 1 , 6 , 3 , 7 , 6 , 1 , 3 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 2.0 , 5.0E-5 , 0.0001 , 1.0 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 6 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 2 , ( uint8_T ) 0 } , { ( NULL ) , (
NULL ) , 7 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ] , ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 3 , ( uint8_T ) 0 } , { (
const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 4 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 3 ] , ( const void * ) & rtcapiStoredFloats [ 2 ] ,
( int8_T ) 4 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 374 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 453 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 3770843893U , 1198021238U , 2663944681U ,
196968331U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo *
graduation_project_prototype_collect_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void graduation_project_prototype_collect_InitializeDataMapInfo ( void ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void graduation_project_prototype_collect_host_InitializeDataMapInfo (
graduation_project_prototype_collect_host_DataMapInfo_T * dataMap , const
char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif

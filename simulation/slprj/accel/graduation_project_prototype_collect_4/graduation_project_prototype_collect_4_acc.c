#include "graduation_project_prototype_collect_4_acc.h"
#include "rtwtypes.h"
#include <string.h>
#include <emmintrin.h>
#include "mwmathutil.h"
#include "graduation_project_prototype_collect_4_acc_private.h"
#include "multiword_types.h"
#include "simstruc_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf (
int_T * bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr ,
real_T tMinusDelay , real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ;
real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) {
numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz -
1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && !
isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T * tempX = (
NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024 ; if (
newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU = (
real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if ( tempU
== ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * uBufPtr = tempU ; } else { * tailPtr =
testIdx ; } return ( true ) ; } real_T
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( real_T
tMinusDelay , real_T tStart , real_T * uBuf , int_T bufSz , int_T * lastIdx ,
int_T oldestIdx , int_T newIdx , real_T initOutput , boolean_T discrete ,
boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2
, u1 , u2 ; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && (
oldestIdx == 0 ) && ( tMinusDelay > tStart ) ) return initOutput ; if (
tMinusDelay <= tStart ) return initOutput ; if ( ( tMinusDelay <= tBuf [
oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [ oldestIdx ] ) ; } else {
int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ;
t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ;
u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout =
u2 ; } else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2
- t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; }
} if ( minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx
== newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx ==
newIdx ) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ;
if ( tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i
== newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else {
while ( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ;
} i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete
) { double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } real_T look1_pbinlxpw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ; uint32_T
found ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) { bpIdx =
0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if (
u0 < bp0 [ maxIndex ] ) { bpIdx = prevIndex [ 0U ] ; iLeft = 0U ; iRght =
maxIndex ; found = 0U ; while ( found == 0U ) { if ( u0 < bp0 [ bpIdx ] ) {
iRght = bpIdx - 1U ; bpIdx = ( ( bpIdx + iLeft ) - 1U ) >> 1U ; } else if (
u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ; } else { iLeft = bpIdx + 1U ; bpIdx
= ( ( bpIdx + iRght ) + 1U ) >> 1U ; } } frac = ( u0 - bp0 [ bpIdx ] ) / (
bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac
= ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ]
) ; } prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [ bpIdx ] ; return ( table [
bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } void
rt_invd4x4_snf ( const real_T u [ 16 ] , real_T y [ 16 ] ) { real_T x [ 16 ]
; real_T s ; real_T smax ; int32_T c ; int32_T ijA ; int32_T ix ; int32_T iy
; int32_T jA ; int32_T jBcol ; int32_T jj ; int32_T jp1j ; int32_T pipk ;
int8_T ipiv [ 4 ] ; int8_T p [ 4 ] ; int8_T p_0 ; for ( ix = 0 ; ix < 16 ; ix
++ ) { y [ ix ] = 0.0 ; x [ ix ] = u [ ix ] ; } ipiv [ 0 ] = 1 ; ipiv [ 1 ] =
2 ; ipiv [ 2 ] = 3 ; for ( pipk = 0 ; pipk < 3 ; pipk ++ ) { jBcol = pipk * 5
+ 1 ; jj = pipk * 5 ; c = 4 - pipk ; iy = 0 ; smax = muDoubleScalarAbs ( x [
jj ] ) ; for ( jA = 2 ; jA <= c ; jA ++ ) { s = muDoubleScalarAbs ( x [ (
jBcol + jA ) - 2 ] ) ; if ( s > smax ) { iy = jA - 1 ; smax = s ; } } if ( x
[ ( jBcol + iy ) - 1 ] != 0.0 ) { if ( iy != 0 ) { ipiv [ pipk ] = ( int8_T )
( ( pipk + iy ) + 1 ) ; iy = ( pipk + iy ) + 1 ; smax = x [ pipk ] ; x [ pipk
] = x [ iy - 1 ] ; x [ iy - 1 ] = smax ; smax = x [ pipk + 4 ] ; x [ pipk + 4
] = x [ iy + 3 ] ; x [ iy + 3 ] = smax ; smax = x [ pipk + 8 ] ; x [ pipk + 8
] = x [ iy + 7 ] ; x [ iy + 7 ] = smax ; smax = x [ pipk + 12 ] ; x [ pipk +
12 ] = x [ ( iy + 12 ) - 1 ] ; x [ ( iy + 12 ) - 1 ] = smax ; } iy = ( jBcol
- pipk ) - 1 ; for ( ix = jBcol + 1 ; ix <= iy + 4 ; ix ++ ) { x [ ix - 1 ]
/= x [ jj ] ; } } c = 3 - pipk ; jA = jj ; jj += 4 ; for ( jp1j = 0 ; jp1j <
c ; jp1j ++ ) { if ( x [ ( jp1j << 2 ) + jj ] != 0.0 ) { smax = - x [ ( jp1j
<< 2 ) + jj ] ; iy = jA + 6 ; ix = ( jA - pipk ) - 1 ; for ( ijA = iy ; ijA
<= ix + 9 ; ijA ++ ) { x [ ijA - 1 ] += x [ ( ( ( jBcol + ijA ) - jA ) - 5 )
- 1 ] * smax ; } } jA += 4 ; } } p [ 0 ] = 1 ; p [ 1 ] = 2 ; p [ 2 ] = 3 ; p
[ 3 ] = 4 ; if ( ipiv [ 0 ] > 1 ) { pipk = p [ ipiv [ 0 ] - 1 ] ; p [ ipiv [
0 ] - 1 ] = 1 ; p [ 0 ] = ( int8_T ) pipk ; } if ( ipiv [ 1 ] > 2 ) { pipk =
p [ ipiv [ 1 ] - 1 ] ; p [ ipiv [ 1 ] - 1 ] = p [ 1 ] ; p [ 1 ] = ( int8_T )
pipk ; } if ( ipiv [ 2 ] > 3 ) { pipk = p [ 3 ] ; p [ 3 ] = p [ 2 ] ; p [ 2 ]
= ( int8_T ) pipk ; } for ( jA = 0 ; jA < 4 ; jA ++ ) { jj = jA + 1 ; p_0 = p
[ jA ] ; y [ jA + ( ( p_0 - 1 ) << 2 ) ] = 1.0 ; for ( pipk = jj ; pipk < 5 ;
pipk ++ ) { if ( y [ ( ( ( p_0 - 1 ) << 2 ) + pipk ) - 1 ] != 0.0 ) { for (
ix = pipk + 1 ; ix < 5 ; ix ++ ) { y [ ( ix + ( ( p_0 - 1 ) << 2 ) ) - 1 ] -=
y [ ( ( ( p_0 - 1 ) << 2 ) + pipk ) - 1 ] * x [ ( ( ( pipk - 1 ) << 2 ) + ix
) - 1 ] ; } } } } for ( pipk = 0 ; pipk < 4 ; pipk ++ ) { jBcol = pipk << 2 ;
for ( jA = 3 ; jA >= 0 ; jA -- ) { jj = jA << 2 ; if ( y [ jA + jBcol ] !=
0.0 ) { y [ jA + jBcol ] /= x [ jA + jj ] ; iy = jA - 1 ; for ( ix = 0 ; ix
<= iy ; ix ++ ) { y [ ix + jBcol ] -= x [ ix + jj ] * y [ jA + jBcol ] ; } }
} } } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_33_29_0
; real_T B_33_37_0 ; real_T B_33_48_0 ; real_T B_33_56_0 ; real_T B_33_67_0 ;
real_T B_33_75_0 ; real_T B_33_86_0 ; real_T B_33_94_0 ; real_T B_33_105_0 ;
real_T B_33_113_0 ; __m128d tmp_1 ; __m128d tmp_2 ; __m128d tmp_3 ; __m128d
tmp_4 ; B_graduation_project_prototype_collect_4_T * _rtB ;
DW_graduation_project_prototype_collect_4_T * _rtDW ;
P_graduation_project_prototype_collect_4_T * _rtP ;
PrevZCX_graduation_project_prototype_collect_4_T * _rtZCE ;
X_graduation_project_prototype_collect_4_T * _rtX ; real_T rtb_B_1_2_0 [ 3 ]
; real_T B_27_8_0_idx_0 ; real_T rtb_B_1_4_0 ; real_T rtb_B_27_4_0 ; real_T
rtb_B_28_2_0 ; real_T rtb_B_28_3_0 ; real_T rtb_B_28_6_0 ; real_T
rtb_B_33_229_0 ; real_T rtb_B_33_236_0 ; real_T rtb_B_33_247_0 ; real_T
rtb_B_9_1_1 ; real_T * tmp_5 ; int32_T i ; int32_T i_0 ; int8_T tmp ; int8_T
tmp_0 ; boolean_T rtb_B_27_26_0 ; boolean_T rtb_B_27_29_0 ; boolean_T
rtb_B_27_32_0 ; boolean_T rtb_B_27_34_0 ; boolean_T rtb_B_27_36_0 ; boolean_T
rtb_B_27_37_0 ; boolean_T rtb_B_33_32_0 ; void * diag ; ZCEventType zcEvent ;
_rtDW = ( ( DW_graduation_project_prototype_collect_4_T * ) ssGetRootDWork (
S ) ) ; _rtZCE = ( ( PrevZCX_graduation_project_prototype_collect_4_T * )
_ssGetPrevZCSigState ( S ) ) ; _rtX = ( (
X_graduation_project_prototype_collect_4_T * ) ssGetContStates ( S ) ) ; _rtP
= ( ( P_graduation_project_prototype_collect_4_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_graduation_project_prototype_collect_4_T * ) _ssGetModelBlockIO
( S ) ) ; _rtB -> B_33_0_0 [ 0 ] = _rtX -> Integrator_CSTATE [ 0 ] ; _rtB ->
B_33_0_0 [ 1 ] = _rtX -> Integrator_CSTATE [ 1 ] ; _rtB -> B_33_0_0 [ 2 ] =
_rtX -> Integrator_CSTATE [ 2 ] ; _rtB -> B_33_0_0 [ 3 ] = _rtX ->
Integrator_CSTATE [ 3 ] ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( i != 0 )
&& ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_3_0_c > 0.0 ) { if ( !
_rtDW -> Saturation_MODE_k ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart (
S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( (
XDis_graduation_project_prototype_collect_4_T * ) ssGetContStateDisabled ( S
) ) -> Integrator_CSTATE_o = 0 ; _rtDW -> Saturation_MODE_k = true ; } } else
{ if ( ssGetTaskTime ( S , 1 ) == ssGetTStart ( S ) ) { ( (
XDis_graduation_project_prototype_collect_4_T * ) ssGetContStateDisabled ( S
) ) -> Integrator_CSTATE_o = 1 ; } if ( _rtDW -> Saturation_MODE_k ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( (
XDis_graduation_project_prototype_collect_4_T * ) ssGetContStateDisabled ( S
) ) -> Integrator_CSTATE_o = 1 ; _rtDW -> Saturation_MODE_k = false ; } } }
if ( _rtDW -> Saturation_MODE_k ) { _rtB -> B_1_0_0 = _rtX ->
Integrator_CSTATE_o ; _rtB -> B_1_1_0 [ 0 ] = _rtB -> B_1_1_0_n [ 0 ] ; _rtB
-> B_1_1_0 [ 1 ] = _rtB -> B_1_1_0_n [ 1 ] ; _rtB -> B_1_1_0 [ 2 ] = _rtB ->
B_1_0_0 ; _rtB -> B_1_3_0 = ( 1.0 / _rtB -> B_1_1_0 [ 0 ] + 1.0 / _rtB ->
B_1_1_0 [ 1 ] ) + 1.0 / _rtB -> B_1_1_0 [ 2 ] ; rtb_B_1_4_0 = 1.0 / _rtB ->
B_1_3_0 ; _rtB -> B_1_5_0 [ 0 ] = _rtB -> B_1_4_0 [ 0 ] * rtb_B_1_4_0 ; _rtB
-> B_1_5_0 [ 1 ] = _rtB -> B_1_4_0 [ 1 ] * rtb_B_1_4_0 ; _rtB -> B_1_6_0 [ 0
] = _rtB -> B_33_0_0 [ 0 ] * _rtB -> B_1_5_0 [ 0 ] ; _rtB -> B_1_6_0 [ 1 ] =
_rtB -> B_1_5_0 [ 1 ] * _rtB -> B_33_0_0 [ 2 ] ; _rtB -> B_1_7_0 = _rtB ->
B_1_6_0 [ 0 ] + _rtB -> B_1_6_0 [ 1 ] ; _rtB -> B_1_8_0 [ 0 ] = _rtB ->
B_1_5_0 [ 0 ] * _rtB -> B_33_0_0 [ 1 ] ; _rtB -> B_1_8_0 [ 1 ] = _rtB ->
B_1_5_0 [ 1 ] * _rtB -> B_33_0_0 [ 3 ] ; _rtB -> B_1_9_0 = _rtB -> B_1_8_0 [
0 ] + _rtB -> B_1_8_0 [ 1 ] ; rtb_B_1_4_0 = muDoubleScalarHypot ( _rtB ->
B_1_7_0 , _rtB -> B_1_9_0 ) ; _rtB -> B_1_11_0 = look1_pbinlxpw ( rtb_B_1_4_0
, _rtP -> P_5 , _rtP -> P_4 , & _rtDW -> m_bpIndex_o , 1U ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> Switch_Mode = ( _rtB -> B_1_11_0 !=
0.0 ) ; } if ( _rtDW -> Switch_Mode ) { _rtB -> B_0_0_0 = rtb_B_1_4_0 / _rtB
-> B_1_11_0 ; _rtB -> B_1_13_0 = _rtB -> B_0_0_0 ; } else { _rtB -> B_1_13_0
= _rtB -> B_1_0_0_b ; } memcpy ( & _rtB -> B_1_14_0 [ 0 ] , & _rtB -> B_1_2_0
[ 0 ] , sizeof ( real_T ) << 4U ) ; _rtB -> B_1_14_0 [ 0 ] = _rtB -> B_1_13_0
; _rtB -> B_1_14_0 [ 2 ] = _rtB -> B_1_13_0 ; _rtB -> B_1_14_0 [ 8 ] = _rtB
-> B_1_13_0 ; _rtB -> B_1_14_0 [ 10 ] = _rtB -> B_1_13_0 ; memcpy ( & _rtB ->
B_1_15_0 [ 0 ] , & _rtB -> B_1_14_0 [ 0 ] , sizeof ( real_T ) << 4U ) ; _rtB
-> B_1_15_0 [ 5 ] = _rtB -> B_1_13_0 ; _rtB -> B_1_15_0 [ 7 ] = _rtB ->
B_1_13_0 ; _rtB -> B_1_15_0 [ 13 ] = _rtB -> B_1_13_0 ; _rtB -> B_1_15_0 [ 15
] = _rtB -> B_1_13_0 ; for ( i = 0 ; i <= 14 ; i += 2 ) { tmp_3 =
_mm_loadu_pd ( & _rtB -> B_1_15_0 [ i ] ) ; tmp_4 = _mm_loadu_pd ( & _rtB ->
B_1_3_0_b [ i ] ) ; _mm_storeu_pd ( & _rtB -> B_1_16_0 [ i ] , _mm_add_pd (
tmp_3 , tmp_4 ) ) ; } rt_invd4x4_snf ( _rtB -> B_1_16_0 , _rtB -> B_1_17_0 )
; for ( i = 0 ; i < 4 ; i ++ ) { rtb_B_1_4_0 = _rtB -> B_1_17_0 [ ( i << 2 )
+ 1 ] ; rtb_B_9_1_1 = _rtB -> B_1_17_0 [ i << 2 ] ; rtb_B_27_4_0 = _rtB ->
B_1_17_0 [ ( i << 2 ) + 2 ] ; B_27_8_0_idx_0 = _rtB -> B_1_17_0 [ ( i << 2 )
+ 3 ] ; for ( i_0 = 0 ; i_0 <= 2 ; i_0 += 2 ) { tmp_3 = _mm_loadu_pd ( & _rtB
-> B_1_5_0_l [ i_0 + 4 ] ) ; tmp_4 = _mm_loadu_pd ( & _rtB -> B_1_5_0_l [ i_0
] ) ; tmp_1 = _mm_loadu_pd ( & _rtB -> B_1_5_0_l [ i_0 + 8 ] ) ; tmp_2 =
_mm_loadu_pd ( & _rtB -> B_1_5_0_l [ i_0 + 12 ] ) ; _mm_storeu_pd ( & _rtB ->
B_1_18_0 [ i_0 + ( i << 2 ) ] , _mm_add_pd ( _mm_add_pd ( _mm_add_pd (
_mm_mul_pd ( _mm_set1_pd ( rtb_B_1_4_0 ) , tmp_3 ) , _mm_mul_pd ( _mm_set1_pd
( rtb_B_9_1_1 ) , tmp_4 ) ) , _mm_mul_pd ( _mm_set1_pd ( rtb_B_27_4_0 ) ,
tmp_1 ) ) , _mm_mul_pd ( _mm_set1_pd ( B_27_8_0_idx_0 ) , tmp_2 ) ) ) ; } }
_rtB -> B_1_19_0 = _rtB -> B_1_13_0 - _rtB -> B_1_0_0 ; _rtB -> B_1_20_0 =
_rtP -> P_6 * _rtB -> B_1_19_0 ; if ( ssIsModeUpdateTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> Saturation_SubsysRanBC ) ; } } if ( _rtB -> B_33_4_0_k
>= _rtP -> P_108 ) { memcpy ( & _rtB -> B_33_2_0 [ 0 ] , & _rtB -> B_1_17_0 [
0 ] , sizeof ( real_T ) << 4U ) ; } else { memcpy ( & _rtB -> B_33_2_0 [ 0 ]
, & _rtB -> B_33_5_0_c [ 0 ] , sizeof ( real_T ) << 4U ) ; } rtb_B_1_4_0 =
_rtB -> B_33_0_0 [ 1 ] ; rtb_B_9_1_1 = _rtB -> B_33_0_0 [ 0 ] ; rtb_B_27_4_0
= _rtB -> B_33_0_0 [ 2 ] ; B_27_8_0_idx_0 = _rtB -> B_33_0_0 [ 3 ] ; for ( i
= 0 ; i <= 2 ; i += 2 ) { tmp_3 = _mm_loadu_pd ( & _rtB -> B_33_2_0 [ i + 4 ]
) ; tmp_4 = _mm_loadu_pd ( & _rtB -> B_33_2_0 [ i ] ) ; tmp_1 = _mm_loadu_pd
( & _rtB -> B_33_2_0 [ i + 8 ] ) ; tmp_2 = _mm_loadu_pd ( & _rtB -> B_33_2_0
[ i + 12 ] ) ; _mm_storeu_pd ( & _rtB -> B_33_3_0 [ i ] , _mm_add_pd (
_mm_add_pd ( _mm_add_pd ( _mm_mul_pd ( tmp_3 , _mm_set1_pd ( rtb_B_1_4_0 ) )
, _mm_mul_pd ( tmp_4 , _mm_set1_pd ( rtb_B_9_1_1 ) ) ) , _mm_mul_pd ( tmp_1 ,
_mm_set1_pd ( rtb_B_27_4_0 ) ) ) , _mm_mul_pd ( tmp_2 , _mm_set1_pd (
B_27_8_0_idx_0 ) ) ) ) ; } _rtB -> B_33_4_0 = _rtX -> Rotoranglethetam_CSTATE
; _rtB -> B_33_5_0 = _rtX -> Rotorspeedwm_CSTATE ; i = ssIsSampleHit ( S , 1
, 0 ) ; if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB ->
B_33_22_0_n ) { if ( ! _rtDW -> sinthrcosthr_MODE ) { if ( ssGetTaskTime ( S
, 1 ) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S
) ; } _rtDW -> sinthrcosthr_MODE = true ; } } else if ( _rtDW ->
sinthrcosthr_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB
-> B_9_2_0 [ 0 ] = _rtP -> P_31 ; _rtB -> B_9_2_0 [ 1 ] = _rtP -> P_31 ; _rtB
-> B_9_2_0 [ 2 ] = _rtP -> P_31 ; _rtB -> B_9_2_0 [ 3 ] = _rtP -> P_31 ; for
( i = 0 ; i < 16 ; i ++ ) { _rtB -> B_9_4_0 [ i ] = _rtP -> P_32 ; } _rtDW ->
sinthrcosthr_MODE = false ; } } if ( _rtDW -> sinthrcosthr_MODE ) { _rtB ->
B_9_0_0 = _rtP -> P_33 * _rtB -> B_33_5_0 ; muDoubleScalarSinCos ( _rtB ->
B_33_4_0 , & rtb_B_1_4_0 , & rtb_B_9_1_1 ) ; _rtB -> B_9_2_0 [ 0 ] =
rtb_B_1_4_0 ; _rtB -> B_9_2_0 [ 1 ] = rtb_B_9_1_1 ; _rtB -> B_9_2_0 [ 2 ] =
_rtB -> B_9_0_0_l [ 0 ] ; _rtB -> B_9_2_0 [ 3 ] = _rtB -> B_9_0_0_l [ 1 ] ;
memcpy ( & _rtB -> B_9_3_0 [ 0 ] , & _rtB -> B_9_1_0 [ 0 ] , sizeof ( real_T
) << 4U ) ; _rtB -> B_9_3_0 [ 4 ] = _rtB -> B_33_5_0 ; memcpy ( & _rtB ->
B_9_4_0 [ 0 ] , & _rtB -> B_9_3_0 [ 0 ] , sizeof ( real_T ) << 4U ) ; _rtB ->
B_9_4_0 [ 1 ] = _rtB -> B_9_0_0 ; if ( ssIsModeUpdateTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> sinthrcosthr_SubsysRanBC ) ; } } i = ssIsSampleHit ( S
, 1 , 0 ) ; if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB ->
B_33_23_0 ) { if ( ! _rtDW -> sinthrcosthr1_MODE ) { if ( ssGetTaskTime ( S ,
1 ) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S )
; } _rtDW -> sinthrcosthr1_MODE = true ; } } else if ( _rtDW ->
sinthrcosthr1_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
_rtB -> B_10_2_0 [ 0 ] = _rtP -> P_36 ; _rtB -> B_10_2_0 [ 1 ] = _rtP -> P_36
; _rtB -> B_10_2_0 [ 2 ] = _rtP -> P_36 ; _rtB -> B_10_2_0 [ 3 ] = _rtP ->
P_36 ; _rtDW -> sinthrcosthr1_MODE = false ; } } if ( _rtDW ->
sinthrcosthr1_MODE ) { _rtB -> B_10_0_0 = _rtP -> P_38 * _rtB -> B_33_5_0 ;
muDoubleScalarSinCos ( _rtB -> B_33_4_0 , & rtb_B_1_4_0 , & rtb_B_9_1_1 ) ;
_rtB -> B_10_2_0 [ 0 ] = rtb_B_1_4_0 ; _rtB -> B_10_2_0 [ 1 ] = rtb_B_9_1_1 ;
_rtB -> B_10_2_0 [ 2 ] = _rtB -> B_10_0_0_d [ 0 ] ; _rtB -> B_10_2_0 [ 3 ] =
_rtB -> B_10_0_0_d [ 1 ] ; memcpy ( & _rtB -> B_10_3_0 [ 0 ] , & _rtB ->
B_10_1_0 [ 0 ] , sizeof ( real_T ) << 4U ) ; _rtB -> B_10_3_0 [ 14 ] = _rtB
-> B_10_0_0 ; memcpy ( & _rtB -> B_10_4_0 [ 0 ] , & _rtB -> B_10_3_0 [ 0 ] ,
sizeof ( real_T ) << 4U ) ; _rtB -> B_10_4_0 [ 11 ] = _rtB -> B_33_5_0 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
sinthrcosthr1_SubsysRanBC ) ; } } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( i
!= 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_25_0 ) { if ( !
_rtDW -> sinbetacosbetasinthcosth_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> sinbetacosbetasinthcosth_MODE = true ; } } else if ( _rtDW ->
sinbetacosbetasinthcosth_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep
( S ) ; _rtDW -> sinbetacosbetasinthcosth_MODE = false ; } } if ( _rtDW ->
sinbetacosbetasinthcosth_MODE ) { _rtB -> B_8_1_0 = _rtB -> B_8_1_0_o - _rtB
-> B_33_5_0 ; _rtB -> B_8_2_0 = _rtP -> P_27 * _rtB -> B_8_1_0 ; _rtB ->
B_8_3_0 = _rtP -> P_28 * ssGetT ( S ) ; _rtB -> B_8_4_0 = _rtB -> B_8_3_0 -
_rtB -> B_33_4_0 ; muDoubleScalarSinCos ( _rtB -> B_8_3_0 , & _rtB -> B_8_5_0
, & _rtB -> B_8_5_1 ) ; muDoubleScalarSinCos ( _rtB -> B_8_4_0 , & _rtB ->
B_8_6_0 , & _rtB -> B_8_6_1 ) ; memcpy ( & _rtB -> B_8_7_0 [ 0 ] , & _rtB ->
B_8_0_0 [ 0 ] , sizeof ( real_T ) << 4U ) ; _rtB -> B_8_7_0 [ 14 ] = _rtB ->
B_8_1_0 ; memcpy ( & _rtB -> B_8_8_0 [ 0 ] , & _rtB -> B_8_7_0 [ 0 ] , sizeof
( real_T ) << 4U ) ; _rtB -> B_8_8_0 [ 11 ] = _rtB -> B_8_2_0 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
sinbetacosbetasinthcosth_SubsysRanBC ) ; } } switch ( ( int32_T ) _rtB ->
B_33_24_0_m ) { case 1 : _rtB -> B_33_9_0 [ 0 ] = _rtB -> B_9_2_0 [ 0 ] ;
_rtB -> B_33_9_0 [ 1 ] = _rtB -> B_9_2_0 [ 1 ] ; _rtB -> B_33_9_0 [ 2 ] =
_rtB -> B_9_2_0 [ 2 ] ; _rtB -> B_33_9_0 [ 3 ] = _rtB -> B_9_2_0 [ 3 ] ;
break ; case 2 : _rtB -> B_33_9_0 [ 0 ] = _rtB -> B_10_2_0 [ 0 ] ; _rtB ->
B_33_9_0 [ 1 ] = _rtB -> B_10_2_0 [ 1 ] ; _rtB -> B_33_9_0 [ 2 ] = _rtB ->
B_10_2_0 [ 2 ] ; _rtB -> B_33_9_0 [ 3 ] = _rtB -> B_10_2_0 [ 3 ] ; break ;
default : _rtB -> B_33_9_0 [ 0 ] = _rtB -> B_8_6_0 ; _rtB -> B_33_9_0 [ 1 ] =
_rtB -> B_8_6_1 ; _rtB -> B_33_9_0 [ 2 ] = _rtB -> B_8_5_0 ; _rtB -> B_33_9_0
[ 3 ] = _rtB -> B_8_5_1 ; break ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( (
i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_17_0_j ) { if
( ! _rtDW -> Rotorreferenceframe_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> Rotorreferenceframe_MODE = true ; } } else if ( _rtDW ->
Rotorreferenceframe_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S )
; _rtB -> B_5_0_0 = _rtP -> P_19 ; _rtB -> B_5_1_0 = _rtP -> P_19 ; _rtB ->
B_5_2_0 = _rtP -> P_20 ; _rtB -> B_5_3_0 = _rtP -> P_20 ; _rtDW ->
Rotorreferenceframe_MODE = false ; } } if ( _rtDW -> Rotorreferenceframe_MODE
) { _rtB -> B_5_0_0 = _rtB -> B_33_3_0 [ 2 ] ; _rtB -> B_5_1_0 = - (
1.7320508075688772 * _rtB -> B_33_3_0 [ 3 ] + _rtB -> B_33_3_0 [ 2 ] ) / 2.0
; _rtB -> B_5_2_0 = _rtB -> B_33_3_0 [ 0 ] * _rtB -> B_33_9_0 [ 1 ] + _rtB ->
B_33_9_0 [ 0 ] * _rtB -> B_33_3_0 [ 1 ] ; _rtB -> B_5_3_0 = ( (
1.7320508075688772 * _rtB -> B_33_9_0 [ 0 ] - _rtB -> B_33_9_0 [ 1 ] ) * _rtB
-> B_33_3_0 [ 0 ] + ( - 1.7320508075688772 * _rtB -> B_33_9_0 [ 1 ] - _rtB ->
B_33_9_0 [ 0 ] ) * _rtB -> B_33_3_0 [ 1 ] ) / 2.0 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Rotorreferenceframe_SubsysRanBC ) ; } } i = ssIsSampleHit ( S , 1 , 0 ) ; if
( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_18_0_j ) {
if ( ! _rtDW -> Stationaryreferenceframe_MODE ) { if ( ssGetTaskTime ( S , 1
) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
} _rtDW -> Stationaryreferenceframe_MODE = true ; } } else if ( _rtDW ->
Stationaryreferenceframe_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep
( S ) ; _rtB -> B_6_0_0 = _rtP -> P_21 ; _rtB -> B_6_1_0 = _rtP -> P_21 ;
_rtB -> B_6_2_0 = _rtP -> P_22 ; _rtB -> B_6_3_0 = _rtP -> P_22 ; _rtDW ->
Stationaryreferenceframe_MODE = false ; } } if ( _rtDW ->
Stationaryreferenceframe_MODE ) { _rtB -> B_6_0_0 = _rtB -> B_33_9_0 [ 1 ] *
_rtB -> B_33_3_0 [ 2 ] - _rtB -> B_33_9_0 [ 0 ] * _rtB -> B_33_3_0 [ 3 ] ;
_rtB -> B_6_1_0 = ( ( - _rtB -> B_33_9_0 [ 1 ] - 1.7320508075688772 * _rtB ->
B_33_9_0 [ 0 ] ) * _rtB -> B_33_3_0 [ 2 ] + ( _rtB -> B_33_9_0 [ 0 ] -
1.7320508075688772 * _rtB -> B_33_9_0 [ 1 ] ) * _rtB -> B_33_3_0 [ 3 ] ) /
2.0 ; _rtB -> B_6_2_0 = _rtB -> B_33_3_0 [ 0 ] ; _rtB -> B_6_3_0 = - (
1.7320508075688772 * _rtB -> B_33_3_0 [ 1 ] + _rtB -> B_33_3_0 [ 0 ] ) / 2.0
; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Stationaryreferenceframe_SubsysRanBC ) ; } } i = ssIsSampleHit ( S , 1 , 0 )
; if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB ->
B_33_19_0_o ) { if ( ! _rtDW -> Synchronousreferenceframe_MODE ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Synchronousreferenceframe_MODE = true ; } } else if ( _rtDW ->
Synchronousreferenceframe_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep
( S ) ; _rtB -> B_7_0_0 = _rtP -> P_23 ; _rtB -> B_7_1_0 = _rtP -> P_23 ;
_rtB -> B_7_2_0 = _rtP -> P_24 ; _rtB -> B_7_3_0 = _rtP -> P_24 ; _rtDW ->
Synchronousreferenceframe_MODE = false ; } } if ( _rtDW ->
Synchronousreferenceframe_MODE ) { _rtB -> B_7_0_0 = _rtB -> B_33_9_0 [ 1 ] *
_rtB -> B_33_3_0 [ 2 ] + _rtB -> B_33_9_0 [ 0 ] * _rtB -> B_33_3_0 [ 3 ] ;
_rtB -> B_7_1_0 = ( ( 1.7320508075688772 * _rtB -> B_33_9_0 [ 0 ] - _rtB ->
B_33_9_0 [ 1 ] ) * _rtB -> B_33_3_0 [ 2 ] + ( - 1.7320508075688772 * _rtB ->
B_33_9_0 [ 1 ] - _rtB -> B_33_9_0 [ 0 ] ) * _rtB -> B_33_3_0 [ 3 ] ) / 2.0 ;
_rtB -> B_7_2_0 = _rtB -> B_33_3_0 [ 0 ] * _rtB -> B_33_9_0 [ 3 ] + _rtB ->
B_33_3_0 [ 1 ] * _rtB -> B_33_9_0 [ 2 ] ; _rtB -> B_7_3_0 = ( (
1.7320508075688772 * _rtB -> B_33_9_0 [ 2 ] - _rtB -> B_33_9_0 [ 3 ] ) * _rtB
-> B_33_3_0 [ 0 ] + ( - 1.7320508075688772 * _rtB -> B_33_9_0 [ 3 ] - _rtB ->
B_33_9_0 [ 2 ] ) * _rtB -> B_33_3_0 [ 1 ] ) / 2.0 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Synchronousreferenceframe_SubsysRanBC ) ; } } switch ( ( int32_T ) _rtB ->
B_33_20_0_g ) { case 1 : _rtB -> B_33_13_0 [ 0 ] = _rtB -> B_5_0_0 ; _rtB ->
B_33_13_0 [ 1 ] = _rtB -> B_5_1_0 ; break ; case 2 : _rtB -> B_33_13_0 [ 0 ]
= _rtB -> B_6_0_0 ; _rtB -> B_33_13_0 [ 1 ] = _rtB -> B_6_1_0 ; break ;
default : _rtB -> B_33_13_0 [ 0 ] = _rtB -> B_7_0_0 ; _rtB -> B_33_13_0 [ 1 ]
= _rtB -> B_7_1_0 ; break ; } switch ( ( int32_T ) _rtB -> B_33_21_0_g ) {
case 1 : _rtB -> B_33_14_0 [ 0 ] = _rtB -> B_5_2_0 ; _rtB -> B_33_14_0 [ 1 ]
= _rtB -> B_5_3_0 ; break ; case 2 : _rtB -> B_33_14_0 [ 0 ] = _rtB ->
B_6_2_0 ; _rtB -> B_33_14_0 [ 1 ] = _rtB -> B_6_3_0 ; break ; default : _rtB
-> B_33_14_0 [ 0 ] = _rtB -> B_7_2_0 ; _rtB -> B_33_14_0 [ 1 ] = _rtB ->
B_7_3_0 ; break ; } _rtB -> B_33_15_0 [ 0 ] = _rtP -> P_111 * _rtB ->
B_33_13_0 [ 0 ] ; rtb_B_1_4_0 = _rtP -> P_111 * _rtB -> B_33_14_0 [ 0 ] ;
_rtB -> B_33_15_0 [ 2 ] = rtb_B_1_4_0 ; _rtB -> B_33_16_0 [ 0 ] = _rtP ->
P_112 [ 0 ] * rtb_B_1_4_0 ; _rtB -> B_33_15_0 [ 1 ] = _rtP -> P_111 * _rtB ->
B_33_13_0 [ 1 ] ; rtb_B_1_4_0 = _rtP -> P_111 * _rtB -> B_33_14_0 [ 1 ] ;
_rtB -> B_33_15_0 [ 3 ] = rtb_B_1_4_0 ; _rtB -> B_33_16_0 [ 1 ] = _rtP ->
P_112 [ 1 ] * rtb_B_1_4_0 ; ssCallAccelRunBlock ( S , 33 , 17 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_33_18_0 [ 0 ] = _rtP -> P_133 [ 0 ] * _rtB
-> B_33_3_0 [ 0 ] ; _rtB -> B_33_18_0 [ 1 ] = _rtP -> P_133 [ 1 ] * _rtB ->
B_33_3_0 [ 1 ] ; _rtB -> B_33_19_0 [ 0 ] = _rtB -> B_33_18_0 [ 0 ] * _rtB ->
B_33_0_0 [ 1 ] ; _rtB -> B_33_19_0 [ 1 ] = _rtB -> B_33_0_0 [ 0 ] * _rtB ->
B_33_18_0 [ 1 ] ; _rtB -> B_33_20_0 = _rtB -> B_33_19_0 [ 0 ] + _rtB ->
B_33_19_0 [ 1 ] ; _rtB -> B_33_21_0 = _rtP -> P_134 * _rtB -> B_33_4_0 ; _rtB
-> B_33_22_0 [ 0 ] = _rtP -> P_135 [ 0 ] * _rtB -> B_33_5_0 ; _rtB ->
B_33_22_0 [ 1 ] = _rtP -> P_135 [ 1 ] * _rtB -> B_33_20_0 ; _rtB -> B_33_22_0
[ 2 ] = _rtP -> P_135 [ 2 ] * _rtB -> B_33_21_0 ; ssCallAccelRunBlock ( S ,
33 , 23 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_33_24_0 = _rtP -> P_136 * _rtB ->
B_33_22_0 [ 0 ] ; ssCallAccelRunBlock ( S , 33 , 25 , SS_CALL_MDL_OUTPUTS ) ;
i = ssIsSampleHit ( S , 6 , 0 ) ; if ( i != 0 ) { ssCallAccelRunBlock ( S ,
33 , 26 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 33 , 27 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_33_28_0 = _rtX -> integrator_CSTATE ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_138 ; B_33_29_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW
-> TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW
-> TransportDelay_IWORK . Head , _rtP -> P_139 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK . Head ] == ssGetT ( S ) )
) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_31_0 =
_rtP -> P_140 ; } rtb_B_33_32_0 = ( ssGetT ( S ) >= _rtB -> B_33_31_0 ) ; i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_33_0 = _rtDW ->
Memory_PreviousInput ; } if ( rtb_B_33_32_0 ) { _rtB -> B_33_35_0 = ( _rtB ->
B_33_28_0 - B_33_29_0 ) * _rtP -> P_42 ; } else { _rtB -> B_33_35_0 = _rtB ->
B_33_33_0 ; } _rtB -> B_33_36_0 = _rtX -> integrator_CSTATE_n ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_p . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_143 ; B_33_37_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_j . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_j . Last , _rtDW -> TransportDelay_IWORK_j .
Tail , _rtDW -> TransportDelay_IWORK_j . Head , _rtP -> P_144 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_j . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_j
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_39_0 = _rtP -> P_145 ; } rtb_B_33_32_0 = ( ssGetT ( S )
>= _rtB -> B_33_39_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_41_0 = _rtDW -> Memory_PreviousInput_e ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_43_0 = ( _rtB -> B_33_36_0 - B_33_37_0 ) * _rtP -> P_41 ; }
else { _rtB -> B_33_43_0 = _rtB -> B_33_41_0 ; } _rtB -> B_33_45_0 =
muDoubleScalarHypot ( _rtB -> B_33_35_0 , _rtB -> B_33_43_0 ) ; _rtB ->
B_33_46_0 = _rtP -> P_147 * muDoubleScalarAtan2 ( _rtB -> B_33_43_0 , _rtB ->
B_33_35_0 ) ; _rtB -> B_33_47_0 = _rtX -> integrator_CSTATE_g ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_l . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_149 ; B_33_48_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_m . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_m . Last , _rtDW -> TransportDelay_IWORK_m .
Tail , _rtDW -> TransportDelay_IWORK_m . Head , _rtP -> P_150 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_m . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_m
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_50_0 = _rtP -> P_151 ; } rtb_B_33_32_0 = ( ssGetT ( S )
>= _rtB -> B_33_50_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_52_0 = _rtDW -> Memory_PreviousInput_d ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_54_0 = ( _rtB -> B_33_47_0 - B_33_48_0 ) * _rtP -> P_44 ; }
else { _rtB -> B_33_54_0 = _rtB -> B_33_52_0 ; } _rtB -> B_33_55_0 = _rtX ->
integrator_CSTATE_j ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_a . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_154 ; B_33_56_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_jk . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_jk . Last , _rtDW -> TransportDelay_IWORK_jk .
Tail , _rtDW -> TransportDelay_IWORK_jk . Head , _rtP -> P_155 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_jk . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_jk . Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit
( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_58_0 = _rtP -> P_156 ; }
rtb_B_33_32_0 = ( ssGetT ( S ) >= _rtB -> B_33_58_0 ) ; i = ssIsSampleHit ( S
, 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_60_0 = _rtDW ->
Memory_PreviousInput_m ; } if ( rtb_B_33_32_0 ) { _rtB -> B_33_62_0 = ( _rtB
-> B_33_55_0 - B_33_56_0 ) * _rtP -> P_43 ; } else { _rtB -> B_33_62_0 = _rtB
-> B_33_60_0 ; } _rtB -> B_33_64_0 = muDoubleScalarHypot ( _rtB -> B_33_54_0
, _rtB -> B_33_62_0 ) ; _rtB -> B_33_65_0 = _rtP -> P_158 *
muDoubleScalarAtan2 ( _rtB -> B_33_62_0 , _rtB -> B_33_54_0 ) ; _rtB ->
B_33_66_0 = _rtX -> integrator_CSTATE_h ; { real_T * * uBuffer = ( real_T * *
) & _rtDW -> TransportDelay_PWORK_h . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_160 ; B_33_67_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_a . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_a . Last , _rtDW -> TransportDelay_IWORK_a .
Tail , _rtDW -> TransportDelay_IWORK_a . Head , _rtP -> P_161 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_a . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_a
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_69_0 = _rtP -> P_162 ; } rtb_B_33_32_0 = ( ssGetT ( S )
>= _rtB -> B_33_69_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_71_0 = _rtDW -> Memory_PreviousInput_k ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_73_0 = ( _rtB -> B_33_66_0 - B_33_67_0 ) * _rtP -> P_46 ; }
else { _rtB -> B_33_73_0 = _rtB -> B_33_71_0 ; } _rtB -> B_33_74_0 = _rtX ->
integrator_CSTATE_b ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_ln . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_165 ; B_33_75_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_p . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_p . Last , _rtDW -> TransportDelay_IWORK_p .
Tail , _rtDW -> TransportDelay_IWORK_p . Head , _rtP -> P_166 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_p . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_p
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_77_0 = _rtP -> P_167 ; } rtb_B_33_32_0 = ( ssGetT ( S )
>= _rtB -> B_33_77_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_79_0 = _rtDW -> Memory_PreviousInput_kj ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_81_0 = ( _rtB -> B_33_74_0 - B_33_75_0 ) * _rtP -> P_45 ; }
else { _rtB -> B_33_81_0 = _rtB -> B_33_79_0 ; } _rtB -> B_33_83_0 =
muDoubleScalarHypot ( _rtB -> B_33_73_0 , _rtB -> B_33_81_0 ) ; _rtB ->
B_33_84_0 = _rtP -> P_169 * muDoubleScalarAtan2 ( _rtB -> B_33_81_0 , _rtB ->
B_33_73_0 ) ; _rtB -> B_33_85_0 = _rtX -> integrator_CSTATE_o ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_171 ; B_33_86_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_h . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_h . Last , _rtDW -> TransportDelay_IWORK_h .
Tail , _rtDW -> TransportDelay_IWORK_h . Head , _rtP -> P_172 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_h . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_h
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_88_0 = _rtP -> P_173 ; } rtb_B_33_32_0 = ( ssGetT ( S )
>= _rtB -> B_33_88_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_90_0 = _rtDW -> Memory_PreviousInput_o ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_92_0 = ( _rtB -> B_33_85_0 - B_33_86_0 ) * _rtP -> P_48 ; }
else { _rtB -> B_33_92_0 = _rtB -> B_33_90_0 ; } _rtB -> B_33_93_0 = _rtX ->
integrator_CSTATE_f ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_d . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_176 ; B_33_94_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_jc . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_jc . Last , _rtDW -> TransportDelay_IWORK_jc .
Tail , _rtDW -> TransportDelay_IWORK_jc . Head , _rtP -> P_177 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_jc . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_jc . Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit
( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_96_0 = _rtP -> P_178 ; }
rtb_B_33_32_0 = ( ssGetT ( S ) >= _rtB -> B_33_96_0 ) ; i = ssIsSampleHit ( S
, 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_98_0 = _rtDW ->
Memory_PreviousInput_p ; } if ( rtb_B_33_32_0 ) { _rtB -> B_33_100_0 = ( _rtB
-> B_33_93_0 - B_33_94_0 ) * _rtP -> P_47 ; } else { _rtB -> B_33_100_0 =
_rtB -> B_33_98_0 ; } _rtB -> B_33_102_0 = muDoubleScalarHypot ( _rtB ->
B_33_92_0 , _rtB -> B_33_100_0 ) ; _rtB -> B_33_103_0 = _rtP -> P_180 *
muDoubleScalarAtan2 ( _rtB -> B_33_100_0 , _rtB -> B_33_92_0 ) ; _rtB ->
B_33_104_0 = _rtX -> integrator_CSTATE_p ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_l5 . TUbufferPtrs [ 0 ] ; real_T simTime
= ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_182 ; B_33_105_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_d . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_d . Last , _rtDW -> TransportDelay_IWORK_d .
Tail , _rtDW -> TransportDelay_IWORK_d . Head , _rtP -> P_183 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_d . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_d
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_107_0 = _rtP -> P_184 ; } rtb_B_33_32_0 = ( ssGetT ( S
) >= _rtB -> B_33_107_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_109_0 = _rtDW -> Memory_PreviousInput_j ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_111_0 = ( _rtB -> B_33_104_0 - B_33_105_0 ) * _rtP -> P_50 ; }
else { _rtB -> B_33_111_0 = _rtB -> B_33_109_0 ; } _rtB -> B_33_112_0 = _rtX
-> integrator_CSTATE_fq ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_n . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_187 ; B_33_113_0 =
graduation_project_prototype_collect_4_acc_rt_TDelayInterpolate ( tMinusDelay
, 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_l . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_l . Last , _rtDW -> TransportDelay_IWORK_l .
Tail , _rtDW -> TransportDelay_IWORK_l . Head , _rtP -> P_188 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
TransportDelay_IWORK_l . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_l
. Head ] == ssGetT ( S ) ) ) ) ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { _rtB -> B_33_115_0 = _rtP -> P_189 ; } rtb_B_33_32_0 = ( ssGetT ( S
) >= _rtB -> B_33_115_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
_rtB -> B_33_117_0 = _rtDW -> Memory_PreviousInput_f ; } if ( rtb_B_33_32_0 )
{ _rtB -> B_33_119_0 = ( _rtB -> B_33_112_0 - B_33_113_0 ) * _rtP -> P_49 ; }
else { _rtB -> B_33_119_0 = _rtB -> B_33_117_0 ; } _rtB -> B_33_121_0 =
muDoubleScalarHypot ( _rtB -> B_33_111_0 , _rtB -> B_33_119_0 ) ; _rtB ->
B_33_122_0 = _rtP -> P_191 * muDoubleScalarAtan2 ( _rtB -> B_33_119_0 , _rtB
-> B_33_111_0 ) ; rtb_B_1_4_0 = _rtP -> P_192 [ 0 ] * _rtB -> B_33_17_0 [ 0 ]
; _rtB -> B_33_124_0 [ 0 ] = rtb_B_1_4_0 ; _rtB -> B_33_125_0 [ 0 ] = _rtP ->
P_193 * _rtB -> B_33_16_0_f [ 0 ] ; _rtB -> B_33_125_0 [ 2 ] = _rtP -> P_193
* rtb_B_1_4_0 ; rtb_B_1_4_0 = _rtP -> P_192 [ 1 ] * _rtB -> B_33_17_0 [ 1 ] ;
_rtB -> B_33_124_0 [ 1 ] = rtb_B_1_4_0 ; _rtB -> B_33_125_0 [ 1 ] = _rtP ->
P_193 * _rtB -> B_33_16_0_f [ 1 ] ; _rtB -> B_33_125_0 [ 3 ] = _rtP -> P_193
* rtb_B_1_4_0 ; _rtB -> B_33_123_0 = ( 0.0 - _rtB -> B_33_13_0 [ 0 ] ) - _rtB
-> B_33_13_0 [ 1 ] ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( i != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_11_0 ) { if ( ! _rtDW ->
Rotorreferenceframe_MODE_d ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart (
S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Rotorreferenceframe_MODE_d = true ; } } else if ( _rtDW ->
Rotorreferenceframe_MODE_d ) { ssSetBlockStateForSolverChangedAtMajorStep ( S
) ; _rtB -> B_2_2_0 = _rtP -> P_13 ; _rtB -> B_2_0_0 = _rtP -> P_13 ; _rtB ->
B_2_3_0 = _rtP -> P_14 ; _rtB -> B_2_1_0 = _rtP -> P_14 ; _rtDW ->
Rotorreferenceframe_MODE_d = false ; } } if ( _rtDW ->
Rotorreferenceframe_MODE_d ) { _rtB -> B_2_0_0 = - 0.57735026918962573 * _rtB
-> B_33_125_0 [ 1 ] ; _rtB -> B_2_1_0 = ( ( _rtB -> B_33_9_0 [ 0 ] -
1.7320508075688772 * _rtB -> B_33_9_0 [ 1 ] ) * _rtB -> B_33_125_0 [ 3 ] +
2.0 * _rtB -> B_33_9_0 [ 0 ] * _rtB -> B_33_125_0 [ 2 ] ) *
0.33333333333333331 ; _rtB -> B_2_2_0 = ( 2.0 * _rtB -> B_33_125_0 [ 0 ] +
_rtB -> B_33_125_0 [ 1 ] ) * 0.33333333333333331 ; _rtB -> B_2_3_0 = ( (
1.7320508075688772 * _rtB -> B_33_9_0 [ 0 ] + _rtB -> B_33_9_0 [ 1 ] ) * _rtB
-> B_33_125_0 [ 3 ] + 2.0 * _rtB -> B_33_9_0 [ 1 ] * _rtB -> B_33_125_0 [ 2 ]
) * 0.33333333333333331 ; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC (
_rtDW -> Rotorreferenceframe_SubsysRanBC_k ) ; } } i = ssIsSampleHit ( S , 1
, 0 ) ; if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB ->
B_33_12_0 ) { if ( ! _rtDW -> Stationaryreferenceframe_MODE_b ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Stationaryreferenceframe_MODE_b = true ; } } else if ( _rtDW ->
Stationaryreferenceframe_MODE_b ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_3_2_0 = _rtP ->
P_15 ; _rtB -> B_3_0_0 = _rtP -> P_15 ; _rtB -> B_3_3_0 = _rtP -> P_16 ; _rtB
-> B_3_1_0 = _rtP -> P_16 ; _rtDW -> Stationaryreferenceframe_MODE_b = false
; } } if ( _rtDW -> Stationaryreferenceframe_MODE_b ) { _rtB -> B_3_0_0 = ( (
- _rtB -> B_33_9_0 [ 0 ] - 1.7320508075688772 * _rtB -> B_33_9_0 [ 1 ] ) *
_rtB -> B_33_125_0 [ 1 ] + - 2.0 * _rtB -> B_33_9_0 [ 0 ] * _rtB ->
B_33_125_0 [ 0 ] ) * 0.33333333333333331 ; _rtB -> B_3_1_0 = -
0.57735026918962573 * _rtB -> B_33_125_0 [ 3 ] ; _rtB -> B_3_2_0 = ( ( _rtB
-> B_33_9_0 [ 1 ] - 1.7320508075688772 * _rtB -> B_33_9_0 [ 0 ] ) * _rtB ->
B_33_125_0 [ 1 ] + 2.0 * _rtB -> B_33_9_0 [ 1 ] * _rtB -> B_33_125_0 [ 0 ] )
* 0.33333333333333331 ; _rtB -> B_3_3_0 = ( 2.0 * _rtB -> B_33_125_0 [ 2 ] +
_rtB -> B_33_125_0 [ 3 ] ) * 0.33333333333333331 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Stationaryreferenceframe_SubsysRanBC_c ) ; } } i = ssIsSampleHit ( S , 1 , 0
) ; if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB ->
B_33_13_0_a ) { if ( ! _rtDW -> Synchronousreferenceframe_MODE_d ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Synchronousreferenceframe_MODE_d = true ; } } else if ( _rtDW ->
Synchronousreferenceframe_MODE_d ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_4_2_0 = _rtP ->
P_17 ; _rtB -> B_4_0_0 = _rtP -> P_17 ; _rtB -> B_4_3_0 = _rtP -> P_18 ; _rtB
-> B_4_1_0 = _rtP -> P_18 ; _rtDW -> Synchronousreferenceframe_MODE_d = false
; } } if ( _rtDW -> Synchronousreferenceframe_MODE_d ) { _rtB -> B_4_0_0 = (
( _rtB -> B_33_9_0 [ 0 ] - 1.7320508075688772 * _rtB -> B_33_9_0 [ 1 ] ) *
_rtB -> B_33_125_0 [ 1 ] + 2.0 * _rtB -> B_33_9_0 [ 0 ] * _rtB -> B_33_125_0
[ 0 ] ) / 3.0 ; _rtB -> B_4_1_0 = ( ( _rtB -> B_33_9_0 [ 2 ] -
1.7320508075688772 * _rtB -> B_33_9_0 [ 3 ] ) * _rtB -> B_33_125_0 [ 3 ] +
2.0 * _rtB -> B_33_9_0 [ 2 ] * _rtB -> B_33_125_0 [ 2 ] ) / 3.0 ; _rtB ->
B_4_2_0 = ( ( 1.7320508075688772 * _rtB -> B_33_9_0 [ 0 ] + _rtB -> B_33_9_0
[ 1 ] ) * _rtB -> B_33_125_0 [ 1 ] + 2.0 * _rtB -> B_33_9_0 [ 1 ] * _rtB ->
B_33_125_0 [ 0 ] ) / 3.0 ; _rtB -> B_4_3_0 = ( ( 1.7320508075688772 * _rtB ->
B_33_9_0 [ 2 ] + _rtB -> B_33_9_0 [ 3 ] ) * _rtB -> B_33_125_0 [ 3 ] + 2.0 *
_rtB -> B_33_9_0 [ 3 ] * _rtB -> B_33_125_0 [ 2 ] ) / 3.0 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Synchronousreferenceframe_SubsysRanBC_o ) ; } } switch ( ( int32_T ) _rtB ->
B_33_14_0_p ) { case 1 : _rtB -> B_33_129_0 [ 0 ] = _rtB -> B_2_2_0 ; _rtB ->
B_33_129_0 [ 1 ] = _rtB -> B_2_0_0 ; break ; case 2 : _rtB -> B_33_129_0 [ 0
] = _rtB -> B_3_2_0 ; _rtB -> B_33_129_0 [ 1 ] = _rtB -> B_3_0_0 ; break ;
default : _rtB -> B_33_129_0 [ 0 ] = _rtB -> B_4_2_0 ; _rtB -> B_33_129_0 [ 1
] = _rtB -> B_4_0_0 ; break ; } _rtB -> B_33_130_0 = ( 0.0 - _rtB ->
B_33_14_0 [ 0 ] ) - _rtB -> B_33_14_0 [ 1 ] ; switch ( ( int32_T ) _rtB ->
B_33_15_0_c ) { case 1 : _rtB -> B_33_131_0 [ 0 ] = _rtB -> B_2_3_0 ; _rtB ->
B_33_131_0 [ 1 ] = _rtB -> B_2_1_0 ; break ; case 2 : _rtB -> B_33_131_0 [ 0
] = _rtB -> B_3_3_0 ; _rtB -> B_33_131_0 [ 1 ] = _rtB -> B_3_1_0 ; break ;
default : _rtB -> B_33_131_0 [ 0 ] = _rtB -> B_4_3_0 ; _rtB -> B_33_131_0 [ 1
] = _rtB -> B_4_1_0 ; break ; } if ( _rtB -> B_33_8_0 >= _rtP -> P_194 ) {
_rtB -> B_33_132_0 = _rtB -> B_1_13_0 ; } else { _rtB -> B_33_132_0 = _rtB ->
B_33_9_0_b ; } _rtB -> B_33_133_0 [ 2 ] = _rtP -> P_195 [ 2 ] * _rtB ->
B_33_123_0 ; _rtB -> B_33_133_0 [ 11 ] = _rtP -> P_195 [ 11 ] * _rtB ->
B_33_130_0 ; _rtB -> B_33_133_0 [ 0 ] = _rtP -> P_195 [ 0 ] * _rtB ->
B_33_13_0 [ 0 ] ; _rtB -> B_33_133_0 [ 3 ] = _rtB -> B_33_3_0 [ 2 ] * _rtP ->
P_195 [ 3 ] ; _rtB -> B_33_133_0 [ 5 ] = _rtB -> B_33_0_0 [ 2 ] * _rtP ->
P_195 [ 5 ] ; _rtB -> B_33_133_0 [ 7 ] = _rtB -> B_33_129_0 [ 0 ] * _rtP ->
P_195 [ 7 ] ; _rtB -> B_33_133_0 [ 9 ] = _rtB -> B_33_14_0 [ 0 ] * _rtP ->
P_195 [ 9 ] ; _rtB -> B_33_133_0 [ 12 ] = _rtB -> B_33_3_0 [ 0 ] * _rtP ->
P_195 [ 12 ] ; _rtB -> B_33_133_0 [ 14 ] = _rtB -> B_33_0_0 [ 0 ] * _rtP ->
P_195 [ 14 ] ; _rtB -> B_33_133_0 [ 16 ] = _rtB -> B_33_131_0 [ 0 ] * _rtP ->
P_195 [ 16 ] ; _rtB -> B_33_133_0 [ 1 ] = _rtP -> P_195 [ 1 ] * _rtB ->
B_33_13_0 [ 1 ] ; _rtB -> B_33_133_0 [ 4 ] = _rtB -> B_33_3_0 [ 3 ] * _rtP ->
P_195 [ 4 ] ; _rtB -> B_33_133_0 [ 6 ] = _rtB -> B_33_0_0 [ 3 ] * _rtP ->
P_195 [ 6 ] ; _rtB -> B_33_133_0 [ 8 ] = _rtB -> B_33_129_0 [ 1 ] * _rtP ->
P_195 [ 8 ] ; _rtB -> B_33_133_0 [ 10 ] = _rtB -> B_33_14_0 [ 1 ] * _rtP ->
P_195 [ 10 ] ; _rtB -> B_33_133_0 [ 13 ] = _rtB -> B_33_3_0 [ 1 ] * _rtP ->
P_195 [ 13 ] ; _rtB -> B_33_133_0 [ 15 ] = _rtB -> B_33_0_0 [ 1 ] * _rtP ->
P_195 [ 15 ] ; _rtB -> B_33_133_0 [ 17 ] = _rtB -> B_33_131_0 [ 1 ] * _rtP ->
P_195 [ 17 ] ; _rtB -> B_33_133_0 [ 18 ] = _rtP -> P_195 [ 18 ] * _rtB ->
B_33_132_0 ; rtb_B_1_4_0 = _rtB -> B_33_133_0 [ 10 ] ; rtb_B_27_4_0 = _rtB ->
B_33_133_0 [ 9 ] ; B_27_8_0_idx_0 = _rtB -> B_33_133_0 [ 11 ] ; for ( i = 0 ;
i < 3 ; i ++ ) { rtb_B_1_2_0 [ i ] = ( ( _rtP -> P_196 [ i + 3 ] *
rtb_B_1_4_0 + _rtP -> P_196 [ i ] * rtb_B_27_4_0 ) + _rtP -> P_196 [ i + 6 ]
* B_27_8_0_idx_0 ) * _rtP -> P_197 ; } _rtB -> B_33_136_0 = _rtX ->
Integrator_CSTATE_a ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( i != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_65_0_h > 0 ) { if ( !
_rtDW -> Subsystem1_MODE_b ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart (
S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Subsystem1_MODE_b = true ; } } else if ( _rtDW -> Subsystem1_MODE_b ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW -> Subsystem1_MODE_b
= false ; } } if ( _rtDW -> Subsystem1_MODE_b ) { _rtB -> B_30_0_0 =
rtb_B_1_2_0 [ 0 ] * muDoubleScalarCos ( _rtB -> B_33_136_0 ) + rtb_B_1_2_0 [
1 ] * muDoubleScalarSin ( _rtB -> B_33_136_0 ) ; _rtB -> B_30_1_0 = -
rtb_B_1_2_0 [ 0 ] * muDoubleScalarSin ( _rtB -> B_33_136_0 ) + rtb_B_1_2_0 [
1 ] * muDoubleScalarCos ( _rtB -> B_33_136_0 ) ; if ( ssIsModeUpdateTimeStep
( S ) ) { srUpdateBC ( _rtDW -> Subsystem1_SubsysRanBC_c ) ; } } i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S )
) { if ( _rtB -> B_33_67_0 > 0 ) { if ( ! _rtDW -> Subsystempi2delay_MODE_m )
{ if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Subsystempi2delay_MODE_m = true ; } } else if ( _rtDW ->
Subsystempi2delay_MODE_m ) { ssSetBlockStateForSolverChangedAtMajorStep ( S )
; _rtDW -> Subsystempi2delay_MODE_m = false ; } } if ( _rtDW ->
Subsystempi2delay_MODE_m ) { _rtB -> B_29_0_0 = rtb_B_1_2_0 [ 0 ] *
muDoubleScalarSin ( _rtB -> B_33_136_0 ) - rtb_B_1_2_0 [ 1 ] *
muDoubleScalarCos ( _rtB -> B_33_136_0 ) ; _rtB -> B_29_1_0 = rtb_B_1_2_0 [ 0
] * muDoubleScalarCos ( _rtB -> B_33_136_0 ) + rtb_B_1_2_0 [ 1 ] *
muDoubleScalarSin ( _rtB -> B_33_136_0 ) ; if ( ssIsModeUpdateTimeStep ( S )
) { srUpdateBC ( _rtDW -> Subsystempi2delay_SubsysRanBC_e ) ; } } if ( _rtB
-> B_33_65_0_h != 0 ) { _rtB -> B_33_139_0 [ 0 ] = _rtB -> B_30_0_0 ; _rtB ->
B_33_139_0 [ 1 ] = _rtB -> B_30_1_0 ; } else { _rtB -> B_33_139_0 [ 0 ] =
_rtB -> B_29_0_0 ; _rtB -> B_33_139_0 [ 1 ] = _rtB -> B_29_1_0 ; } i =
ssIsSampleHit ( S , 5 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_140_0 [ 0 ] = _rtB
-> B_33_26_0 ; _rtB -> B_33_140_0 [ 1 ] = _rtB -> B_33_27_0 ; _rtB ->
B_33_140_0 [ 2 ] = _rtB -> B_33_45_0 ; _rtB -> B_33_140_0 [ 3 ] = _rtB ->
B_33_46_0 ; _rtB -> B_33_140_0 [ 4 ] = _rtB -> B_33_64_0 ; _rtB -> B_33_140_0
[ 5 ] = _rtB -> B_33_65_0 ; _rtB -> B_33_140_0 [ 6 ] = _rtB -> B_33_83_0 ;
_rtB -> B_33_140_0 [ 7 ] = _rtB -> B_33_84_0 ; _rtB -> B_33_140_0 [ 8 ] =
_rtB -> B_33_102_0 ; _rtB -> B_33_140_0 [ 9 ] = _rtB -> B_33_103_0 ; _rtB ->
B_33_140_0 [ 10 ] = _rtB -> B_33_121_0 ; _rtB -> B_33_140_0 [ 11 ] = _rtB ->
B_33_122_0 ; _rtB -> B_33_140_0 [ 12 ] = _rtB -> B_33_139_0 [ 0 ] ; _rtB ->
B_33_140_0 [ 13 ] = _rtB -> B_33_139_0 [ 1 ] ; if ( ssGetLogOutput ( S ) ) {
{ const char * errMsg = ( NULL ) ; void * fp = ( void * ) _rtDW ->
ToFile_PWORK . FilePtr ; if ( fp != ( NULL ) ) { { real_T t ; void * u ; t =
ssGetTaskTime ( S , 5 ) ; u = ( void * ) & _rtB -> B_33_140_0 [ 0 ] ; errMsg
= rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u ) ; if ( errMsg != ( NULL
) ) { ssSetErrorStatus ( S , errMsg ) ; return ; } } } } } if (
ssGetLogOutput ( S ) ) { { const char * errMsg = ( NULL ) ; void * fp = (
void * ) _rtDW -> ToFile1_PWORK . FilePtr ; if ( fp != ( NULL ) ) { { real_T
t ; void * u ; t = ssGetTaskTime ( S , 5 ) ; u = ( void * ) & _rtB ->
B_33_22_0 [ 0 ] ; errMsg = rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u )
; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( S , errMsg ) ; return ; } }
} } } } i = ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) { _rtB -> B_33_161_0
[ 0 ] = _rtDW -> UnitDelay_DSTATE [ 0 ] ; _rtB -> B_33_161_0 [ 1 ] = _rtDW ->
UnitDelay_DSTATE [ 1 ] ; _rtB -> B_33_161_0 [ 2 ] = _rtDW -> UnitDelay_DSTATE
[ 2 ] ; } if ( _rtB -> B_33_41_0_i ) { _rtB -> B_33_163_0 = _rtB -> B_33_32_0
; } else { if ( _rtB -> B_33_42_0 ) { _rtB -> B_26_1_0 = _rtB -> B_33_161_0 [
0 ] ; } else { _rtB -> B_26_1_0 = muDoubleScalarHypot ( _rtB -> B_33_161_0 [
0 ] , _rtB -> B_33_161_0 [ 1 ] ) ; } _rtB -> B_33_163_0 = _rtB -> B_26_1_0 ;
} if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> um1_MODE = _rtB ->
B_33_163_0 >= _rtP -> P_200 ? 1 : _rtB -> B_33_163_0 > _rtP -> P_201 ? 0 : -
1 ; } _rtB -> B_33_164_0 = _rtDW -> um1_MODE == 1 ? _rtP -> P_200 : _rtDW ->
um1_MODE == - 1 ? _rtP -> P_201 : _rtB -> B_33_163_0 ; if ( _rtB ->
B_33_41_0_i ) { _rtB -> B_22_0_0 = _rtB -> B_33_31_0_p * ssGetT ( S ) * _rtB
-> B_33_40_0 ; _rtB -> B_22_1_0 = _rtB -> B_22_0_0 + _rtB -> B_33_39_0_l ;
_rtB -> B_33_168_0 = _rtB -> B_22_1_0 ; } else { if ( _rtB -> B_33_42_0 ) {
_rtB -> B_24_1_0 = _rtB -> B_33_161_0 [ 1 ] ; } else { _rtB -> B_24_1_0 =
muDoubleScalarAtan2 ( _rtB -> B_33_161_0 [ 1 ] , _rtB -> B_33_161_0 [ 0 ] ) ;
} _rtB -> B_33_168_0 = _rtB -> B_24_1_0 ; } rtb_B_1_4_0 = muDoubleScalarMod (
_rtB -> B_33_168_0 , _rtB -> B_33_37_0 ) ; i = ssIsSampleHit ( S , 1 , 0 ) ;
if ( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_43_0_o
) { if ( ! _rtDW -> SVModulatorPattern1_MODE ) { if ( ssGetTaskTime ( S , 1 )
!= ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> SVModulatorPattern1_MODE = true ; } } else if ( _rtDW ->
SVModulatorPattern1_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S )
; _rtDW -> SVModulatorPattern1_MODE = false ; } } if ( _rtDW ->
SVModulatorPattern1_MODE ) { rtb_B_9_1_1 = look1_pbinlxpw ( rtb_B_1_4_0 ,
_rtP -> P_53 , _rtP -> P_52 , & _rtDW -> m_bpIndex_eq , 5U ) ; rtb_B_9_1_1 =
muDoubleScalarFloor ( rtb_B_9_1_1 ) ; rtb_B_27_4_0 = rtb_B_1_4_0 - (
rtb_B_9_1_1 - _rtB -> B_27_2_0 ) * _rtB -> B_27_1_0 ; B_27_8_0_idx_0 =
muDoubleScalarCos ( rtb_B_27_4_0 + _rtB -> B_27_0_0 ) * _rtB -> B_33_164_0 ;
rtb_B_27_4_0 = _rtB -> B_33_164_0 * muDoubleScalarSin ( rtb_B_27_4_0 ) ; _rtB
-> B_27_11_0 [ 0 ] = _rtP -> P_54 * B_27_8_0_idx_0 ; _rtB -> B_27_11_0 [ 1 ]
= _rtP -> P_54 * rtb_B_27_4_0 ; _rtB -> B_27_11_0 [ 2 ] = ( _rtB -> B_27_3_0
- ( B_27_8_0_idx_0 + rtb_B_27_4_0 ) ) * _rtP -> P_54 ; _rtB -> B_27_12_0 =
muDoubleScalarMod ( rtb_B_9_1_1 , _rtB -> B_27_4_0 ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> Switch1_Mode = ( _rtB -> B_27_12_0
>= _rtP -> P_55 ) ; } if ( _rtDW -> Switch1_Mode ) { rtb_B_1_2_0 [ 0 ] = _rtB
-> B_27_11_0 [ 0 ] ; rtb_B_1_2_0 [ 1 ] = _rtB -> B_27_11_0 [ 1 ] ; } else {
rtb_B_1_2_0 [ 0 ] = _rtB -> B_27_11_0 [ 1 ] ; rtb_B_1_2_0 [ 1 ] = _rtB ->
B_27_11_0 [ 0 ] ; } i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB ->
B_27_15_0 = _rtP -> P_56 ; } B_27_8_0_idx_0 = ssGetT ( S ) + _rtB ->
B_27_15_0 ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB ->
B_27_17_0 = _rtP -> P_57 ; } _rtB -> B_27_19_0 = _rtP -> P_58 *
muDoubleScalarRem ( B_27_8_0_idx_0 , _rtB -> B_27_17_0 ) ; _rtB -> B_27_22_0
= ( ( 2.0 * _rtB -> B_27_19_0 - 1.0 ) + 1.0 ) * 0.5 * _rtP -> P_59 ; _rtB ->
B_27_23_0 = _rtP -> P_60 * _rtB -> B_27_11_0 [ 2 ] ; B_27_8_0_idx_0 = _rtP ->
P_61 * rtb_B_1_2_0 [ 0 ] ; _rtB -> B_27_25_0 = _rtB -> B_27_23_0 +
B_27_8_0_idx_0 ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { if (
ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> RelationalOperator_Mode_o = ( _rtB
-> B_27_22_0 >= _rtB -> B_27_25_0 ) ; } rtb_B_27_26_0 = _rtDW ->
RelationalOperator_Mode_o ; } rtb_B_27_4_0 = _rtP -> P_62 * rtb_B_1_2_0 [ 1 ]
; _rtB -> B_27_28_0 = _rtB -> B_27_25_0 + rtb_B_27_4_0 ; i = ssIsSampleHit (
S , 1 , 0 ) ; if ( i != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator1_Mode = ( _rtB -> B_27_22_0 >= _rtB -> B_27_28_0 ) ; }
rtb_B_27_29_0 = _rtDW -> RelationalOperator1_Mode ; } _rtB -> B_27_31_0 =
_rtP -> P_63 * _rtB -> B_27_11_0 [ 2 ] + _rtB -> B_27_28_0 ; i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { if ( ssIsModeUpdateTimeStep ( S
) ) { _rtDW -> RelationalOperator2_Mode_p = ( _rtB -> B_27_22_0 >= _rtB ->
B_27_31_0 ) ; } rtb_B_27_32_0 = _rtDW -> RelationalOperator2_Mode_p ; } _rtB
-> B_27_33_0 = _rtB -> B_27_31_0 + rtb_B_27_4_0 ; i = ssIsSampleHit ( S , 1 ,
0 ) ; if ( i != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator3_Mode = ( _rtB -> B_27_22_0 >= _rtB -> B_27_33_0 ) ; }
rtb_B_27_34_0 = _rtDW -> RelationalOperator3_Mode ; } _rtB -> B_27_35_0 =
_rtB -> B_27_33_0 + B_27_8_0_idx_0 ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator4_Mode = ( _rtB -> B_27_22_0 >= _rtB -> B_27_35_0 ) ; }
rtb_B_27_36_0 = _rtDW -> RelationalOperator4_Mode ; if (
ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> RelationalOperator5_Mode = ( _rtB
-> B_27_22_0 >= _rtB -> B_27_23_0 ) ; } rtb_B_27_37_0 = _rtDW ->
RelationalOperator5_Mode ; zcEvent = rt_ZCFcn ( ANY_ZERO_CROSSING , & _rtZCE
-> HitCrossing_Input_ZCE , _rtB -> B_27_19_0 - _rtP -> P_64 ) ; if ( _rtDW ->
HitCrossing_MODE == 0 ) { if ( zcEvent != NO_ZCEVENT ) { _rtB -> B_27_38_0 =
! _rtB -> B_27_38_0 ; _rtDW -> HitCrossing_MODE = 1 ; } else if ( _rtB ->
B_27_38_0 ) { _rtB -> B_27_38_0 = ( ( ! ( _rtB -> B_27_19_0 != _rtP -> P_64 )
) && _rtB -> B_27_38_0 ) ; } else { _rtB -> B_27_38_0 = ( ( _rtB -> B_27_19_0
== _rtP -> P_64 ) || _rtB -> B_27_38_0 ) ; } } else { _rtB -> B_27_38_0 = ( (
! ( _rtB -> B_27_19_0 != _rtP -> P_64 ) ) && _rtB -> B_27_38_0 ) ; _rtDW ->
HitCrossing_MODE = 0 ; } } i = ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) {
_rtB -> B_27_39_0 = _rtDW -> UnitDelay_DSTATE_f ; } i = ssIsSampleHit ( S , 1
, 0 ) ; if ( i != 0 ) { _rtB -> B_27_41_0 = ( ( ( ( ( ( _rtB -> B_27_7_0 + (
real_T ) rtb_B_27_37_0 ) + ( real_T ) rtb_B_27_26_0 ) + ( real_T )
rtb_B_27_29_0 ) + ( real_T ) rtb_B_27_32_0 ) + ( real_T ) rtb_B_27_34_0 ) + (
real_T ) rtb_B_27_36_0 ) - _rtB -> B_27_5_0 ; } _rtB -> B_27_42_0 =
rtb_B_9_1_1 - _rtB -> B_27_6_0 ; if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW
-> Saturation_MODE_i = _rtB -> B_27_42_0 >= _rtP -> P_66 ? 1 : _rtB ->
B_27_42_0 > _rtP -> P_67 ? 0 : - 1 ; } _rtB -> B_27_43_0 = _rtDW ->
Saturation_MODE_i == 1 ? _rtP -> P_66 : _rtDW -> Saturation_MODE_i == - 1 ?
_rtP -> P_67 : _rtB -> B_27_42_0 ; rtb_B_9_1_1 = muDoubleScalarFloor ( _rtB
-> B_27_41_0 ) ; if ( ( _rtP -> P_344 != 0 ) && ( ( ! ( rtb_B_9_1_1 >= 0.0 )
) || ( ! ( rtb_B_9_1_1 <= 6.0 ) ) ) ) { if ( _rtP -> P_344 == 1 ) { if (
_rtDW -> DirectLookUpTablenD_NumIssuedWarnings == 0U ) { diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeWarnMsg" , 1 , 5 ,
 "graduation_project_prototype_collect_4/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( _rtDW ->
DirectLookUpTablenD_NumIssuedWarnings != 0U ) { diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockNumOfIndexOutOfRangeWarnMsg" , 2 , 5 ,
 "graduation_project_prototype_collect_4/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
, 1 , _rtDW -> DirectLookUpTablenD_NumIssuedWarnings ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( _rtDW ->
DirectLookUpTablenD_NumIssuedWarnings < MAX_uint32_T ) { _rtDW ->
DirectLookUpTablenD_NumIssuedWarnings ++ ; } } else { diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeErrorMsg" , 1 , 5 ,
 "graduation_project_prototype_collect_4/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) ; rt_ssSet_slErrMsg ( S , diag ) ; } } rtb_B_9_1_1 = muDoubleScalarFloor (
_rtB -> B_27_43_0 ) ; if ( ( _rtP -> P_344 != 0 ) && ( ( ! ( rtb_B_9_1_1 >=
0.0 ) ) || ( ! ( rtb_B_9_1_1 <= 5.0 ) ) ) ) { if ( _rtP -> P_344 == 1 ) { if
( _rtDW -> DirectLookUpTablenD_NumIssuedWarnings == 0U ) { diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeWarnMsg" , 1 , 5 ,
 "graduation_project_prototype_collect_4/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( _rtDW ->
DirectLookUpTablenD_NumIssuedWarnings != 0U ) { diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockNumOfIndexOutOfRangeWarnMsg" , 2 , 5 ,
 "graduation_project_prototype_collect_4/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
, 1 , _rtDW -> DirectLookUpTablenD_NumIssuedWarnings ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; } if ( _rtDW ->
DirectLookUpTablenD_NumIssuedWarnings < MAX_uint32_T ) { _rtDW ->
DirectLookUpTablenD_NumIssuedWarnings ++ ; } } else { diag =
CreateDiagnosticAsVoidPtr (
"Simulink:blocks:DirectLookupNdBlockIndexOutOfRangeErrorMsg" , 1 , 5 ,
 "graduation_project_prototype_collect_4/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Direct Look-Up Table (n-D)"
) ; rt_ssSet_slErrMsg ( S , diag ) ; } } if ( muDoubleScalarIsNaN ( _rtB ->
B_27_43_0 ) ) { rtb_B_27_4_0 = 0.0 ; } else { rtb_B_27_4_0 = _rtB ->
B_27_43_0 ; } if ( muDoubleScalarIsNaN ( _rtB -> B_27_41_0 ) ) {
B_27_8_0_idx_0 = 0.0 ; } else { B_27_8_0_idx_0 = _rtB -> B_27_41_0 ; } if (
rtb_B_27_4_0 > 5.0 ) { rtb_B_27_4_0 = 5.0 ; } else if ( rtb_B_27_4_0 < 0.0 )
{ rtb_B_27_4_0 = 0.0 ; } if ( B_27_8_0_idx_0 > 6.0 ) { B_27_8_0_idx_0 = 6.0 ;
} else if ( B_27_8_0_idx_0 < 0.0 ) { B_27_8_0_idx_0 = 0.0 ; } i = ( int32_T )
rtb_B_27_4_0 * 21 + ( int32_T ) B_27_8_0_idx_0 * 3 ; rtb_B_27_4_0 = _rtP ->
P_68 [ i ] ; _rtB -> B_27_44_0 [ 0 ] = rtb_B_27_4_0 ; _rtB -> B_27_45_0 [ 0 ]
= ! ( rtb_B_27_4_0 != 0.0 ) ; rtb_B_27_4_0 = _rtP -> P_68 [ i + 1 ] ; _rtB ->
B_27_44_0 [ 1 ] = rtb_B_27_4_0 ; _rtB -> B_27_45_0 [ 1 ] = ! ( rtb_B_27_4_0
!= 0.0 ) ; rtb_B_27_4_0 = _rtP -> P_68 [ i + 2 ] ; _rtB -> B_27_44_0 [ 2 ] =
rtb_B_27_4_0 ; _rtB -> B_27_45_0 [ 2 ] = ! ( rtb_B_27_4_0 != 0.0 ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
SVModulatorPattern1_SubsysRanBC ) ; } } i = ssIsSampleHit ( S , 1 , 0 ) ; if
( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_44_0 ) {
if ( ! _rtDW -> SVModulatorPattern2_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> SVModulatorPattern2_MODE = true ; } } else if ( _rtDW ->
SVModulatorPattern2_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S )
; _rtDW -> SVModulatorPattern2_MODE = false ; } } if ( _rtDW ->
SVModulatorPattern2_MODE ) { B_27_8_0_idx_0 = look1_pbinlxpw ( rtb_B_1_4_0 ,
_rtP -> P_79 , _rtP -> P_78 , & _rtDW -> m_bpIndex , 5U ) ; _rtB -> B_28_1_0
= muDoubleScalarFloor ( B_27_8_0_idx_0 ) ; rtb_B_28_2_0 = look1_pbinlxpw (
_rtB -> B_28_1_0 , _rtP -> P_81 , _rtP -> P_80 , & _rtDW -> m_bpIndex_m , 5U
) ; rtb_B_28_3_0 = look1_pbinlxpw ( _rtB -> B_28_1_0 , _rtP -> P_83 , _rtP ->
P_82 , & _rtDW -> m_bpIndex_i , 5U ) ; B_27_8_0_idx_0 = look1_pbinlxpw ( _rtB
-> B_28_1_0 , _rtP -> P_85 , _rtP -> P_84 , & _rtDW -> m_bpIndex_mz , 5U ) ;
rtb_B_9_1_1 = look1_pbinlxpw ( _rtB -> B_28_1_0 , _rtP -> P_87 , _rtP -> P_86
, & _rtDW -> m_bpIndex_e , 5U ) ; rtb_B_28_6_0 = _rtP -> P_88 * _rtB ->
B_33_164_0 ; rtb_B_27_4_0 = rtb_B_28_6_0 * muDoubleScalarCos ( rtb_B_1_4_0 )
; rtb_B_1_4_0 = rtb_B_28_6_0 * muDoubleScalarSin ( rtb_B_1_4_0 ) ; _rtB ->
B_28_13_0 = rtb_B_27_4_0 * rtb_B_28_2_0 + rtb_B_1_4_0 * rtb_B_28_3_0 ; i =
ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_28_16_0 = _rtP ->
P_89 ; } rtb_B_28_2_0 = ssGetT ( S ) + _rtB -> B_28_16_0 ; i = ssIsSampleHit
( S , 1 , 0 ) ; if ( i != 0 ) { _rtB -> B_28_18_0 = _rtP -> P_90 ; }
rtb_B_28_2_0 = look1_pbinlxpw ( _rtP -> P_91 * muDoubleScalarRem (
rtb_B_28_2_0 , _rtB -> B_28_18_0 ) , _rtP -> P_93 , _rtP -> P_92 , & _rtDW ->
m_bpIndex_c , 2U ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) { _rtB
-> B_28_22_0 = _rtP -> P_94 ; } _rtB -> B_28_24_0 = ( ( rtb_B_28_2_0 - _rtB
-> B_28_22_0 ) + 1.0 ) * 0.5 ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0
) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> RelationalOperator_Mode =
( _rtB -> B_28_24_0 >= _rtB -> B_28_13_0 ) ; } _rtB -> B_28_25_0 = _rtDW ->
RelationalOperator_Mode ; _rtB -> B_28_26_0 = ! ( _rtB -> B_28_25_0 != 0.0 )
; } _rtB -> B_28_27_0 = ( rtb_B_27_4_0 * B_27_8_0_idx_0 + rtb_B_1_4_0 *
rtb_B_9_1_1 ) + _rtB -> B_28_13_0 ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i
!= 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator2_Mode = ( _rtB -> B_28_24_0 >= _rtB -> B_28_27_0 ) ; }
_rtB -> B_28_28_0 = _rtDW -> RelationalOperator2_Mode ; _rtB -> B_28_29_0 = !
( _rtB -> B_28_28_0 != 0.0 ) ; } if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW
-> Saturation_MODE_p = _rtB -> B_28_1_0 >= _rtP -> P_95 ? 1 : _rtB ->
B_28_1_0 > _rtP -> P_96 ? 0 : - 1 ; } _rtB -> B_28_30_0 = _rtDW ->
Saturation_MODE_p == 1 ? _rtP -> P_95 : _rtDW -> Saturation_MODE_p == - 1 ?
_rtP -> P_96 : _rtB -> B_28_1_0 ; switch ( ( int32_T ) _rtB -> B_28_30_0 ) {
case 1 : _rtB -> B_28_31_0 = _rtB -> B_28_0_0 ; break ; case 2 : _rtB ->
B_28_31_0 = _rtB -> B_28_26_0 ; break ; case 3 : _rtB -> B_28_31_0 = _rtB ->
B_28_28_0 ; break ; case 4 : _rtB -> B_28_31_0 = _rtB -> B_28_1_0_d ; break ;
case 5 : _rtB -> B_28_31_0 = _rtB -> B_28_25_0 ; break ; default : _rtB ->
B_28_31_0 = _rtB -> B_28_29_0 ; break ; } _rtB -> B_28_32_0 = ! ( _rtB ->
B_28_31_0 != 0.0 ) ; switch ( ( int32_T ) _rtB -> B_28_30_0 ) { case 1 : _rtB
-> B_28_33_0 = _rtB -> B_28_25_0 ; break ; case 2 : _rtB -> B_28_33_0 = _rtB
-> B_28_29_0 ; break ; case 3 : _rtB -> B_28_33_0 = _rtB -> B_28_0_0 ; break
; case 4 : _rtB -> B_28_33_0 = _rtB -> B_28_26_0 ; break ; case 5 : _rtB ->
B_28_33_0 = _rtB -> B_28_28_0 ; break ; default : _rtB -> B_28_33_0 = _rtB ->
B_28_1_0_d ; break ; } _rtB -> B_28_34_0 = ! ( _rtB -> B_28_33_0 != 0.0 ) ;
switch ( ( int32_T ) _rtB -> B_28_30_0 ) { case 1 : _rtB -> B_28_35_0 = _rtB
-> B_28_28_0 ; break ; case 2 : _rtB -> B_28_35_0 = _rtB -> B_28_1_0_d ;
break ; case 3 : _rtB -> B_28_35_0 = _rtB -> B_28_25_0 ; break ; case 4 :
_rtB -> B_28_35_0 = _rtB -> B_28_29_0 ; break ; case 5 : _rtB -> B_28_35_0 =
_rtB -> B_28_0_0 ; break ; default : _rtB -> B_28_35_0 = _rtB -> B_28_26_0 ;
break ; } _rtB -> B_28_36_0 = ! ( _rtB -> B_28_35_0 != 0.0 ) ; i =
ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) { _rtB -> B_28_37_0 = _rtDW ->
UnitDelay_DSTATE_l ; } if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC (
_rtDW -> SVModulatorPattern2_SubsysRanBC ) ; } } if ( ( int32_T ) _rtB ->
B_33_34_0 == 1 ) { _rtB -> B_33_172_0 [ 0 ] = _rtB -> B_27_44_0 [ 0 ] ; _rtB
-> B_33_172_0 [ 1 ] = _rtB -> B_27_45_0 [ 0 ] ; _rtB -> B_33_172_0 [ 2 ] =
_rtB -> B_27_44_0 [ 1 ] ; _rtB -> B_33_172_0 [ 3 ] = _rtB -> B_27_45_0 [ 1 ]
; _rtB -> B_33_172_0 [ 4 ] = _rtB -> B_27_44_0 [ 2 ] ; _rtB -> B_33_172_0 [ 5
] = _rtB -> B_27_45_0 [ 2 ] ; } else { _rtB -> B_33_172_0 [ 0 ] = _rtB ->
B_28_31_0 ; _rtB -> B_33_172_0 [ 1 ] = _rtB -> B_28_32_0 ; _rtB -> B_33_172_0
[ 2 ] = _rtB -> B_28_33_0 ; _rtB -> B_33_172_0 [ 3 ] = _rtB -> B_28_34_0 ;
_rtB -> B_33_172_0 [ 4 ] = _rtB -> B_28_35_0 ; _rtB -> B_33_172_0 [ 5 ] =
_rtB -> B_28_36_0 ; } if ( ssIsModeUpdateTimeStep ( S ) ) { for ( i = 0 ; i <
6 ; i ++ ) { _rtDW -> Saturation_MODE [ i ] = _rtB -> B_33_172_0 [ i ] >=
_rtP -> P_202 ? 1 : _rtB -> B_33_172_0 [ i ] > _rtP -> P_203 ? 0 : - 1 ; } }
for ( i = 0 ; i < 6 ; i ++ ) { rtb_B_1_4_0 = _rtDW -> Saturation_MODE [ i ]
== 1 ? _rtP -> P_202 : _rtDW -> Saturation_MODE [ i ] == - 1 ? _rtP -> P_203
: _rtB -> B_33_172_0 [ i ] ; _rtB -> B_33_173_0 [ i ] = rtb_B_1_4_0 ; _rtB ->
B_33_174_0 [ i ] = rtb_B_1_4_0 * _rtB -> B_33_2_0_m ; } switch ( ( int32_T )
_rtB -> B_33_26_0_n ) { case 1 : tmp_5 = & _rtB -> B_9_4_0 [ 0 ] ; break ;
case 2 : tmp_5 = & _rtB -> B_10_4_0 [ 0 ] ; break ; default : tmp_5 = & _rtB
-> B_8_8_0 [ 0 ] ; break ; } for ( i = 0 ; i < 16 ; i ++ ) { rtb_B_1_4_0 =
tmp_5 [ i ] ; _rtB -> B_33_185_0 [ i ] = rtb_B_1_4_0 ; if ( _rtB -> B_33_6_0
>= _rtP -> P_204 ) { rtb_B_27_4_0 = _rtB -> B_1_18_0 [ i ] ; } else {
rtb_B_27_4_0 = _rtB -> B_33_7_0 [ i ] ; } _rtB -> B_33_186_0 [ i ] =
rtb_B_27_4_0 ; _rtB -> B_33_187_0 [ i ] = ( 0.0 - rtb_B_1_4_0 ) -
rtb_B_27_4_0 ; } rtb_B_1_4_0 = _rtB -> B_33_0_0 [ 1 ] ; rtb_B_9_1_1 = _rtB ->
B_33_0_0 [ 0 ] ; rtb_B_27_4_0 = _rtB -> B_33_0_0 [ 2 ] ; B_27_8_0_idx_0 =
_rtB -> B_33_0_0 [ 3 ] ; for ( i = 0 ; i <= 2 ; i += 2 ) { tmp_3 =
_mm_loadu_pd ( & _rtB -> B_33_187_0 [ i + 4 ] ) ; tmp_4 = _mm_loadu_pd ( &
_rtB -> B_33_187_0 [ i ] ) ; tmp_1 = _mm_loadu_pd ( & _rtB -> B_33_187_0 [ i
+ 8 ] ) ; tmp_2 = _mm_loadu_pd ( & _rtB -> B_33_187_0 [ i + 12 ] ) ;
_mm_storeu_pd ( & _rtB -> B_33_188_0 [ i ] , _mm_add_pd ( _mm_add_pd (
_mm_add_pd ( _mm_mul_pd ( tmp_3 , _mm_set1_pd ( rtb_B_1_4_0 ) ) , _mm_mul_pd
( tmp_4 , _mm_set1_pd ( rtb_B_9_1_1 ) ) ) , _mm_mul_pd ( tmp_1 , _mm_set1_pd
( rtb_B_27_4_0 ) ) ) , _mm_mul_pd ( tmp_2 , _mm_set1_pd ( B_27_8_0_idx_0 ) )
) ) ; } _rtB -> B_33_189_0 [ 0 ] = _rtB -> B_33_131_0 [ 0 ] + _rtB ->
B_33_188_0 [ 0 ] ; _rtB -> B_33_189_0 [ 2 ] = _rtB -> B_33_129_0 [ 0 ] + _rtB
-> B_33_188_0 [ 2 ] ; _rtB -> B_33_189_0 [ 1 ] = _rtB -> B_33_131_0 [ 1 ] +
_rtB -> B_33_188_0 [ 1 ] ; _rtB -> B_33_189_0 [ 3 ] = _rtB -> B_33_129_0 [ 1
] + _rtB -> B_33_188_0 [ 3 ] ; _rtB -> B_33_190_0 [ 0 ] = _rtP -> P_205 *
_rtB -> B_33_189_0 [ 0 ] ; _rtB -> B_33_190_0 [ 1 ] = _rtP -> P_205 * _rtB ->
B_33_189_0 [ 1 ] ; _rtB -> B_33_190_0 [ 2 ] = _rtP -> P_205 * _rtB ->
B_33_189_0 [ 2 ] ; _rtB -> B_33_190_0 [ 3 ] = _rtP -> P_205 * _rtB ->
B_33_189_0 [ 3 ] ; i = ssIsSampleHit ( S , 6 , 0 ) ; if ( i != 0 ) { _rtB ->
B_33_191_0 = _rtP -> P_206 * _rtB -> B_33_27_0 ; } _rtB -> B_33_192_0 = _rtP
-> P_207 * _rtB -> B_33_5_0 ; _rtB -> B_33_193_0 = ( _rtB -> B_33_20_0 - _rtB
-> B_33_191_0 ) - _rtB -> B_33_192_0 ; _rtB -> B_33_194_0 = _rtP -> P_208 *
_rtB -> B_33_193_0 ; _rtB -> B_33_195_0 = _rtP -> P_209 * _rtB -> B_33_5_0 ;
_rtB -> B_33_202_0 = ( muDoubleScalarSin ( _rtP -> P_212 * ssGetTaskTime ( S
, 0 ) + _rtP -> P_213 ) * _rtP -> P_210 + _rtP -> P_211 ) * _rtB ->
B_33_133_0 [ 9 ] ; _rtB -> B_33_204_0 = ( muDoubleScalarSin ( _rtP -> P_216 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_217 ) * _rtP -> P_214 + _rtP -> P_215 ) *
_rtB -> B_33_133_0 [ 9 ] ; _rtB -> B_33_206_0 = ( muDoubleScalarSin ( _rtP ->
P_220 * ssGetTaskTime ( S , 0 ) + _rtP -> P_221 ) * _rtP -> P_218 + _rtP ->
P_219 ) * _rtB -> B_33_133_0 [ 10 ] ; _rtB -> B_33_208_0 = (
muDoubleScalarSin ( _rtP -> P_224 * ssGetTaskTime ( S , 0 ) + _rtP -> P_225 )
* _rtP -> P_222 + _rtP -> P_223 ) * _rtB -> B_33_133_0 [ 10 ] ; _rtB ->
B_33_210_0 = ( muDoubleScalarSin ( _rtP -> P_228 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_229 ) * _rtP -> P_226 + _rtP -> P_227 ) * _rtB -> B_33_133_0 [ 11 ]
; _rtB -> B_33_212_0 = ( muDoubleScalarSin ( _rtP -> P_232 * ssGetTaskTime (
S , 0 ) + _rtP -> P_233 ) * _rtP -> P_230 + _rtP -> P_231 ) * _rtB ->
B_33_133_0 [ 11 ] ; rtb_B_1_4_0 = _rtB -> B_33_133_0 [ 10 ] ; rtb_B_27_4_0 =
_rtB -> B_33_133_0 [ 9 ] ; B_27_8_0_idx_0 = _rtB -> B_33_133_0 [ 11 ] ; for (
i = 0 ; i < 3 ; i ++ ) { rtb_B_28_2_0 = ( _rtP -> P_234 [ i + 3 ] *
rtb_B_1_4_0 + _rtP -> P_234 [ i ] * rtb_B_27_4_0 ) + _rtP -> P_234 [ i + 6 ]
* B_27_8_0_idx_0 ; _rtB -> B_33_213_0 [ i ] = rtb_B_28_2_0 ; _rtB ->
B_33_214_0 [ i ] = _rtP -> P_235 * rtb_B_28_2_0 ; } _rtB -> B_33_216_0 = (
muDoubleScalarSin ( _rtP -> P_238 * ssGetTaskTime ( S , 0 ) + _rtP -> P_239 )
* _rtP -> P_236 + _rtP -> P_237 ) * _rtB -> B_33_214_0 [ 0 ] ; _rtB ->
B_33_218_0 = ( muDoubleScalarSin ( _rtP -> P_242 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_243 ) * _rtP -> P_240 + _rtP -> P_241 ) * _rtB -> B_33_214_0 [ 0 ]
; _rtB -> B_33_220_0 = ( muDoubleScalarSin ( _rtP -> P_246 * ssGetTaskTime (
S , 0 ) + _rtP -> P_247 ) * _rtP -> P_244 + _rtP -> P_245 ) * _rtB ->
B_33_214_0 [ 1 ] ; _rtB -> B_33_222_0 = ( muDoubleScalarSin ( _rtP -> P_250 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_251 ) * _rtP -> P_248 + _rtP -> P_249 ) *
_rtB -> B_33_214_0 [ 1 ] ; _rtB -> B_33_223_0 = _rtB -> B_33_47_0_j - _rtB ->
B_33_139_0 [ 0 ] ; ssCallAccelRunBlock ( S , 33 , 224 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 33 , 225 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_33_226_0 = _rtB -> B_33_26_0 - _rtB -> B_33_22_0 [ 0 ] ; i = ssIsSampleHit
( S , 3 , 0 ) ; if ( i != 0 ) { rtb_B_33_229_0 = _rtP -> P_252 * _rtB ->
B_33_226_0 + _rtDW -> Integrator_DSTATE ; if ( rtb_B_33_229_0 > _rtP -> P_255
) { _rtB -> B_33_230_0 = _rtP -> P_255 ; } else if ( rtb_B_33_229_0 < _rtP ->
P_256 ) { _rtB -> B_33_230_0 = _rtP -> P_256 ; } else { _rtB -> B_33_230_0 =
rtb_B_33_229_0 ; } } _rtB -> B_33_231_0 = _rtB -> B_33_230_0 - _rtB ->
B_33_139_0 [ 1 ] ; ssCallAccelRunBlock ( S , 33 , 232 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 33 , 233 , SS_CALL_MDL_OUTPUTS ) ; i =
ssIsSampleHit ( S , 3 , 0 ) ; if ( i != 0 ) { rtb_B_33_236_0 = _rtP -> P_257
* _rtB -> B_33_223_0 + _rtDW -> Integrator_DSTATE_d ; if ( rtb_B_33_236_0 >
_rtP -> P_260 ) { _rtB -> B_33_237_0 = _rtP -> P_260 ; } else if (
rtb_B_33_236_0 < _rtP -> P_261 ) { _rtB -> B_33_237_0 = _rtP -> P_261 ; }
else { _rtB -> B_33_237_0 = rtb_B_33_236_0 ; } _rtB -> B_33_239_0 = _rtP ->
P_262 * _rtB -> B_33_230_0 / _rtB -> B_33_73_0_g ; } _rtB -> B_33_240_0 =
_rtP -> P_263 * _rtB -> B_33_22_0 [ 0 ] ; _rtB -> B_33_241_0 = _rtB ->
B_33_239_0 + _rtB -> B_33_240_0 ; _rtB -> B_33_243_0 = _rtB -> B_33_241_0 *
_rtB -> B_33_139_0 [ 1 ] * _rtP -> P_264 ; rtb_B_1_4_0 = _rtB -> B_33_237_0 +
_rtB -> B_33_243_0 ; i = ssIsSampleHit ( S , 3 , 0 ) ; if ( i != 0 ) {
rtb_B_33_247_0 = _rtP -> P_265 * _rtB -> B_33_231_0 + _rtDW ->
Integrator_DSTATE_l ; if ( rtb_B_33_247_0 > _rtP -> P_268 ) { _rtB ->
B_33_248_0 = _rtP -> P_268 ; } else if ( rtb_B_33_247_0 < _rtP -> P_269 ) {
_rtB -> B_33_248_0 = _rtP -> P_269 ; } else { _rtB -> B_33_248_0 =
rtb_B_33_247_0 ; } } _rtB -> B_33_250_0 = _rtB -> B_33_139_0 [ 0 ] * _rtB ->
B_33_241_0 * _rtP -> P_270 ; B_27_8_0_idx_0 = _rtB -> B_33_248_0 + _rtB ->
B_33_250_0 ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( i != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_70_0 > 0 ) { if ( ! _rtDW
-> Subsystem1_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW -> Subsystem1_MODE
= true ; } } else if ( _rtDW -> Subsystem1_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW -> Subsystem1_MODE =
false ; } } if ( _rtDW -> Subsystem1_MODE ) { _rtB -> B_32_0_0 = rtb_B_1_4_0
* muDoubleScalarCos ( _rtB -> B_33_136_0 ) - B_27_8_0_idx_0 *
muDoubleScalarSin ( _rtB -> B_33_136_0 ) ; _rtB -> B_32_1_0 = rtb_B_1_4_0 *
muDoubleScalarSin ( _rtB -> B_33_136_0 ) + B_27_8_0_idx_0 * muDoubleScalarCos
( _rtB -> B_33_136_0 ) ; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC (
_rtDW -> Subsystem1_SubsysRanBC ) ; } } i = ssIsSampleHit ( S , 1 , 0 ) ; if
( ( i != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_33_72_0 > 0 )
{ if ( ! _rtDW -> Subsystempi2delay_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> Subsystempi2delay_MODE = true ; } } else if ( _rtDW ->
Subsystempi2delay_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
_rtDW -> Subsystempi2delay_MODE = false ; } } if ( _rtDW ->
Subsystempi2delay_MODE ) { _rtB -> B_31_0_0 = rtb_B_1_4_0 * muDoubleScalarSin
( _rtB -> B_33_136_0 ) + B_27_8_0_idx_0 * muDoubleScalarCos ( _rtB ->
B_33_136_0 ) ; _rtB -> B_31_1_0 = - rtb_B_1_4_0 * muDoubleScalarCos ( _rtB ->
B_33_136_0 ) + B_27_8_0_idx_0 * muDoubleScalarSin ( _rtB -> B_33_136_0 ) ; if
( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Subsystempi2delay_SubsysRanBC ) ; } } if ( _rtB -> B_33_70_0 != 0 ) {
rtb_B_27_4_0 = _rtB -> B_32_0_0 ; } else { rtb_B_27_4_0 = _rtB -> B_31_0_0 ;
} _rtB -> B_33_255_0 [ 0 ] = _rtP -> P_271 * rtb_B_27_4_0 ; if ( _rtB ->
B_33_70_0 != 0 ) { rtb_B_27_4_0 = _rtB -> B_32_1_0 ; } else { rtb_B_27_4_0 =
_rtB -> B_31_1_0 ; } _rtB -> B_33_255_0 [ 1 ] = _rtP -> P_271 * rtb_B_27_4_0
; _rtB -> B_33_255_0 [ 2 ] = _rtP -> P_271 * 0.0 ; ssCallAccelRunBlock ( S ,
33 , 256 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 33 , 257 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 33 , 258 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 33 , 259 ,
SS_CALL_MDL_OUTPUTS ) ; i = ssIsSampleHit ( S , 3 , 0 ) ; if ( i != 0 ) {
ssCallAccelRunBlock ( S , 33 , 260 , SS_CALL_MDL_OUTPUTS ) ; if (
rtb_B_33_247_0 > _rtP -> P_273 ) { rtb_B_33_247_0 -= _rtP -> P_273 ; } else
if ( rtb_B_33_247_0 >= _rtP -> P_272 ) { rtb_B_33_247_0 = 0.0 ; } else {
rtb_B_33_247_0 -= _rtP -> P_272 ; } rtb_B_1_4_0 = _rtP -> P_274 * _rtB ->
B_33_231_0 ; if ( rtb_B_33_247_0 > _rtB -> B_33_48_0 ) { tmp = _rtB ->
B_33_49_0 ; } else { tmp = _rtB -> B_33_50_0_b ; } if ( rtb_B_1_4_0 > _rtB ->
B_33_48_0 ) { tmp_0 = _rtB -> B_33_51_0 ; } else { tmp_0 = _rtB ->
B_33_52_0_d ; } if ( ( _rtB -> B_33_48_0 != rtb_B_33_247_0 ) && ( tmp ==
tmp_0 ) ) { _rtB -> B_33_270_0 = graduation_project_prototype_collect_4_rtC (
S ) -> B_33_1_0 ; } else { _rtB -> B_33_270_0 = rtb_B_1_4_0 ; } if (
rtb_B_33_229_0 > _rtP -> P_276 ) { rtb_B_33_229_0 -= _rtP -> P_276 ; } else
if ( rtb_B_33_229_0 >= _rtP -> P_275 ) { rtb_B_33_229_0 = 0.0 ; } else {
rtb_B_33_229_0 -= _rtP -> P_275 ; } rtb_B_33_247_0 = _rtP -> P_277 * _rtB ->
B_33_226_0 ; if ( rtb_B_33_229_0 > _rtB -> B_33_53_0 ) { tmp = _rtB ->
B_33_54_0_e ; } else { tmp = _rtB -> B_33_55_0_b ; } if ( rtb_B_33_247_0 >
_rtB -> B_33_53_0 ) { tmp_0 = _rtB -> B_33_56_0 ; } else { tmp_0 = _rtB ->
B_33_57_0 ; } if ( ( _rtB -> B_33_53_0 != rtb_B_33_229_0 ) && ( tmp == tmp_0
) ) { _rtB -> B_33_280_0 = graduation_project_prototype_collect_4_rtC ( S )
-> B_33_2_0 ; } else { _rtB -> B_33_280_0 = rtb_B_33_247_0 ; } if (
rtb_B_33_236_0 > _rtP -> P_279 ) { rtb_B_33_236_0 -= _rtP -> P_279 ; } else
if ( rtb_B_33_236_0 >= _rtP -> P_278 ) { rtb_B_33_236_0 = 0.0 ; } else {
rtb_B_33_236_0 -= _rtP -> P_278 ; } rtb_B_33_229_0 = _rtP -> P_280 * _rtB ->
B_33_223_0 ; if ( rtb_B_33_236_0 > _rtB -> B_33_58_0_d ) { tmp = _rtB ->
B_33_59_0 ; } else { tmp = _rtB -> B_33_60_0_j ; } if ( rtb_B_33_229_0 > _rtB
-> B_33_58_0_d ) { tmp_0 = _rtB -> B_33_61_0 ; } else { tmp_0 = _rtB ->
B_33_62_0_f ; } if ( ( _rtB -> B_33_58_0_d != rtb_B_33_236_0 ) && ( tmp ==
tmp_0 ) ) { _rtB -> B_33_290_0 = graduation_project_prototype_collect_4_rtC (
S ) -> B_33_3_0 ; } else { _rtB -> B_33_290_0 = rtb_B_33_229_0 ; } } i =
ssIsSampleHit ( S , 4 , 0 ) ; if ( i != 0 ) { ssCallAccelRunBlock ( S , 33 ,
291 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 21 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_33_296_0 [ 0 ] = _rtP -> P_281 * _rtB ->
B_33_17_0 [ 2 ] * _rtP -> P_284 ; _rtB -> B_33_296_0 [ 1 ] = _rtP -> P_282 *
_rtB -> B_33_17_0 [ 3 ] * _rtP -> P_284 ; _rtB -> B_33_296_0 [ 2 ] = _rtP ->
P_283 * _rtB -> B_33_17_0 [ 4 ] * _rtP -> P_284 ; ssCallAccelRunBlock ( S ,
33 , 297 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID7 ( SimStruct * S , int_T tid ) {
B_graduation_project_prototype_collect_4_T * _rtB ;
DW_graduation_project_prototype_collect_4_T * _rtDW ;
P_graduation_project_prototype_collect_4_T * _rtP ; _rtDW = ( (
DW_graduation_project_prototype_collect_4_T * ) ssGetRootDWork ( S ) ) ; _rtP
= ( ( P_graduation_project_prototype_collect_4_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_graduation_project_prototype_collect_4_T * ) _ssGetModelBlockIO
( S ) ) ; _rtB -> B_33_2_0_m = ( _rtP -> P_285 >= 0.0 ) ; _rtB -> B_33_3_0_c
= _rtP -> P_286 ; _rtB -> B_33_4_0_k = _rtP -> P_287 ; _rtB -> B_33_6_0 =
_rtP -> P_289 ; _rtB -> B_33_8_0 = _rtP -> P_291 ; _rtB -> B_33_9_0_b = _rtP
-> P_292 ; _rtB -> B_1_0_0_b = _rtP -> P_7 ; _rtB -> B_1_1_0_n [ 0 ] = _rtP
-> P_8 [ 0 ] ; _rtB -> B_1_1_0_n [ 1 ] = _rtP -> P_8 [ 1 ] ; _rtB -> B_1_4_0
[ 0 ] = _rtP -> P_11 [ 0 ] ; _rtB -> B_1_4_0 [ 1 ] = _rtP -> P_11 [ 1 ] ;
memcpy ( & _rtB -> B_33_5_0_c [ 0 ] , & _rtP -> P_288 [ 0 ] , sizeof ( real_T
) << 4U ) ; memcpy ( & _rtB -> B_33_7_0 [ 0 ] , & _rtP -> P_290 [ 0 ] ,
sizeof ( real_T ) << 4U ) ; memcpy ( & _rtB -> B_1_2_0 [ 0 ] , & _rtP -> P_9
[ 0 ] , sizeof ( real_T ) << 4U ) ; memcpy ( & _rtB -> B_1_3_0_b [ 0 ] , &
_rtP -> P_10 [ 0 ] , sizeof ( real_T ) << 4U ) ; memcpy ( & _rtB -> B_1_5_0_l
[ 0 ] , & _rtP -> P_12 [ 0 ] , sizeof ( real_T ) << 4U ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW -> Saturation_SubsysRanBC
) ; } _rtB -> B_33_11_0 = _rtP -> P_323 ; _rtB -> B_33_12_0 = _rtP -> P_324 ;
_rtB -> B_33_13_0_a = _rtP -> P_325 ; _rtB -> B_33_14_0_p = _rtP -> P_293 ;
_rtB -> B_33_15_0_c = _rtP -> P_294 ; _rtB -> B_33_16_0_f [ 0 ] = _rtP ->
P_295 [ 0 ] ; _rtB -> B_33_16_0_f [ 1 ] = _rtP -> P_295 [ 1 ] ; _rtB ->
B_33_17_0_j = _rtP -> P_326 ; _rtB -> B_33_18_0_j = _rtP -> P_327 ; _rtB ->
B_33_19_0_o = _rtP -> P_328 ; _rtB -> B_33_20_0_g = _rtP -> P_296 ; _rtB ->
B_33_21_0_g = _rtP -> P_297 ; _rtB -> B_33_22_0_n = _rtP -> P_329 ; _rtB ->
B_33_23_0 = _rtP -> P_330 ; _rtB -> B_33_24_0_m = _rtP -> P_298 ; _rtB ->
B_33_25_0 = _rtP -> P_331 ; _rtB -> B_33_26_0_n = _rtP -> P_299 ; memcpy ( &
_rtB -> B_8_0_0 [ 0 ] , & _rtP -> P_29 [ 0 ] , sizeof ( real_T ) << 4U ) ;
_rtB -> B_8_1_0_o = _rtP -> P_30 ; if ( ssIsModeUpdateTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> sinbetacosbetasinthcosth_SubsysRanBC ) ; } _rtB ->
B_9_0_0_l [ 0 ] = _rtP -> P_34 [ 0 ] ; _rtB -> B_9_0_0_l [ 1 ] = _rtP -> P_34
[ 1 ] ; memcpy ( & _rtB -> B_9_1_0 [ 0 ] , & _rtP -> P_35 [ 0 ] , sizeof (
real_T ) << 4U ) ; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW
-> sinthrcosthr_SubsysRanBC ) ; } _rtB -> B_10_0_0_d [ 0 ] = _rtP -> P_39 [ 0
] ; _rtB -> B_10_0_0_d [ 1 ] = _rtP -> P_39 [ 1 ] ; memcpy ( & _rtB ->
B_10_1_0 [ 0 ] , & _rtP -> P_40 [ 0 ] , sizeof ( real_T ) << 4U ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
sinthrcosthr1_SubsysRanBC ) ; } _rtB -> B_33_31_0_p = _rtP -> P_301 ; _rtB ->
B_33_32_0 = _rtP -> P_302 ; _rtB -> B_33_34_0 = _rtP -> P_304 ; _rtB ->
B_33_37_0 = _rtP -> P_307 ; _rtB -> B_33_39_0_l = _rtP -> P_309 * _rtP ->
P_303 ; _rtB -> B_33_40_0 = _rtP -> P_310 ; _rtB -> B_33_41_0_i = ( _rtP ->
P_308 == _rtP -> P_305 ) ; _rtB -> B_33_42_0 = ( _rtP -> P_308 == _rtP ->
P_306 ) ; _rtB -> B_33_43_0_o = ( _rtB -> B_33_34_0 == _rtP -> P_300 ) ; _rtB
-> B_33_44_0 = ! _rtB -> B_33_43_0_o ; _rtB -> B_27_0_0 = _rtP -> P_69 ; _rtB
-> B_27_1_0 = _rtP -> P_70 ; _rtB -> B_27_2_0 = _rtP -> P_71 ; _rtB ->
B_27_3_0 = _rtP -> P_72 ; _rtB -> B_27_4_0 = _rtP -> P_73 ; _rtB -> B_27_5_0
= _rtP -> P_74 ; _rtB -> B_27_6_0 = _rtP -> P_75 ; _rtB -> B_27_7_0 = _rtP ->
P_76 ; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
SVModulatorPattern1_SubsysRanBC ) ; } _rtB -> B_28_0_0 = _rtP -> P_98 ; _rtB
-> B_28_1_0_d = _rtP -> P_99 ; if ( ssIsModeUpdateTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> SVModulatorPattern2_SubsysRanBC ) ; } _rtB ->
B_33_47_0_j = _rtP -> P_311 ; _rtB -> B_33_48_0 = _rtP -> P_312 ; _rtB ->
B_33_49_0 = _rtP -> P_332 ; _rtB -> B_33_50_0_b = _rtP -> P_333 ; _rtB ->
B_33_51_0 = _rtP -> P_334 ; _rtB -> B_33_52_0_d = _rtP -> P_335 ; _rtB ->
B_33_53_0 = _rtP -> P_313 ; _rtB -> B_33_54_0_e = _rtP -> P_336 ; _rtB ->
B_33_55_0_b = _rtP -> P_337 ; _rtB -> B_33_56_0 = _rtP -> P_338 ; _rtB ->
B_33_57_0 = _rtP -> P_339 ; _rtB -> B_33_58_0_d = _rtP -> P_314 ; _rtB ->
B_33_59_0 = _rtP -> P_340 ; _rtB -> B_33_60_0_j = _rtP -> P_341 ; _rtB ->
B_33_61_0 = _rtP -> P_342 ; _rtB -> B_33_62_0_f = _rtP -> P_343 ; _rtB ->
B_33_65_0_h = ( uint8_T ) ( _rtP -> P_315 == _rtP -> P_316 ) ; _rtB ->
B_33_67_0 = ( uint8_T ) ( _rtP -> P_315 == _rtP -> P_317 ) ; _rtB ->
B_33_70_0 = ( uint8_T ) ( _rtP -> P_318 == _rtP -> P_319 ) ; _rtB ->
B_33_72_0 = ( uint8_T ) ( _rtP -> P_318 == _rtP -> P_320 ) ; _rtB ->
B_33_73_0_g = _rtP -> P_321 * _rtB -> B_33_47_0_j ; _rtB -> B_33_74_0_l =
_rtP -> P_322 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) {
B_graduation_project_prototype_collect_4_T * _rtB ;
DW_graduation_project_prototype_collect_4_T * _rtDW ;
P_graduation_project_prototype_collect_4_T * _rtP ; int32_T isHit ; _rtDW = (
( DW_graduation_project_prototype_collect_4_T * ) ssGetRootDWork ( S ) ) ;
_rtP = ( ( P_graduation_project_prototype_collect_4_T * ) ssGetModelRtp ( S )
) ; _rtB = ( ( B_graduation_project_prototype_collect_4_T * )
_ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 33 , 17 ,
SS_CALL_MDL_UPDATE ) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK . Head = ( ( _rtDW -> TransportDelay_IWORK .
Head < ( _rtDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK
. Head == _rtDW -> TransportDelay_IWORK . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Tail , & _rtDW -> TransportDelay_IWORK . Head , &
_rtDW -> TransportDelay_IWORK . Last , simTime - _rtP -> P_138 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = _rtB -> B_33_28_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput = _rtB ->
B_33_35_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_j . Head = ( ( _rtDW -> TransportDelay_IWORK_j
. Head < ( _rtDW -> TransportDelay_IWORK_j . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_j . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_j . Head == _rtDW -> TransportDelay_IWORK_j . Tail ) {
if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_j . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_j . Tail , & _rtDW -> TransportDelay_IWORK_j . Head , &
_rtDW -> TransportDelay_IWORK_j . Last , simTime - _rtP -> P_143 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_j . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_j . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_j . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_j . Head ] = _rtB -> B_33_36_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_e = _rtB ->
B_33_43_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_l . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_m . Head = ( ( _rtDW -> TransportDelay_IWORK_m
. Head < ( _rtDW -> TransportDelay_IWORK_m . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_m . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_m . Head == _rtDW -> TransportDelay_IWORK_m . Tail ) {
if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_m . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_m . Tail , & _rtDW -> TransportDelay_IWORK_m . Head , &
_rtDW -> TransportDelay_IWORK_m . Last , simTime - _rtP -> P_149 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_m . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_m . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_m . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_m . Head ] = _rtB -> B_33_47_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_d = _rtB ->
B_33_54_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_a . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_jk . Head = ( ( _rtDW ->
TransportDelay_IWORK_jk . Head < ( _rtDW -> TransportDelay_IWORK_jk .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_jk . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_jk . Head == _rtDW ->
TransportDelay_IWORK_jk . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_jk . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_jk . Tail , & _rtDW -> TransportDelay_IWORK_jk . Head ,
& _rtDW -> TransportDelay_IWORK_jk . Last , simTime - _rtP -> P_154 , uBuffer
, ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_jk .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK_jk .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_jk . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> TransportDelay_IWORK_jk . Head ] = _rtB -> B_33_55_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_m = _rtB -> B_33_62_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_h . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_a . Head = ( ( _rtDW
-> TransportDelay_IWORK_a . Head < ( _rtDW -> TransportDelay_IWORK_a .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_a . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_a . Head == _rtDW ->
TransportDelay_IWORK_a . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_a . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_a . Tail , & _rtDW -> TransportDelay_IWORK_a . Head , &
_rtDW -> TransportDelay_IWORK_a . Last , simTime - _rtP -> P_160 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_a . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_a . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_a . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_a . Head ] = _rtB -> B_33_66_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_k = _rtB ->
B_33_73_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_ln . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S )
; _rtDW -> TransportDelay_IWORK_p . Head = ( ( _rtDW ->
TransportDelay_IWORK_p . Head < ( _rtDW -> TransportDelay_IWORK_p .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_p . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_p . Head == _rtDW ->
TransportDelay_IWORK_p . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_p . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_p . Tail , & _rtDW -> TransportDelay_IWORK_p . Head , &
_rtDW -> TransportDelay_IWORK_p . Last , simTime - _rtP -> P_165 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_p . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_p . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = _rtB -> B_33_74_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_kj = _rtB
-> B_33_81_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_h . Head = ( ( _rtDW -> TransportDelay_IWORK_h
. Head < ( _rtDW -> TransportDelay_IWORK_h . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_h . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_h . Head == _rtDW -> TransportDelay_IWORK_h . Tail ) {
if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_h . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_h . Tail , & _rtDW -> TransportDelay_IWORK_h . Head , &
_rtDW -> TransportDelay_IWORK_h . Last , simTime - _rtP -> P_171 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_h . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_h . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_h . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_h . Head ] = _rtB -> B_33_85_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_o = _rtB ->
B_33_92_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_d . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_jc . Head = ( ( _rtDW ->
TransportDelay_IWORK_jc . Head < ( _rtDW -> TransportDelay_IWORK_jc .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_jc . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_jc . Head == _rtDW ->
TransportDelay_IWORK_jc . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_jc . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_jc . Tail , & _rtDW -> TransportDelay_IWORK_jc . Head ,
& _rtDW -> TransportDelay_IWORK_jc . Last , simTime - _rtP -> P_176 , uBuffer
, ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_jc .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK_jc .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_jc . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> TransportDelay_IWORK_jc . Head ] = _rtB -> B_33_93_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_p = _rtB -> B_33_100_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_l5 . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_d . Head = ( ( _rtDW
-> TransportDelay_IWORK_d . Head < ( _rtDW -> TransportDelay_IWORK_d .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_d . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_d . Head == _rtDW ->
TransportDelay_IWORK_d . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_d . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_d . Tail , & _rtDW -> TransportDelay_IWORK_d . Head , &
_rtDW -> TransportDelay_IWORK_d . Last , simTime - _rtP -> P_182 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_d . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_d . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_d . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_d . Head ] = _rtB -> B_33_104_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_j = _rtB -> B_33_111_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_n . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_l . Head = ( ( _rtDW
-> TransportDelay_IWORK_l . Head < ( _rtDW -> TransportDelay_IWORK_l .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_l . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_l . Head == _rtDW ->
TransportDelay_IWORK_l . Tail ) { if ( !
graduation_project_prototype_collect_4_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_l . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_l . Tail , & _rtDW -> TransportDelay_IWORK_l . Head , &
_rtDW -> TransportDelay_IWORK_l . Last , simTime - _rtP -> P_187 , uBuffer ,
( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_l . MaxNewBufSize )
) { ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } }
( * uBuffer + _rtDW -> TransportDelay_IWORK_l . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_l . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_l . Head ] = _rtB -> B_33_112_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_f = _rtB -> B_33_119_0 ; } isHit = ssIsSampleHit ( S , 2
, 0 ) ; if ( isHit != 0 ) { _rtDW -> UnitDelay_DSTATE [ 0 ] = _rtB ->
B_33_255_0 [ 0 ] ; _rtDW -> UnitDelay_DSTATE [ 1 ] = _rtB -> B_33_255_0 [ 1 ]
; _rtDW -> UnitDelay_DSTATE [ 2 ] = _rtB -> B_33_255_0 [ 2 ] ; } if ( _rtDW
-> SVModulatorPattern1_MODE ) { isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { _rtDW -> UnitDelay_DSTATE_f = _rtB -> B_27_39_0 ; } } if (
_rtDW -> SVModulatorPattern2_MODE ) { isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtDW -> UnitDelay_DSTATE_l = _rtB -> B_28_37_0 ; } }
isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Integrator_DSTATE += _rtP -> P_253 * _rtB -> B_33_280_0 ; _rtDW ->
Integrator_DSTATE_d += _rtP -> P_258 * _rtB -> B_33_290_0 ; _rtDW ->
Integrator_DSTATE_l += _rtP -> P_266 * _rtB -> B_33_270_0 ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID7 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) {
B_graduation_project_prototype_collect_4_T * _rtB ;
DW_graduation_project_prototype_collect_4_T * _rtDW ;
P_graduation_project_prototype_collect_4_T * _rtP ;
XDot_graduation_project_prototype_collect_4_T * _rtXdot ; _rtDW = ( (
DW_graduation_project_prototype_collect_4_T * ) ssGetRootDWork ( S ) ) ;
_rtXdot = ( ( XDot_graduation_project_prototype_collect_4_T * ) ssGetdX ( S )
) ; _rtP = ( ( P_graduation_project_prototype_collect_4_T * ) ssGetModelRtp (
S ) ) ; _rtB = ( ( B_graduation_project_prototype_collect_4_T * )
_ssGetModelBlockIO ( S ) ) ; _rtXdot -> Integrator_CSTATE [ 0 ] = _rtB ->
B_33_190_0 [ 0 ] ; _rtXdot -> Integrator_CSTATE [ 1 ] = _rtB -> B_33_190_0 [
1 ] ; _rtXdot -> Integrator_CSTATE [ 2 ] = _rtB -> B_33_190_0 [ 2 ] ; _rtXdot
-> Integrator_CSTATE [ 3 ] = _rtB -> B_33_190_0 [ 3 ] ; if ( _rtDW ->
Saturation_MODE_k ) { _rtXdot -> Integrator_CSTATE_o = _rtB -> B_1_20_0 ; }
else { ( ( XDot_graduation_project_prototype_collect_4_T * ) ssGetdX ( S ) )
-> Integrator_CSTATE_o = 0.0 ; } _rtXdot -> Rotoranglethetam_CSTATE = _rtB ->
B_33_195_0 ; _rtXdot -> Rotorspeedwm_CSTATE = _rtB -> B_33_194_0 ; _rtXdot ->
integrator_CSTATE = _rtB -> B_33_202_0 ; _rtXdot -> integrator_CSTATE_n =
_rtB -> B_33_204_0 ; _rtXdot -> integrator_CSTATE_g = _rtB -> B_33_206_0 ;
_rtXdot -> integrator_CSTATE_j = _rtB -> B_33_208_0 ; _rtXdot ->
integrator_CSTATE_h = _rtB -> B_33_210_0 ; _rtXdot -> integrator_CSTATE_b =
_rtB -> B_33_212_0 ; _rtXdot -> integrator_CSTATE_o = _rtB -> B_33_216_0 ;
_rtXdot -> integrator_CSTATE_f = _rtB -> B_33_218_0 ; _rtXdot ->
integrator_CSTATE_p = _rtB -> B_33_220_0 ; _rtXdot -> integrator_CSTATE_fq =
_rtB -> B_33_222_0 ; _rtXdot -> Integrator_CSTATE_a = _rtB -> B_33_241_0 ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { __m128d tmp ;
B_graduation_project_prototype_collect_4_T * _rtB ;
DW_graduation_project_prototype_collect_4_T * _rtDW ;
P_graduation_project_prototype_collect_4_T * _rtP ;
ZCV_graduation_project_prototype_collect_4_T * _rtZCSV ; int32_T i ; _rtDW =
( ( DW_graduation_project_prototype_collect_4_T * ) ssGetRootDWork ( S ) ) ;
_rtZCSV = ( ( ZCV_graduation_project_prototype_collect_4_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( (
P_graduation_project_prototype_collect_4_T * ) ssGetModelRtp ( S ) ) ; _rtB =
( ( B_graduation_project_prototype_collect_4_T * ) _ssGetModelBlockIO ( S ) )
; if ( _rtDW -> Saturation_MODE_k ) { _rtZCSV -> Switch_SwitchCond_ZC = _rtB
-> B_1_11_0 ; } else { { ( ( ZCV_graduation_project_prototype_collect_4_T * )
ssGetSolverZcSignalVector ( S ) ) -> Switch_SwitchCond_ZC = 0.0 ; } }
ssCallAccelRunBlock ( S , 33 , 17 , SS_CALL_MDL_ZERO_CROSSINGS ) ; _rtZCSV ->
um1_UprLim_ZC = _rtB -> B_33_163_0 - _rtP -> P_200 ; _rtZCSV -> um1_LwrLim_ZC
= _rtB -> B_33_163_0 - _rtP -> P_201 ; if ( _rtDW -> SVModulatorPattern1_MODE
) { _rtZCSV -> Switch1_SwitchCond_ZC = _rtB -> B_27_12_0 - _rtP -> P_55 ;
_rtZCSV -> RelationalOperator_RelopInput_ZC_i = _rtB -> B_27_22_0 - _rtB ->
B_27_25_0 ; _rtZCSV -> RelationalOperator1_RelopInput_ZC = _rtB -> B_27_22_0
- _rtB -> B_27_28_0 ; _rtZCSV -> RelationalOperator2_RelopInput_ZC_i = _rtB
-> B_27_22_0 - _rtB -> B_27_31_0 ; _rtZCSV ->
RelationalOperator3_RelopInput_ZC = _rtB -> B_27_22_0 - _rtB -> B_27_33_0 ;
_rtZCSV -> RelationalOperator4_RelopInput_ZC = _rtB -> B_27_22_0 - _rtB ->
B_27_35_0 ; _rtZCSV -> RelationalOperator5_RelopInput_ZC = _rtB -> B_27_22_0
- _rtB -> B_27_23_0 ; _rtZCSV -> HitCrossing_Input_ZC = _rtB -> B_27_19_0 -
_rtP -> P_64 ; if ( _rtDW -> HitCrossing_MODE == 0 ) { _rtZCSV ->
HitCrossing_Output_ZC = ( ( _rtB -> B_27_19_0 - _rtP -> P_64 ) * ( real_T )
_rtB -> B_27_38_0 != 0.0 ) ; } else { _rtZCSV -> HitCrossing_Output_ZC =
ssGetT ( S ) - ssGetTimeOfLastOutput ( S ) ; } _rtZCSV ->
Saturation_UprLim_ZC_e = _rtB -> B_27_42_0 - _rtP -> P_66 ; _rtZCSV ->
Saturation_LwrLim_ZC_i = _rtB -> B_27_42_0 - _rtP -> P_67 ; } else { { real_T
* zcsv = & ( ( ( ZCV_graduation_project_prototype_collect_4_T * )
ssGetSolverZcSignalVector ( S ) ) -> Switch1_SwitchCond_ZC ) ; int_T i ; for
( i = 0 ; i < 11 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } if ( _rtDW ->
SVModulatorPattern2_MODE ) { _rtZCSV -> RelationalOperator_RelopInput_ZC =
_rtB -> B_28_24_0 - _rtB -> B_28_13_0 ; _rtZCSV ->
RelationalOperator2_RelopInput_ZC = _rtB -> B_28_24_0 - _rtB -> B_28_27_0 ;
_rtZCSV -> Saturation_UprLim_ZC_c = _rtB -> B_28_1_0 - _rtP -> P_95 ; _rtZCSV
-> Saturation_LwrLim_ZC_p = _rtB -> B_28_1_0 - _rtP -> P_96 ; } else { {
real_T * zcsv = & ( ( ( ZCV_graduation_project_prototype_collect_4_T * )
ssGetSolverZcSignalVector ( S ) ) -> RelationalOperator_RelopInput_ZC ) ;
int_T i ; for ( i = 0 ; i < 4 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } for ( i = 0
; i <= 4 ; i += 2 ) { tmp = _mm_loadu_pd ( & _rtB -> B_33_172_0 [ i ] ) ;
_mm_storeu_pd ( & _rtZCSV -> Saturation_UprLim_ZC [ i ] , _mm_sub_pd ( tmp ,
_mm_set1_pd ( _rtP -> P_202 ) ) ) ; _mm_storeu_pd ( & _rtZCSV ->
Saturation_LwrLim_ZC [ i ] , _mm_sub_pd ( tmp , _mm_set1_pd ( _rtP -> P_203 )
) ) ; } } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 1047518853U ) ; ssSetChecksumVal ( S , 1 , 3055303905U ) ;
ssSetChecksumVal ( S , 2 , 2284915398U ) ; ssSetChecksumVal ( S , 3 ,
1272944498U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != ( SLSize )
sizeof ( DW_graduation_project_prototype_collect_4_T ) ) { static char msg [
256 ] ; sprintf ( msg , "Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof (
DW_graduation_project_prototype_collect_4_T ) ) ; ssSetErrorStatus ( S , msg
) ; } if ( ssGetSizeofGlobalBlockIO ( S ) != ( SLSize ) sizeof (
B_graduation_project_prototype_collect_4_T ) ) { static char msg [ 256 ] ;
sprintf ( msg , "Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof (
B_graduation_project_prototype_collect_4_T ) ) ; ssSetErrorStatus ( S , msg )
; } { int ssSizeofParams ; ssGetSizeofParams ( S , & ssSizeofParams ) ; if (
ssSizeofParams != sizeof ( P_graduation_project_prototype_collect_4_T ) ) {
static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_graduation_project_prototype_collect_4_T ) ) ;
ssSetErrorStatus ( S , msg ) ; } } _ssSetModelRtp ( S , ( real_T * ) &
graduation_project_prototype_collect_4_rtDefaultP ) ; _ssSetConstBlockIO ( S
, & graduation_project_prototype_collect_4_rtInvariant ) ; rt_InitInfAndNaN (
sizeof ( real_T ) ) ; } static void mdlInitializeSampleTimes ( SimStruct * S
) { { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS =
ssGetSFunction ( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; }
slAccRegPrmChangeFcn ( S , mdlOutputsTID7 ) ; } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"

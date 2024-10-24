#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_nxjvkMAWNMdcRzZZdKzTgC" , 17 , 40 } , {
"struct_HojAm3OvRNpWupjoU8kGuE" , 18 , 48 } , {
"struct_lsyqUhLVN2aOBRoFlTuY5B" , 19 , 88 } , {
"struct_7U2Xy3czgmwuE6XJcblrBG" , 20 , 16 } , {
"struct_oelS3oJRN3v85ZyO6rQa7G" , 21 , 112 } , {
"struct_GuZC7YYZUOK5mseIsYVPMB" , 22 , 96 } , {
"struct_eLgyfQcxb2WnpXMf1nKTTD" , 23 , 96 } , { "uint64_T" , 24 , 8 } , {
"int64_T" , 25 , 8 } , { "uint_T" , 26 , 32 } , { "char_T" , 27 , 8 } , {
"uchar_T" , 28 , 8 } , { "time_T" , 29 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_nxjvkMAWNMdcRzZZdKzTgC ) , sizeof (
struct_HojAm3OvRNpWupjoU8kGuE ) , sizeof ( struct_lsyqUhLVN2aOBRoFlTuY5B ) ,
sizeof ( struct_7U2Xy3czgmwuE6XJcblrBG ) , sizeof (
struct_oelS3oJRN3v85ZyO6rQa7G ) , sizeof ( struct_GuZC7YYZUOK5mseIsYVPMB ) ,
sizeof ( struct_eLgyfQcxb2WnpXMf1nKTTD ) , sizeof ( uint64_T ) , sizeof (
int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) ,
sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_nxjvkMAWNMdcRzZZdKzTgC" , "struct_HojAm3OvRNpWupjoU8kGuE" ,
"struct_lsyqUhLVN2aOBRoFlTuY5B" , "struct_7U2Xy3czgmwuE6XJcblrBG" ,
"struct_oelS3oJRN3v85ZyO6rQa7G" , "struct_GuZC7YYZUOK5mseIsYVPMB" ,
"struct_eLgyfQcxb2WnpXMf1nKTTD" , "uint64_T" , "int64_T" , "uint_T" ,
"char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & rtB . lvinmjfvue [ 0 ] ) , 0 , 0 , 696 } , { (
char_T * ) ( & rtB . f031aucpiu ) , 3 , 0 , 4 } , { ( char_T * ) ( & rtB .
bkaifibb5p ) , 8 , 0 , 5 } , { ( char_T * ) ( & rtDW . du1v2hvbvg ) , 0 , 0 ,
69 } , { ( char_T * ) ( & rtDW . owebgbvroi [ 0 ] ) , 11 , 0 , 82 } , { (
char_T * ) ( & rtDW . j2k4ky1xb0 ) , 7 , 0 , 12 } , { ( char_T * ) ( & rtDW .
jktdqo2p05 [ 0 ] ) , 10 , 0 , 64 } , { ( char_T * ) ( & rtDW . i4fon4hhkn ) ,
2 , 0 , 16 } , { ( char_T * ) ( & rtDW . hbt0pci0uu [ 0 ] ) , 8 , 0 , 29 } }
; static DataTypeTransitionTable rtBTransTable = { 9U , rtBTransitions } ;
static DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
AlphaBetaZerotodq0_Alignment ) , 0 , 0 , 1945 } , { ( char_T * ) ( & rtP .
Constant_Value_lmhwhmdz2u ) , 8 , 0 , 9 } , { ( char_T * ) ( & rtP .
Constant_Value_k53mpkuj3j ) , 2 , 0 , 12 } , { ( char_T * ) ( & rtP .
DirectLookUpTablenD_DiagnosticForOutOfRangeInput ) , 3 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 4U , rtPTransitions } ;

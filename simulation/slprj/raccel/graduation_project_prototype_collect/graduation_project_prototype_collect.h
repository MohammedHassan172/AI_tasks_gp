#ifndef RTW_HEADER_graduation_project_prototype_collect_h_
#define RTW_HEADER_graduation_project_prototype_collect_h_
#ifndef graduation_project_prototype_collect_COMMON_INCLUDES_
#define graduation_project_prototype_collect_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "sl_fileio_rtw.h"
#include "simtarget/slSimTgtSlFileioRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "graduation_project_prototype_collect_types.h"
#include <float.h>
#include "mwmathutil.h"
#include "rt_zcfcn.h"
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME graduation_project_prototype_collect
#define NSAMPLE_TIMES (8) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (324) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (28)   
#elif NCSTATES != 28
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T lvinmjfvue [ 4 ] ; real_T e01tql3zqc [ 16 ] ; real_T
oou541cdqq [ 4 ] ; real_T mmzyuzpya5 ; real_T bh5r34wuaf ; real_T lphsusogsg
[ 4 ] ; real_T ll1hepiqdn [ 2 ] ; real_T lbvb3aac5c [ 2 ] ; real_T ijcgfhotzs
[ 4 ] ; real_T gmjkz1ru3e [ 2 ] ; real_T ixygus4gig [ 5 ] ; real_T d4mrz35apo
[ 12 ] ; real_T ljisofhn3l [ 2 ] ; real_T d4cb5huedc [ 2 ] ; real_T
f2h5smzqv0 ; real_T kjuzzavjpl ; real_T lrjennhdrg [ 3 ] ; real_T oos02mulbx
; real_T im2qnp2pzf ; real_T jtcbm2s0cm ; real_T aexbreubkh ; real_T
bxla0ijbnx [ 3 ] ; real_T fhvflvwza1 ; real_T h02nughqqj ; real_T lf3on5hnoi
; real_T pxgtca1lve ; real_T gqf15p1dz0 ; real_T b4oqwejrjm ; real_T
iuzsr2u15r ; real_T iwbarhb2bk ; real_T irn5y20ak4 ; real_T ncggwvkkn3 ;
real_T cvwhe0o4l5 ; real_T nuslqv1hu3 ; real_T k5ynav5c1v ; real_T h1zjrhs5pq
; real_T dkviwiihcv ; real_T c4ge52qtah ; real_T ht15qzeugk ; real_T
j5hf1yjxzh ; real_T earnmg21lv ; real_T ph3fm2po3m ; real_T lwgehlowol ;
real_T eottc0nam0 ; real_T kenqtxpydf ; real_T aslmadskrn ; real_T a4uuznjjc2
; real_T niohbq3yce ; real_T dffy4sxqlu ; real_T nckd2vp2ym ; real_T
fjlaoktgvw ; real_T pgmwnifwz3 ; real_T iuj5gmvi4z ; real_T kq3a25vp1t ;
real_T nkqijph0dz ; real_T hprqcepoik ; real_T hvffwddyll ; real_T dlvtusb3ds
; real_T pw0ttdltfa ; real_T kq3rj1qk1x ; real_T f10c2vxlm4 ; real_T
mm3qy5yws1 ; real_T fkcxmmbe1m ; real_T nfg250xpij ; real_T lega1ivx25 ;
real_T e3txj5nydu ; real_T bb1wxb01g1 ; real_T cmpudvfmfg ; real_T j3w2ppirfg
; real_T otpmxpc0wg ; real_T fn55vobl5y ; real_T ppgcpq3dna ; real_T
ft0ojvmr3d ; real_T jtybpuhqxe ; real_T o3pcbr3dln ; real_T jou3thgpuf ;
real_T pbcsdqvwkh ; real_T b5ye5zig1f ; real_T harp5juvjj ; real_T m4flle1xhi
; real_T dkl2brqq4l ; real_T nc4x0kjslh ; real_T aielcdsx3w ; real_T
jnri2xzqr1 ; real_T jg2b2dwyto ; real_T huihntarbz ; real_T oaoknim5qe ;
real_T mrqhtw4shc ; real_T izyhdgeynx ; real_T gf0fpqrdqz ; real_T cvum4m4ht1
; real_T hjnbkrerrl ; real_T cerlaaotg0 ; real_T catlonbcbi ; real_T
l0cxlqoy1l ; real_T nuwd3levpa ; real_T mzaijat5sc ; real_T az44tiyauw ;
real_T cnhfoscleb ; real_T isbb5qelgc ; real_T p1eir1uv2l ; real_T iv21gxj12o
; real_T oedc1fdrfk ; real_T ihat2vhadn ; real_T fkv0bugyi2 ; real_T
arksco3tqi ; real_T jt2jb5lz2j ; real_T ptdm3aefua ; real_T mjybhqhfeo ;
real_T it5w03bouy ; real_T czqd02arxc ; real_T ccuzfsqrqm ; real_T onk2xfeqbq
; real_T ekqf4q1gna ; real_T nycjraukwt ; real_T psd5sjin1n ; real_T
iigfhvktts ; real_T g04fxja0ze ; real_T ls5tb5izhr ; real_T di1q4wwsjy ;
real_T mgj5ibadgb ; real_T aafngiz0b5 ; real_T ne44lffdfq ; real_T fqpkborrky
; real_T a1bn0vlzu1 ; real_T bkjh3cqkl2 [ 2 ] ; real_T lplpxpfnwl [ 4 ] ;
real_T ibgue2cpyy [ 2 ] ; real_T cug10ebvvj ; real_T dz1tf2zjkk [ 2 ] ;
real_T f34xubnxxx ; real_T kximrirdrr [ 19 ] ; real_T iwb53udxj5 ; real_T
ep5va441s2 [ 2 ] ; real_T eeupqxoz5b ; real_T ebqopdsodw ; real_T plbonf3utg
; real_T mbw2hxuhtx ; real_T f2ugkkglxw ; real_T j4fgww4j5y ; real_T
lcbaxswo3g ; real_T i1xraoyix0 ; real_T be1pucxfq1 ; real_T hg1vb33xgp ;
real_T lgfuqct11r ; real_T o2afpo1bhs ; real_T ppupegzif3 ; real_T keuka0tnsj
[ 3 ] ; real_T kj0to1gwpp ; real_T iey5kdl1ol ; real_T lqot4te0ia ; real_T
cljjziqnd4 [ 6 ] ; real_T bavsokmria [ 6 ] ; real_T lqblxwjpsf [ 6 ] ; real_T
mv5do4ms5k [ 16 ] ; real_T pn00oodbzx [ 16 ] ; real_T jbjxf4fbvv [ 16 ] ;
real_T e0iay3fvgj [ 4 ] ; real_T kqyqit0nkm [ 4 ] ; real_T p5fuazzeck [ 4 ] ;
real_T nqpue0vrt0 ; real_T hexyp2merm ; real_T cesjksggsq ; real_T gix1mhi00r
; real_T jgoahoiiwq ; real_T noaevnvad5 ; real_T jamzcwmmle ; real_T
np1alqdz3a ; real_T oitq0dyyxq ; real_T h0jnp5f2jt ; real_T i2logf3b0u ;
real_T kslnozwwn1 [ 3 ] ; real_T mc3efl4ere [ 3 ] ; real_T ceokmgrhue ;
real_T a0ej4izxmc ; real_T cz5sft0noc ; real_T g3vgstm4g3 ; real_T gezi3je1ax
[ 2 ] ; real_T ajo05qm4im [ 3 ] ; real_T igcmbgwamd ; real_T ptcp5bkpa4 ;
real_T oucx2re132 ; real_T fi4qdoampk ; real_T doqjlf042m ; real_T os2nnlp2pp
; real_T df0cmfia1b ; real_T a4dnylvh3l ; real_T iyg2tqjmdz ; real_T
d1pbnqivxe ; real_T izhprxpjsm ; real_T oxh2yi0xax ; real_T ezgqz4jw0k ;
real_T pm50du5olg ; real_T fzzwpeohtj ; real_T gg2xbhafea ; real_T frvvone4ou
; real_T ccuoohcoby ; real_T nbdtcwkcia ; real_T k4tiewitj2 ; real_T
chi5cvjtrg ; real_T c1fvynnlgz ; real_T pfyk5opzbk ; real_T l3ac5c0agd ;
real_T cesnq2edok ; real_T lhh0icro53 ; real_T ixb5i1gxbi ; real_T pdzungbvef
; real_T f1jaub25mr ; real_T grfglidrso ; real_T jigs1ibcqf ; real_T
crfhlgloss ; real_T dpjx2gq00q ; real_T arflpyz22b ; real_T e5ebrc2y0h ;
real_T ijmxijodjl ; real_T axajzwngcd ; real_T dx2akq1xtx ; real_T o0xe05teth
; real_T it2dxs52rp ; real_T ct2rnibmo1 ; real_T anvn3apjgt ; real_T
euxny4cm0f ; real_T iqd12ao5xp ; real_T daadcvq5ip ; real_T hj3pppg4ca ;
real_T o3ucuznyew ; real_T d5jm5jif10 ; real_T oayglxn5na ; real_T ne01ep3k2r
; real_T ehh4nt3lzv ; real_T fk2cnu24qv [ 3 ] ; real_T jmyxmowcn2 ; real_T
nnzbfrntvj ; real_T ofc0eizjlw ; real_T d0buvrjicm ; real_T o2b21cd15g ;
real_T pu4jkio2sc ; real_T l0fe2bbef5 ; real_T gqd3i5ascl ; real_T bj2rkj3gai
; real_T cla100jmpw ; real_T noq4u5d0w3 ; real_T hwncbff0ek ; real_T
jur3xn53mn ; real_T mywbrwb1sh ; real_T hh2tjxynco ; real_T jvh3y2egpp [ 3 ]
; real_T mfd5oml2yu [ 3 ] ; real_T c1k1izbcfq ; real_T dfe30dxipq ; real_T
avkcjx0v1l ; real_T itqccb1njg ; real_T jgpgocp4rw ; real_T iqwmzgljmq [ 4 ]
; real_T maj4ja5anq [ 16 ] ; real_T pvcnmwvky5 [ 16 ] ; real_T mi0ekbk5ob [
16 ] ; real_T knm2iibxks ; real_T lap03yb1fu [ 4 ] ; real_T ge3kqztqhy [ 16 ]
; real_T kwvb2tc1zn [ 16 ] ; real_T lupb5ha3ql [ 16 ] ; real_T i3l5pe4ri1 ;
real_T bby3homfma ; real_T azpq5sqbrr ; real_T g423dacc0p ; real_T fcahh42ks4
[ 16 ] ; real_T lwve3sazoa ; real_T kofpvmyce4 ; real_T ibo3pkvy5m ; real_T
fvrzvsctu4 ; real_T p5qlvh0c4k [ 16 ] ; real_T fgelopovmv [ 16 ] ; real_T
jbmdw2obhh ; real_T m5tmssdiaa ; real_T kdz3ok45hn ; real_T jbrkgvertf ;
real_T h4ii1v3x2l ; real_T hhv3om52d4 ; real_T hq1hjdyctc ; real_T hr21gsmfog
; real_T iszvqzgoks ; real_T igw1banhll ; real_T b40g41vhmi ; real_T
gstors223z ; real_T hcisopw4hm ; real_T g1znqce5i5 ; real_T o35ndtztd5 ;
real_T h2x44eodmu ; real_T pga5vgtdul ; real_T jqstbgs3lg ; real_T cykvppzmth
; real_T ksughnfgxc ; real_T epnsrer0xl ; real_T h5yhxbn4px ; real_T
fbtrroc4tc ; real_T j05g4trf2p ; real_T apdoomhepj ; real_T en4nk1s0dh [ 3 ]
; real_T pgtvimm3it ; real_T l3gd1q0nba [ 2 ] ; real_T lagrdxsyvj [ 2 ] ;
real_T gmgalikong ; real_T acqoql0tnx [ 2 ] ; real_T izag1mey0r ; real_T
bhdtmizrl1 ; real_T c5t4qjdezn ; real_T bu3w4zj2id [ 16 ] ; real_T ittgezz3ha
[ 16 ] ; real_T axtcj0djba [ 16 ] ; real_T gsiib3kxqi [ 16 ] ; real_T
j43pra0fjc [ 16 ] ; real_T ijuzr44wbo ; real_T eiu3o0vwjw ; real_T nnql2kngph
; uint8_T f031aucpiu ; uint8_T ftwcud3ono ; uint8_T h5tueg3xan ; uint8_T
p1kjyoe3no ; boolean_T bkaifibb5p ; boolean_T g4gzzvmdow ; boolean_T
ps552cz0bj ; boolean_T cutsqo2kl1 ; boolean_T jh0n0dq2us ; } B ; typedef
struct { real_T du1v2hvbvg ; real_T e0u0asznho ; real_T b2dacjocdr ; real_T
i0jbdvkbx0 [ 3 ] ; real_T pufhfxpv1p ; real_T jrbhtlrgas ; real_T j1oehdl2f1
; real_T fraawjib0f ; real_T k1g2nm455a ; real_T cq12wnfoxn ; real_T
ic2wcvtu5a ; real_T jfzlwzi0iz ; real_T a4g2escexa ; real_T hryvoxr4wz ;
real_T fv1xx0nem5 ; real_T ghhxhjes50 ; real_T kyd3w4m2eh ; real_T eqjsyt5ld3
; real_T ixu4rjhj2e ; real_T l2b153duoy ; real_T ic2hcp35nf ; real_T
flxxatm4gm ; real_T namdfgryp2 ; real_T i3i21ovleu ; real_T naspze5xxr ;
real_T a3cpitdc0k ; real_T fxi5ilqfou ; real_T mil5dps1ol ; real_T metd1wwcs3
; real_T mtguitsqxp [ 16 ] ; real_T mlixcbtphu [ 2 ] ; struct { real_T
modelTStart ; } mrgf4u0u0f ; struct { real_T modelTStart ; } auuqebsxd0 ;
struct { real_T modelTStart ; } bhprvdqi3o ; struct { real_T modelTStart ; }
ll5y2cz1nt ; struct { real_T modelTStart ; } ddu11ymmyx ; struct { real_T
modelTStart ; } dnl4sdibbm ; struct { real_T modelTStart ; } hm3pqjey05 ;
struct { real_T modelTStart ; } ekiip4njdx ; struct { real_T modelTStart ; }
cdcfu5drwx ; struct { real_T modelTStart ; } oeo4w5yxpy ; struct { real_T
modelTStart ; } miy0ueupod ; struct { real_T modelTStart ; } k3xkemqtve ;
struct { real_T modelTStart ; } l1f3uh0bgg ; struct { real_T modelTStart ; }
emvpkv3udj ; struct { real_T modelTStart ; } kdkvmwcsfx ; struct { real_T
modelTStart ; } bat01xclmg ; struct { real_T modelTStart ; } jpkmtezkuc ;
struct { real_T modelTStart ; } btoraxpm1u ; struct { real_T modelTStart ; }
n5md3zt320 ; struct { real_T modelTStart ; } kn3ylhkvio ; void * owebgbvroi [
22 ] ; struct { void * LoggedData ; } b3zjwjkaja ; struct { void * LoggedData
; } fdkvc5213v ; struct { void * LoggedData ; } no1rjofoxh ; struct { void *
AQHandles ; } asrl3zgnd5 ; struct { void * TUbufferPtrs [ 2 ] ; } aaldu02fuj
; struct { void * TUbufferPtrs [ 2 ] ; } do3htsussl ; struct { void *
TUbufferPtrs [ 2 ] ; } oguvtkpr5i ; struct { void * TUbufferPtrs [ 2 ] ; }
nmj2tkdsme ; struct { void * TUbufferPtrs [ 2 ] ; } pipiukyrp5 ; struct {
void * TUbufferPtrs [ 2 ] ; } a5v1pmlkch ; struct { void * TUbufferPtrs [ 2 ]
; } jeaxciyupa ; struct { void * TUbufferPtrs [ 2 ] ; } mmcyygpn5c ; struct {
void * TUbufferPtrs [ 2 ] ; } fn5njtud3k ; struct { void * TUbufferPtrs [ 2 ]
; } bgl1l5zbp3 ; struct { void * TUbufferPtrs [ 2 ] ; } buvdxs3glp ; struct {
void * TUbufferPtrs [ 2 ] ; } pzqn1pwxdv ; struct { void * TUbufferPtrs [ 2 ]
; } ftfzsjf14l ; struct { void * TUbufferPtrs [ 2 ] ; } kv1wpwoa1r ; struct {
void * TUbufferPtrs [ 2 ] ; } dlrggb0x4h ; struct { void * TUbufferPtrs [ 2 ]
; } cihvjcgtmq ; struct { void * TUbufferPtrs [ 2 ] ; } i2vkb03gvd ; struct {
void * TUbufferPtrs [ 2 ] ; } kqegvw2kxe ; struct { void * TUbufferPtrs [ 2 ]
; } k5kapv1y3t ; struct { void * TUbufferPtrs [ 2 ] ; } dtfpqwal1v ; struct {
void * FilePtr ; } jqxdpry2y3 ; struct { void * FilePtr ; } ebx24y5dsc ;
struct { void * LoggedData ; } l3e4mbismb ; struct { void * LoggedData ; }
evixqybsp0 ; struct { void * LoggedData ; } adeqebxx1p ; struct { void *
LoggedData ; } oednkfytpz ; struct { void * LoggedData ; } c4btfncyvu ;
struct { void * LoggedData [ 2 ] ; } f52qss2jdm ; struct { void * LoggedData
; } damavux25x ; struct { void * LoggedData ; } oto5xl2zxz ; struct { void *
LoggedData ; } lu5fgy0vfe ; struct { void * AQHandles ; } egdhng13lm ; struct
{ void * AQHandles ; } n3cujsjdb5 ; struct { void * AQHandles ; } h5tfxoguk1
; struct { void * AQHandles ; } dsfk0g1moz ; uint32_T j2k4ky1xb0 ; uint32_T
ji1lxxq3m1 ; uint32_T fp2fqzhgk4 ; uint32_T n24juxwtsr ; uint32_T fp4z1l5nll
; uint32_T eht40e0hfx ; uint32_T mtkzorxtel ; uint32_T fsdag0jhtk ; uint32_T
eddz3cpobs ; uint32_T erl03hoqhv ; uint32_T iztbp0q2mg ; uint32_T nuozkzchae
; int_T jktdqo2p05 [ 23 ] ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } espw1n3ocv ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } e0lth3mqr5 ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } eljw4xkpep ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
beogffj2pr ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } jpq1rvrcuf ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
j4knlccsub ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } lmw2rqbsqi ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
pzacfj5pjs ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } haqlcwgigq ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
p3mgqpae3s ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } h05wvsxbrf ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
asmjfkl13c ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } duivj5k3zo ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
bdnqrfyrso ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } pii33j4yi1 ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
ckfri3vr5q ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } laru0mwqws ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
gahjk5nfhc ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } lffnw0xkgy ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
msliuldepb ; struct { int_T Count ; int_T Decimation ; } abfdxenptr ; struct
{ int_T Count ; int_T Decimation ; } g05xu3lfgz ; int_T kuwusb4rke [ 7 ] ;
int_T i15ri0ocwu ; int_T ihoqop1itl [ 6 ] ; int_T pdq11ohhux ; int_T
bfqma4lbuh ; int_T gphckewbub ; int_T epdduk5uq1 ; int_T ji4ndq0nlh ; int8_T
i4fon4hhkn ; int8_T dshww2ksmw ; int8_T bknwykhitr ; int8_T fyfmnpnpzc ;
int8_T bxzlkhns5z ; int8_T isbiz5muob ; int8_T dasq5tnemw ; int8_T ap1juwl2qn
; int8_T a3zsdjp5tt ; int8_T b2hpbhjbpy ; int8_T h3l00nnmol ; int8_T
mvcx2ogzac ; int8_T if4lwsfk4b ; int8_T nvqosetwr2 ; int8_T pxnqmbah0h ;
int8_T ijqebiabyh ; boolean_T hbt0pci0uu [ 3 ] ; boolean_T frt02lgh11 ;
boolean_T ctk2dca5ut ; boolean_T ng44jhuagl ; boolean_T jca0fw0zsn ;
boolean_T gqcctre23i ; boolean_T agesp404rx ; boolean_T aodqfxsue5 ;
boolean_T bpfhsczm3w ; boolean_T mo4vk04lvk ; boolean_T ma3mxtjbyf ;
boolean_T hc5q5crbkz ; boolean_T k5exhrkzir ; boolean_T b2ccvte2tp ;
boolean_T m4djucw35b ; boolean_T atadooohmx ; boolean_T h0liskrpof ;
boolean_T fju41030la ; boolean_T imx4zh41y5 ; boolean_T o2ytysdmw5 ;
boolean_T mo1x5xhxu3 ; boolean_T gkt3pogpfv ; boolean_T gnfam3ufq4 ;
boolean_T cfeegxhpsn ; boolean_T cczrjlyqmw ; boolean_T dxmpvxefca ;
boolean_T elcmlqoq10 ; } DW ; typedef struct { real_T nlbeaactnt [ 4 ] ;
real_T awzwkhop24 ; real_T h5oxxd1oef ; real_T l5qaetv0p3 ; real_T hrqscwgvd0
; real_T fp1ic3b3ts ; real_T a5szub0c05 ; real_T ddcye1rfpt ; real_T
iupcdqc3c4 ; real_T mmsrhsaozp ; real_T kzd1n4ldxk ; real_T jlajkdvmi1 ;
real_T fhb4qkipml ; real_T pfsszr10ch ; real_T jf52bt50kz ; real_T gzkzypvrfd
; real_T c2zvsg4r4k ; real_T ptmjlebedy ; real_T p2jw3nx11h ; real_T
mc00iuwzcx ; real_T mbfs1x5iwl ; real_T ew120ihmc0 ; real_T gedzd3nhor ;
real_T g3zkyxroqx ; real_T evgvrbo4kl ; } X ; typedef struct { real_T
nlbeaactnt [ 4 ] ; real_T awzwkhop24 ; real_T h5oxxd1oef ; real_T l5qaetv0p3
; real_T hrqscwgvd0 ; real_T fp1ic3b3ts ; real_T a5szub0c05 ; real_T
ddcye1rfpt ; real_T iupcdqc3c4 ; real_T mmsrhsaozp ; real_T kzd1n4ldxk ;
real_T jlajkdvmi1 ; real_T fhb4qkipml ; real_T pfsszr10ch ; real_T jf52bt50kz
; real_T gzkzypvrfd ; real_T c2zvsg4r4k ; real_T ptmjlebedy ; real_T
p2jw3nx11h ; real_T mc00iuwzcx ; real_T mbfs1x5iwl ; real_T ew120ihmc0 ;
real_T gedzd3nhor ; real_T g3zkyxroqx ; real_T evgvrbo4kl ; } XDot ; typedef
struct { boolean_T nlbeaactnt [ 4 ] ; boolean_T awzwkhop24 ; boolean_T
h5oxxd1oef ; boolean_T l5qaetv0p3 ; boolean_T hrqscwgvd0 ; boolean_T
fp1ic3b3ts ; boolean_T a5szub0c05 ; boolean_T ddcye1rfpt ; boolean_T
iupcdqc3c4 ; boolean_T mmsrhsaozp ; boolean_T kzd1n4ldxk ; boolean_T
jlajkdvmi1 ; boolean_T fhb4qkipml ; boolean_T pfsszr10ch ; boolean_T
jf52bt50kz ; boolean_T gzkzypvrfd ; boolean_T c2zvsg4r4k ; boolean_T
ptmjlebedy ; boolean_T p2jw3nx11h ; boolean_T mc00iuwzcx ; boolean_T
mbfs1x5iwl ; boolean_T ew120ihmc0 ; boolean_T gedzd3nhor ; boolean_T
g3zkyxroqx ; boolean_T evgvrbo4kl ; } XDis ; typedef struct { real_T
nlbeaactnt [ 4 ] ; real_T awzwkhop24 ; real_T h5oxxd1oef ; real_T l5qaetv0p3
; real_T hrqscwgvd0 ; real_T fp1ic3b3ts ; real_T a5szub0c05 ; real_T
ddcye1rfpt ; real_T iupcdqc3c4 ; real_T mmsrhsaozp ; real_T kzd1n4ldxk ;
real_T jlajkdvmi1 ; real_T fhb4qkipml ; real_T pfsszr10ch ; real_T jf52bt50kz
; real_T gzkzypvrfd ; real_T c2zvsg4r4k ; real_T ptmjlebedy ; real_T
p2jw3nx11h ; real_T mc00iuwzcx ; real_T mbfs1x5iwl ; real_T ew120ihmc0 ;
real_T gedzd3nhor ; real_T g3zkyxroqx ; real_T evgvrbo4kl ; } CStateAbsTol ;
typedef struct { real_T nlbeaactnt [ 4 ] ; real_T awzwkhop24 ; real_T
h5oxxd1oef ; real_T l5qaetv0p3 ; real_T hrqscwgvd0 ; real_T fp1ic3b3ts ;
real_T a5szub0c05 ; real_T ddcye1rfpt ; real_T iupcdqc3c4 ; real_T mmsrhsaozp
; real_T kzd1n4ldxk ; real_T jlajkdvmi1 ; real_T fhb4qkipml ; real_T
pfsszr10ch ; real_T jf52bt50kz ; real_T gzkzypvrfd ; real_T c2zvsg4r4k ;
real_T ptmjlebedy ; real_T p2jw3nx11h ; real_T mc00iuwzcx ; real_T mbfs1x5iwl
; real_T ew120ihmc0 ; real_T gedzd3nhor ; real_T g3zkyxroqx ; real_T
evgvrbo4kl ; } CXPtMin ; typedef struct { real_T nlbeaactnt [ 4 ] ; real_T
awzwkhop24 ; real_T h5oxxd1oef ; real_T l5qaetv0p3 ; real_T hrqscwgvd0 ;
real_T fp1ic3b3ts ; real_T a5szub0c05 ; real_T ddcye1rfpt ; real_T iupcdqc3c4
; real_T mmsrhsaozp ; real_T kzd1n4ldxk ; real_T jlajkdvmi1 ; real_T
fhb4qkipml ; real_T pfsszr10ch ; real_T jf52bt50kz ; real_T gzkzypvrfd ;
real_T c2zvsg4r4k ; real_T ptmjlebedy ; real_T p2jw3nx11h ; real_T mc00iuwzcx
; real_T mbfs1x5iwl ; real_T ew120ihmc0 ; real_T gedzd3nhor ; real_T
g3zkyxroqx ; real_T evgvrbo4kl ; } CXPtMax ; typedef struct { real_T
nvfgdrcm3d [ 7 ] ; real_T mfiuwowy3p ; real_T a4e2iqoazj ; real_T pdsx5rsffq
[ 6 ] ; real_T ltvzs5fo0b [ 6 ] ; real_T ilpkjvwaos ; real_T o3umnsws1t [ 3 ]
; real_T kdsaixe1s4 ; real_T kbl1k2wozu ; real_T hx1tywj2j0 ; real_T
i3ipwdcos0 ; real_T cnvee1g5u4 ; real_T nblghsd1e1 ; real_T kicpzmrogm ;
real_T nv2otttesi ; real_T i5zoci5dje ; real_T a35wvnz01u ; real_T opa31zezsu
; real_T mmtg5zedss ; real_T mf5l14vytf ; real_T oij3avyzol ; real_T
kplh10tr1v ; real_T ceijmaoe5e ; real_T a5gkeztqku ; } ZCV ; typedef struct {
ZCSigState c1ygdd0f50 ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T AlphaBetaZerotodq0_Alignment ;
real_T dq0toAlphaBetaZero_Alignment ; real_T DCVoltageSource_Amplitude ;
real_T SVPWMGenerator2Level_Fc ; real_T PIDController_I ; real_T
PIDController1_I ; real_T PIDController2_I ; real_T
PIDController1_InitialConditionForIntegrator ; real_T
PIDController_InitialConditionForIntegrator ; real_T
PIDController2_InitialConditionForIntegrator ; real_T
SVPWMGenerator2Level_InputType ; real_T PIDController1_LowerSaturationLimit ;
real_T PIDController_LowerSaturationLimit ; real_T
PIDController2_LowerSaturationLimit ; real_T PWMGenerator2Level_MinMax [ 2 ]
; real_T PIDController1_P ; real_T PIDController_P ; real_T PIDController2_P
; real_T SVPWMGenerator2Level_SwitchingPattern ; real_T
PIDController1_UpperSaturationLimit ; real_T
PIDController_UpperSaturationLimit ; real_T
PIDController2_UpperSaturationLimit ; real_T CompareToConstant_const ; real_T
CompareToConstant_const_mvnovccirx ; real_T CompareToConstant1_const ; real_T
CompareToConstant_const_cslc2daqzm ; real_T
CompareToConstant1_const_fyrikjwbdg ; real_T Linv_Y0 ; real_T RLinv_Y0 ;
real_T Lm_Y0 ; real_T Integrator_IC ; real_T uDLookupTable_tableData [ 2 ] ;
real_T uDLookupTable_bp01Data [ 2 ] ; real_T uTT1e6s_Gain ; real_T
Constant1_Value ; real_T u2_Value [ 2 ] ; real_T u1_Value [ 16 ] ; real_T
u5_Value [ 16 ] ; real_T u1_Value_ck1yzahv2t [ 2 ] ; real_T
u1_Value_l1ozppsjwf [ 16 ] ; real_T vqrvdr_Y0 ; real_T vqsvds_Y0 ; real_T
vqrvdr_Y0_igenqlxbjq ; real_T vqsvds_Y0_jyddusdce4 ; real_T
vqrvdr_Y0_ci1nok5evm ; real_T vqsvds_Y0_folfbhqlef ; real_T irairb_Y0 ;
real_T isaisb_Y0 ; real_T irairb_Y0_aqn0f44xqv ; real_T isaisb_Y0_dys2dzsaka
; real_T irairb_Y0_mhfktw5wtk ; real_T isaisb_Y0_bklcb1cddp ; real_T
sinbetacosbetasinthcosth_Y0 ; real_T W_Y0 ; real_T Gain2_Gain ; real_T
web_psb_Gain ; real_T u3_Value [ 16 ] ; real_T we_Value ; real_T
sinthrcosthr_Y0 ; real_T W_Y0_iyd2ain4kp ; real_T Gain1_Gain ; real_T
Constant_Value [ 2 ] ; real_T u1_Value_cmhxktmqup [ 16 ] ; real_T
sinthrcosthr_Y0_max1mqskqy ; real_T W_Y0_hsnegedwrg ; real_T Gain3_Gain ;
real_T Constant_Value_jvcgu1tp21 [ 2 ] ; real_T u4_Value [ 16 ] ; real_T
Gain_Gain ; real_T Gain_Gain_ntv32ixjsb ; real_T Gain_Gain_kdjuq5oq42 ;
real_T Gain_Gain_g2icy1o3o0 ; real_T Gain_Gain_l54bghzo2b ; real_T
Gain_Gain_nh05nfscsi ; real_T Gain_Gain_lwuakiuuwu ; real_T
Gain_Gain_cajgqbeys5 ; real_T Gain_Gain_prdbqwyfl2 ; real_T
Gain_Gain_p0mgrtime2 ; real_T Pulses_Y0 ; real_T
uDLookupTable_tableData_b0ryx234pb [ 6 ] ; real_T
uDLookupTable_bp01Data_g1ex22b024 [ 6 ] ; real_T Switch1_Threshold ; real_T
Constant4_Value ; real_T Constant2_Value ; real_T uib2_Gain ; real_T u4_Gain
; real_T u2_Gain ; real_T u2_Gain_ce3c4l405s ; real_T u2_Gain_pvrujwybik ;
real_T HitCrossing_Offset ; real_T UnitDelay_InitialCondition ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
DirectLookUpTablenD_table [ 126 ] ; real_T Constant_Value_b2vvpg1mtn ; real_T
Constant1_Value_hfyugvi3wh ; real_T Constant2_Value_nyckbncwg1 ; real_T
Constant8_Value ; real_T Constant1_Value_etg4zkjytm ; real_T
Constant2_Value_ntcdbysvye ; real_T Constant3_Value ; real_T Constant7_Value
; real_T Pulses_Y0_e01g3l1335 ; real_T
LookUpTableDeterminethesectorofUbasedonalpharad_tableData [ 6 ] ; real_T
LookUpTableDeterminethesectorofUbasedonalpharad_bp01Data [ 6 ] ; real_T
uDLookupTable_tableData_mhqtrk0ebo [ 6 ] ; real_T
uDLookupTable_bp01Data_o3m2ufmxqy [ 6 ] ; real_T uDLookupTable1_tableData [ 6
] ; real_T uDLookupTable1_bp01Data [ 6 ] ; real_T uDLookupTable2_tableData [
6 ] ; real_T uDLookupTable2_bp01Data [ 6 ] ; real_T uDLookupTable3_tableData
[ 6 ] ; real_T uDLookupTable3_bp01Data [ 6 ] ; real_T gain_Gain ; real_T
Constant3_Value_lq5snj5m3d ; real_T Constant4_Value_atiw15czaq ; real_T
uib1_Gain ; real_T uDLookupTable_tableData_kmohmp0ajl [ 3 ] ; real_T
uDLookupTable_bp01Data_efxgdt3xpj [ 3 ] ; real_T Constant2_Value_gsdutk4fzo ;
real_T Saturation_UpperSat_k1rxbymieb ; real_T Saturation_LowerSat_mv1pu1c1rk
; real_T UnitDelay_InitialCondition_oiissgtaqz ; real_T
Constant1_Value_gwx2lfu1ss ; real_T Constant2_Value_amq3dw2414 ; real_T dq_Y0
[ 2 ] ; real_T dq_Y0_beojh2gwon [ 2 ] ; real_T alpha_beta_Y0 [ 2 ] ; real_T
alpha_beta_Y0_e2bzecmzah [ 2 ] ; real_T Gain_Gain_dy4nztqf1d ; real_T
Gain_Gain_njlxfjpdzs ; real_T Gain_Gain_ae2yavqvxr ; real_T
Gain_Gain_oeci4mtbun ; real_T Gain_Gain_m3ggziievm ; real_T
Gain_Gain_eipj0ixpdz ; real_T Gain_Gain_nryawodyby ; real_T
Gain_Gain_m5k1emz3of ; real_T Gain_Gain_cfbswsdzpb ; real_T
Gain_Gain_nl2p143gvq ; real_T Constant1_Value_kzsvvkd5vs ; real_T
Constant1_Value_aw0ko2cv3j ; real_T Constant1_Value_fzkk0bnp3j ; real_T
Integrator_IC_fibe0df1qk [ 4 ] ; real_T Switch_Threshold ; real_T
Rotoranglethetam_IC ; real_T Rotorspeedwm_IC ; real_T ib_Gain ; real_T
GainVr_Vs1_Gain [ 2 ] ; real_T StateSpace_P1_Size [ 2 ] ; real_T
StateSpace_P1 [ 220 ] ; real_T StateSpace_P2_Size [ 2 ] ; real_T
StateSpace_P2 [ 4 ] ; real_T StateSpace_P3_Size [ 2 ] ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 880 ] ; real_T
StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 12 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 [ 6 ] ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 [ 6 ] ; real_T
StateSpace_P8_Size [ 2 ] ; real_T StateSpace_P8 [ 6 ] ; real_T
StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ; real_T StateSpace_P10_Size
[ 2 ] ; real_T StateSpace_P10 ; real_T u1_Gain [ 2 ] ; real_T up_Gain ;
real_T Gain_Gain_cxgdozlfu4 [ 3 ] ; real_T Gain_Gain_cxvgc2lug0 ; real_T
donotdeletethisgain_Gain ; real_T donotdeletethisgain_Gain_efmuktoi1o ;
real_T donotdeletethisgain_Gain_a1h5gsmnfr ; real_T Kv1_Gain ; real_T
UniformRandomNumber1_Minimum ; real_T UniformRandomNumber1_Maximum ; real_T
UniformRandomNumber1_Seed ; real_T UniformRandomNumber_Minimum ; real_T
UniformRandomNumber_Maximum ; real_T UniformRandomNumber_Seed ; real_T
integrator_IC ; real_T TransportDelay_Delay ; real_T
TransportDelay_InitOutput ; real_T K1_Value ; real_T Memory_InitialCondition
; real_T integrator_IC_pxswvytdjq ; real_T TransportDelay_Delay_iftrtv2wmm ;
real_T TransportDelay_InitOutput_p4uagmfvhi ; real_T K1_Value_ov3o541dnz ;
real_T Memory_InitialCondition_dfom2ivv2x ; real_T RadDeg_Gain ; real_T
integrator_IC_daivqm451l ; real_T TransportDelay_Delay_m3jer2omf0 ; real_T
TransportDelay_InitOutput_khq4eszvey ; real_T K1_Value_bxuatcgplg ; real_T
Memory_InitialCondition_b1tbqmdmu3 ; real_T integrator_IC_lzn3twtmfq ; real_T
TransportDelay_Delay_pxdogt32xz ; real_T TransportDelay_InitOutput_fxl4x2td5w
; real_T K1_Value_pyzcnp1pqw ; real_T Memory_InitialCondition_b51wvn1d1u ;
real_T RadDeg_Gain_pbfubgjltx ; real_T integrator_IC_edp35d5ha1 ; real_T
TransportDelay_Delay_hlxb35zgen ; real_T TransportDelay_InitOutput_l33qxj3afz
; real_T K1_Value_nx2o2avvt1 ; real_T Memory_InitialCondition_dhreheujjz ;
real_T integrator_IC_l4ka2yceym ; real_T TransportDelay_Delay_jzjbaa5ctl ;
real_T TransportDelay_InitOutput_nzlobmll1z ; real_T K1_Value_db0rzpphrj ;
real_T Memory_InitialCondition_fs1cnfterh ; real_T RadDeg_Gain_lmooslmjbr ;
real_T integrator_IC_ldr34cyjtu ; real_T TransportDelay_Delay_hrdpjxjsd4 ;
real_T TransportDelay_InitOutput_igffedrstf ; real_T K1_Value_bxl5tjjpfj ;
real_T Memory_InitialCondition_c2ko1vmglg ; real_T integrator_IC_ncyu5pbaoa ;
real_T TransportDelay_Delay_pc4gepyzmt ; real_T
TransportDelay_InitOutput_lqybx2ceon ; real_T K1_Value_c1qrkgo1fj ; real_T
Memory_InitialCondition_b42g11iz1j ; real_T RadDeg_Gain_iw201mxnns ; real_T
integrator_IC_hqxshbmp2i ; real_T TransportDelay_Delay_girtnzjasw ; real_T
TransportDelay_InitOutput_keykqs4qqg ; real_T K1_Value_ivxx02dqsm ; real_T
Memory_InitialCondition_gojis3bbhc ; real_T integrator_IC_l5ejhzps5h ; real_T
TransportDelay_Delay_ismcjoc5z4 ; real_T TransportDelay_InitOutput_ljxb0g2t0w
; real_T K1_Value_f1lpdnkhvu ; real_T Memory_InitialCondition_jf304lqcyd ;
real_T RadDeg_Gain_nld5rtcto2 ; real_T integrator_IC_im3nxf22pz ; real_T
TransportDelay_Delay_li0srt1jom ; real_T TransportDelay_InitOutput_mrt2fgbd11
; real_T K1_Value_h3cyeq05s4 ; real_T Memory_InitialCondition_ae1hl2beri ;
real_T integrator_IC_cizf3vyqy3 ; real_T TransportDelay_Delay_c3kuhq1tmk ;
real_T TransportDelay_InitOutput_iqikl5qisq ; real_T K1_Value_gliuqzqkch ;
real_T Memory_InitialCondition_oim4fgjrfl ; real_T RadDeg_Gain_hxdev00ox2 ;
real_T integrator_IC_id3oqyw3zs ; real_T TransportDelay_Delay_gfzlso442t ;
real_T TransportDelay_InitOutput_fw1555jo3i ; real_T K1_Value_kqgpjqxtl5 ;
real_T Memory_InitialCondition_o5eo5ilqbn ; real_T integrator_IC_ko1mnjsolw ;
real_T TransportDelay_Delay_h14bgqkqpr ; real_T
TransportDelay_InitOutput_gg1pjv5uee ; real_T K1_Value_hmcgbsqevk ; real_T
Memory_InitialCondition_jhgewnvceq ; real_T RadDeg_Gain_ohc4yyajzb ; real_T
integrator_IC_nb45zgdscp ; real_T TransportDelay_Delay_cchjdc4px3 ; real_T
TransportDelay_InitOutput_k0khfjf43s ; real_T K1_Value_b4nj0ralat ; real_T
Memory_InitialCondition_i42hzhwjo1 ; real_T integrator_IC_jdszf3kxnh ; real_T
TransportDelay_Delay_aexlf55zxy ; real_T TransportDelay_InitOutput_n4vngowuli
; real_T K1_Value_pyqikfqppy ; real_T Memory_InitialCondition_mvhozmflc4 ;
real_T RadDeg_Gain_f1lmapvdap ; real_T integrator_IC_neqimkjluh ; real_T
TransportDelay_Delay_hiakiljn1l ; real_T TransportDelay_InitOutput_jrvgibmfbn
; real_T K1_Value_cc52jr1tbm ; real_T Memory_InitialCondition_ctgd1u34sx ;
real_T integrator_IC_khrfhstbkp ; real_T TransportDelay_Delay_ibovbpaddz ;
real_T TransportDelay_InitOutput_jvi0rc1ban ; real_T K1_Value_fnpvaryrmh ;
real_T Memory_InitialCondition_hpseoczdt5 ; real_T RadDeg_Gain_cudxpld3hb ;
real_T integrator_IC_likdocw2zb ; real_T TransportDelay_Delay_cojmyky0yl ;
real_T TransportDelay_InitOutput_ok0odgcuyt ; real_T K1_Value_d0vsxao1ah ;
real_T Memory_InitialCondition_jio3sjealx ; real_T integrator_IC_e55mjrbt3j ;
real_T TransportDelay_Delay_m5fcpiszzc ; real_T
TransportDelay_InitOutput_n5imkxppa5 ; real_T K1_Value_lr14e3s4vd ; real_T
Memory_InitialCondition_e3wnoecesu ; real_T RadDeg_Gain_eu3zhqsrha ; real_T
GainVr_Vs_Gain [ 2 ] ; real_T u_Vb_Gain ; real_T Switch2_Threshold ; real_T
unitconversion_Gain [ 19 ] ; real_T Gain3_Gain_m1jkoow2cm [ 9 ] ; real_T
Gain1_Gain_ijdqjn0kfn ; real_T Integrator_IC_pgbn5sd1dy ; real_T
Integrator_gainval ; real_T Integrator_gainval_ld4rkk4vwq ; real_T Rr_Gain ;
real_T Gain2_Gain_k40ujjpy24 ; real_T Tvds2_Gain ; real_T
Integrator_gainval_hw1ypy1hgp ; real_T Tvds1_Gain ; real_T
UnitDelay_InitialCondition_pzx2rrfnsh ; real_T um1_UpperSat ; real_T
um1_LowerSat ; real_T Saturation_UpperSat_gv1zxpeeyy ; real_T
Saturation_LowerSat_cylf2nmiga ; real_T Switch1_Threshold_ljw0dhgvwc ; real_T
wbase_Gain ; real_T u_Tb2_Gain ; real_T F_Gain ; real_T u_2H_Gain ; real_T
web_psb_Gain_btyrplnn0r ; real_T sinwt_Amp ; real_T sinwt_Bias ; real_T
sinwt_Freq ; real_T sinwt_Phase ; real_T coswt_Amp ; real_T coswt_Bias ;
real_T coswt_Freq ; real_T coswt_Phase ; real_T sinwt_Amp_kaj303prng ; real_T
sinwt_Bias_eo2tvogysi ; real_T sinwt_Freq_jmsdc1qfap ; real_T
sinwt_Phase_e40hoaxtc0 ; real_T coswt_Amp_lotbg3ady4 ; real_T
coswt_Bias_pkdfrvyfzo ; real_T coswt_Freq_gy4rrmly2r ; real_T
coswt_Phase_cks54w344c ; real_T sinwt_Amp_ppjhta5ade ; real_T
sinwt_Bias_flwl1uwydj ; real_T sinwt_Freq_i0s1emiimc ; real_T
sinwt_Phase_faj42pj3vn ; real_T coswt_Amp_nzlxg1xukb ; real_T
coswt_Bias_bkkdttcimg ; real_T coswt_Freq_jyp404ctqb ; real_T
coswt_Phase_ixgxpt4zk5 ; real_T Gain3_Gain_hixkjfmrfb [ 9 ] ; real_T
Gain1_Gain_evezn5cjq0 ; real_T sinwt_Amp_edycohfw2n ; real_T
sinwt_Bias_ojeuz3kiwy ; real_T sinwt_Freq_p0h2fsybis ; real_T
sinwt_Phase_f2jjaw3e2f ; real_T coswt_Amp_fze0rt25nj ; real_T
coswt_Bias_gotsz450pe ; real_T coswt_Freq_dsg35iutco ; real_T
coswt_Phase_b05d3ayxrf ; real_T sinwt_Amp_jtggovxcvv ; real_T
sinwt_Bias_k03a0l4ngu ; real_T sinwt_Freq_mtnxy0sium ; real_T
sinwt_Phase_oxelmkkwq3 ; real_T coswt_Amp_mbtvjxxxmt ; real_T
coswt_Bias_n2y5xckms2 ; real_T coswt_Freq_hjpnxaqkas ; real_T
coswt_Phase_hny4a0wyr1 ; real_T Gain_Gain_jm4wsubqhp ; real_T Step1_Time ;
real_T Step1_Y0 ; real_T Step1_YFinal ; real_T sinwt_Amp_lejb5q1drx ; real_T
sinwt_Bias_fsysvjnpdv ; real_T sinwt_Freq_h2yfwpywe4 ; real_T
sinwt_Phase_b12v44pwkf ; real_T coswt_Amp_o1ltt5pdlh ; real_T
coswt_Bias_fzasbs01jq ; real_T coswt_Freq_bucy43teey ; real_T
coswt_Phase_hdytwcvkdv ; real_T sinwt_Amp_hbhrn0c3l5 ; real_T
sinwt_Bias_ngasuri14f ; real_T sinwt_Freq_izus5nrqgj ; real_T
sinwt_Phase_lnfnv4ci0i ; real_T coswt_Amp_cgelhat4ym ; real_T
coswt_Bias_lbadqe1qoz ; real_T coswt_Freq_l2gy35fupw ; real_T
coswt_Phase_pzlkopbzti ; real_T sinwt_Amp_fd1g3e1jxz ; real_T
sinwt_Bias_ekchsxspnw ; real_T sinwt_Freq_er04gzhbyo ; real_T
sinwt_Phase_lthjgr3htm ; real_T coswt_Amp_cbakb1lpf4 ; real_T
coswt_Bias_bs13bmejzz ; real_T coswt_Freq_k3ksg4tv2k ; real_T
coswt_Phase_igwni2bbwk ; real_T sinwt_Amp_bidhycowh3 ; real_T
sinwt_Bias_ktj1onprva ; real_T sinwt_Freq_bz3l0yj4ws ; real_T
sinwt_Phase_j5lu4omqjx ; real_T coswt_Amp_bdpzf3qm5d ; real_T
coswt_Bias_ohxwdhvdqt ; real_T coswt_Freq_hzptxtkujv ; real_T
coswt_Phase_dmdizmz41l ; real_T sinwt_Amp_dj2zfovxcb ; real_T
sinwt_Bias_kdvg0mkwaw ; real_T sinwt_Freq_ebv0m2croj ; real_T
sinwt_Phase_kxnh30c4dj ; real_T coswt_Amp_j0sfpf0zu0 ; real_T
coswt_Bias_pcausyepjz ; real_T coswt_Freq_jyz3mepj5h ; real_T
coswt_Phase_ce20mbimlk ; real_T Constant3_Value_mb13l0gxqo ; real_T
Constant4_Value_mv2wi233zc ; real_T uib1_Gain_fac4etu01m ; real_T
uDLookupTable_tableData_a4ltqu4xb4 [ 3 ] ; real_T
uDLookupTable_bp01Data_p3xuy2fusr [ 3 ] ; real_T Constant2_Value_dzk2imfsc3 ;
real_T UnitDelay_InitialCondition_dttkzptqzp ; real_T Step_Time ; real_T
Step_Y0 ; real_T Step_YFinal ; real_T Constant_Value_hut4tpkugj ; real_T
Constant1_Value_alqf2d4lc5 ; real_T Constant2_Value_afsuawgxbn [ 16 ] ;
real_T Constant3_Value_kr2bwtxikm ; real_T Constant4_Value_cmnkab0z4n [ 16 ]
; real_T Constant5_Value ; real_T Lm_nosat_Value ; real_T
Constant3_Value_ouvvljqkp0 ; real_T Constant4_Value_bjg2igozv4 ; real_T
Constant6_Value [ 2 ] ; real_T Constant3_Value_nltabvbh3t ; real_T
Constant4_Value_mu2mphswby ; real_T Constant2_Value_ppglw0fzdq ; real_T
Constant4_Value_pcedlnlqne ; real_T Constant_Value_m4r2isv0lu ; real_T
Constant1_Value_i0rprf1eid ; real_T Constant2_Value_gx2k4auir2 ; real_T
Constant3_Value_fj15ghwvge ; real_T Constant_Value_cfcvmx1ib5 ; real_T
Constant1_Value_mlwtrpfhot ; real_T Constant2_Value_bxpoo4u2no ; real_T
DegRad_Gain ; real_T Freq2_Value ; real_T Id_Value ; real_T
Clamping_zero_Value ; real_T Clamping_zero_Value_dfpkmwfljw ; real_T
Clamping_zero_Value_lqrk3a3k1y ; real_T lm_Gain ; real_T
Gain1_Gain_njsoa1aqa3 ; boolean_T Constant_Value_lmhwhmdz2u ; boolean_T
Constant1_Value_kxhc2gs4cl ; boolean_T Constant2_Value_kloxydkm3r ; boolean_T
Constant_Value_ohxe4e5ozd ; boolean_T Constant1_Value_lrv1fami4q ; boolean_T
Constant2_Value_aynpxkeryg ; boolean_T Constant_Value_bgkx1lk1ww ; boolean_T
Constant1_Value_fqdgvdsuvx ; boolean_T Constant3_Value_nnvdkzivgm ; int8_T
Constant_Value_k53mpkuj3j ; int8_T Constant2_Value_by52il1jgp ; int8_T
Constant3_Value_grljrwbpot ; int8_T Constant4_Value_b04bju3fbb ; int8_T
Constant_Value_aclrvnnu5g ; int8_T Constant2_Value_p1rcfpbgwg ; int8_T
Constant3_Value_mx5ig4v2ee ; int8_T Constant4_Value_kgjmor5mx0 ; int8_T
Constant_Value_kk01qmg3bh ; int8_T Constant2_Value_ldbseppdqu ; int8_T
Constant3_Value_fjwlskc5lo ; int8_T Constant4_Value_bgnwcz5wwl ; uint8_T
DirectLookUpTablenD_DiagnosticForOutOfRangeInput ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_graduation_project_prototype_collect_GetDWork ( ) ; extern void
mr_graduation_project_prototype_collect_SetDWork ( const mxArray * ssDW ) ;
extern mxArray *
mr_graduation_project_prototype_collect_GetSimStateDisallowedBlocks ( ) ;
extern const rtwCAPI_ModelMappingStaticInfo *
graduation_project_prototype_collect_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif

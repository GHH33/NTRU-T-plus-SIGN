#ifndef INFO_H
#define INFO_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#include "params.h"

int64_t __rdtsc(void);


#ifdef PARAM_1
// discrete Gaussian
#define K       128
#define KMASK   0x7f
#define w1		14
static const __int128 CDT[w1 + 1] = { 
	((__int128)0x1932fb << 64) ^ (__int128)0x22ad86adb1733f94,
	((__int128)0x2e1041 << 64) ^ (__int128)0x82bef4f008323c49,
	((__int128)0x39e811 << 64) ^ (__int128)0xae899cb405fb4aa6,
	((__int128)0x3e83d7 << 64) ^ (__int128)0x7243271f194e7efb,
	((__int128)0x3fbe91 << 64) ^ (__int128)0x454eb00b1384ba83,
	((__int128)0x3ff820 << 64) ^ (__int128)0x180d102455b3c166,
	((__int128)0x3fff57 << 64) ^ (__int128)0x78d4c414fd79c65b,
	((__int128)0x3ffff6 << 64) ^ (__int128)0x415e76b65a5e03a1,
	((__int128)0x3fffff << 64) ^ (__int128)0x9c847c8d54419a59,
	((__int128)0x3fffff << 64) ^ (__int128)0xfd44e79e390a7465,
	((__int128)0x3fffff << 64) ^ (__int128)0xfff2ceb0bb71725f,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffd439939ecb14,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffff9c4bbb0e0c,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffff64d321d0,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffffffffff
};
#define DegG 11
static const uint64_t Coef_G[DegG + 1] = {
	0x005e6d0f8c9d9df1,
	0x00207f2d4279f8e9,
	0x0e8fe133fb53a67f,
	0x0af9e2199d129f9f,
	0x001d1c1e8a4c8545,
	0x000043793e63e69d,
	0x00430553ed3138ef,
	0x006ef37b1010aa0f,
	0x00497876f9dd10d1,
	0x0048fa213bff70bd,
	0x0060a630f89b7937,
	0x1000000000000000  //2^*(60)
};

static const int32_t expDiff_G[DegG] = { 22, 13, 20, 26, 26, 11, 18, 19, 18, 17, 11 };

// rejection sampling
#define DegR 13
static const uint64_t Coef_R[DegR + 1] = {
	0x06757118e3db89b7,
	0x04b232ca76209e09,
	0x04de91e4671978e5,
	0x011d0ade7016f993,
	0x00ec067580632e83,
	0x02bf58555f7d85a1,
	0x0074705405e61ec9,
	0x04377ad4903a56f7,
	0x008607e294974f2f,
	0x03778d1da47ebba9,
	0x049778cd77e8cca3,
	0x048f98630f450f47,
	0x060a5ca4d6df8943,
	0x07ffffffffffffff
};
static const int32_t expDiff_R[DegR] = { 42, 41, 43, 41, 39, 43, 37, 43, 37, 39, 39, 38, 37 };

#define vartheta2 59
#define BitGamma 7 // gamma = ceiling[beta2 / (sigma * alpha * ln2)] < 2^{7}
#define ThetaChat 21
#define ValChat 0x0000001d602a63f5   // chat = ValChat / 2^{ThetaChat}
#define ThetaEps 58
#define EpsVal 1329119 // epsilon = EpsVal / 2^{ThetaEps} 

#endif


#ifdef PARAM_2
// discrete Gaussian
#define K       256
#define KMASK   0xff
#define w1		9
static const __int128 CDT[w1 + 1] = {
	((__int128)0x2400ef << 64) ^ (__int128)0xccd18d83bdfc62e7,
	((__int128)0x3a4188 << 64) ^ (__int128)0x73b08f055741b45e,
	((__int128)0x3f8278 << 64) ^ (__int128)0x55c1821245510b74,
	((__int128)0x3ffbc4 << 64) ^ (__int128)0x163f3147519b711b,
	((__int128)0x3ffff1 << 64) ^ (__int128)0xd9d33988fbd109a2,
	((__int128)0x3fffff << 64) ^ (__int128)0xedd8f02f026356c9,
	((__int128)0x3fffff << 64) ^ (__int128)0xfff716328f66f206,
	((__int128)0x3fffff << 64) ^ (__int128)0xfffffe53b1c74448,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffe148bf7d,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffffffffff
};
#define DegG 11  
static const uint64_t Coef_G[DegG + 1] = {
	0x15449d12fa02e3ff,
	0x16f881c6d6042fff,
	0x1026ff19a3d981ff,
	0x131adc62be5533ff,
	0x0009f0525264b169,
	0x12133bf405fc71ff,
	0x1c2c72690534e5ff,
	0x124c2415446babff,
	0x130366b1ecf05fff,
	0x1da2bf23d9659bff,
	0x000f65c8931e81d5,
	0x2000000000000000 // 2^{61}
};
static const int32_t expDiff_G[DegG] = { 21, 21, 20, 29, 11, 19, 20, 19, 18, 27, 8 };

// rejection sampling
#define DegR 13
static const uint64_t Coef_R[DegR + 1] = {
	0x097406ee735a1611,
	0x0ac9247f1258a04b,
	0x08c65c5d4a7d0c0f,
	0x0326082b1ba9dded,
	0x082ea5a1905724ff,
	0x0990ba6cd3e7d39b,
	0x027c22a6723ce6c9,
	0x0090996ae8531e83,
	0x070b157d36a7fc41,
	0x09260a82e380fb11,
	0x00981ad795f88e95,
	0x0ed1597776dbe789,
	0x0f65c567529ccc07,
	0x0fffffffffffffff
};
static const int32_t expDiff_R[DegR] = { 42, 42, 43, 40, 41, 43, 43, 37, 40, 44, 35, 39, 38 };

#define vartheta2 60
#define BitGamma 7 // gamma = ceiling[beta2 / (sigma * alpha * ln2)] = 141 < 2^{7}
#define ThetaChat 21
#define ValChat 0x2e18da10ed  // chat = ValChat / 2^{ThetaChat}
#define ThetaEps 59
#define EpsVal 2017081 // epsilon = EpsVal / 2^{ThetaEps}

#endif

#ifdef PARAM_3
// discrete Gaussian
#define K       256
#define KMASK   0xff
#define w1		10
static const __int128 CDT[w1 + 1] = {
	((__int128)0x1fc992 << 64) ^ (__int128)0x94451f54a8c6db7e,
	((__int128)0x3658c0 << 64) ^ (__int128)0xf5aac22f2ead2d4d,
	((__int128)0x3e6913 << 64) ^ (__int128)0xdcbb4cd0884fc4ef,
	((__int128)0x3fdcb9 << 64) ^ (__int128)0xb049b80b255bb2ee,
	((__int128)0x3ffe6c << 64) ^ (__int128)0xd324030d42937908,
	((__int128)0x3ffff6 << 64) ^ (__int128)0xd4c8968604fa9be6,
	((__int128)0x3fffff << 64) ^ (__int128)0xe4f642cfe80a7f3a,
	((__int128)0x3fffff << 64) ^ (__int128)0xffd7ba01a60ebcaa,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffe1be305e5d48,
	((__int128)0x3fffff << 64) ^ (__int128)0xfffffff48d0caa07,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffffffffff
};
#define DegG 11
static const uint64_t Coef_G[DegG + 1] = {
	0x00020c9d5cc041a5,
	0x000636246038f84d,
	0x000620f15a85486d,
	0x00001457cdeba3bf,
	0x0003b65bfc2d7dc7,
	0x0000012f25b32147,
	0x000029702f6775f9,
	0x0004b86223b24569,
	0x0006e1e340e0c685,
	0x000786b1ed097c79,
	0x00057c9cbf7807bd,
	0x4000000000000000  // 2^{62}
};
static const int32_t expDiff_G[DegG] = { 20, 21, 27, 15, 30, 15, 15, 19, 19, 19, 6 };

// rejection sampling
#define DegR 13
static const uint64_t Coef_R[DegR + 1] = {
	0x0ece3217e32dba75,
	0x17b3dced69105d4f,
	0x0d87649c8ea11427,
	0x06cfbb698c645471,
	0x0c6b2b4495ddcda7,
	0x145eee74b4ca509d,
	0x0ed9d4b2d7a38083,
	0x04bc9785c3d68c3d,
	0x00a5c09ac77f6b89,
	0x12e18518d9e35b5b,
	0x06e1e24dcc2ed729,
	0x0f0d62779b3f5d5b,
	0x15f271fb754a7035,
	0x1fffffffffffffff
};
static const int32_t expDiff_R[DegR] = { 42, 43, 43, 41, 41, 42, 43, 44, 36, 42, 39, 39, 38 };

#define vartheta2 61
#define BitGamma 7 // gamma = ceiling[beta2 / (sigma * alpha * ln2)] = 155 < 2^{7}
#define ThetaChat 21
#define ValChat 0x40ae732eab  // chat = ValChat / 2^{ThetaChat}
#define ThetaEps 61
#define EpsVal 2724241 // epsilon = EpsVal / 2^{ThetaEps}

#endif

#endif
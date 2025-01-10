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
#define w1		15
static const __int128 CDT[w1 + 1] = { 
	((__int128)0x3105bc << 64) ^ (__int128)0x5818cd57b3e3d732,
	((__int128)0x5a1fb2 << 64) ^ (__int128)0x1868198ae6d06778,
	((__int128)0x7258ff << 64) ^ (__int128)0x40aa2094d435114f,
	((__int128)0x7c622b << 64) ^ (__int128)0x425611abe8ebdb46,	
	((__int128)0x7f4e62 << 64) ^ (__int128)0xd4ca4b6071d09e1f,
	((__int128)0x7fe78f << 64) ^ (__int128)0x7a8da1bfb05db845,
	((__int128)0x7ffd9a << 64) ^ (__int128)0x76a793aa1b2d7640,
	((__int128)0x7fffd5 << 64) ^ (__int128)0x4e23ca0ea1b0967a,
	((__int128)0x7ffffd << 64) ^ (__int128)0xe5d7571956973f86,
	((__int128)0x7fffff << 64) ^ (__int128)0xed49ee361ed770f7,
	((__int128)0x7fffff << 64) ^ (__int128)0xff8a8e49845bfcb0,
	((__int128)0x7fffff << 64) ^ (__int128)0xfffdf8aad848ef85,
	((__int128)0x7fffff << 64) ^ (__int128)0xfffff9af3396cdd1,
	((__int128)0x7fffff << 64) ^ (__int128)0xfffffff229fbf217,
	((__int128)0x7fffff << 64) ^ (__int128)0xffffffffeac401b4,
	((__int128)0x7fffff << 64) ^ (__int128)0xffffffffffffffff
};
#define DegG 11
static const uint64_t Coef_G[DegG + 1] = {
	0x00162cc6fefad729,
	0x0020b278fd01a9ef,
	0x1f633e564b57507f,
	0x1957442cc4f55d7f,
	0x0023fe3b78aa44c7,
	0x002cae3c97741f99,
	0x002f8970eb06fdd9,
	0x002a256d251e9d91,
	0x003bc971b48173ef,
	0x0003f9bc36296bad,
	0x002d1dbe7c0ea199,
	0x2000000000000000 // 2^{61}
};

static const int32_t expDiff_G[DegG] = { 20, 12, 20, 27, 19, 19, 19, 18, 22, 14, 9};

// rejection sampling
#define DegR 13
static const uint64_t Coef_R[DegR + 1] = {
	0x054a0d4dcff034fb,
	0x041e8454d6f5bd6f,
	0x0249971b31ca3085,
	0x023db0438433588d,
	0x007f33bf13fea09b,
	0x065807613c40638f,
	0x047fe4b406128d99,
	0x0595c7129d33b237,
	0x002f895d4f33d529,
	0x02a255e9911c9d45,
	0x03bc96232c4563b1,
	0x07f3770c57f3a84f,
	0x05a3b752ae423e55,
	0x07ffffffffffffff 
};
static const int32_t expDiff_R[DegR] = { 39, 39, 38, 40, 34, 38, 37, 42, 33, 36, 35, 36, 34 };

#define vartheta2 59
#define BitGamma 7 // gamma = ceiling[beta2 / (sigma * alpha * ln2)] < 2^{7}
#define ThetaChat 18
#define ValChat 0x00000003eede7abb // chat = ValChat / 2^{ThetaChat}
#define ThetaEps 58
#define EpsVal 209317 // epsilon = EpsVal / 2^{ThetaEps} 

#endif

#ifdef PARAM_2
// discrete Gaussian
#define K       256
#define KMASK   0xff
#define w1		9
static const __int128 CDT[w1 + 1] = {
	((__int128)0x23c86c << 64) ^ (__int128)0x696947f55fc3be1a,
	((__int128)0x3a1473 << 64) ^ (__int128)0xf69b97aeff8e74fb,
	((__int128)0x3f7977 << 64) ^ (__int128)0xa0e578f8240490a8,
	((__int128)0x3ffb33 << 64) ^ (__int128)0x5a7f3b35756e502a,
	((__int128)0x3fffee << 64) ^ (__int128)0xbfcd25ff5606e5ca,
	((__int128)0x3fffff << 64) ^ (__int128)0xe7cc13306c2ec793,
	((__int128)0x3fffff << 64) ^ (__int128)0xfff2c9d01ba4001b,
	((__int128)0x3fffff << 64) ^ (__int128)0xfffffd3292e5c8f9,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffc4e6b5ac,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffffffffff
};
#define DegG 11  
static const uint64_t Coef_G[DegG + 1] = {
	0x119f3d63f036ffff,
	0x00004d71ae409bff,
	0x0000376534d4063b,
	0x0000854d6be82681,
	0x00008d15a4108859,
	0x1050201b199adfff,
	0x000019dd8b8a13db,
	0x1116877bc0ba5fff,
	0x12100e8f02913fff,
	0x1ca3ba062b041fff,
	0x0000f22f7c80375d,
	0x2000000000000000 // 2^{61}
};
static const int32_t expDiff_G[DegG] = { 35, 21, 19, 20, 7, 35, 4, 19, 18, 31, 4 };

// rejection sampling
#define DegR 13
static const uint64_t Coef_R[DegR + 1] = {
	0x0791d6b3e76f2a79,
	0x08c91ac6255ef7cb,
	0x0e8aa9889157e041,
	0x0153b20412885b9f,
	0x0703fae234297953,
	0x0857c525a2a9469d,
	0x0234664d24e06971,
	0x082813ca4a7876af,
	0x0ceec6586a224bc1,
	0x088b43eaa7a3519d,
	0x09080769da0a4aa7,
	0x03947749d6529be7,
	0x07917bed96fef3c7,
	0x0fffffffffffffff
};
static const int32_t expDiff_R[DegR] = { 40, 39, 43, 37, 39, 41, 37, 38, 39, 38, 39, 46, 35 };

#define vartheta2 60
#define BitGamma 7 // gamma = ceiling[beta2 / (sigma * alpha * ln2)] = 141 < 2^{7}
#define ThetaChat 19
#define ValChat 0xbb913e801 // chat = ValChat / 2^{ThetaChat}
#define ThetaEps 59
#define EpsVal 1212381 // epsilon = EpsVal / 2^{ThetaEps}

#endif

#ifdef PARAM_3
// discrete Gaussian
#define K       256
#define KMASK   0xff
#define w1		10
static const __int128 CDT[w1 + 1] = {
	((__int128)0x1f87a0 << 64) ^ (__int128)0x24326787ea0c07b6,
	((__int128)0x36122d << 64) ^ (__int128)0x455fb45983c142bc,
	((__int128)0x3e4ebc << 64) ^ (__int128)0xed4c68904782c9d2,
	((__int128)0x3fd887 << 64) ^ (__int128)0xddbd90e427005d93,
	((__int128)0x3ffe1e << 64) ^ (__int128)0xac33d0553545ea22,
	((__int128)0x3ffff4 << 64) ^ (__int128)0x24affbdfececa462,
	((__int128)0x3fffff << 64) ^ (__int128)0xd98e54f630806e23,
	((__int128)0x3fffff << 64) ^ (__int128)0xffc01880b7e4bc13,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffc99f5a587085,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffe85a29e415,
	((__int128)0x3fffff << 64) ^ (__int128)0xffffffffffffffff
};
#define DegG 11
static const uint64_t Coef_G[DegG + 1] = {
	0x00033b270b8b57fb,
	0x000500f242a0a149,
	0x00142def5581a1e9,
	0x00022390ec73634d,
	0x330dd98035f185ff,
	0x0004290b313cd03d,
	0x00094c44b3db55df,
	0x0011510775d9c679,
	0x0019cce1fb7cfa17,
	0x000735258f6a10b9,
	0x00157a430b7a3763,
	0x4000000000000000  // 2^{62}
};
static const int32_t expDiff_G[DegG] = { 21, 19, 24, 8, 32, 19, 19, 19, 21, 17, 8 };

// rejection sampling
#define DegR 13
static const uint64_t Coef_R[DegR + 1] = {
	0x0596b1852ca1a00b,
	0x1249084e00507257,
	0x155474476020d84f,
	0x0af94c7958f9c139,
	0x028e3bda463b3951,

	0x0448a0a687134af1,
	0x198795e6ebaf4da7,
	0x10a42d139971a139,
	0x04a620dac25743fb,
	0x115102bcf17713b9,
	0x0ce66e58a750f8dd,
	0x1cd4924cc275fb83,
	0x157a4193ae4eb0e9,
	0x1fffffffffffffff
};
static const int32_t expDiff_R[DegR] = { 40, 41, 42, 43, 40, 38, 41, 42, 38, 40, 38, 39, 37 };

#define vartheta2 61
#define BitGamma 7 // gamma = ceiling[beta2 / (sigma * alpha * ln2)] = 155 < 2^{7}
#define ThetaChat 20
#define ValChat 0x210c2fb073 // chat = ValChat / 2^{ThetaChat}
#define ThetaEps 58
#define EpsVal 449397 // epsilon = EpsVal / 2^{ThetaEps}

#endif

#endif
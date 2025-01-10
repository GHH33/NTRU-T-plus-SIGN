#include "params.h"
#include "reduce.h"
#include "ntt.h"
#ifdef PARAM_1
const int16_t zetas[256] = {
	-3593,  -308, -1252, -2652, -1463,  2765,  2162, -1734,
	  221, -2586,  -762, -2970,  2901,  2235,  1015,  -338,
	  848, -3771,  -630,  3653, -1398, -2062,  1727,  2800,
	 2327,   784,  3724, -1452,  2631,  1606,  3788, -2896,
	-3236,  1963,  -277,     9,   190,  2434,    40,  2938,
	-3801,   789, -2013, -3068, -1614, -1029,   873,  3826,
	-3324,   108,   513,   427,   480, -3149, -1516, -2280,
	-1113,  1589,  1787,  -474,  2795,  -174,  3014, -3675,
	 -853, -2357,  2246, -1709, -3648, -2183,  -768,  1966,
	 2314, -1323,  3317,   530,  1801, -1750,  3209, -2794,
	-2707,  2029, -3804,  3257, -2077, -1624,   -33, -3576,
	-3201, -1227,  3773,  1763, -2893,  1425,  1008,   300,
	 1236, -2924,  1473,  1810,  1513, -2933,  -490, -1426,
	-1444,   -64,  -304,  -822,   569,  3004, -1093,  3058,
	 -787, -2886, -2187,  1818,   -25,    84,   399,  2039,
	  298, -1923,   467,  2425, -3426,  -471,  -317, -2929,
	-2731, -1270, -2192,  3371,  2890,  1043,  3034, -2206,
	 2420,  1086,  1318, -3814,  -294,  3753, -3296, -2444,
	 2553, -3355,  1346,  1315, -1256,  1455, -2690, -1715,
	  224,  2627,  2877, -1064, -2833, -1849, -3022,    15,
	-3030, -3645,  3809,  2871,  -838,   665, -2602,   140,
	 1079, -1782,  3057, -3205,  -239,  2032,  1971,  -785,
	 1370, -3067,  2714, -2667,    24,  3299, -1612,  -114,
	-2744, -3377, -2599, -2328,  2060, -2313,  2455, -2104,
	-3272,   855,  2141,   180,  3800,  2594,   800, -2688,
	  790,   418, -1855,    88, -1556,  2463,  2098,  -290,
	-3261,  2047,   122,  2048, -1997, -3429, -2846,  3725,
	  454,   318, -2330,  1684, -1147,  1396, -1050,  3528,
	 1677,  2968, -1264, -2205,  -464,  2788, -2119,  2204,
	 1844, -1280,  1601, -1078,  3699, -1368,  1183,  -288,
	 -378,  3728,  2346, -2045,  -500,  1680,   299,  2375,
	-1721,   -55,  1659,  2414,   609, -1739,  1341,  2868
};
#endif

#ifdef PARAM_2
const int16_t zetas[324] = {
	-2511,  -173,   147, -4782,  4502,  -147,   894, -4360,
	-3036,  1904,     2, -1866,   383,   561,  -583, -3848,
	 4720,  3036, -2746,    67,   322,  3110,  4713, -4212,
	 1310,  2584, -4253,   245,  3352,  4263,  3347,  3173,
	 1682,  4661,  1856,  -555, -4263,  2832, -4704,  2616,
	-4185,  2746, -1386, -4528, -2535,   925,  -786, -3347,
	  555, -2701,   -58, -4225,   -64,  4253,  2093,   164,
	-3389, -2979, -4410,  2603, -3342, -1800,  2346, -2157,
	-1769,  -592,  1212,    77,  2343,  3284,  3591,  2704,
	 -292,  2676,    13,  3790,  2696, -2101,  3736, -3290,
	  100,  1080,  2792,  -650,  1071,  2679,  1517,  1898,
	-4695,  1918, -1413,  3595, -2900,  4227, -3200, -2274,
	-1896, -2233,  4612,  1974,    61,  -648,  -377, -1098,
	 -416,  2281,  1217, -3083, -4776,  -269, -1918,  1152,
	-1446,  2547,   650, -2975, -1294, -3160,  1589,  3342,
	-4721, -2438,  3506, -1593,  -489,  3389,   592, -3678,
	-1358, -3727,  2524,  1253,   815,   773, -4464,  1785,
	 4460,  1896, -2704, -3268,  3050,  3407, -2333,  2900,
	-4193, -1214,  3083,  4151, -2967,   292,   648,  2655,
	 -961, -2408,  -390, -1071,   498, -4245,  4572,  3905,
	-3000,  -100, -1938, -4152, -2214,  3528, -2614,  3579,
	 1884,  1117,  -767,  2014,  3743,  1729, -4810,    48,
	 4858, -4817,  3795, -1109,  2291, -4271,  3159,  -529,
	-2909, -2380,  2528, -3372,  3821,  2143, -1428, -3571,
	  -79, -3540, -3461, -1993,  4458, -3270, -1274,  1484,
	 2758,  2560,  3107,   547, -1741, -4061, -2320,  2277,
	 3223,   946, -2851,  2680, -4190,  4859,  2886, -1973,
	 1608, -2514, -4122, -4101, -3128,   973,  4456,   578,
	-3878,  4619, -1962,  3140,  3690, -3230,  2801,  3756,
	-3841,  2124,  3396, -1392, -4788,  3599, -3124,  2998,
	-1616, -1536,    80,  3936,  -205, -4141,   118, -3449,
	-3567, -4037,   109,  4146,  4487,  -740,  4494, -4316,
	 2250, -3155, -3429, -3163,   266,  4105, -4568,  1048,
	 3151,  3380,   229,  1848,  2334,   486,  2028, -3751,
	 3942, -2488,  4180, -3053,  2573, -2463,  4685, -3823,
	-3345,   478,  3348,  3471,   123,  -196, -2015, -1819,
	-3842,  4048, -1831, -1192,  -748,   444, -1893, -3243,
	-1350, -2393, -3622, -1229, -3890,  -810,  3080,  4734,
	  361, -4373, -3422,  2811, -3488,   421, -3161, -3582,
	-3776,  3437, -2508, -1209,  2797,  4006,  2231,  4238,
	 2007,  2018, -3953,  3750
};
#endif


#ifdef PARAM_3
const int16_t zetas[324] = {
	-2511,  -173,   147, -4782,  4502,  -147,   894, -4360,
	-3036,  1904,     2, -1866,   383,   561,  -583, -3848,
	 4720,  3036, -2746,    67,   322,  3110,  4713, -4212,
	 1310,  2584, -4253,   245,  3352,  4263,  3347,  3173,
	 1682,  4661,  1856,  -555, -4263,  2832, -4704,  2616,
	-4185,  2746, -1386, -4528, -2535,   925,  -786, -3347,
	  555, -2701,   -58, -4225,   -64,  4253,  2093,   164,
	-3389, -2979, -4410,  2603, -3342, -1800,  2346, -2157,
	-1769,  -592,  1212,    77,  2343,  3284,  3591,  2704,
	 -292,  2676,    13,  3790,  2696, -2101,  3736, -3290,
	  100,  1080,  2792,  -650,  1071,  2679,  1517,  1898,
	-4695,  1918, -1413,  3595, -2900,  4227, -3200, -2274,
	-1896, -2233,  4612,  1974,    61,  -648,  -377, -1098,
	 -416,  2281,  1217, -3083, -4776,  -269, -1918,  1152,
	-1446,  2547,   650, -2975, -1294, -3160,  1589,  3342,
	-4721, -2438,  3506, -1593,  -489,  3389,   592, -3678,
	-1358, -3727,  2524,  1253,   815,   773, -4464,  1785,
	 4460,  1896, -2704, -3268,  3050,  3407, -2333,  2900,
	-4193, -1214,  3083,  4151, -2967,   292,   648,  2655,
	 -961, -2408,  -390, -1071,   498, -4245,  4572,  3905,
	-3000,  -100, -1938, -4152, -2214,  3528, -2614,  3579,
	 1884,  1117,  -767,  2014,  3743,  1729, -4810,    48,
	 4858, -4817,  3795, -1109,  2291, -4271,  3159,  -529,
	-2909, -2380,  2528, -3372,  3821,  2143, -1428, -3571,
	  -79, -3540, -3461, -1993,  4458, -3270, -1274,  1484,
	 2758,  2560,  3107,   547, -1741, -4061, -2320,  2277,
	 3223,   946, -2851,  2680, -4190,  4859,  2886, -1973,
	 1608, -2514, -4122, -4101, -3128,   973,  4456,   578,
	-3878,  4619, -1962,  3140,  3690, -3230,  2801,  3756,
	-3841,  2124,  3396, -1392, -4788,  3599, -3124,  2998,
	-1616, -1536,    80,  3936,  -205, -4141,   118, -3449,
	-3567, -4037,   109,  4146,  4487,  -740,  4494, -4316,
	 2250, -3155, -3429, -3163,   266,  4105, -4568,  1048,
	 3151,  3380,   229,  1848,  2334,   486,  2028, -3751,
	 3942, -2488,  4180, -3053,  2573, -2463,  4685, -3823,
	-3345,   478,  3348,  3471,   123,  -196, -2015, -1819,
	-3842,  4048, -1831, -1192,  -748,   444, -1893, -3243,
	-1350, -2393, -3622, -1229, -3890,  -810,  3080,  4734,
	  361, -4373, -3422,  2811, -3488,   421, -3161, -3582,
	-3776,  3437, -2508, -1209,  2797,  4006,  2231,  4238,
	 2007,  2018, -3953,  3750
};
#endif

/*************************************************
* Name:        fqmul
*
* Description: Multiplication followed by Montgomery reduction
*
* Arguments:   - int16_t a: first factor
*              - int16_t b: second factor
*
* Returns 16-bit integer congruent to a*b*R^{-1} mod q
**************************************************/
static int16_t fqmul(int16_t a, int16_t b)
{
  return montgomery_reduce((int32_t)a*b);
}

/*************************************************
* Name:        fqinv
*
* Description: Inversion
*
* Arguments:   - int16_t a: first factor a = x * R mod q
*
* Returns 16-bit integer congruent to x^{-1} * R^3 mod q
**************************************************/
#ifdef PARAM_1
static int16_t fqinv(int16_t a)
{
	int16_t t1,t2,t3;

	t1 = fqmul(a, a);    //10
	t1 = fqmul(t1, a);   //11
	t1 = fqmul(t1, t1);  //110
	t1 = fqmul(t1, a);   //111
	t2 = fqmul(t1, t1);  //1110
	t2 = fqmul(t2, t2);  //11100
	t2 = fqmul(t2, t2);  //111000
	t3 = fqmul(t1, t2);  //111111
	t2 = fqmul(t2, t2);  //1110000
	t1 = fqmul(t1, t2);  //1110111
	t1 = fqmul(t1, t1);  //11101110
	t1 = fqmul(t1, t1);  //111011100
	t1 = fqmul(t1, t1);  //1110111000
	t1 = fqmul(t1, t1);  //11101110000
	t1 = fqmul(t1, t1);  //111011100000
	t1 = fqmul(t1, t1);  //1110111000000
	t1 = fqmul(t1, t3);  //1110111111111

	return t1;
}
#endif


#if defined(PARAM_2)||defined(PARAM_3)
static int16_t fqinv(int16_t a)
{
	//q -2 =  9719 = 100 10111 1 10111
	int16_t t1,t2;

	t1 = fqmul(a, a);    //10
	t2 = fqmul(t1, a);   //11
	t2 = fqmul(t2, t2);  //110
	t2 = fqmul(t2, a);   //111
	t1 = fqmul(t1, t1);  //100
	t1 = fqmul(t1, t1);  //1000
	t1 = fqmul(t1, t1);  //10000
	t2 = fqmul(t1, t2);  //10111
	t1 = fqmul(t1, t1);  //100000
	t1 = fqmul(t1, t1);  //1000000
	t1 = fqmul(t1, t1);  //10000000
	t1 = fqmul(t1, t2);  //10010111
	t1 = fqmul(t1, t1);  //100101110
	t1 = fqmul(t1, a);   //100101111
	t1 = fqmul(t1, t1);  //1001011110
	t1 = fqmul(t1, t1);  //10010111100
	t1 = fqmul(t1, t1);  //100101111000
	t1 = fqmul(t1, t1);  //1001011110000
	t1 = fqmul(t1, t1);  //10010111100000
	t1 = fqmul(t1, t2);  //10010111110111

	return t1;
}
#endif

/*************************************************
* Name:        ntt
*
* Description: Inplace number-theoretic transform (NTT) in Rq.
*              input is in standard order, output is in bitreversed order
*
* Arguments:   - int16_t r[512]: pointer to input/output vector of elements of Zq
**************************************************/
#ifdef PARAM_1
void ntt(int16_t r[NTRUPLUS_N])
{
	int16_t t;
	int16_t zeta;
	int k = 1;

	zeta = zetas[k++];
	
	for(int i = 0; i < 384; i++)
	{
		t = fqmul(zeta, r[i + NTRUPLUS_N/2]);

		r[i + NTRUPLUS_N/2] = r[i] + r[i + NTRUPLUS_N/2] - t;
		r[i               ] = r[i]                       + t;
	}

	for(int step = 192; step >= 96; step >>= 1)
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t = fqmul(zeta, r[i + step]);
				
				r[i + step] = (r[i] - t);
				r[i       ] = (r[i] + t);
			}
		}
	}

	for(int step = 48; step >= 48; step >>= 1)
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t = fqmul(zeta, r[i + step]);
				
				r[i + step] = barrett_reduce(r[i] - t);
				r[i       ] = barrett_reduce(r[i] + t);
			}
		}
	}

	for(int step = 24; step >= 6; step >>= 1)
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t = fqmul(zeta, r[i + step]);
				
				r[i + step] = (r[i] - t);
				r[i       ] = (r[i] + t);
			}
		}
	}

	for(int step = 3; step >= 3; step >>= 1)
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t = fqmul(zeta, r[i + step]);
				
				r[i + step] = barrett_reduce(r[i] - t);
				r[i       ] = barrett_reduce(r[i] + t);
			}
		}
	}
}
#endif

#ifdef PARAM_2
void ntt(int16_t r[NTRUPLUS_N])
{
	int16_t t1,t2,t3;
	int16_t zeta1, zeta2;
	int k = 1;

	zeta1 = zetas[k++];
	
	for(int i = 0; i < NTRUPLUS_N/2; i++)
	{
		t1 = fqmul(zeta1, r[i + NTRUPLUS_N/2]);
	
		r[i + NTRUPLUS_N/2] = barrett_reduce(r[i] + r[i + NTRUPLUS_N/2] - t1);
		r[i               ] = barrett_reduce(r[i]                       + t1);
	}

	for(int step = NTRUPLUS_N/6; step >= 6; step = step/3)
	{
		for(int start = 0; start < NTRUPLUS_N; start += 3*step)
		{
			zeta1 = zetas[k++];
			zeta2 = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t1 = fqmul(zeta1, r[i +   step]);
				t2 = fqmul(zeta2, r[i + 2*step]);
				t3 = fqmul(2338, t1 - t2);
	
				r[i + 2*step] = barrett_reduce(r[i] - t1 - t3);
				r[i +   step] = barrett_reduce(r[i] - t2 + t3);
				r[i         ] = barrett_reduce(r[i] + t1 + t2);
			}
		}
	}

	for(int start = 0; start < NTRUPLUS_N; start += 6)
	{
		zeta1 = zetas[k++];

		for(int i = start; i < start + 3; i++)
		{
			t1 = fqmul(zeta1, r[i + 3]);
			
			r[i + 3] = barrett_reduce(r[i] - t1);
			r[i    ] = barrett_reduce(r[i] + t1);
		}
	}
}
#endif

#ifdef PARAM_3
void ntt(int16_t r[NTRUPLUS_N])
{
	int16_t t1,t2,t3;
	int16_t zeta1, zeta2;
	int k = 1;

	zeta1 = zetas[k++];
	
	for(int i = 0; i < NTRUPLUS_N/2; i++)
	{
		t1 = fqmul(zeta1, r[i + NTRUPLUS_N/2]);
	
		r[i + NTRUPLUS_N/2] = r[i] + r[i + NTRUPLUS_N/2] - t1;
		r[i               ] = r[i]                       + t1;
	}

	for(int step = 216; step >= 8; step = step/3)
	{
		for(int start = 0; start < NTRUPLUS_N; start += 3*step)
		{
			zeta1 = zetas[k++];
			zeta2 = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t1 = fqmul(zeta1, r[i +   step]);
				t2 = fqmul(zeta2, r[i + 2*step]);
				t3 = fqmul(2338, t1 - t2);
	
				r[i + 2*step] = barrett_reduce(r[i] - t1 - t3);
				r[i +   step] = barrett_reduce(r[i] - t2 + t3);
				r[i         ] = barrett_reduce(r[i] + t1 + t2);
			}
		}
	}

	for(int step = 4; step >= 4; step >>= 1)
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta1 = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t1 = fqmul(zeta1, r[i + step]);
				
				r[i + step] = barrett_reduce(r[i] - t1);
				r[i       ] = barrett_reduce(r[i] + t1);
			}
		}
	}
}
#endif

/*************************************************
* Name:        invntt
*
* Description: inverse number-theoretic transform in Rq and
*              multiplication by Montgomery factor R = 2^16.
*
* Arguments:   - int16_t b[NTRUPLUS_N]: pointer to output vector of elements of Zq
*              - int16_t a[NTRUPLUS_N]: pointer to input vector of elements of Zq
**************************************************/
#ifdef PARAM_1
void invntt(int16_t r[NTRUPLUS_N])
{
	int16_t t1, t2;
	int16_t zeta;
	int k = 255;

	for(int step = 3; step <= NTRUPLUS_N/4; step <<= 1)	
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta = zetas[k--];

			for(int i = start; i < start + step; i++)
			{
				t1 = r[i + step];

				r[i + step] = fqmul(zeta,  t1 - r[i]);
				r[i       ] = barrett_reduce(r[i] + t1);
			}
		}
	}

	for(int i = 0; i < NTRUPLUS_N/2; i++)
	{
		t1 = r[i] + r[i + NTRUPLUS_N/2];
		t2 = fqmul(1568, r[i] - r[i + NTRUPLUS_N/2]);

		r[i               ] = fqmul(256, t1 - t2);
		r[i + NTRUPLUS_N/2] = fqmul(512, t2);
	}
}
#endif
#ifdef PARAM_2
void invntt(int16_t r[NTRUPLUS_N])
{
   int16_t t1, t2, t3;
   int16_t zeta1, zeta2;
   int k = 323;

   for(int start = 0; start < NTRUPLUS_N; start += 6)
   {
      zeta1 = zetas[k--];

      for(int i = start; i < start + 3; i++)
      {
         t1 = r[i + 3];

         r[i + 3] = fqmul(zeta1,  t1 - r[i]);         
         r[i    ] = barrett_reduce(r[i] + t1);
      }
   }

   for(int step = 6; step <= NTRUPLUS_N/6; step = 3*step)
   {
      for(int start = 0; start < NTRUPLUS_N; start += 3*step)
      {
         zeta2 = zetas[k--];
         zeta1 = zetas[k--];

         for(int i = start; i < start + step; i++)
         {
            t1 = fqmul(2338, r[i +   step] - r[i]);
            t2 = fqmul(zeta1, r[i + 2*step] - r[i]        + t1);
            t3 = fqmul(zeta2, r[i + 2*step] - r[i + step] - t1);
            
            r[i         ] = barrett_reduce(r[i] + r[i + step] + r[i + 2*step]);
            r[i +   step] = t2;         
            r[i + 2*step] = t3;
         }         
      }
   }

   for(int i = 0; i < NTRUPLUS_N/2; i++)
   {
      t1 = r[i] + r[i + NTRUPLUS_N/2];
      t2 = fqmul(-3962, r[i] - r[i + NTRUPLUS_N/2]);

      r[i               ] = fqmul(-2438, t1 - t2);
      r[i + NTRUPLUS_N/2] = fqmul(4845, t2);
   }
}
#endif

#ifdef PARAM_3
void invntt(int16_t r[NTRUPLUS_N])
{
	int16_t t1, t2, t3;
	int16_t zeta1, zeta2;
	int k = 323;

	for(int step = 4; step <= 4; step <<= 1)
	{
		for(int start = 0; start < NTRUPLUS_N; start += (step << 1))
		{
			zeta1 = zetas[k--];

			for(int i = start; i < start + step; i++)
			{
				t1 = r[i + step];

				r[i + step] = fqmul(zeta1, t1 - r[i]);
				r[i       ] = barrett_reduce(r[i] + t1);
			}
		}
	}

	for(int step = 8; step <= NTRUPLUS_N/6; step = 3*step)
	{
		for(int start = 0; start < NTRUPLUS_N; start += 3*step)
		{
			zeta2 = zetas[k--];
			zeta1 = zetas[k--];

			for(int i = start; i < start + step; i++)
			{
				t1 = fqmul(2338, r[i +   step] - r[i]);
				t2 = fqmul(zeta1, r[i + 2*step] - r[i]        + t1);
				t3 = fqmul(zeta2, r[i + 2*step] - r[i + step] - t1);
				
				r[i         ] = barrett_reduce(r[i] + r[i + step] + r[i + 2*step]);
				r[i +   step] = t2;			
				r[i + 2*step] = t3;
			}			
		}
	}

	for(int i = 0; i < NTRUPLUS_N/2; i++)
	{
		t1 = barrett_reduce(r[i] + r[i + NTRUPLUS_N/2]);
		t2 = fqmul(-3962, r[i] - r[i + NTRUPLUS_N/2]);

		r[i               ] = fqmul(-2438, t1 - t2);
		r[i + NTRUPLUS_N/2] = fqmul(4845, t2);
	}
}
#endif
/*************************************************
* Name:        basemul
*
* Description: Multiplication of polynomials in Zq[X]/(X^4-zeta)
*              used for multiplication of elements in Rq in NTT domain
*
* Arguments:   - int16_t c[4]: pointer to the output polynomial
*              - const int16_t a[4]: pointer to the first factor
*              - const int16_t b[4]: pointer to the second factor
*              - int16_t zeta: integer defining the reduction polynomial
**************************************************/
#if defined(PARAM_1) || defined(PARAM_2)
void basemul(int16_t c[3], const int16_t a[3], const int16_t b[3], int16_t zeta)
{
	c[0] = montgomery_reduce(a[2]*b[1]+a[1]*b[2]);
	c[1] = montgomery_reduce(a[2]*b[2]);
	c[2] = montgomery_reduce(a[2]*b[0]+a[1]*b[1]+a[0]*b[2]);
	c[0] = montgomery_reduce(c[0]*zeta+a[0]*b[0]);
	c[1] = montgomery_reduce(c[1]*zeta+a[0]*b[1]+a[1]*b[0]);
}
#endif


#ifdef PARAM_3
void basemul(int16_t c[4], const int16_t a[4], const int16_t b[4], int16_t zeta)
{
	c[0]  = montgomery_reduce(a[1]*b[3]+a[2]*b[2]+a[3]*b[1]);
	c[1]  = montgomery_reduce(a[2]*b[3]+a[3]*b[2]);
	c[2]  = montgomery_reduce(a[3]*b[3]);
	c[3]  = montgomery_reduce(a[0]*b[3]+a[1]*b[2]);
	c[3] += montgomery_reduce(a[2]*b[1]+a[3]*b[0]);
	c[3]  = barrett_reduce(c[3]);

	c[0]  = montgomery_reduce(c[0]*zeta+a[0]*b[0]);
	c[1]  = montgomery_reduce(c[1]*zeta+a[0]*b[1]+a[1]*b[0]);
	c[2]  = montgomery_reduce(c[2]*zeta+a[0]*b[2]);
	c[2] += montgomery_reduce(a[1]*b[1]+a[2]*b[0]);
	c[2]  = barrett_reduce(c[2]);
}
#endif
/*************************************************
* Name:        baseinv
*
* Description: Inversion of polynomial in Zq[X]/(X^2-zeta)
*              used for inversion of element in Rq in NTT domain
*
* Arguments:   - int16_t b[2]: pointer to the output polynomial
*              - const int16_t a[2]: pointer to the input polynomial
*              - int16_t zeta: integer defining the reduction polynomial
**************************************************/
#if defined(PARAM_1) || defined(PARAM_2)
int baseinv(int16_t b[3], const int16_t a[3], int16_t zeta)
{
	int16_t det;
	int r;

	b[0]  = fqmul(a[1],a[2]);
	b[1]  = fqmul(a[2],a[2]);
	b[2]  = montgomery_reduce(a[1]*a[1]-a[0]*a[2]);
	b[0]  = montgomery_reduce(a[0]*a[0]-b[0]*zeta);
	b[1]  = montgomery_reduce(b[1]*zeta-a[0]*a[1]);

	det   = montgomery_reduce(b[2]*a[1]+b[1]*a[2]);
	det   = montgomery_reduce(det*zeta+b[0]*a[0]); 
	det   = fqinv(det);

	b[0]  = fqmul(b[0],det);
	b[1]  = fqmul(b[1],det);
	b[2]  = fqmul(b[2],det);

	r = (uint16_t)det;
	r = (uint32_t)(-r) >> 31;

	return r - 1;
}
#endif

#ifdef PARAM_3
int baseinv(int16_t b[4], const int16_t a[4], int16_t zeta)
{
	int r;
	int16_t t0, t1, t2;
	
	t0 = montgomery_reduce(a[2]*a[2] - (a[1]*a[3] << 1));
	t1 = montgomery_reduce(a[3]*a[3]);
	t0 = montgomery_reduce(a[0]*a[0] + t0*zeta);

	t1 = montgomery_reduce(t1*zeta);
	t1 = montgomery_reduce(((a[0]*a[2]) << 1) - a[1]*a[1]) - t1;
	t2 = montgomery_reduce(t1*t1);
	t2 = montgomery_reduce(t0*t0 - t2*zeta);

	t2 = fqinv(t2);

	r = (uint16_t)t2;
	r = (uint32_t)(-r) >> 31;

	t0 = fqmul(t0,t2);
	t1 = fqmul(t1,t2);
	t2 = fqmul(t1,zeta);
	
	b[0] = montgomery_reduce(a[0]*t0 - a[2]*t2);
	b[1] = montgomery_reduce(a[3]*t2 - a[1]*t0);
	b[2] = montgomery_reduce(a[2]*t0 - a[0]*t1);
	b[3] = montgomery_reduce(a[1]*t1 - a[3]*t0);

	return r - 1;
}

#endif
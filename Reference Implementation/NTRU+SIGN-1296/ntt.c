#include "params.h"
#include "reduce.h"
#include "ntt.h"


#ifdef PARAM_1
const int16_t zetas[216] = {
	1375,   661, -3144,  -246,  -953,  3144, -3504, -3405,
	3240,   376, -1824, -2734,   890, -2794,  -237,  1280,
	 -25, -3240,  2508,   -45,   806, -1000,  3454,   749,
   -1363, -2076,  2774,  -983, -2565,  2711, -2639, -1670,
	2489,  -674,  1556, -2304, -2711, -1001,  1579,  2311,
	 -44, -2508,  1425,  2773,   782,  3006, -1602,  2639,
	2304,    81,   604,  1800,  1297, -2774,  2510,   740,
   -1770,  1312,   330,  -982, -1149, -3321, -2172, -2456,
	2599, -2074, -3022,   870, -3237, -1733,   966,  2699,
	   6,   371,   365,  -190, -2243, -2053,  1264, -2638,
	3227,  -471,  2957,  3428,   657,  1415,   758,   582,
	 342,  -240, -3186,  2611, -1332,  1084,   490,  -594,
   -1058,  3494, -2577,  1970,  2995,  1025, -2975,  2588,
   -1566,  -845, -1158,  -313,  -149, -2991,   163,  -747,
	-896, -3154, -3307, -1027,  -497, -2752,  1070,  -530,
	2342,  2038,  -409,  2268, -2519,  2447, -3221, -2602,
	-926, -2273,  1635, -1676,  1380,  2248,  1074, -1598,
	-218,  1174,  -184,  -775, -1569, -1688, -1872,   794,
   -1689,  1836,  2374,   623, -1066,  -538,  1651,  1181,
	 634,  1818,  3469,   547, -3547, -1108,   866, -3094,
	 488, -1974,  -671,   932, -2041,  3143,  2472,  2973,
	1040,   351, -3530,  1482,  2522, -3248, -2515,  1379,
	2847,  2654,   139, -1468,  -343, -1096,   136,  -667,
   -1010, -1232,   521,  3473, -3345,  1990,  2511,  -311,
   -1020,  1438,   446,  2111,  1091,   992, -1769,  1809,
	 452,   509, -1260,  1357, -3091, -1667,   415,  3259,
	 168, -2082, -3390,  -253,  2321,   516, -2874, -2574
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
//110 11 110 1 0111
static int16_t fqinv(int16_t a)
{
	int16_t t1;

	t1 = fqmul(a, a);    //10
	t1 = fqmul(t1, a);   //11
	t1 = fqmul(t1, t1);  //110
	t1 = fqmul(t1, t1);  //1100
	t1 = fqmul(t1, a);   //1101
	t1 = fqmul(t1, t1);  //11010
	t1 = fqmul(t1, a);   //11011
	t1 = fqmul(t1, t1);  //110110
	t1 = fqmul(t1, a);   //110111
	t1 = fqmul(t1, t1);  //1101110
	t1 = fqmul(t1, a);   //1101111
	t1 = fqmul(t1, t1);  //11011110
	t1 = fqmul(t1, t1);  //110111100
	t1 = fqmul(t1, a);   //110111101
	t1 = fqmul(t1, t1);  //1101111010
	t1 = fqmul(t1, t1);  //11011110100
	t1 = fqmul(t1, a);   //11011110101
	t1 = fqmul(t1, t1);  //110111101010	
	t1 = fqmul(t1, a);   //110111101011
	t1 = fqmul(t1, t1);  //1101111010110
	t1 = fqmul(t1, a);   //1101111010111	

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

	for(int step = NTRUPLUS_N/6; step >= 12; step = step/3)
	{
		for(int start = 0; start < NTRUPLUS_N; start += 3*step)
		{
			zeta1 = zetas[k++];
			zeta2 = zetas[k++];

			for(int i = start; i < start + step; i++)
			{
				t1 = fqmul(zeta1, r[i +   step]);
				t2 = fqmul(zeta2, r[i + 2*step]);
				t3 = fqmul(-714, t1 - t2);
	
				r[i + 2*step] = barrett_reduce(r[i] - t1 - t3);
				r[i +   step] = barrett_reduce(r[i] - t2 + t3);
				r[i         ] = barrett_reduce(r[i] + t1 + t2);
			}
		}
	}

	for(int step = 6; step >= 3; step >>= 1)
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
	int16_t t1, t2, t3;
	int16_t zeta1, zeta2;
	int k = 215;
 
	
	for(int step = 3; step <= 6; step <<= 1)
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
 
	for(int step = 12; step <= NTRUPLUS_N/6; step = 3*step)
	{
	   for(int start = 0; start < NTRUPLUS_N; start += 3*step)
	   {
		  zeta2 = zetas[k--];
		  zeta1 = zetas[k--];
 
		  for(int i = start; i < start + step; i++)
		  {
			 t1 = fqmul(-714, r[i +   step] - r[i]);
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
	   t2 = fqmul(2394, r[i] - r[i + NTRUPLUS_N/2]);
 
	   r[i               ] = fqmul(-2601, t1 - t2);
	   r[i + NTRUPLUS_N/2] = fqmul(1927, t2);
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
#ifdef PARAM_1
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
	if(det == 0) return 1;

	det   = fqinv(det);

	b[0]  = fqmul(b[0],det);
	b[1]  = fqmul(b[1],det);
	b[2]  = fqmul(b[2],det);

	r = (uint16_t)det;
	r = (uint32_t)(-r) >> 31;

	return r - 1;
}
#endif


#ifdef PARAM_2
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

	if(t2 == 0) return 1;

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


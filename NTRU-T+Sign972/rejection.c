#include "rejection.h"

static inline uint64_t myMul64Shift(uint64_t a, uint64_t b, int shift)
{
	__int128 a128 = (__int128)a;
	__int128 b128 = (__int128)b;
	__int128 c128;

	c128 = (a128 * b128 + (1 << (shift -1))) >> shift;

	return (uint64_t)c128;
}

static inline uint64_t myMul64Shift_NoRounding(uint64_t a, uint64_t b, int shift)
{
	__int128 a128 = (__int128)a;
	__int128 b128 = (__int128)b;
	__int128 c128;

	c128 = (a128 * b128) >> shift;

	return (uint64_t)c128;
}

uint64_t PExpG(uint64_t xin)
{
	uint64_t r;

	r = myMul64Shift(Coef_G[0], xin, expDiff_G[0]);
	for (int i = 1; i < DegG; i++) {
		r = myMul64Shift(Coef_G[i] - r, xin, expDiff_G[i]);
	}
	r = (Coef_G[DegG] - r);

	return r;
}

uint64_t PExpR(uint64_t xin)
{
	int64_t r;
	r = myMul64Shift(Coef_R[0], xin, expDiff_R[0]);
	for (int i = 1; i < DegR; i++) {
		r = myMul64Shift(Coef_R[i] - r, xin, expDiff_R[i]);
	}
	r = (Coef_R[DegR] - r);

	return r;
}

static void ConDiv(uint64_t x, uint64_t c, uint64_t* k, uint64_t* y, int diffE)
{
	uint64_t b;

	(*k) = 0;
	(*y) = x >> diffE;			

	for (int i = diffE - 1; i >= 0; i--) {
		(*y) <<= 1;
		(*y) |= (x >> i) & 1;
		b = LSBMASK((*y) >= c);
		(*k) |= (1ULL << i) & b;
		(*y) -= c & b;
	}
}

int SampleBernExpSimple(uint64_t x)
{
	uint64_t val, ran;

	val = PExpG(x);

#if defined(PARAM_1) || defined(PARAM_2)
    // coefficient precision = 61-bit
	ran = (((uint64_t)(rand() & 0x3fffffff) << 31) ^ rand());
#endif

#ifdef PARAM_3
	// coefficient precision = 62-bit
	ran = (((uint64_t)(rand() & 0x7fffffff) << 31) ^ rand());
#endif


	return (ran <= val) ? 1 : 0;
}

uint64_t exp_extended(int64_t x, int* exponent)
{
	uint64_t absx, q, r, temp;
	int signx = (x >= 0);

	absx = CMUX(x, -x, (int64_t)signx) << ThetaChat;

	ConDiv(absx, ValChat, &q, &r, BitGamma);

	*exponent = CMUX(vartheta2 + q, vartheta2 - (q + 1), (int64_t)signx);
	r = CMUX(r, ValChat - r, (int64_t)signx);

	r = PExpR(r);
	temp = CMUX(q * (uint64_t)EpsVal, (q+1) * (uint64_t)EpsVal, (int64_t)signx);	
	temp = myMul64Shift(r, temp, ThetaEps);											
	r = CMUX(r - temp, r + temp, (int64_t)signx);

	return r;
}

/*approx polynomial of exp(-1/sigma^2) for rejection sampling*/
int SampleBernExp(uint64_t x)
{
	uint64_t val, ran;
	int e;

	val = exp_extended(x, &e);
	val >>= (e - vartheta2);

#ifdef PARAM_1
	// coefficient precision = 59-bit
	ran = (((uint64_t)(rand() & 0x0fffffff) << 31) ^ rand());
#endif

#ifdef PARAM_2
	// coefficient precision = 60-bit
	ran = (((uint64_t)(rand() & 0x1fffffff) << 31) ^ rand());
#endif

#ifdef PARAM_3
	// coefficient precision = 61-bit
	ran = (((uint64_t)(rand() & 0x3fffffff) << 31) ^ rand());
#endif

	return (ran <= val);
}

/*approx polynomial of cosh(-1/sigma^2) for rejection sampling*/
int SampleBernCosh(int64_t x)
{
	uint64_t val1, val2;
	uint64_t val, ran;
	int e1, e2;

	uint64_t absx;
	int signx = (x >= 0);
	absx = CMUX(x, -1 * x, (int64_t)signx);

	val1 = exp_extended(-1 * absx, &e1);	// exp(+)
	val2 = exp_extended(     absx, &e2);	// exp(-)

	e2 -= e1;
	val2 = CMUX(val2 >> e2, 0, e2 <= vartheta2);
	val1 += val2;
	e1 += 1;

#ifdef PARAM_1
	// coefficient precision = 59-bit
	ran = (((uint64_t)(rand() & 0x0fffffff) << 31) ^ rand());
#endif

#ifdef PARAM_2
	// coefficient precision = 60-bit
	ran = (((uint64_t)(rand() & 0x1fffffff) << 31) ^ rand());
#endif

#ifdef PARAM_3
	// coefficient precision = 61-bit
	ran = (((uint64_t)(rand() & 0x3fffffff) << 31) ^ rand());
#endif
	val = myMul64Shift_NoRounding(ran, val1, vartheta2);

	return (val < (1ULL << e1)) ? 1 : 0;
}
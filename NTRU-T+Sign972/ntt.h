#ifndef NTT_H
#define NTT_H

#include <stdint.h>
#include "params.h"
#ifdef PARAM_1
extern const int16_t zetas[256];
#endif
#ifdef PARAM_2
extern const int16_t zetas[324];
#endif
#ifdef PARAM_3
extern const int16_t zetas[324];
#endif
void ntt(int16_t r[NTRUPLUS_N]);
void invntt(int16_t r[NTRUPLUS_N]);

#ifdef PARAM_1
void basemul(int16_t c[3], const int16_t a[3], const int16_t b[3], int16_t zeta);
int  baseinv(int16_t b[3], const int16_t a[3], int16_t zeta);
#endif

#ifdef PARAM_2
void basemul(int16_t c[3], const int16_t a[3], const int16_t b[3], int16_t zeta);
int  baseinv(int16_t b[3], const int16_t a[3], int16_t zeta);
#endif

#ifdef PARAM_3
void basemul(int16_t c[4], const int16_t a[4], const int16_t b[4], int16_t zeta);
int  baseinv(int16_t c[4], const int16_t a[4], int16_t zeta);
#endif
#endif
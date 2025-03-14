#ifndef REDUCE_H
#define REDUCE_H

#include <stdint.h>
#ifdef PARAM_1
#define QINV 46185
#endif


#if defined(PARAM_2) || defined(PARAM_3)
#define QINV 35913 // q^(-1) mod 2^16

#endif

int16_t montgomery_reduce(int32_t a);
int16_t barrett_reduce(int16_t a);
int16_t caddq(int16_t a);
int16_t csubq(int16_t a);
int16_t caddp(int16_t a);
int16_t csubp(int16_t a);
int16_t freezep(int16_t a);
int max(int16_t a, int16_t b);

#endif
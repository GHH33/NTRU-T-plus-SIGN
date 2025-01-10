#ifndef GAUSS_H
#define GAUSS_H

#include "info.h"
#include "rejection.h"
#include "params.h"
#include "poly.h"


int approxG(void);
void approxG_test(poly *y1, const unsigned char seed[CRHBYTES], uint16_t nonce);
void sample_y(poly *a1, poly *a2, uint8_t *b, const unsigned char seed[CRHBYTES], uint16_t nonce);
#endif
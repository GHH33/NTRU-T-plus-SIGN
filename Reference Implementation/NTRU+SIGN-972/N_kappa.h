#ifndef N_KAPPA_H
#define N_KAPPA_H

#include <math.h>
#include <stdlib.h>
#include "params.h"
#include "poly.h"

void shift_mod_ring(poly *a, poly*b);
void heapify(int32_t *heap, int size, int root);
int32_t max_tau_heap(poly *a);
int32_t max_tau_heap2(int32_t a[NTRUPLUS_N]);
int32_t N_kappa(poly *a, poly *b);



#endif // N_KAPPA_H
#include "N_kappa.h"
#include "poly.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//a=bx in predefined trinomial ring Z_q[x]/<x^n-x^(n/2)+1>
void shift_mod_ring(poly *a, poly*b)
{
    poly tmp = *b; 

    for (int i = 0; i<NTRUPLUS_N-1;i++){
        a->coeffs[i+1]=tmp.coeffs[i];
    }
    
    a->coeffs[0] = (-1)*tmp.coeffs[NTRUPLUS_N-1];
    a->coeffs[NTRUPLUS_N/2] += tmp.coeffs[NTRUPLUS_N-1];
    
}



void heapify(int32_t *heap, int size, int root) 
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != root) {
        int32_t temp = heap[root];
        heap[root] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

int32_t max_tau_heap(poly *a) 
{
    int32_t heap[NTRUPLUS_TAU];
    int heap_size = 0;

    // Configurate initial heap with tau elements
    for (int i = 0; i < NTRUPLUS_TAU; i++) {
        heap[heap_size++] = a->coeffs[i];
    }
    for (int i = NTRUPLUS_TAU / 2 - 1; i >= 0; i--) {
        heapify(heap, heap_size, i);
    }

    // Maintain max tau elements compared to other coefficients
    for (int i = NTRUPLUS_TAU; i < NTRUPLUS_N; i++) {
        if (a->coeffs[i] > heap[0]) {
            heap[0] = a->coeffs[i];
            heapify(heap, heap_size, 0);
        }
    }

    // Sum of all elements in heap
    int32_t total = 0;
    for (int i = 0; i < heap_size; i++) {
        total += heap[i];
    }

    return total;
}

int32_t max_tau_heap2(int32_t a[NTRUPLUS_N]) 
{
    int32_t heap[NTRUPLUS_TAU];
    int heap_size = 0;

    for (int i = 0; i < NTRUPLUS_TAU; i++) {
        heap[heap_size++] = a[i];
    }
    for (int i = NTRUPLUS_TAU / 2 - 1; i >= 0; i--) {
        heapify(heap, heap_size, i);
    }

    for (int i = NTRUPLUS_TAU; i < NTRUPLUS_N; i++) {
        if (a[i] > heap[0]) {
            heap[0] = a[i];
            heapify(heap, heap_size, 0);
        }
    }

    int32_t total = 0;
    for (int i = 0; i < heap_size; i++) {
        total += heap[i];
    }

    return total;
}

int32_t N_kappa(poly *a, poly *b)
{
    poly tmp1 = *a, tmp2 = *b;
    poly row_max;
    int32_t middle1[2*NTRUPLUS_N], middle2[2*NTRUPLUS_N]; 
    
    int32_t **T = (int32_t **)malloc(NTRUPLUS_N * sizeof(int32_t *));
    if (!T) {
        perror("Memory allocation failed");
        return -1;
    }

    for (int i = 0; i < NTRUPLUS_N; i++) {
        T[i] = (int32_t *)malloc(NTRUPLUS_N * sizeof(int32_t));
         if (!T[i]) {
            perror("Memory allocation failed");
            return -1;
        }
    }


    T[0][0] = innerproduct(a, a) + innerproduct(b, b);
    middle1[0] = a->coeffs[NTRUPLUS_N/2-1];
    middle1[1] = a->coeffs[NTRUPLUS_N/2];
    middle2[0] = b->coeffs[NTRUPLUS_N/2-1];
    middle2[1] = b->coeffs[NTRUPLUS_N/2];

    for (int j = 1; j<NTRUPLUS_N; j++){
        shift_mod_ring(&tmp1, &tmp1);
        shift_mod_ring(&tmp2, &tmp2);
        T[0][j] = innerproduct(a, &tmp1) + innerproduct(b, &tmp2);
        T[j][0] = T[0][j];
        middle1[2*j] = tmp1.coeffs[NTRUPLUS_N/2-1];
        middle1[2*j + 1] = tmp1.coeffs[NTRUPLUS_N/2];
        middle2[2*j] = tmp2.coeffs[NTRUPLUS_N/2-1];
        middle2[2*j + 1] = tmp2.coeffs[NTRUPLUS_N/2];
    }
    row_max.coeffs[0] = max_tau_heap2(T[0]);


    for (int i = 1; i<NTRUPLUS_N; i++){
        for (int j = i; j < NTRUPLUS_N; j++){
            T[i][j] = T[i-1][j-1];
            T[i][j] += -middle1[2*(i-1)] * middle1[2*(j-1)] - middle2[2*(i-1)] * middle2[2*(j-1)];
            T[i][j] += middle1[2*i + 1] * middle1[2*j + 1] + middle2[2*i + 1] * middle2[2*j + 1];

            if (i != j){
                T[j][i] = T[i][j];
            }
        }
        row_max.coeffs[i] = max_tau_heap2(T[i]);
        free(T[i-1]);
    }

    return max_tau_heap(&row_max);
}
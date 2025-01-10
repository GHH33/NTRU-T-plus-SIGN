#ifndef PARAMS_H
#define PARAMS_H

#define PARAM_1
#define NTT_s

#define SEEDBYTES 32
#define CRHBYTES 64
#define CRYPTO_C_BYTES 32
#define CRYPTO_RANDOMBYTES 32

#ifdef PARAM_1
#define CRYPTO_ALGNAME "NTRU-T+SIGN768"
#define NTRUPLUS_N 768
#define NTRUPLUS_Q 7681
#define NTRUPLUS_logQ 13
#define NTRUPLUS_T 1
#define NTRUPLUS_TAU 33
#define NTRUPLUS_d 8
#define B_sc 385
#define B2bound 89019225
#define Binftybound 1070

#define qhat 3841
#define Rqhat 2044
#define Rmodq -3593
#define R2modq -2112
#define ntt_level 256

#define BASE_ENC_HB_Z1 80
#define BASE_ENC_H 80
#define ENC_bound 391
#define CRYPTO_BYTES 1193 // 32 + 8*768/8 + 391 + 2


#endif

#ifdef PARAM_2
#define CRYPTO_ALGNAME "NTRU-T+SIGN972"
#define NTRUPLUS_N 972
#define NTRUPLUS_Q 9721
#define NTRUPLUS_logQ 14
#define NTRUPLUS_T -7
#define NTRUPLUS_TAU 38
#define NTRUPLUS_d 9
#define B_sc 470
#define B2bound 196560400
#define Binftybound 1550

#define qhat 4861
#define Rqhat 3605
#define Rmodq -2511  //2^16 mod+- q
#define R2modq -3808
#define ntt_level 324

#define BASE_ENC_HB_Z1 100
#define BASE_ENC_H 100
#define ENC_bound 357
#define CRYPTO_BYTES 1485 // 32 + (9*972+4)/8 + 357 + 2

#endif

#ifdef PARAM_3
#define CRYPTO_ALGNAME "NTRU-T+SIGN1296"
#define NTRUPLUS_N 1296
#define NTRUPLUS_Q 9721
#define NTRUPLUS_logQ 14
#define NTRUPLUS_T -7
#define NTRUPLUS_TAU 41
#define NTRUPLUS_d 9
#define B_sc 558
#define B2bound 338376025
#define Binftybound 1630

#define qhat 4861
#define Rqhat 3605
#define Rmodq -2511
#define R2modq -3808
#define ntt_level 324

#define BASE_ENC_HB_Z1 160
#define BASE_ENC_H 160
#define ENC_bound 531
#define CRYPTO_BYTES 2023 // 32 + 9*1296/8 + 485 + 2 


#endif
#define NTRUPLUS_P ((NTRUPLUS_Q - (NTRUPLUS_T)) / ALPHA_HINT) 

#define NTRUPLUS_GAMMA2N (NTRUPLUS_GAMMA * NTRUPLUS_GAMMA * NTRUPLUS_N -1)
#define halfN NTRUPLUS_N/2
#define halfp NTRUPLUS_P/2
#define ALPHA_HINT (1 << NTRUPLUS_d)
#define HALF_ALPHA_HINT (ALPHA_HINT >> 1) // ALPHA / 2
#define B_scsquare (B_sc*B_sc)

#define POLYC_PACKEDBYTES (NTRUPLUS_N >> 3)       // 1bit * N / 8bits
#define POLYQ_PACKEDBYTES ((NTRUPLUS_logQ * NTRUPLUS_N) >> 3) 
#define POLY_HIGHBITS_PACKEDBYTES (NTRUPLUS_N * 3 / 4)
#define CRYPTO_PUBLICKEYBYTES (POLYQ_PACKEDBYTES)                  // seed + b
#define CRYPTO_SECRETKEYBYTES (3 * POLYQ_PACKEDBYTES + SEEDBYTES)  // pk + s + K

#endif
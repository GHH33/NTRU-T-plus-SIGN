#ifndef PARAMS_H
#define PARAMS_H

#define PARAM_1
#define NTT_s

#define SEEDBYTES 32
#define CRHBYTES 64
#define CRYPTO_C_BYTES 32
#define CRYPTO_RANDOMBYTES 32


#ifdef PARAM_1
#define CRYPTO_ALGNAME "NTRU+SIGN648"
#define NTRUPLUS_N 648
#define NTRUPLUS_Q 7129
#define NTRUPLUS_logQ 13
#define NTRUPLUS_T -39
#define NTRUPLUS_TAU 35
#define NTRUPLUS_d 8
#define B_sc 372
#define B2bound 72250000
#define Binftybound 1300

#define qhat -3564
#define Rqhat 4252   //2^15 mod q
#define Rmodq 1375   // 2^16 mod +- q
#define R2modq 1440  //2^32 mod +- q
#define ntt_level 162

#define BASE_ENC_HB_Z1 80
#define BASE_ENC_H 80
#define ENC_bound 327
#define CRYPTO_BYTES 1009 // 32 + 8*648/8 + 327 + 2

#endif

#ifdef PARAM_2
#define CRYPTO_ALGNAME "NTRU+SIGN972"
#define NTRUPLUS_N 972
#define NTRUPLUS_Q 9721
#define NTRUPLUS_logQ 14
#define NTRUPLUS_T -7
#define NTRUPLUS_TAU 38
#define NTRUPLUS_d 8
#define B_sc 466
#define B2bound 156750400
#define Binftybound 1400

#define qhat -4860 //2^(-1) mod+-q
#define Rqhat 3605
#define Rmodq -2511  //2^16 mod+- q
#define R2modq -3808
#define ntt_level 324

#define BASE_ENC_HB_Z1 150
#define BASE_ENC_H 150
#define ENC_bound 551
#define CRYPTO_BYTES 1557 // 32 + (8*972)/8 + 551 + 2

#endif

#ifdef PARAM_3
#define CRYPTO_ALGNAME "NTRU+SIGN1296"
#define NTRUPLUS_N 1296
#define NTRUPLUS_Q 9721
#define NTRUPLUS_logQ 14
#define NTRUPLUS_T -7
#define NTRUPLUS_TAU 41
#define NTRUPLUS_d 9
#define B_sc 552
#define B2bound 334633849
#define Binftybound 1630

#define qhat 4861
#define Rqhat 3605
#define Rmodq -2511
#define R2modq -3808
#define ntt_level 324

#define BASE_ENC_HB_Z1 160
#define BASE_ENC_H 160
#define ENC_bound 528
#define CRYPTO_BYTES 2020 // 32 + 9*1296/8 + 528 + 2 


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

#define CRYPTO_PUBLICKEYBYTES (POLYQ_PACKEDBYTES)                                      // seed + b
#define CRYPTO_SECRETKEYBYTES (3 * POLYQ_PACKEDBYTES + SEEDBYTES)  // pk + s + K

#if defined(PARAM_1) || defined(PARAM_3) 
#define POLY_HIGHBITS_PACKEDBYTES (NTRUPLUS_N * 3 / 4)
#endif

#ifdef PARAM_2
#define POLY_HIGHBITS_PACKEDBYTES ((NTRUPLUS_N * 7 - 4)/ 8)
#endif

#endif
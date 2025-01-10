#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "poly.h"
#include "reduce.h"
#include "sign.h"
#include "packing.h"
#include "sampler.h"
#include "gaussian.h"
#include "ntt.h"
#include "symmetric.h"
#include "randombytes.h"
#include "decompose.h"
#include "rejection.h"

#define TEST_LOOP 1000

uint64_t t[TEST_LOOP];
extern unsigned long long rejyzctr;
extern unsigned long long ctr_reject;


static int64_t cpucycles(void)
{
  unsigned int hi, lo;

    __asm__ __volatile__ ("rdtsc\n\t" : "=a" (lo), "=d"(hi));

    return ((int64_t)lo) | (((int64_t)hi) << 32);
}

static int test_Correctness()
{
	double rejyzctr = .0;
	uint8_t pk[CRYPTO_PUBLICKEYBYTES] = {0};
	uint8_t sk[CRYPTO_SECRETKEYBYTES] = {0};


	unsigned long long siglen = 0;
	uint8_t sig[CRYPTO_BYTES] = {0};
	uint8_t msg[SEEDBYTES] = {0};
	randombytes(msg, SEEDBYTES);

	int result = 0;
	unsigned long long kcycles, ecycles, dcycles;
	unsigned long long cycles1, cycles2, cycles3, cycles4, cycles5, cycles6;

	kcycles=0;
	ecycles=0;
	dcycles=0;
	for(int i = 0; i < TEST_LOOP; i++)
	{
		cycles1 = cpucycles();
		crypto_sign_keypair(pk, sk);
		cycles2 = cpucycles();
		kcycles += cycles2-cycles1;

		cycles3 = cpucycles();
		crypto_sign(sig, &siglen, msg, SEEDBYTES, sk);
		cycles4 = cpucycles();
		ecycles += cycles4-cycles3;
        

		rejyzctr += ctr_reject;

		cycles5 = cpucycles();
		result += crypto_sign_verify(msg, SEEDBYTES, sig, siglen, pk);
		cycles6 = cpucycles();
		dcycles += cycles6-cycles5;
		
	}  

	printf("  KeyGen runs in ................. %8lld cycles", kcycles/TEST_LOOP);
	printf("\n"); 

	printf("  Sign runs in ................. %8lld cycles", ecycles/TEST_LOOP);
	printf("\n"); 

	printf("  Verify runs in ................. %8lld cycles", dcycles/TEST_LOOP);
	printf("\n"); 

	printf("Statistical Repetitions of Rejection Sampling: %.2f\n",(double)rejyzctr/TEST_LOOP);
	printf("\n");


	if(result == 0)    {
		printf("Verification Success!\n");
	}

	else{
		printf("Verification Fail\n");
	}

	return 0;
}


int main(void)
{
   printf("=================== PARAMETERS ===================\n");
   printf("ALGORITHM_NAME  : %s\n", CRYPTO_ALGNAME);
   printf("PUBLICKEYBYTES  : %d\n", CRYPTO_PUBLICKEYBYTES);
   printf("SECRETKEYBYTES  : %d\n", CRYPTO_SECRETKEYBYTES);
   printf("SIGNATUREBYTES  : %d\n", CRYPTO_BYTES);
   printf("\n");

    test_Correctness();
    
	
    return 0;
}

#include "gaussian.h"
#include "fips202.h"
#include "symmetric.h"

#include <stdint.h>
#include "params.h"
#include "poly.h"
#include <stdlib.h>



static int approxBaseGplus(void)
{
	int result = 0;

	__int128 r;

	// 86 bits random
	r = (__int128)rand();
	r ^= (__int128)rand() << 31;
	r ^= (__int128)(rand() & 0xffffff) << 62;


	// comparing and counting
	for (int i = 0; i < w1; i++) {
		result += (r > CDT[i]) ? 1 : 0;
	}

	return result;
}

static inline int approxGplus(void)
{
	int y1, y0, x;

	while (1) {
		y1 = approxBaseGplus();
		y0 = rand() & KMASK;

		x = y0 * (y0 + (y1 << 1) * K);
		if (SampleBernExpSimple(x) == 1) {
			return y1 * K + y0;
		}
	}
}

int approxG(void)
{
	int y, b;

	y = approxGplus();
	b = rand() & 0x01;

	while (y == 0 && b == 0) {
		y = approxGplus();
		b = rand() & 0x01;
	}

	b = rand() & 0x01;

	return ((b << 1) - 1) * y;
}


void sample_2y(poly *a1, poly *a2, uint8_t *b, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
	
 	uint8_t tmp[CRHBYTES + 2];

	for (int i = 0; i < NTRUPLUS_N; i++){
		a1->coeffs[i] = approxBaseGplus();
		a2->coeffs[i] = approxBaseGplus();
	}
    	
    for (int i = 0; i < CRHBYTES; i++)
    {
      tmp[i] = seed[i];
    }
    tmp[CRHBYTES + 0] = nonce >> 0;     
    tmp[CRHBYTES + 1] = nonce >> 8;
    shake256(b, 1, tmp, CRHBYTES+2);
    *b = *b & 0x1;

	
}

static int approxBaseGplus_test(const unsigned char *buf)
{
    int result = 0;

	__int128 r;

	// 86 bits random 
	r = (__int128)buf[0];
	r ^= (__int128)buf[1] << 8;
	r ^= (__int128)buf[2] << 16;
	r ^= (__int128)buf[3] << 24;
	r ^= (__int128)buf[4] << 32;
	r ^= (__int128)buf[5] << 40;
	r ^= (__int128)buf[6] << 48;
	r ^= (__int128)buf[7] << 56;
	r ^= (__int128)buf[8] << 64;
	r ^= (__int128)buf[9] << 72;
	r ^= (__int128)(buf[10] & 0x3f) << 80;

	// comparing and counting
	for (int i = 0; i < w1; i++) {
		result += (r > CDT[i]) ? 1 : 0;
	}

	return result;
}

static inline int approxGplus_test(int16_t *a, const unsigned char *buf)
{
	int y1, y0, x;

	y1 = approxBaseGplus_test(buf);
	y0 = buf[11] & KMASK;
	x = y0 * (y0 + (y1 << 1) * K);

	if (SampleBernExpSimple(x) == 1) {
		*a = y1 * K + y0;
		return 1;
	}
	
	return 0;
	
}

#ifdef PARAM_1
#define POLY_Y_NBLOCKS ((7800 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)
void approxG_test(poly *a, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
	int b, check;
	int pos = 0;
	int ctr = 0;
	int off = 0;
    int16_t tmp = 0;
    uint8_t buf[POLY_Y_NBLOCKS*STREAM256_BLOCKBYTES];
    int16_t buflen = POLY_Y_NBLOCKS*STREAM256_BLOCKBYTES;
    stream256_state state;
    
    stream256_init(&state, seed, nonce);
	stream256_squeezeblocks(buf, POLY_Y_NBLOCKS, &state);


	
 	
  	while(pos + 13 < buflen) {
    	
    	check = approxGplus_test(&tmp, &buf[pos]);
    	pos += 12;
    	b = buf[pos] & 0x1;

    	while (tmp == 0 && b == 0) {
			pos++;
			check = approxGplus_test(&tmp, &buf[pos]);
			pos += 12;
			b = buf[pos] & 0x1;		
		}
    	
    	b = (buf[pos] >> 1) & 0x1;
    	a->coeffs[ctr] = ((b << 1) - 1) * tmp;
    	ctr += check;
    	pos ++;

    	if (ctr == 648){
    		break;
    	}

	}
	while(ctr < NTRUPLUS_N) {
		off = buflen % 13;
		/*for (i = 0; i < off; ++i)
            buf[i] = buf[buflen - off + i];*/

		stream256_squeezeblocks(buf, 1, &state);
		buflen = STREAM256_BLOCKBYTES + off;

		
		pos = 0;
		while(pos + 13 < buflen) {
			
			check = approxGplus_test(&tmp, &buf[pos]);
	    	pos += 12;
	    	b = buf[pos] & 0x1;
	    	
	    	while (tmp == 0 && b == 0) {
	    		pos++;
				check = approxGplus_test(&tmp, &buf[pos]);
				b = (buf[pos] >> 1) & 0x1;
			}

    		b = (buf[pos] >> 1) & 0x1;
    		a->coeffs[ctr] = ((b << 1) - 1) * tmp;
    		ctr += check;
    		pos++;

    		if (ctr == 648){
    		break;
    	}


		}
		
		if (ctr == 648){
    		break;
    	}
	}
	
}

#endif

#ifdef PARAM_2
#define POLY_Y_NBLOCKS ((16248 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)
void approxG_test(poly *a, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
	int b, check;
	int pos = 0;
	int ctr = 0;
	int i = 0;
	int off = 0;
    int16_t tmp = 0;
    uint8_t buf[POLY_Y_NBLOCKS*STREAM256_BLOCKBYTES];
    int16_t buflen = POLY_Y_NBLOCKS*STREAM256_BLOCKBYTES;
    stream256_state state;
    
    stream256_init(&state, seed, nonce);
	stream256_squeezeblocks(buf, POLY_Y_NBLOCKS, &state);
 	
  	while(pos + 13 < buflen) {
    	
    	check = approxGplus_test(&tmp, &buf[pos]);
    	pos += 12;
    	b = buf[pos] & 0x1;

    	while (tmp == 0 && b == 0) {
			pos++;
			check = approxGplus_test(&tmp, &buf[pos]);
			pos += 12;
			b = buf[pos] & 0x1;		
		}
    	
    	b = (buf[pos] >> 1) & 0x1;
    	a->coeffs[ctr] = ((b << 1) - 1) * tmp;
    	ctr += check;
    	pos ++;


	}
	while(ctr < NTRUPLUS_N) {
		off = buflen % 13;
		for (i = 0; i < off; ++i)
            buf[i] = buf[buflen - off + i];

		stream256_squeezeblocks(buf, 1, &state);
		buflen = STREAM256_BLOCKBYTES + off;
		
		pos = 0;
		while(pos + 13 < buflen) {
			
			check = approxGplus_test(&tmp, &buf[pos]);
	    	pos += 12;
	    	b = buf[pos] & 0x1;
	    	
	    	while (tmp == 0 && b == 0) {
	    		pos++;
				check = approxGplus_test(&tmp, &buf[pos]);
				b = (buf[pos] >> 1) & 0x1;
			}

    		b = (buf[pos] >> 1) & 0x1;
    		a->coeffs[ctr] = ((b << 1) - 1) * tmp;
    		ctr += check;
    		pos++;

    		if (ctr == 972){
    			break;
    		}


		}
		
		if (ctr == 972){
    		break;
    	}
	}
	
}
#endif

#ifdef PARAM_3
#define POLY_Y_NBLOCKS ((16248 + STREAM256_BLOCKBYTES - 1)/STREAM256_BLOCKBYTES)
void approxG_test(poly *a, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
	int b, check;
	int pos = 0;
	int ctr = 0;
	int i = 0;
	int off = 0;
    int16_t tmp = 0;
    uint8_t buf[POLY_Y_NBLOCKS*STREAM256_BLOCKBYTES];
    int16_t buflen = POLY_Y_NBLOCKS*STREAM256_BLOCKBYTES;
    stream256_state state;
    
    stream256_init(&state, seed, nonce);
	stream256_squeezeblocks(buf, POLY_Y_NBLOCKS, &state);
 	
  	while(pos + 13 < buflen) {
    	
    	check = approxGplus_test(&tmp, &buf[pos]);
    	pos += 12;
    	b = buf[pos] & 0x1;

    	while (tmp == 0 && b == 0) {
			pos++;
			check = approxGplus_test(&tmp, &buf[pos]);
			pos += 12;
			b = buf[pos] & 0x1;		
		}
    	
    	b = (buf[pos] >> 1) & 0x1;
    	a->coeffs[ctr] = ((b << 1) - 1) * tmp;
    	ctr += check;
    	pos ++;


	}
	while(ctr < NTRUPLUS_N) {
		off = buflen % 13;
		for (i = 0; i < off; ++i)
            buf[i] = buf[buflen - off + i];

		stream256_squeezeblocks(buf, 1, &state);
		buflen = STREAM256_BLOCKBYTES + off;
		
		pos = 0;
		while(pos + 13 < buflen) {
			
			check = approxGplus_test(&tmp, &buf[pos]);
	    	pos += 12;
	    	b = buf[pos] & 0x1;
	    	
	    	while (tmp == 0 && b == 0) {
	    		pos++;
				check = approxGplus_test(&tmp, &buf[pos]);
				b = (buf[pos] >> 1) & 0x1;
			}

    		b = (buf[pos] >> 1) & 0x1;
    		a->coeffs[ctr] = ((b << 1) - 1) * tmp;
    		ctr += check;
    		pos++;

    		if (ctr == 1296){
    			break;
    		}


		}
		
		if (ctr == 1296){
    		break;
    	}
	}
	
}
#endif

void sample_y(poly *a1, poly *a2, uint8_t *b, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
	
 	uint8_t tmp[CRHBYTES + 2];
    
	approxG_test(a1, seed, nonce++);
	approxG_test(a2, seed, nonce++);
	
    for (int i = 0; i < CRHBYTES; i++)
    {
      tmp[i] = seed[i];
    }
    tmp[CRHBYTES + 0] = nonce >> 0;     
    tmp[CRHBYTES + 1] = nonce >> 8;
    shake256(b, 1, tmp, CRHBYTES+2);
    *b = *b & 0x1;

	
}
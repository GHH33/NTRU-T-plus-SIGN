#include <stdint.h>
#include "params.h"
#include "poly.h"
#include "ntt.h"
#include "symmetric.h"
#include "sampler.h"
#include "gaussian.h"
#include <stdlib.h>


#if defined(PARAM_1) || defined(PARAM_3)
void poly_cbd1(poly *r, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
    
    uint8_t buf[NTRUPLUS_N/4];
    stream128_state state;

    stream128_init(&state, seed, nonce);
    shake128_squeeze(buf, NTRUPLUS_N/4, &state);

    for(int i = 0; i < NTRUPLUS_N/8; i++)
    {   
        r->coeffs[8*i]   =  (buf[2*i]       & 0x1) -  (buf[2*i+1]       & 0x1);
        r->coeffs[8*i+1] = ((buf[2*i] >> 1) & 0x1) - ((buf[2*i+1] >> 1) & 0x1);
        r->coeffs[8*i+2] = ((buf[2*i] >> 2) & 0x1) - ((buf[2*i+1] >> 2) & 0x1);
        r->coeffs[8*i+3] = ((buf[2*i] >> 3) & 0x1) - ((buf[2*i+1] >> 3) & 0x1);
        r->coeffs[8*i+4] = ((buf[2*i] >> 4) & 0x1) - ((buf[2*i+1] >> 4) & 0x1);
        r->coeffs[8*i+5] = ((buf[2*i] >> 5) & 0x1) - ((buf[2*i+1] >> 5) & 0x1);
        r->coeffs[8*i+6] = ((buf[2*i] >> 6) & 0x1) - ((buf[2*i+1] >> 6) & 0x1);
        r->coeffs[8*i+7] = ((buf[2*i] >> 7) & 0x1) - ((buf[2*i+1] >> 7) & 0x1);
    }
}
#endif

#if defined(PARAM_2)
void poly_cbd1(poly *r, const unsigned char seed[CRHBYTES], uint16_t nonce)
{
    
    uint8_t buf[NTRUPLUS_N/4];
    stream128_state state;

    stream128_init(&state, seed, nonce);
    shake128_squeeze(buf, NTRUPLUS_N/4, &state);


    for(int i = 0; i < NTRUPLUS_N/4; i++)
    {   
        r->coeffs[4*i]   =  (buf[i]       & 0x1) - ((buf[i] >> 4) & 0x1);
        r->coeffs[4*i+1] = ((buf[i] >> 1) & 0x1) - ((buf[i] >> 5) & 0x1);
        r->coeffs[4*i+2] = ((buf[i] >> 2) & 0x1) - ((buf[i] >> 6) & 0x1);
        r->coeffs[4*i+3] = ((buf[i] >> 3) & 0x1) - ((buf[i] >> 7) & 0x1);
       
    }

   
}
#endif

uint64_t innerproduct(poly *a1, poly *a2)
{
    int res = 0;
    
    for (int i = 0; i < NTRUPLUS_N ; i+=6)
    {
        res += a1->coeffs[i] * a2->coeffs[i];
        res += a1->coeffs[i+1] * a2->coeffs[i+1];
        res += a1->coeffs[i+2] * a2->coeffs[i+2];
        res += a1->coeffs[i+3] * a2->coeffs[i+3];
        res += a1->coeffs[i+4] * a2->coeffs[i+4];
        res += a1->coeffs[i+5] * a2->coeffs[i+5];
    }
           
    return res;
}

void poly_ntt(poly *r)
{
    ntt(r->coeffs);
}

void poly_invntt(poly *r)
{
    invntt(r->coeffs);
}

void poly_add(poly *r, const poly *a, const poly *b)
{
    for(int i = 0; i < NTRUPLUS_N; ++i)
        r->coeffs[i] = a->coeffs[i] + b->coeffs[i];
}

#if defined(PARAM_1) || defined(PARAM_2)
void poly_add_qhat(poly *r, const poly *a)
{
    for(int i = 0; i < NTRUPLUS_N/3; ++i)
    {
        r->coeffs[3*i  ] = a->coeffs[3*i] + qhat;
        r->coeffs[3*i+1] = a->coeffs[3*i+1];
        r->coeffs[3*i+2] = a->coeffs[3*i+2];
    }
}
#endif

#if defined(PARAM_3)
void poly_add_qhat(poly *r, const poly *a)
{
    for(int i = 0; i < NTRUPLUS_N/4; ++i)
    {
        r->coeffs[4*i  ] = a->coeffs[4*i] + qhat;
        r->coeffs[4*i+1] = a->coeffs[4*i+1];
        r->coeffs[4*i+2] = a->coeffs[4*i+2];
        r->coeffs[4*i+3] = a->coeffs[4*i+3];
    }
}
#endif

void poly_caddq(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] = caddq(v->coeffs[i]);
}

void poly_csubq(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] = csubq(v->coeffs[i]);
}

void poly_caddp(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] = caddp(v->coeffs[i]);
}

void poly_csubp(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] = csubp(v->coeffs[i]);
}

void poly_freezep(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] = freezep(v->coeffs[i]);
}


uint16_t poly_eqcheck(const poly *a, const poly *b){
    
    uint16_t ret = 0;

    for (int i = 0; i < NTRUPLUS_N; ++i)
    {
        ret |= a->coeffs[i] - b->coeffs[i];
    }
    return ret;
}

uint16_t c_eqcheck(const uint8_t c[CRYPTO_C_BYTES], const uint8_t c2[CRYPTO_C_BYTES]){
    
    uint16_t ret = 0;

    for (int i = 0; i < CRYPTO_C_BYTES; ++i)
    {
        ret |= c[i] - c2[i];
    }

    return ret;
}


void poly_bc(poly *v, const poly *c, uint8_t b)
{
    b = 1-b;
    for (int i = 0; i < NTRUPLUS_N; ++i)
    {
        v->coeffs[i] = c->coeffs[i] & b;
    }
}


void poly_cqhat(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] *= qhat;
}

void poly_barrett_reduce(poly *v)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
        v->coeffs[i] = barrett_reduce(v->coeffs[i]);

}

void poly_sub(poly *r, const poly *a, const poly *b)
{
    for(int i = 0; i < NTRUPLUS_N; ++i)
        r->coeffs[i] = a->coeffs[i] - b->coeffs[i];
}

void poly_cneg(poly *r, const uint8_t b)
{
    for (int i = 0; i < NTRUPLUS_N; i++)
    {
        r->coeffs[i] *= 1 - 2 * b;
    }
}

void poly_neg(poly *r)
{
    for (int i = 0; i < NTRUPLUS_N; i++)
    {
        r->coeffs[i] *= -1;
    }
}

void poly_shift(poly *r, const poly *a)
{
    for (int i = 0; i < NTRUPLUS_N; i++)
    {
        r->coeffs[i] = a->coeffs[i] << NTRUPLUS_d;
    }
}

uint64_t poly_sqnorm2(const poly *a, const poly *b)
{
    
    uint64_t ret = 0;

    for (int i = 0; i < NTRUPLUS_N; ++i)
    {
            ret += (uint64_t)a->coeffs[i] * a->coeffs[i] + b->coeffs[i] * b->coeffs[i];
    }
    return ret;
}

uint16_t poly_inftynorm(const poly *a, const poly *b)
{
    
    uint16_t ret = 0;

    for (int i = 0; i < NTRUPLUS_N; ++i) 
            ret = max(ret, abs(a->coeffs[i]));
    
    for (int i = 0; i < NTRUPLUS_N; ++i) 
            ret = max(ret, abs(b->coeffs[i]));

    return ret;
}

void poly_copy(poly *r, const poly *a)
{
    for (int i = 0; i < NTRUPLUS_N; ++i) 
            r->coeffs[i] = a->coeffs[i];   
}

#ifdef PARAM_1
void poly_basemul(poly *c, const poly *a, const poly *b)
{
    for(int i = 0; i < NTRUPLUS_N/6; i++)
    {
        basemul(c->coeffs + 6*i, a->coeffs + 6*i, b->coeffs + 6*i, zetas[128 + i]);
        basemul(c->coeffs + 6*i + 3, a->coeffs + 6*i + 3, b->coeffs + 6*i + 3, -zetas[128 + i]);
    }
}
#endif

#ifdef PARAM_2
void poly_basemul(poly *c, const poly *a, const poly *b)
{
	for(int i = 0; i < NTRUPLUS_N/6; i++)
	{
		basemul(c->coeffs + 6*i, a->coeffs + 6*i, b->coeffs + 6*i, zetas[162 + i]);
		basemul(c->coeffs + 6*i + 3, a->coeffs + 6*i + 3, b->coeffs + 6*i + 3, -zetas[162 + i]);
	}
}
#endif

#ifdef PARAM_3
void poly_basemul(poly *c, const poly *a, const poly *b)
{
    for(int i = 0; i < NTRUPLUS_N/8; i++)
    {
        basemul(c->coeffs + 8*i, a->coeffs + 8*i, b->coeffs + 8*i, zetas[162 + i]);
        basemul(c->coeffs + 8*i + 4, a->coeffs + 8*i + 4, b->coeffs + 8*i + 4, -zetas[162 + i]);
    }
}
#endif

#ifdef PARAM_1
int poly_baseinv(poly *r, const poly *a)
{
    int result = 0;

    for(int i = 0; i < NTRUPLUS_N/6; i++)
    {
        result += baseinv(r->coeffs + 6*i, a->coeffs + 6*i, zetas[128 + i]);
        result += baseinv(r->coeffs + 6*i + 3, a->coeffs + 6*i + 3, -zetas[128 + i]);
     }

    return result;
}
#endif

#ifdef PARAM_2
int poly_baseinv(poly *r, const poly *a)
{
	int result = 0;

	for(int i = 0; i < NTRUPLUS_N/6; i++)
	{
		result += baseinv(r->coeffs + 6*i, a->coeffs + 6*i, zetas[162 + i]);
		result += baseinv(r->coeffs + 6*i + 3, a->coeffs + 6*i + 3, -zetas[162 + i]);
	 }

	return result;
}
#endif

#ifdef PARAM_3
int poly_baseinv(poly *r, const poly *a)
{
    int result = 0;

    for(int i = 0; i < NTRUPLUS_N/8; i++)
    {
        result += baseinv(r->coeffs + 8*i, a->coeffs + 8*i, zetas[162 + i]);
        result += baseinv(r->coeffs + 8*i + 4, a->coeffs + 8*i + 4, -zetas[162 + i]);
     }

    return result;
}
#endif


#if defined(PARAM_1)
void polyq_pack(uint8_t *r, const poly *a)
{
    int i;

    for(i=0;i<NTRUPLUS_N/8;i++){
        int16_t t[8];

        for(int j = 0; j < 8 ; j++)\
        {
            t[j] = barrett_reduce(a->coeffs[8*i+j]);
            t[j] += (t[j] >> 15) & NTRUPLUS_Q;
        }

    
        r[13*i+ 0] =  t[0];
        r[13*i+ 1] = (t[0] >>  8) | ((t[1] & 0x07) << 5);
        r[13*i+ 2] = (t[1] >>  3);
        r[13*i+ 3] = (t[1] >> 11) | (t[2] << 2);
        r[13*i+ 4] = (t[2] >>  6) | (t[3] << 7);
        r[13*i+ 5] = (t[3] >>  1);
        r[13*i+ 6] = (t[3] >>  9) | (t[4] << 4);
        r[13*i+ 7] = (t[4] >>  4);
        r[13*i+ 8] = (t[4] >> 12) | (t[5] << 1);
        r[13*i+ 9] = (t[5] >>  7) | (t[6] << 6);
        r[13*i+10] = (t[6] >>  2);
        r[13*i+11] = (t[6] >> 10) | (t[7] << 3);
        r[13*i+12] = (t[7] >>  5);
    }

}

void polyq_unpack(poly *r, const uint8_t *a)
{
    int i;
    for(i=0;i<NTRUPLUS_N/8;i++)
    {
        r->coeffs[8*i+0] =  a[13*i+ 0]       | (((uint16_t)a[13*i+ 1] & 0x1f) << 8);
        r->coeffs[8*i+1] = (a[13*i+ 1] >> 5) | (((uint16_t)a[13*i+ 2]       ) << 3) | (((uint16_t)a[13*i+ 3] & 0x03) << 11);
        r->coeffs[8*i+2] = (a[13*i+ 3] >> 2) | (((uint16_t)a[13*i+ 4] & 0x7f) << 6);
        r->coeffs[8*i+3] = (a[13*i+ 4] >> 7) | (((uint16_t)a[13*i+ 5]       ) << 1) | (((uint16_t)a[13*i+ 6] & 0x0f) <<  9);
        r->coeffs[8*i+4] = (a[13*i+ 6] >> 4) | (((uint16_t)a[13*i+ 7]       ) << 4) | (((uint16_t)a[13*i+ 8] & 0x01) << 12);
        r->coeffs[8*i+5] = (a[13*i+ 8] >> 1) | (((uint16_t)a[13*i+ 9] & 0x3f) << 7);
        r->coeffs[8*i+6] = (a[13*i+ 9] >> 6) | (((uint16_t)a[13*i+10]       ) << 2) | (((uint16_t)a[13*i+11] & 0x07) << 10);
        r->coeffs[8*i+7] = (a[13*i+11] >> 3) | (((uint16_t)a[13*i+12]       ) << 5);
    }
}
#endif


#if defined(PARAM_2) || defined(PARAM_3)
void polyq_pack(uint8_t *r, const poly *a)
{
    int i;

    for(i=0;i<NTRUPLUS_N/4;i++){
        int16_t t[4];

        for(int j = 0; j < 4 ; j++)\
        {
            t[j] = barrett_reduce(a->coeffs[4*i+j]);
            t[j] += (t[j] >> 15) & NTRUPLUS_Q;
        }

    
        r[7*i+ 0] =  t[0];
        r[7*i+ 1] = (t[0] >>  8) | ((t[1] & 0x03) << 6);
        r[7*i+ 2] = (t[1] >>  2);
        r[7*i+ 3] = (t[1] >> 10) | ((t[2] & 0x0f) << 4);
        r[7*i+ 4] = (t[2] >>  4);
        r[7*i+ 5] = (t[2] >> 12) | ((t[3] & 0x3f) << 2); 
        r[7*i+ 6] = (t[3] >>  6);
        
    }

}

void polyq_unpack(poly *r, const uint8_t *a)
{
    int i;
    for(i=0;i<NTRUPLUS_N/4;i++)
    {
        r->coeffs[4*i+0] =  a[7*i+ 0]       | (((uint16_t)a[7*i+ 1] & 0x3f) << 8);
        r->coeffs[4*i+1] = (a[7*i+ 1] >> 6) | (((uint16_t)a[7*i+ 2]       ) << 2) | (((uint16_t)a[7*i+ 3] & 0x0f) << 10);
        r->coeffs[4*i+2] = (a[7*i+ 3] >> 4) | (((uint16_t)a[7*i+ 4]       ) << 4) | (((uint16_t)a[7*i+ 5] & 0x03) << 12);            
        r->coeffs[4*i+3] = (a[7*i+ 5] >> 2) | (((uint16_t)a[7*i+ 6]       ) << 6);
    }
}
#endif

void polyeta_pack(uint8_t *r, const poly *a)
{
    unsigned int i;
    uint8_t t[8];

    for (i = 0; i < NTRUPLUS_N / 4; ++i)
{
        t[0] = 1 - a->coeffs[4 * i + 0];
        t[1] = 1 - a->coeffs[4 * i + 1];
        t[2] = 1 - a->coeffs[4 * i + 2];
        t[3] = 1 - a->coeffs[4 * i + 3];
        r[i] = t[0] >> 0;
        r[i] |= t[1] << 2;
        r[i] |= t[2] << 4;
        r[i] |= t[3] << 6;
    }
}

void polyeta_unpack(poly *r, const uint8_t *a)
{
    unsigned int i;
    for (i = 0; i < NTRUPLUS_N / 4; ++i)
{
        r->coeffs[4 * i + 0] = a[i] >> 0;
        r->coeffs[4 * i + 0] &= 0x3;

        r->coeffs[4 * i + 1] = a[i] >> 2;
        r->coeffs[4 * i + 1] &= 0x3;

        r->coeffs[4 * i + 2] = a[i] >> 4;
        r->coeffs[4 * i + 2] &= 0x3;

        r->coeffs[4 * i + 3] = a[i] >> 6;
        r->coeffs[4 * i + 3] &= 0x3;

        r->coeffs[4 * i + 0] = 1 - r->coeffs[4 * i + 0];
        r->coeffs[4 * i + 1] = 1 - r->coeffs[4 * i + 1];
        r->coeffs[4 * i + 2] = 1 - r->coeffs[4 * i + 2];
        r->coeffs[4 * i + 3] = 1 - r->coeffs[4 * i + 3];
    }
}

void poly_pack_highbits(uint8_t *buf, const poly *a)
{
    unsigned int i;
    for (i = 0; i < NTRUPLUS_N / 4; i++)
{
        buf[3 * i + 0] =   a->coeffs[4 * i + 0];
        buf[3 * i + 0] |= (a->coeffs[4 * i + 1] << 6) & 0xff;

        buf[3 * i + 1] =  (a->coeffs[4 * i + 1] >> 2) & 0x0f;
        buf[3 * i + 1] |= (a->coeffs[4 * i + 2] << 4) & 0xff;

        buf[3 * i + 2] =  (a->coeffs[4 * i + 2] >> 4) & 0x03;
        buf[3 * i + 2] |= (a->coeffs[4 * i + 3] << 2) & 0xff;
    }
}

#if defined(PARAM_1)
void poly_decomposed_pack(uint8_t *buf, const poly *a)
{
    for (int i = 0; i < NTRUPLUS_N; i++)
    {
        buf[i] = a->coeffs[i];
    }
}

void poly_decomposed_unpack(poly *a, const uint8_t *buf)
{
    for(int i = 0; i < NTRUPLUS_N; i++)
    {
        a->coeffs[i] = buf[i];
    }
}
#endif

#if defined(PARAM_2)
void poly_decomposed_pack(uint8_t *buf, const poly *a)
{
    for (int i = 0; i < NTRUPLUS_N / 8 ; i++)
    {
        buf[9*i+ 0] =  a->coeffs[8*i + 0];
        buf[9*i+ 1] = (a->coeffs[8*i + 0] >>  8) | ((a->coeffs[8*i + 1] & 0x7f) << 1);
        buf[9*i+ 2] = (a->coeffs[8*i + 1] >>  7) | ((a->coeffs[8*i + 2] & 0x3f) << 2);
        buf[9*i+ 3] = (a->coeffs[8*i + 2] >>  6) | ((a->coeffs[8*i + 3] & 0x1f) << 3);
        buf[9*i+ 4] = (a->coeffs[8*i + 3] >>  5) | ((a->coeffs[8*i + 4] & 0x0f) << 4);
        buf[9*i+ 5] = (a->coeffs[8*i + 4] >>  4) | ((a->coeffs[8*i + 5] & 0x07) << 5); 
        buf[9*i+ 6] = (a->coeffs[8*i + 5] >>  3) | ((a->coeffs[8*i + 6] & 0x03) << 6); 
        buf[9*i+ 7] = (a->coeffs[8*i + 6] >>  2) | ((a->coeffs[8*i + 7] & 0x01) << 7); 
        buf[9*i+ 8] = (a->coeffs[8*i + 7] >>  1); 
    }

    buf[1089] =  a->coeffs[968];
    buf[1090] = (a->coeffs[968] >>  8) | ((a->coeffs[969] & 0x7f) << 1);
    buf[1091] = (a->coeffs[969] >>  7) | ((a->coeffs[970] & 0x3f) << 2);
    buf[1092] = (a->coeffs[970] >>  6) | ((a->coeffs[971] & 0x1f) << 3);
    buf[1093] = (a->coeffs[971] >>  5);


}

void poly_decomposed_unpack(poly *a, const uint8_t *buf)
{
 
    for (int i = 0; i < NTRUPLUS_N / 8 ; i++)
    {
        a->coeffs[8*i + 0] = buf[9*i + 0]        | (((uint16_t)buf[9*i + 1] & 0x01) << 8);
        a->coeffs[8*i + 1] = (buf[9*i + 1] >> 1) | (((uint16_t)buf[9*i + 2] & 0x03) << 7);
        a->coeffs[8*i + 2] = (buf[9*i + 2] >> 2) | (((uint16_t)buf[9*i + 3] & 0x07) << 6);
        a->coeffs[8*i + 3] = (buf[9*i + 3] >> 3) | (((uint16_t)buf[9*i + 4] & 0x0f) << 5);
        a->coeffs[8*i + 4] = (buf[9*i + 4] >> 4) | (((uint16_t)buf[9*i + 5] & 0x1f) << 4);
        a->coeffs[8*i + 5] = (buf[9*i + 5] >> 5) | (((uint16_t)buf[9*i + 6] & 0x3f) << 3);
        a->coeffs[8*i + 6] = (buf[9*i + 6] >> 6) | (((uint16_t)buf[9*i + 7] & 0x7f) << 2);
        a->coeffs[8*i + 7] = (buf[9*i + 7] >> 7) | (((uint16_t)buf[9*i + 8]) << 1);
    }


    a->coeffs[968] = buf[1089]        | (((uint16_t)buf[1090] & 0x01) << 8);
    a->coeffs[969] = (buf[1090] >> 1) | (((uint16_t)buf[1091] & 0x03) << 7);
    a->coeffs[970] = (buf[1091] >> 2) | (((uint16_t)buf[1092] & 0x07) << 6);
    a->coeffs[971] = (buf[1092] >> 3) | (((uint16_t)buf[1093] & 0x0f) << 5);
}
#endif

#if defined(PARAM_3)
void poly_decomposed_pack(uint8_t *buf, const poly *a)
{
    for (int i = 0; i < NTRUPLUS_N/8; i++)
    {
        buf[9*i+ 0] =  a->coeffs[8*i + 0];
        buf[9*i+ 1] = (a->coeffs[8*i + 0] >>  8) | ((a->coeffs[8*i + 1] & 0x7f) << 1);
        buf[9*i+ 2] = (a->coeffs[8*i + 1] >>  7) | ((a->coeffs[8*i + 2] & 0x3f) << 2);
        buf[9*i+ 3] = (a->coeffs[8*i + 2] >>  6) | ((a->coeffs[8*i + 3] & 0x1f) << 3);
        buf[9*i+ 4] = (a->coeffs[8*i + 3] >>  5) | ((a->coeffs[8*i + 4] & 0x0f) << 4);
        buf[9*i+ 5] = (a->coeffs[8*i + 4] >>  4) | ((a->coeffs[8*i + 5] & 0x07) << 5); 
        buf[9*i+ 6] = (a->coeffs[8*i + 5] >>  3) | ((a->coeffs[8*i + 6] & 0x03) << 6); 
        buf[9*i+ 7] = (a->coeffs[8*i + 6] >>  2) | ((a->coeffs[8*i + 7] & 0x01) << 7); 
        buf[9*i+ 8] = (a->coeffs[8*i + 7] >>  1); 
    }
}

void poly_decomposed_unpack(poly *a, const uint8_t *buf)
{
    for(int i = 0; i < NTRUPLUS_N/8; i++)
    {
        a->coeffs[8*i+0] =  buf[9*i+ 0]       | (((uint16_t)buf[9*i+ 1] & 0x01) << 8);
        a->coeffs[8*i+1] = (buf[9*i+ 1] >> 1) | (((uint16_t)buf[9*i+ 2] & 0x03) << 7);
        a->coeffs[8*i+2] = (buf[9*i+ 2] >> 2) | (((uint16_t)buf[9*i+ 3] & 0x07) << 6);
        a->coeffs[8*i+3] = (buf[9*i+ 3] >> 3) | (((uint16_t)buf[9*i+ 4] & 0x0f) << 5);
        a->coeffs[8*i+4] = (buf[9*i+ 4] >> 4) | (((uint16_t)buf[9*i+ 5] & 0x1f) << 4);
        a->coeffs[8*i+5] = (buf[9*i+ 5] >> 5) | (((uint16_t)buf[9*i+ 6] & 0x3f) << 3);
        a->coeffs[8*i+6] = (buf[9*i+ 6] >> 6) | (((uint16_t)buf[9*i+ 7] & 0x7f) << 2);
        a->coeffs[8*i+7] = (buf[9*i+ 7] >> 7) | (((uint16_t)buf[9*i+ 8] ) << 1);
    }
}
#endif

void poly_compose(poly *a, const poly *ha, const poly *la)
{
    for (int i = 0; i < NTRUPLUS_N; ++i)
    {
        a->coeffs[i] = (ha->coeffs[i] << NTRUPLUS_d) + la->coeffs[i];
        a->coeffs[i] -= ((~(la->coeffs[i] - HALF_ALPHA_HINT)) & ALPHA_HINT);
    }
}


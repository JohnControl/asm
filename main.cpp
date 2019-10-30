#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

#include "timing.h"
/*
 Data addresses need to be 16-byte (128 bits) aligned to be loaded/stored for SSE, 32-byte aligned for AVX/AVX2 and 64-byte aligned for AVX512
*/

__attribute__ ((aligned (32))) float data256[8] = {0, 1, 2, 3, 4, 5, 6, 7};
__attribute__ ((aligned (64))) float data512[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
__attribute__ ((aligned (64))) float data512_2[16] = {0};
 
void func(void);
 
int main(void)
{
	

	int64_t i;
	Time time1;
	
	//time1.tic();
  	

	asm("mov eax, 776\n");

		
	/*
	for(i = 0; i < 1000000000; i++)
	{
		func();
	}
	

	time1.toc();
	*/	
		/*  asm(".intel_syntax noprefix\n"
        "mov rax, 1099511627776           \n"
		"        \n"
		"VPSRLVQ ymm1,ymm2,ymm3\n");*/
		
		/*
		asm("vmovups ymm0, %0" 
		:
		: "m" (data256));
			
		
		asm("vmovups %0, ymm0": "=m" (data256));
		
		printf("%f\n", data256[5]);
		
		*/
		//asm("vmovups zmm0, %0":  :"m" (data512));
		asm("vmovups %0, zmm0": "=m" (data512_2));

	for(size_t i = 0; i < 16; i++)
	{
		printf("%f\n",data512_2[i]);
	}
		
	//uint64_t iiii = 18446744073709551615ULL;

	//printf("elapsed time = %llu nanoseconds\n", time1.elapsed());
		
}
void func(void)
{
	asm("vmovups ymm0, %0" 
	:
	: "m" (data256));
    //printf("The answer is %d.\n", get_random());
	//return printf("%" PRId64 "\n", get_random());
}
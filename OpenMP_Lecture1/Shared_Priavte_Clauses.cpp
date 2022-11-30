#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DS_timer.h"

#define numThreads (4)
#define VECTOR_SIZE (134217728)

int main(void)
{
	
	int a = 0;
	int re[4] = { 0 };

	#pragma omp parallel for num_threads(4) shared(re) private(a)
	for (int i = 0; i < 4; i++)
	{
		a = i;
		a = a*a;
		re[i] = a;
	}

	for (int i = 0; i < 4; i++)
		printf("[Thread %d] a = %d\n", i, re[i]);

	
	getchar();
}

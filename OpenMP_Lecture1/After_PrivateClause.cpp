#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DS_timer.h"

#define numThreads (4)
#define VECTOR_SIZE (134217728)

int main()
{
	int tid = 0;
	int priVar = 100;

	#pragma omp parallel for num_threads(4) private(tid, priVar)
	for (int i = 0; i < 4; i++)
	{
		tid = omp_get_thread_num();
		priVar = tid * 10;
		printf("[Thread %d] priVar = %d\n", tid, priVar);
	}
	printf("[After parallel region] priVar = %d\n", priVar);
	
	// getchar();
}


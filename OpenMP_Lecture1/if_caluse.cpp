#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DS_timer.h"

void test(int val)
{
	#pragma omp parallel if (val)
	if (omp_in_parallel())
	{
		#pragma omp single
		printf("val = %d, parallelized with %d threads\n",val, omp_get_num_threads());
	}
	else
	{
		printf("val = %d, serialized\n", val);
	}
}

int main()
{
	omp_set_num_threads(2);
	test(0);
	test(2);

	getchar();
		
}

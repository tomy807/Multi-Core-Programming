#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DS_timer.h"

#define numThreads (8)

int main(void)
{

	#pragma omp parallel num_threads(numThreads)
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				printf("Section A executed by thread %d\n", omp_get_thread_num());
			}

			#pragma omp section
			{
				printf("Section B executed by thread %d\n", omp_get_thread_num());
			}
		}
	}

	getchar();
}

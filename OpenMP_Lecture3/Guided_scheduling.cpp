#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DS_timer.h"

int main()
{
	#pragma omp parallel for schedule(guided, 1) num_threads(3)
	for (int i = 0; i < 12; i++)
	{
		int tID = omp_get_thread_num();
		printf("[%d] by thread %d\n", i, tID);
		sleep(1);
	}
    return 0;
}

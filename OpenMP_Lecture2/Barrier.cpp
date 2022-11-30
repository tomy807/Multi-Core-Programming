#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DS_timer.h"

int main()
{
	int tID = 0;
	#pragma omp parallel private (tID)
	{
		tID = omp_get_thread_num();
		if (tID % 2 == 0)
			sleep(1);

		printf("[%d] before\n", tID);

		#pragma omp barrier
		printf("[%d] after\n", tID);
	}

}

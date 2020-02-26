#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mmult.h"
//Program takes in 4 size parameters, creates matricies of parameter sizes, and then prints the matrix product (in addition prints time to execute).
int main (int argc, char *argv[])
{	
	//Future built matrices
	struct matrix mat1;
	struct matrix mat2;
	//Time logs
	struct timespec start, finish;
	struct matrix *result;

	//Matrix Dimensions:
	int row1 = atoi(argv[1]);
	int row2 = atoi(argv[3]);
	int column1 = atoi(argv[2]);
	int column2 = atoi(argv[4]);
	//Building Arrays based on parameter size
	mat1 = mat(row1, column1);
	mat2 = mat(row2, column2);
	//Log mmult start time
	clock_gettime(CLOCK_REALTIME, &start);
	result = mmult(&mat1, &mat2);
	//Log mmult end time
	clock_gettime(CLOCK_REALTIME, &finish);
	printf("Time in Seconds: %ld.%ld\n", (finish.tv_sec - start.tv_sec), (finish.tv_nsec - start.tv_nsec));
	free(result);
	return 0;	
}

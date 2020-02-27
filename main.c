#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mmult.h"
//Program takes in 4 size parameters, creates matricies of parameter sizes, and then prints the matrix product (in addition prints time to execute).
//PROGRAM CURRENTLY HAS ERROR! When trying to print a matrix of all dimensions = 1 EXCEPT the row dimension of matrix 1, the program seg faults. Example input = "./mmult 10 1 1 1" will print an error. Same if "./mmult 15 7 7 10
int main (int argc, char *argv[])
{
	//Checking if argument count is correct
	if (argc != 5) {
		printf("Incorrect Argument Amount\n");
		return 0;
	}
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
	//Checking if array dimensions are valid (greater than 0)
	if ((row1 <= 0) | (row2 <= 0) | (column1 <= 0) | (column2 <= 0) ) {
		printf("Matrix size is invalid, please enter again\n");
		return 0;
	}
	//Building Arrays based on parameter size
	mat1 = mat(row1, column1);
	mat2 = mat(row2, column2);
	//Log mmult start time
	clock_gettime(CLOCK_REALTIME, &start);
	result = mmult(&mat1, &mat2);
	//Log mmult end timec
	clock_gettime(CLOCK_REALTIME, &finish);
	//Print out Matrix

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < column2; j++) {
			printf("%lf ", result->elements[i][j]);
		}
		printf("\n");
		//free(result->elements);
	}
	//Print time taken to run mmult()
	printf("Time in Seconds: %ld.%d\n", (finish.tv_sec - start.tv_sec), (abs(finish.tv_nsec - start.tv_nsec)));	
	//Free allocated struct pointer and dynamically allocated arrays
	free(mat1.elements);
	free(mat2.elements);
	free(result->elements);
	free(result);
	return 0;	
}

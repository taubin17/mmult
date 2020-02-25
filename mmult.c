#include <stdio.h>
#include "matrix.h"

int *multiply (struct matrix *one, struct matrix *two)
{
	
	int temp = 0;
	int result[one->columns][two->rows];

		
	
	for (int i = 0; i < one->rows; i++) {
		for (int j = 0; j < two->columns; j++) {
			for (int k = 0; k < one->columns; k++) {
				temp += one->elements[i][k] * two->elements[k][j];
			}
			result[i][j] = temp;
			temp = 0;
		}
	}
	
	for (int i = 0; i < one->columns; i++) {
		for (int j = 0; j < two->rows; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return *result;
}

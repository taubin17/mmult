#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mmult.h"

double rand_double() //PRE: Rand is random integer number. POST: Rand now is a number between 0 and 100
{
	const double max = 100.0;
	double result = ((double)rand() / (double)RAND_MAX) * max;
	return result;
}
struct matrix *mmult (struct matrix *mat1, struct matrix *mat2) //PRE: Matrix 
{	
	struct matrix* result = (struct matrix *)malloc(sizeof(struct matrix));
	result->elements = (double **)malloc(mat1->rows * sizeof(double *));
	for (int i = 0; i < mat1->columns; i++) {
		result->elements[i] = (double *)malloc(mat2->columns * sizeof(double));
	}
	double temp = 0;
	for (int i = 0; i < mat1->rows; i++) {
		for (int j = 0; j < mat2->columns; j++) {
			for (int k = 0; k < mat1->columns; k++) {
				temp += (mat1->elements[i][k] * mat2->elements[k][j]);
			}
			result->elements[i][j] = temp;
			temp = 0;	
		}
	}
	printf("%lf \n", result->elements[1][0]);
	return result; 
}

struct matrix mat(int rows, int columns) 
{	
	struct matrix mat;
	mat.rows = rows;
	mat.columns = columns;
	mat.elements = (double **)malloc(rows * sizeof(double *));
	for (int i = 0; i < mat.rows; i++) {
		mat.elements[i] = (double *)malloc(columns * sizeof(double));
	}
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.columns; j++) {
			mat.elements[i][j] = rand_double();
		}
	}
	return mat;
}


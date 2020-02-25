#include <stdio.h>
#include <string.h>
#include "matrix.h"

struct dimensions mat(char file[]) 
{
	struct dimensions matrix;
	char *piece;
	char buffer[1000];
	FILE *fd;
	char copy[100000];
	fd = fopen(file, "r");
	matrix.columns = 0;
	matrix.rows = 0;
	matrix.count = 0;

	while (fgets(buffer, 1000, fd)) {
		strcat(copy, buffer);
		piece = strtok(buffer, ", ");
		while (piece != NULL) {
			matrix.count++;
			piece = strtok(NULL, ", ");
		}
	}
	printf("%s", copy);
	piece = strtok(copy, "\n");
	while (piece != NULL) {
		matrix.rows++;
		piece = strtok(NULL, "\n");
	}
	
	printf("%d\n", matrix.count);
	printf("%d\n", matrix.rows);
	matrix.columns = (matrix.count / matrix.rows);
	printf("%d\n", matrix.columns);
	return matrix;
}

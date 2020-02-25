#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"

int main (int argc, char *argv[])
{
	struct dimensions a, b;
	a = mat(argv[1]);
	b = mat(argv[2]);
	
	printf("%d\n%d\n", a.rows, b.rows);	
	return 0;	
}

 

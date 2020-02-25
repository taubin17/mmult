#ifndef matrix_h_
#define gps_h_
struct dimensions {
	int rows;
	int columns;
	int count;
};
struct matrix {
	int rows;
	int columns;
	int **elements;
};

struct dimensions mat (char file[]);

struct matrix *parse(struct dimensions, char file[]);

int *multiply(struct matrix *one, struct matrix *two);
#endif
 

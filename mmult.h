#ifndef mmult_h_
#define mmult_h_
struct matrix {
	int rows;
	int columns;
	double **elements;
};

struct matrix mat(int rows, int columns);

struct matrix *mmult(struct matrix *one, struct matrix *two);
#endif

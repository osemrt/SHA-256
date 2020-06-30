#include "../inc/declarations.h"

void plot(double x[], int y[], int size) {
	int scaleRatio = 10;
	int i, j;

	for (i = 0; i < size; i++) {
		printf("%.10f seconds, %10d characters : ", x[i], y[i]);
		for (j = 0; j < x[i]* scaleRatio; j++) {
			printf("*");
		}
		printf("\n");
	}
}
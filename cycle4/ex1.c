#include<stdio.h>

void readpoly(double *poly, int n) {
	for (int i = n; i >= 0; i--) {
		printf("Enter the coefficient of x^%d: ", i);
		scanf("%lf", (poly++));
	}
}

void printpoly(double *poly, int n) {
	for (int i = 0, j = n; i <= n; i++, j--) {
		printf("%.2f x^%d ", poly[i], j);
		if (i < n)
			printf("+");
	}
	printf("\n");
}

void add(double *poly1, int n, double *poly2, int m, double *poly3, int *x) {
	int i = n, j = m;
	while (i >= 0 && j >= 0) {
		if (i == j) {
			*(poly3++) = *(poly1++) + *(poly2++);
			i--, j--;
		} else if (i > j) {
			*(poly3++) = *(poly1++);
			i--;
		} else {
			*(poly3++) = *(poly2++);
			j--;
		}
		(*x)++;
	}
	if (i > 0) {
		*(poly3++) = *(poly1++);
		(*x)++;
	}
	if (j > 0) {
		*(poly3++) = *(poly1++);
		(*x)++;
	}
}

void main() {
	int n, m;
	printf("Enter the Degree of the 1st polynomial: ");
	scanf("%d", &n);
	double poly1[n + 1];
	readpoly(poly1, n);

	printf("Enter the Degree of the 2nd polynomial ");
	scanf("%d", &m);
	double poly2[m + 1];
	readpoly(poly2, m);

	int x = 0;
	double poly3[m + n];
	add(poly1, n, poly2, m, poly3, &x);
	printf("1st Polynomial is\n");
	printpoly(poly1, n);
	printf("2nd Polynomial is\n");
	printpoly(poly2, m);
	printf("The sum of 2 polynomials is\n");
	printpoly(poly3, x);
}
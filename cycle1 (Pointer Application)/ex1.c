#include <stdio.h>
int main() {
	int m, n, A[30], B[30], C[60], i = 0, j = 0, k = 0;;

	printf("Enter the no of elements of 1st array: ");
	scanf(" %d", &m);
	printf("Enter %d Elements: ", m);
	for (i = 0; i < m; i++)
		scanf(" %d", &A[i]);

	printf("Enter the no of elements of 2nd array: ");
	scanf(" %d", &n);
	printf("Enter %d Elements: ", n);
	for (i = 0; i < n; i++)
		scanf(" %d", &B[i]);

	i = 0;
	while (i < m && j < n) {
		if (A[i] < B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	}
	while (i < m)
		C[k++] = A[i++];
	while (j < n)
		C[k++] = B[j++];

	printf("Merged list is: ");
	for (i = 0; i < k; i++)
		printf("%d ", C[i]);

	printf("\n");
}

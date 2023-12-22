#include<stdio.h>

void main() {
	int i, j, temp, arr[20], count;
	printf("Enter the Number of elements: ");
	scanf("%d", &count);
	printf("Enter the elements: ");
	for (i = 0; i < count; i++)
		scanf("%d", arr + i);
	for (i = 0; i < count; i++)
		for (j = 0; j < count - i - 1; j++)
			if (*(arr + j) > *(arr + j + 1)) {
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
	printf("The sorted elements are : ");
	for (i = 0; i < count; i++)
		printf(" %d ", *(arr + i));
	printf("\n");
}

#include<stdio.h>
void main() {
	int arr[20], n, *ptr, i;
	printf("Enter the no of Elements: ");
	scanf(" %d", &n);
	printf("Enter %d elements: ", n);
	for (i = 0; i < n; i++)
		scanf(" %d", arr + i);
	ptr = arr;
	for (i = 1; i < n; i++)
		if (*ptr > *(arr + i))
			ptr = (arr + i);
	printf("Smallest number is %d \n", *ptr);
}

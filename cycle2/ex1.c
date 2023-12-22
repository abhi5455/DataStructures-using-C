#include<stdio.h>
void main() {
	int arr[20], count, key, i;
	printf("Enter the no of elements: ");
	scanf(" %d", &count);
	printf("Enter the %d elements: ", count);
	for (i = 0; i < count; i++) {
		scanf("%d", arr + i);
	}
	printf("Enter the element to be searched: ");
	scanf("%d", &key);
	for (i = 0; i < count; i++)
		if (*(arr + i) == key)
			break;
	if (i == count)
		printf("The Element is not Found \n");
	else
		printf("The Element %d is Found at position %d \n", key, i + 1);
}

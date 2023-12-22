#include<stdio.h>

void main() {
	int i, key, mid, top, bot, arr[20], count, flag = 0;
	printf("Enter the no of elements: ");
	scanf("%d", &count);
	printf("Enter the %d elements: ", count);
	for (i = 0; i < count; i++)
		scanf("%d", arr + i);
	printf("Enter the element to be searched : ");
	scanf("%d", &key);
	top = 0;
	bot = count - 1;
	while (top <= bot) {
		mid = (top + bot) / 2;
		if (*(arr + mid) == key) {
			flag = 1;
			break;
		}
		if (*(arr + mid) < key)
			top = mid + 1;
		else
			bot = mid - 1;
	}
	if (flag)
		printf("The element %d is found at position %d \n", key, mid + 1);
	else
		printf("The element not found \n");
}

/*
 To implement various sorting technics on an array
 Jithin Raj S R, S3, CSE
 Roll no - 74
*/
#include<stdio.h>

#define MAX 10

void swap(int list[], int a, int b) {
	int temp;
	temp = list[b];
	list[b] = list[a];
	list[a] = temp;
}

void bubblesort(int list[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - 1 - i; j++)
			if (list[j] > list[j + 1])
				swap(list, j + 1, j);
}

void selectionsort(int list[], int size) {
	int i, j, min;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = min + 1; j < size; j++)
			if (list[min] > list[j])
				min = j;
		swap(list, min, i);
	}
}

int partition(int list[], int l, int r) {
	int pv = r, i = -1, j;
	for (j = i + 1; j < r; j++) {
		if (list[j] < list[pv]) {
			i++;
			swap(list, j, i);
		}
	}
	i++;
	swap(list, i, pv);
	return i;
}

void quicksort(int list[], int beg, int end) {
	if (beg < end) {
		int pv = partition(list, beg, end);
		quicksort(list, beg, pv - 1);
		quicksort(list, pv + 1, end);
	}
}

void display(int list[], int size, char *msg) {
	int i;
	printf("%s", msg);
	for (i = 0; i < size; i++)
		printf(" %d", list[i]);
	printf("\n");
}

void main() {
	int bubble[MAX], insertion[MAX], selection[MAX], quick[MAX], merge[MAX], heap[MAX];
	int size, i, in;
	printf("How many elements : ");
	scanf("%d", &size);
	printf("Enter the elements : ");
	for (i = 0; i < size; i++) {
		scanf("%d", &in);
		bubble[i] = in;
		insertion[i] = in;
		selection[i] = in;
		quick[i] = in;
		merge[i] = in;
		heap[i] = in;
	}
	bubblesort(bubble, size);
	display(bubble, size, "Bubble sorted array : ");
	selectionsort(selection, size);
	display(selection, size, "Selection sorted array : ");
	quicksort(quick, 0, size - 1);
	display(quick, size, "Quick sorted array : ");

}

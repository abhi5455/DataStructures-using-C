#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int num;
	char name[50];
	int mark;
	struct node *link;
};
struct node *head = NULL;

void insert(int n, char s[], int m) {
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	if (newnode == NULL) {
		printf("Memory Underflow\n");
		return;
	}
	if (head == NULL) {
		head = newnode;
		head->num = n;
		strcpy(head->name, s);
		head->mark = m;
		head->link = NULL;
		return;
	}
	newnode->num = n;
	strcpy(newnode->name, s);
	newnode->mark = m;
	newnode->link = head;
	head = newnode;
}

void Delete() {
	struct node *ptr, *temp, *ptr1;
	int key, n;

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Enter the number to be deleted: ");
	scanf("%d", &key);

	if (head->num == key) {
		temp = head;
		head = head->link;
		n = temp->num;
		free(temp);
		printf("Delelted number is %d\n", n);
		return;
	}

	ptr = head;
	while (ptr != NULL && ptr->num != key) {
		temp = ptr;
		ptr = ptr->link;
	}
	if (ptr == NULL) {
		printf("Can't find number\n");
		return;
	}
	n = ptr->num;
	ptr1 = ptr->link;
	temp->link = ptr1;
	free(ptr);
	printf("Deleted student is of number %d\n", n);
	return;
}

void search() {
	struct node *ptr;
	// int n;
	char s[50];
	printf("Enter the name to be searched: ");
	scanf("%s", s);

	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->name, s) == 0) {
			printf("Found\n");
			printf("Number:%d\nName:%s\nMark:%d\n", ptr->num, ptr->name, ptr->mark);
			return;
		} else {
			ptr = ptr->link;
		}
	}
	if (ptr == NULL) {
		printf("No student of the given name\n");
	}
}

void display() {
	struct node *ptr;
	if (head == NULL) {
		printf("Nothing to print\n");
		return;
	}
	ptr = head;
	while (ptr->link != NULL) {
		printf("Number:%d\nName:%s\nMark:%d\n", ptr->num, ptr->name, ptr->mark);
		ptr = ptr->link;
	}
	printf("Number:%d\nName:%s\nMark:%d\n", ptr->num, ptr->name, ptr->mark);
}

void sort() {
	struct node *ptr1, *ptr2;
	int n = 0, temp, marktemp;
	char stemp[50];
	struct node *ptr = head;
	while (ptr->link != NULL) {
		n++;
		ptr = ptr->link;
	}
	for (int i = 0; i < n - 1; i++) {
		ptr1 = head;
		ptr2 = ptr1->link;
		for (int j = 0; j < n - i - 1; j++) {
			if (ptr1->num > ptr2->num) {
				temp = ptr1->num;
				ptr1->num = ptr2->num;
				ptr2->num = temp;

				strcpy(stemp, ptr1->name);
				strcpy(ptr1->name, ptr2->name);
				strcpy(ptr2->name, stemp);

				marktemp = ptr1->mark;
				ptr1->mark = ptr2->mark;
				ptr2->mark = marktemp;
			}
			ptr1 = ptr2;
			ptr2 = ptr2->link;
		}
	}
	printf("Sorted successfully\n");
	display();
}

void main() {
	int choice = 1;
	int num, mark;
	char name[50];

	printf("1-Insert at beginning\n2-Delete based on number\n3-Search based on num/name\n4-Sort based on number\n5-Display\n");
	do {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter number,name and totalmark: ");
				scanf("%d%s%d", &num, name, &mark);
				insert(num, name, mark);
				break;
			case 2:
				Delete();
				break;
			case 3:
				search();
				break;
			case 4:
				sort();
				break;
			case 5:
				display();
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
	} while (choice <= 5);
}
#include<stdio.h>
#define SIZE 20
#define INVALID '\0'
char stack[SIZE];
int top = -1;
void push(char item) {
	if (top == SIZE - 1)
		printf("Stack Overflow\n");
	else
		stack[++top] = item;
}
char pop() {
	if (top == -1) {
		printf("Stack Underflow\n");
		return INVALID;
	} else
		return stack[top--];
}
int main() {
	int flag = 0, i, j, len = 0;
	char str[20], S[20];
	printf("Enter the string: ");
	scanf("%s", str);
	for (i = 0; str[i] != '\0'; i++)
		len++;
	for (i = 0; i < len / 2; i++)
		push(str[i]);
	i = ((len % 2 == 1) ? (len / 2) + 1 : len / 2);
	for (j = i; j < len; j++)
		if (str[j] != pop()) {
			flag = 1;
			break;
		}
	if (!flag)
		printf("The string %s is a palindrome", str);
	else
		printf("The string %s is not a palindrome", str);
}
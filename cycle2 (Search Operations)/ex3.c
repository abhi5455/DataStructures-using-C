#include<stdio.h>
#define SIZE 5
#define INVALID -9999
int stack[SIZE],top=-1;
void push(int item){
	if(top == SIZE-1)
		printf("Stack Overflow\n");
	else
		stack[++top]=item;
}
int pop(){
	if(top == -1) {
        printf("Stack Underflow\n");
        return INVALID;
    }
	return stack[top--];
}
void display(){
	int i;
	if(top == -1)
		printf("Stack is empty\n");
	else{
		printf("Elements of the Stack are: ");
		for(i=0;i<=top;i++)
			printf("%d  ",stack[i]);
		printf("\n");
	}
}
void main() {
    int choice, item;
    printf("1 - Push\n2 - Pop\n3 - Display\n4 - Exit\n");
    do {
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the Element: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != INVALID)
                    printf("Popped element is: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid CHOICE\n");
        }
    }while(choice <= 4);
}
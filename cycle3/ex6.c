#include <stdio.h>
#define MAX_SIZE 50

struct node {
    int data;
    int priority;
};

struct node queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int data, int priority) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear].data = data;
        queue[rear].priority = priority;
    }
    else {
        int i, j;
        for (i = front; i <= rear; i++)
            if (priority > queue[i].priority) {
                for (j = rear + 1; j >= i; j--) {
                    queue[j].data = queue[j - 1].data;
                    queue[j].priority = queue[j - 1].priority;
                }
                queue[i].data = data;
                queue[i].priority = priority;
                rear++;
                return;
            }
        queue[++rear].data = data;
        queue[rear].priority = priority;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return;
    }
    printf("Deleted element: %d having priority %d\n", queue[front].data,queue[front].priority);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    int i;
    printf("Priority Queue (Element,Priority): ");
    for (i = front; i <= rear; i++) {
        printf("(%d, %d)  ", queue[i].data, queue[i].priority);
    }
    printf("\n");
}

int main() {
    int item,priority,choice;
    printf("1- Insert\n2- Delete\n3- Display\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element and its priority: ");
                scanf("%d %d",&item,&priority);
                insert(item,priority);
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            default:printf("INVALID CHOICE\n");
        }
    }while(choice<=3);
    return 0;
}
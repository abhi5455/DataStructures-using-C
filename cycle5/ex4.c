#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int item)
{
    struct node *newnode;
    newnode = (struct node * ) malloc(sizeof(struct node));

    if((front == NULL) && (rear == NULL))
    {
        front=rear=newnode;
        rear->data=item;
        rear->link=NULL;

    }
    else
    {
        rear->link=newnode;
        newnode->data=item;
        newnode->link=NULL;
        rear=newnode;
    }

}
void dequeue()
{
    struct node *ptr;
    int n;
    if (front == NULL)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        n=front->data;
        ptr=front->link;
        free(front);
        front=ptr;
        printf("Deleted element is %d\n",n);
        return;
    }
}

void display()
{
    struct node *ptr;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("The Queue is: ");
    ptr=front;
    while(ptr->link!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("%d\n",ptr->data);
}

void main()
{
    int choice=1,item;
    printf("\nImplementation of Queue using Linked List\n");
    printf("1-Enqueue\n2-Dequeue\n3-Display\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value to be inserted: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:dequeue();
                break;
            case 3:display();
                break;
            default:printf("Invalid choice\n");
                break;
        }
    }
    while(choice<=3);
}
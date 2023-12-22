#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *top=NULL;

void push(int item)
{
    struct node *newnode;
    newnode =(struct node *)malloc(sizeof(struct node));

    if (top == NULL)
    {
        top = newnode;
        top->data=item;
        top->link = NULL;
    }
    else
    {
        newnode->data=item;
        newnode->link = top;
        top = newnode;
    }
}
void pop()
{
    struct node *ptr;
    int n;
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    n=top->data;
    ptr=top->link;
    free(top);
    top=ptr;
    printf("Removed  Element : %d\n", n);
    return;
}
void display()
{
    struct node *ptr;
    if(top==NULL)
    {
        printf("Stack empty\n");
        return;
    }
    printf("Elements of stack are: ");
    ptr=top;
    while(ptr->link!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("%d\n",ptr->data);

}
void main()
{
    int choice=1,num;
    printf("1-PUSH\n2-POP\n3-DISPLAY\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value to be pushed: ");
                scanf("%d",&num);
                push(num);
                break;
            case 2:pop();
                break;
            case 3:display();
                break;
            default:printf("Invalid choice\n");
                break;
        }
    }
    while(choice<=3);
}
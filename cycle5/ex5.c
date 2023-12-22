#include <stdio.h>
#include <stdlib.h>

struct queue{
    int Item[20];
    int front;
    int rear;
}*Q;
struct stack{
    int Item[20];
    int top;
}*S;
void enqueue(int item)
{
    if(Q->rear==20-1)
    {
        printf("Queue Full");
        return;
    }
    if(Q->front==-1)
    {
        Q->front=0;
    }
    Q->rear++;
    Q->Item[Q->rear]=item;
}
void dequeue()
{
    if((Q->rear==-1)||(Q->front>Q->rear))
    {
        printf("Queue Empty");
        return;
    }
    else
    {
        printf("Item dequeued is %d\n",Q->Item[Q->front]);
        Q->front++;
    }
}
void display()
{
    if((Q->rear==-1)||(Q->front>Q->rear))
    {
        printf("Queue Empty");
        return;
    }
    printf("Elements of the queue are\n");
    for(int i=Q->front;i<=Q->rear;i++)
    {
        printf("%d ",Q->Item[i]);
    }
    printf("\n");
}
void push(int item) {
    S->top++;
    S->Item[S->top]=item;
}

int pop() {
    return S->Item[S->top--];
}
void reverse()
{
    for(int i=Q->front;i<=Q->rear;i++)
    {
        push(Q->Item[i]);
    }
    for(int i=Q->front;i<=Q->rear;i++)
    {
        Q->Item[i]=pop();
    }
    printf("Queue after reversing is\n");
    display();

}
void main()
{
    int ch=1,item;
    Q = (struct queue*) malloc(sizeof(struct queue));
    S = (struct stack*) malloc(sizeof(struct stack));
    Q->front=-1;
    Q->rear=-1;
    S->top=-1;
    printf("1-ENQUEUE/2-DEQUEUE/3-DISPLAY/4-REVERSE\n");
    do
    {
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: printf("Enter the item to be enqueued: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: reverse();
                break;
        }
    }while(ch<=4);
}
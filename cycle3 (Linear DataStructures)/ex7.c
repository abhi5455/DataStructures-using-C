#include <stdio.h>
#define SIZE 5
int DQ[SIZE],f=-1,r=-1;

int isFull() {
    if((r + 1) % SIZE == f)
        return 1;
    return 0;
}

int isEmpty() {
    if (f == -1)
        return 1;
    return 0;
}

void enqueFront(int key) {
    if (isFull()) {
        printf("Overflow: Dequeue is full\n");
        return;
    }
    if (f==-1)
        r = f = 0;
    else
        f = (f - 1 + SIZE) % SIZE;
    DQ[f] = key;
}

void enqueBack(int key) {
    if (isFull()) {
        printf("Overflow: Dequeue is full\n");
        return;
    }
    if (f == -1)
        f = r = 0;
    else
        r = (r + 1) % SIZE;
    DQ[r] = key;
}

int dequeFront() {
    if (isEmpty()) {
        printf("Underflow: Dequeue is empty\n");
        return 0;
    }
    int frontValue = DQ[f];
    if (f == r)
        f = r = -1;
    else
        f = (f + 1) % SIZE;
    return frontValue;
}

int dequeBack() {
    if (isEmpty()) {
        printf("Underflow: Dequeue is empty\n");
        return 0;
    }
    int rearValue = DQ[r];
    if (f == r)
        f = r = -1;
    else
        r = (r - 1 + SIZE) % SIZE;
    return rearValue;
}
void display(){
    if(r==-1){
        printf("DQueue is Empty\n");
        return;
    }
    printf ("Elements of the Queue are: ");
    int i;
    if(f <= r){
        for(i=f;i<=r;i++)
            printf("%d  ",DQ[i]);
    }
    else{
        for(i=f;i<SIZE;i++)
            printf("%d  ",DQ[i]);
        for(i=0;i<=r;i++)
            printf("%d  ",DQ[i]);
    }
	printf("\n");
}
int main() {
    int choice,in,out,dir;
    printf("1 - EnqueFront\n2 - EnqueBack\n3 - DequeFront\n4 - DequeBack\n5 - Display\n6 - Exit\n");
    do{
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the Element to be added in front : ");
                scanf("%d",&in);
                enqueFront(in);
                break;
            case 2:printf("Enter the Element to be added in back : ");
                scanf("%d",&in);
                enqueBack(in);
                break;
            case 3:out = dequeFront();
                if(out)
                    printf("Dequed element : %d\n",out);
                break;
            case 4:out = dequeBack();
                if(out)
                    printf("Dequed element : %d\n",out);
                break;
            case 5:display();
                break;
            case 6:printf("Exiting!!\n");
                break;
            default:printf("Invalid input\n");
        }
    }while(choice <=5);
}

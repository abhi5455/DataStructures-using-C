#include<stdio.h>
#define SIZE 5
#define INVALID -99999
int Q[SIZE],f=-1,r=-1;
void enque(int item){
	if((r+1) % SIZE == f)
		printf("Queue is full\n");
	else{
		if(f==-1)
			f=0;
		r = (r+1) % SIZE;
		Q[r] = item;
	}
}
int deque(){
	if(r == -1)
		printf("Queue is empty\n");
	else{
		int item = Q[f];
		f = (f+1) % SIZE;
		if(f == (r+1) % SIZE)
			f=r=-1;
		return item;
	}
	return INVALID;
}
void display(){
    if(r==-1){
        printf("Queue Empty\n");
        return;
    }
    printf ("Elements of the Queue are: ");
    int i;
    if(f <= r){
        for(i=f;i<=r;i++)
            printf("%d ",Q[i]);
    }
    else{
        for(i=f;i<SIZE;i++)
            printf("%d ",Q[i]);
        for(i=0;i<=r;i++)
            printf("%d ",Q[i]);
    }
	printf("\n");
}
void main(){
	int choice=0,item;
	printf("1 - Enque\n2 - Deque\n3 - Display\n4 - Exit\n");
	do{
		printf("Enter the choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter Element: ");
				scanf("%d",&item);
				enque(item);
				break;
			case 2:item = deque();
				if(item != INVALID )
					printf("Dequed element : %d\n",item);
				break;
			case 3:display();
				break;
			case 4:printf("Exiting\n");
				break;
			default:printf("INVALID CHOICE\n");
		}
	}while(choice <= 3);
}

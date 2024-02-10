#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define INVALID -99999
int top=-1,f=-1,r=-1,stack[MAX],queue[MAX],visited[MAX];
void push(int data){
  if(top!=MAX-1)
	stack[++top]=data;
}
int pop(){
	if(top==-1)
		return INVALID;
	return stack[top--];
}
void enque(int data){
	if(f==-1)
		f=0;
	if(r!=MAX-1)
		queue[++r]=data;
}
int deque(){
	if(f!=-1){
		int item = queue[f++];
		if(f==r+1)
			f=r=-1;
		return item;
	}
	return INVALID;
}
void bfs(int list[],int adj[MAX][MAX],int index,int size){
	int i,j,cur;
	for(i=0;i<size;i++)
		visited[i]=0;
	enque(index);
	printf("Breadth first search ");
	while(f!=-1){
		cur=deque();
		if(visited[cur]==0){
			printf("\n-> %d",list[cur]);
			visited[cur]=1;
		}
		for(j=0;j<size;j++){
			if(adj[cur][j]==1 && visited[j]==0)
				enque(j);
		}
	}
	printf("\n");
}

void dfs(int list[],int adj[MAX][MAX],int index,int size){
        int i,j,cur;
        for(i=0;i<size;i++)
                visited[i]=0;
        push(index);
        printf("Depth first search ");
        while(top!=-1){
                cur=pop();
                if(visited[cur]==0){
                        printf("\n-> %d",list[cur]);
                        visited[cur]=1;
                }
                for(j=0;j<size;j++){
                        if(adj[cur][j]==1 && visited[j]==0)
                                push(j);
                }
        }
        printf("\n");
}

void main(){
	int key=-1,j,size,list[MAX],adj[MAX][MAX],i,a;
	printf("How many elements : ");
	scanf("%d",&size);
	printf("Enter the elements : ");
	for(i=0;i<size;i++)
		scanf("%d",&list[i]);
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			adj[i][j]=0;
	printf("If edge is present, enter 1 else 0\n");
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			printf("Edge between [%d] and [%d] : ",list[i],list[j]);
			scanf("%d",&a);
			adj[i][j]=a;
			adj[j][i]=a;
		}
	}

	for(i=0;i<size;i++){
		printf("\n");
		for(j=0;j<size;j++)
			printf("%d  ",adj[i][j]);
	}
	while(key!=-2){
		printf("\nEnter the starting vertex [-2 to exit]: ");
		scanf("%d",&key);
		for(i=0;i<size;i++){
			if(list[i]==key){
				key=i;
				break;
			}
		}
		if(key==-1)
			printf("Vertex not found..\n");
		else{
			dfs(list,adj,key,size);
        	        bfs(list,adj,key,size);
		}
		key=-1;
 }
}

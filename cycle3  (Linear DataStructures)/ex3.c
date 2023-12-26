#include<stdio.h>
#include<string.h>
#define MAX 25
char expr[MAX],conv[MAX];
int flag=0;

int prior(char ch){
        if(ch=='^')
                return 5;
        if(ch=='*' || ch=='/')
                return 4;
        if(ch=='+' || ch=='-')
                return 3;
        if(ch=='(')
                return 6;
        return -1;
}

int prior_operator(int start,int end){
	flag=0;
	int i,pr=0,tpr=0,index=-1;
	for(i=start;i<=end;i++){
		if(conv[i]==0){
			tpr=prior(expr[i]);
			if(tpr>pr){
				pr=tpr;
				index=i;
			}
		}
	}
	if(expr[index]=='#')
		return -1;
	if(pr==6)
		flag=1;
	return index;
}
void swap(int index){
	if(expr[index]!='#'){
		conv[index-1]=1;
		conv[index]=1;
		int i=index,j;
		char temp;
		while(conv[++i]!=0);
		if(i-index==1){
			conv[i]=1;
			temp=expr[i];
			expr[i]=expr[index];
			expr[index]=temp;
		}
		else{
			temp=expr[index];
			for(j=index;j<i;j++){
				expr[j]=expr[j+1];
			}
			expr[i-1]=temp;
		}
	}
}

void post(int start, int end){
	int br=0,i,op_index=prior_operator(start,end);
	if(op_index!=-1){
		if(flag){
			conv[op_index]=1;
			expr[op_index]='#';
			for(i=start;i<end;i++){
				if(expr[i]=='(')
					br++;
				if(expr[i]==')')
					if(br==0){
						conv[i]=1;
						expr[i]='#';
						post(op_index+1,i-1);
						break;
					}
					else
						br--;
			}
		}
		swap(op_index);
		post(start,end);
	}
}

int main(){

	printf("Enter an Infix Expression:  ");
	scanf("%s",expr);
	int i,len;
	len = strlen(expr);
	for(i=0;i<len;i++)
		conv[i]=0;
	post(0,len);
	printf("Result : ");
	for(i=0;i<len;i++)
		if(expr[i]!='#')
			printf("%c",expr[i]);
	printf("\n");
	return 0;
}
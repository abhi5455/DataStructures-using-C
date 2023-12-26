#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void display(struct node* head) {
    struct node *temp = head;
    if(head==NULL)
    {
        printf("There are no Elements in the Linked list\n");
        return;
    }
    printf("Elements of the Linked list are:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}
struct node* insertbegin(struct node* head)
{
    int key;
    printf("Enter the element to be inserted: ");
    scanf("%d",&key);
    struct node* temp= (struct node*)malloc(sizeof(struct node*));
    temp->link=head;
    temp->data=key;
    head=temp;
    return head;
}
struct node* insertend(struct node* head)
{
    int key;
    printf("Enter the element to be inserted: ");
    scanf("%d",&key);
    struct node* temp= head;
    struct node* temp1= (struct node*)malloc(sizeof(struct node*));
    temp1->link=NULL;
    temp1->data=key;
    if(head==NULL)
    {
        head=temp1;
        return head;
    }
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=temp1;
    return head;
}
struct node* insert(struct node *head)
{
    int position,key;
    printf("Enter the element to be inserted: ");
    scanf("%d",&key);
    struct node* temp=head;
    struct node* temp1=(struct node*)malloc(sizeof(struct node*));
    temp1->data=key;
    temp1->link=NULL;
    if(head==NULL)
    {
        printf("Linked list is empty,Inserting as 1st element\n");
        head=temp1;
        return head;
    }
    printf("After which element you want to insert new element: ");
    scanf("%d",&position);
    while(temp->data!=position)
    {
        if(temp->link==NULL)
        {
            printf("The element %d is not present in the Linked list\n", position);
            return head;
        }
        temp = temp->link;
    }
    temp1->link=temp->link;
    temp->link=temp1;
    return head;
}
struct node* deletebegin(struct node* head)
{
    if(head==NULL)
    {
        printf("There are no Elements in the Linked list\n");
        return NULL;
    }
    printf("The Element deleted is %d\n",head->data);
    head=head->link;
    return head;
}
struct node* deleteend(struct node* head)
{
    int key;
    if(head==NULL)
    {
        printf("There are no Elements in the Linked list\n");
        return head;
    }
    struct node* temp=head;
    struct node* temp1=head;
    if(temp->link==NULL)
    {
        head = NULL;
        return head;
    }
    while(temp->link!=NULL)
    {
        temp1 = temp;
        temp = temp->link;
    }
    printf("The Element deleted is %d\n",temp->data);
    temp1->link=NULL;
    return head;
}
struct node* delete(struct node *head)
{
    int position;
    struct node* temp=head;
    struct node* temp1=(struct node*)malloc(sizeof(struct node*));
    temp1=head;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }
    printf("Which element you want to delete: ");
    scanf("%d",&position);
    if(head->data==position)
    {
        head=head->link;
        return head;
    }
    while(temp->data!=position)
    {
        temp1=temp;
        temp = temp->link;
    }
    temp1->link=temp->link;
    return head;
}
int main()
{
    int choice;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    printf("1. Display\n"
           "2. Insert at beginning\n"
           "3. Insert at end\n"
           "4. Insert at a specified position\n"
           "5. Delete from beginning\n"
           "6. Delete from end\n"
           "7. Delete from a specified position\n");
    do
    {
        printf("Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display(head);
                break;
            case 2: head=insertbegin(head);
                break;
            case 3: head=insertend(head);
                break;
            case 4: head=insert(head);
                break;
            case 5: head=deletebegin(head);
                break;
            case 6: head=deleteend(head);
                break;
            case 7: head=delete(head);
                break;
        }
    }while(choice<=7);
}
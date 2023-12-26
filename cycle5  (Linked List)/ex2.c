#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    char data;
    struct Node* rlink;
    struct Node* llink;
};
void insertEnd(struct Node** head, char data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->rlink = NULL;

    if (*head == NULL)
    {
        newNode->llink = NULL;
        *head = newNode;
        return;
    }
    struct Node* ptr = *head;
    while (ptr->rlink != NULL)
        ptr = ptr->rlink;

    ptr->rlink = newNode;
    newNode->llink = ptr;
}

bool isPalindrome(struct Node* head)
{
    struct Node* start = head;
    struct Node* end = head;
    while (end->rlink != NULL)
        end = end->rlink;
    while (start != end)
    {
        if (start->data != end->data)
            return false;

        start = start->rlink;
        end = end->llink;

        if (start == end)
            break;
    }
    return true;
}
int main()
{
    struct Node* head = NULL;
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        insertEnd(&head, str[i]);

    if (isPalindrome(head))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
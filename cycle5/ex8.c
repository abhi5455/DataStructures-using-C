#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coefficient;
    int exp_x;
    int exp_y;
    struct Node* next;
};

typedef struct Node Node;

void insertTerm(Node** head, int coef, int exp_x, int exp_y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coef;
    newNode->exp_x = exp_x;
    newNode->exp_y = exp_y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp_x_1 = (poly1 != NULL) ? poly1->exp_x : 0;
        int exp_x_2 = (poly1 != NULL) ? poly1->exp_y : 0;

        int coef2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp_y_1 = (poly2 != NULL) ? poly2->exp_x : 0;
        int exp_y_2 = (poly2 != NULL) ? poly2->exp_y : 0;

        if (exp_x_1 > exp_y_1 || (exp_x_1 == exp_y_1 && exp_x_2 > exp_y_2)) {
            insertTerm(&result, coef1, exp_x_1, exp_x_2);
            poly1 = poly1->next;
        } else if (exp_x_1 < exp_y_1 || (exp_x_1 == exp_y_1 && exp_x_2 < exp_y_2)) {
            insertTerm(&result, coef2, exp_y_1, exp_y_2);
            poly2 = poly2->next;
        } else {
            int sum = coef1 + coef2;
            if (sum != 0) {
                insertTerm(&result, sum, exp_x_1, exp_x_2);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    return result;
}

void displayPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%dy^%d ", poly->coefficient, poly->exp_x, poly->exp_y);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    int terms1, terms2;
    int coef, exp_x, exp_y;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &terms1);

    for (int i = 0; i < terms1; i++) {
        printf("Enter the term %d (coefficient  exp_x  exp_y):",i+1);
        scanf("%d %d %d", &coef, &exp_x, &exp_y);
        insertTerm(&poly1, coef, exp_x, exp_y);
    }

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &terms2);

    for (int i = 0; i < terms2; i++) {
        printf("Enter the term %d (coefficient  exp_x  exp_y):",i+1);
        scanf("%d %d %d", &coef, &exp_x, &exp_y);
        insertTerm(&poly2, coef, exp_x, exp_y);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial: ");
    displayPolynomial(result);

    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}

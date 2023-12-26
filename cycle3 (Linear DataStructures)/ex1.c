#include <stdio.h>
#include <math.h>

void Push(char s[], int *top, char item) {
    s[++(*top)] = item;
}

void PushF(float s[], int *top, float item) {
    s[++(*top)] = item;
}

char Pop(char s[], int *top) {
    if (*top == -1)
        return '\0';

    return s[(*top)--];
}

float PopF(float s[], int *top) {
    if (*top == -1)
        return 0;

    return s[(*top)--];
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int ICP(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
    }
    return -1;
}


int ISP(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
    }
    return -1;
}

int convertInfixToPostfix(char infix[], char postfix[]) {
    char Stack[100], curr;
    int top = -1, len = 0, i, j = 0;

    for (; infix[len] != '\0'; len++);

    Push(Stack, &top, '(');
    infix[len++] = ')';
    infix[len] = '\0';

    for (i = 0; infix[i] != '\0'; i++) {
        curr = infix[i];
        if (curr == ' ' || curr == '\t')
            continue;


        if (isOperand(curr)) {
            postfix[j++] = curr;
        } else if (curr == '(') {
            Push(Stack, &top, curr);
        } else if (isOperator(curr)) {

            while (top > -1 && ICP(curr) <= ISP(Stack[top])) {
                char item = Pop(Stack, &top);
                postfix[j++] = item;
            }
            Push(Stack, &top, curr);

        } else if (curr == ')') {
            while (top > -1 && Stack[top] != '(') {
                char item = Pop(Stack, &top);
                postfix[j++] = item;
            }
            Pop(Stack, &top);
        } else {
            return 0;
        }
    }
    postfix[j] = '\0';
    return 1;
}

int getAlphaPos(char ch) {
    if (ch >= 'a' && ch <= 'z')
        ch -= 32;

    return ch - 'A';
}

float evalExpr(char opr, float a, float b) {
    switch (opr) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return powf(a, b);
        default:
            return 0;
    }
}

float evalPostfix(char postfix[]) {
    char curr;
    float Stack[100];
    int i, top = -1;
    float values[26][2] = {{0, 0}};

    for (i = 0; postfix[i] != '\0'; i++) {
        curr = postfix[i];
        if (isOperand(curr)) {
            int val = getAlphaPos(curr);
            if(values[val][1] == 0) {
                printf("Enter %c: ", curr);
                scanf(" %f", &values[val][0]);
                values[val][1] = 1;
            }
            PushF(Stack, &top, values[val][0]);
        } else if (isOperator(curr)) {
            float b = PopF(Stack, &top),
                    a = PopF(Stack, &top), c;
            c = evalExpr(curr, a, b);
            PushF(Stack, &top, c);
        }
    }

    return Stack[0];
}

int main() {
    char Q[100], P[100];
    int status;

    printf("Enter Expression(in thr form of variables): ");
    scanf("%[^\n]", Q);

    status = convertInfixToPostfix(Q, P);

    if (status) {
        printf("Postfix exp: %s\n", P);

        printf("result: %f\n", evalPostfix(P));

    } else
        printf("Error in expression\n");

}
#include <stdio.h>
#include <conio.h>
#define MAX 50

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int isMatchingPair(char left, char right) {
    if (left == '(' && right == ')')
        return 1;
    if (left == '{' && right == '}')
        return 1;
    if (left == '[' && right == ']')
        return 1;
    return 0;
}

int checkBalanced(char exp[]) {
    int i;
    char temp;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            temp = pop();
            if (!isMatchingPair(temp, exp[i]))
                return 0;
        }
    }
    if (top == -1)
        return 1;  // Balanced
    else
        return 0;  // Not balanced
}

void main() {
    char expression[MAX];
    clrscr();

    printf("Enter an expression: ");
    gets(expression);

    if (checkBalanced(expression))
        printf("The expression is well parenthesized.\n");
    else
        printf("The expression is NOT well parenthesized.\n");

    getch();
}

#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

// Function to push element into stack
void push(char ch) {
    if (top == MAX - 1)
        printf("\nStack Overflow\n");
    else
        stack[++top] = ch;
}

// Function to pop element from stack
char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

// Function to check matching pair
int match(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

// Function to check if expression is well parenthesized
void checkExpression() {
    char expr[50];
    int i;
    char temp, ch;

    printf("\nEnter expression: ");
    scanf("%s", expr);

    top = -1;  // initialize stack as empty

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);

        // If closing bracket, check match
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("\nUnbalanced expression!\n");
                return;
            } else {
                temp = pop();
                if (!match(temp, ch)) {
                    printf("\nUnbalanced expression!\n");
                    return;
                }
            }
        }
    }

    // If stack empty at end -> balanced
    if (top == -1)
        printf("\nExpression is well parenthesized.\n");
    else
        printf("\nUnbalanced expression!\n");
}

int main() {
    printf("\n--- CHECK BALANCED EXPRESSION ---\n");
    checkExpression();
    return 0;
}

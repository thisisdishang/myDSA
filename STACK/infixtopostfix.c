//Implement a program to convert infix notation to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, k;

    for (i = 0, k = -1; infix[i]; ++i) {
        if (isOperand(infix[i]))
            infix[++k] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++k] = pop(stack);
            pop(stack); // Remove '('
        } else { // Operator
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
        infix[++k] = pop(stack);

    infix[++k] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix);

    printf("Postfix expression: %s\n", infix);

    return 0;
}
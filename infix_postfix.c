#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// Function prototypes
void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    } else {
        stack->items[++stack->top] = value;
    }
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return stack->items[stack->top--];
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0; // Assuming '(' has the lowest precedence
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the '('
        } else if (isOperator(token)) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }

        i++;
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter expression to calculate the batting average:  ");
    scanf("%s", infix);  

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

// Function to push an element to the stack
void push(struct Stack *stack, char c) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = c;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}

// Function to get the precedence of an operator
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        // If the character is an operand, add it to the postfix output
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(stack.arr[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    
    // Get infix expression from user
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    
    // Print postfix expression
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

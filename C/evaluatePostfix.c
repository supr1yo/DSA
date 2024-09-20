// Write a C program to evaluate a postfix expression.
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    int arr[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int value) {
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    }
    else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initStack(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        // If the character is an operand (number), push it to the stack
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements, apply the operator, and push the result
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
            case '+': push(&stack, operand1 + operand2); break;
            case '-': push(&stack, operand1 - operand2); break;
            case '*': push(&stack, operand1 * operand2); break;
            case '/': push(&stack, operand1 / operand2); break;
            default: printf("Invalid operator\n"); return -1;
            }
        }
        i++;
    }

    // The final result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char postfix[MAX];

    // Get the postfix expression from the user
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);

    // Print the result
    printf("Result of evaluation: %d\n", result);

    return 0;
}

// Write a C program to validate the parenthesis of an expression.
#include <stdio.h>
#include <stdlib.h>

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
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    } else {
        return '\0'; // Return null character if stack is empty
    }
}

// Function to check if a character is an opening parenthesis
int isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if two characters are matching pairs of parentheses
int isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to validate the parentheses of an expression
int validateParentheses(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    int i = 0;
    while (expression[i] != '\0') {
        // If the character is an opening parenthesis, push it to the stack
        if (isOpening(expression[i])) {
            push(&stack, expression[i]);
        }
        // If the character is a closing parenthesis
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            // Pop an element from the stack and check if it matches
            char popped = pop(&stack);
            if (!isMatchingPair(popped, expression[i])) {
                return 0; // Invalid expression
            }
        }
        i++;
    }
    
    // If the stack is empty, all parentheses are matched; otherwise, it's invalid
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];
    
    // Get the expression from the user
    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);
    
    // Validate the parentheses
    if (validateParentheses(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }
    
    return 0;
}

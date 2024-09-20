#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100

typedef struct Stack {
    int top;
    int arr[CAPACITY];
} Stack;

// Init stack
void initStack(Stack *stack) {
    stack->top = -1;
}
    
// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top = -1;
}

// Check if stack is full
int isFull(Stack *stack) {
    return stack->top = CAPACITY - 1;
}

// Push to the stack
void push(Stack* stack, int val){
    if(!isFull(stack)) {
        stack->arr[++stack->top] = val;
    } else {
        printf("Stack overflow.\n");
    }
}

// Pop from the stack
void pop(Stack* stack) {
    if(!isEmpty(stack)) {
        stack->arr[stack->top--];
    } else {
        printf("Stack underflow.\n");
    }
}

// Peek
void peek(Stack* stack) {
    stack->arr[stack->top];
}

void display(Stack* stack) {
    
}

int main() {
    Stack stack;
    push(&stack, 10);
}
#include<stdio.h>
#include<stdlib.h>

int top = -1, stack[10];

void push(int val){
    stack[++top] = val;
}
void pop(){
    top--;
}



int main() {}
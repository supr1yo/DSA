// Stack using Array

#include<iostream>
using namespace std;

class Stack {
    public:
    int Top = -1;
    int stack[10];

    void push(int n) {
        stack[++Top] = n;
    }

    int top() {
        if (Top == -1) return 0;
        return stack[Top];
    }

    void pop() {
        if (Top == -1) return;
        Top--;
    }

    int size() {
        return Top + 1;
    }

};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.pop();

    cout << stack.size();

    return 0;
}
#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
} *head = NULL, *n1, *n2, *n3, *ptr = NULL;

node* createNode() {
    node* nw;
    nw = new node;
    cout << "Enter data: ";
    cin >> nw->data;
    nw->next = NULL;

    return nw;
}

void displayNode(node* ptr) {
    cout << "Node values are: " << endl;
    while(ptr != NULL) {
        cout << "Data: " << ptr->data << endl;
        ptr =  ptr->next;
    }
}

int main() {
    n1 = createNode();
    n2 = createNode();
    n3 = createNode();

    n1->next = n2;
    n2->next = n3;
    head = n1;
    ptr = head;

    displayNode(ptr);

    return 0;
}
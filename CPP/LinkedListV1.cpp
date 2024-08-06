#include<iostream>
using namespace std;

struct node {
    int data;
    node *next = NULL;
} *head = NULL, *n1, *n2, *ptr = NULL;

int main() {
    n1 = new node; 
    n1->data = 10;

    n2 = new node; 
    n2->data = 20;

    n1->next = n2;
    head = n1;

    ptr = head;

    while (ptr != NULL) {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }


    return 0;
}

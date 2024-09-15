#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct node* head) {
    struct node* ptr = head;
    while(ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}


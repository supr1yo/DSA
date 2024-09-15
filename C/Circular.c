#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
Node *head = NULL;

void createList(int data) {
    Node *nw = (Node*)malloc(sizeof(Node));
    nw->data = data;
    nw->next = NULL;

    if (head == NULL) {
        head = nw;
    } else {
        
    }
}
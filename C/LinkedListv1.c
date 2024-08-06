#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *A, *B, *C, *ptr = NULL;

    // Adding data to the nodes
    A = (struct node*)malloc(sizeof(struct node));
    A->data = 10;
    A->next = NULL;

    B = (struct node*)malloc(sizeof(struct node));
    B->data = 20;
    B->next = NULL;

    C = (struct node*)malloc(sizeof(struct node));
    C->data = 30;
    C->next = NULL;

    // Linking the nodes
    A->next = B;
    B->next = C;
    head = A;

    // Display
    ptr = head;
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }


    return 0;
}


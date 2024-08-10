#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
} *head = NULL, *n1, *n2, *n3, *ptr = NULL;

struct node* createNode() {
    struct node *nw;
    nw = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data: ");
    scanf("%d", &nw->data);
    nw->next = NULL;
    return nw;
}

void displayNode(struct node* ptr) {
    while (ptr != NULL) {
        printf("Printing nodeds - \n");
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    n1 = createNode();
    n2 = createNode();
    n3 = createNode();

    // Correctly link the nodes
    n1->next = n2;
    n2->next = n3;
    head = n1;
    ptr = head;

    displayNode(ptr);

    return 0;
}

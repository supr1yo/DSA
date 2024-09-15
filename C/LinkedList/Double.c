#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void createNode(int data){
    Node *nw = (Node*)malloc(sizeof(Node));
    nw->prev = NULL;
    nw->data = data;
    nw->next = NULL;

    if (head == NULL) {
        head = nw;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nw;
        nw->prev = temp;
    }
}

void createList() {
    int i, data, size;
    
    printf("Enter the size of linked list: \n");
    scanf("%d", &size);

    for(i = 0; i< size; i++) {
        printf("Enter the node value: ");
        scanf("%d", &data);
        createNode(data);
    }
}

void display() {
    
}


int main() {

}
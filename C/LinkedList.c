#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head=NULL, *n1, *n2, *n3, *n4;


// creates linkedlist
void createList(int data) {
    Node *nw = (Node*)malloc(sizeof(Node));
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
    }
}



// Insert a node at first
void insertAtFirst(int data) {
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
}

// Counts the number of nodes
int count(Node *ptr) {
    int counter = 0;
    while(ptr != NULL) {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

// Insert at any position
void insertAtAny(int data, int pos) {
    Node *ptr = (Node*)malloc(sizeof(Node));
    if (pos < 0 || pos > count(head)) return;  
    ptr->data = data;

    // If inserting at the head (position 0)
    if (pos == 0) {
        ptr->next = head;
        head = ptr;
        return;  
    }

    Node *p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
}

void deleteFromFirst() {
    head = head->next;
}


// Search element
Node *search(Node *ptr, int key) {
    while(ptr) {
        if(ptr->data == key) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

// Sum of elements - O(n)
int add(Node *ptr) {
    int sum = 0; 
    while(ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }

    return sum;
}

// Returns the maximum data
int max(Node *ptr) {
    int m = INT_MIN; // or -32768
    while(ptr != NULL) {
        if(ptr->data > m) {
            m = ptr->data;
        }
        ptr = ptr->next;
    }
    return m;
}



void display(Node *ptr) {
    printf("Nodes of the linked list:\n");
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}


int main() {
    createList(10);
    createList(20);
    createList(30);
    createList(40);

   
    // insertAtFirst(69);
    insertAtAny(420, 3);
    // deleteFromFirst();
    display(head);
    printf("Count: %d\n", count(head));
    printf("Sum: %d\n", add(head));
    printf("Max: %d\n", max(head));
}
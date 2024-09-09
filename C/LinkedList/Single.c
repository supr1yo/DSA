#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int count = 0;
Node *head = NULL;

void createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        Node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    count++;  // Increment count for each node
}

void createList(int size) {
    int i, data;
    for (i = 0; i < size; i++) {
        printf("Enter node value: ");
        scanf("%d", &data);
        createNode(data);
    }
}

void insertAtFirst(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    head = node;
    count++;  // Increment count
}

void insertAtAny(int data, int pos) {
    if (pos < 0 || pos > count) {
        printf("Position out of bounds\n");
        return;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (pos == 0) {
        node->next = head;
        head = node;
    } else {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
    count++;  // Increment count
}

void deleteFromFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    count--;  // Decrement count
}

void deleteFromAny(int pos) {
    if (pos < 0 || pos >= count) {
        printf("Position out of bounds\n");
        return;
    }

    Node *temp = head;

    if (pos == 0) {
        head = head->next;
        free(temp);
    } else {
        Node *prev = NULL;
        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    count--;  // Decrement count
}

void display() {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Create linked list.\n");
        printf("2. Insert a node at first. \n");
        printf("3. Insert a node at any position. \n");
        printf("4. Delete a node from beginning. \n");
        printf("5. Delete a node from any position. \n");
        printf("6. Display list.\n");
        printf("7. Exit the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int size;
            printf("Enter the size of the list: ");
            scanf("%d", &size);
            createList(size);
        } else if (choice == 2) {
            int data;
            printf("Enter the node value: ");
            scanf("%d", &data);
            insertAtFirst(data);
        } else if (choice == 3) {
            int data, pos;
            printf("Enter the node value: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertAtAny(data, pos);
        } else if (choice == 4) {
            deleteFromFirst();
        } else if (choice == 5) {
            int pos;
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteFromAny(pos);
        } else if (choice == 6) {
            display();
        } else if (choice == 7) {
            break;
        } else {
            printf("Enter a correct choice.\n");
        }
    }
    return 0;
}

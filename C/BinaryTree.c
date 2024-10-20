#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;



int main() {
 
    Node *root = (Node *)malloc(sizeof(Node));
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));


    root->data = 1;
    node1->data = 2;
    node2->data = 3;
    node3->data = 4;

    root->left = node1;
    root->right = node2;
    node1->left = NULL;  // No child
    node1->right = NULL; // No child
    node2->left = node3;
    node2->right = NULL; // No child
    node3->left = NULL;  // No child
    node3->right = NULL; // No child



    return 0;
}
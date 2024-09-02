#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
    struct node *prev;
};

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main() {
    int option;
    struct node *start = NULL;

    while(1) {
        printf("\n\n                       **DOUBLE LINKED LIST**");
        printf("\n                             **MAIN MENU **");
        printf("\n\t\t 1:  Create a list");
        printf("\n\t\t 2:  Display the list");
        printf("\n\t\t 3:  Add a node at the beginning");
        printf("\n\t\t 4:  Add a node at the end");
        printf("\n\t\t 5:  Add a node before a given node");
        printf("\n\t\t 6:  Add a node after a given node");
        printf("\n\t\t 7:  Delete a node from the beginning");
        printf("\n\t\t 8:  Delete a node from the end");
        printf("\n\t\t 9:  Delete a node before a given node");
        printf("\n\t\t 10: Delete a node after a given node");
        printf("\n\t\t 11: Delete the entire list");
        printf("\n\t\t 12: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option) {
            case 1: start = create_ll(start);
                    printf("\n DOUBLY LINKED LIST CREATED");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_beg(start);
                    break;
            case 4: start = insert_end(start);
                    break;
            case 5: start = insert_before(start);
                    break;
            case 6: start = insert_after(start);
                    break;
            case 7: start = delete_beg(start);
                    break;
            case 8: start = delete_end(start);
                    break;
            case 9: start = delete_before(start);
                    break;
            case 10: start = delete_after(start);
                    break;
            case 11: start = delete_list(start);
                    printf("\n DOUBLY LINKED LIST DELETED");
                    break;
            case 12: exit(0);
                    break;
            default: printf("Wrong choice");
        }
    }
    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);

    while(num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;

        if(start == NULL) {
        	start=new_node;
        	start->next=start;
            start->prev = start;
            //start = new_node;
        } else {
            ptr = start->prev;
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=start;
            start->prev=new_node;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;
    do{
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=start);
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;

    if(start != NULL) {
        start->prev = new_node;
    }

    start = new_node;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if(start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;
    }

    return start;
}

struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr != NULL) {
        new_node->next = ptr;
        new_node->prev = ptr->prev;

        if(ptr->prev != NULL)
            ptr->prev->next = new_node;
        else
            start = new_node;

        ptr->prev = new_node;
    }

    return start;
}

struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;

    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr != NULL) {
        new_node->prev = ptr;
        new_node->next = ptr->next;

        if(ptr->next != NULL)
            ptr->next->prev = new_node;

        ptr->next = new_node;
    }

    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    if(start != NULL) {
        ptr = start;
        start = start->next;
        if(start != NULL)
            start->prev = NULL;
        free(ptr);
    }
    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr;
    if(start != NULL) {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;

        if(ptr->prev != NULL)
            ptr->prev->next = NULL;
        else
            start = NULL;

        free(ptr);
    }
    return start;
}

struct node *delete_before(struct node *start) {
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to be deleted : ");
    scanf("%d", &val);
    ptr = start;

    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr != NULL && ptr->prev != NULL) {
        temp = ptr->prev;
        if(temp == start)
            start = delete_beg(start);
        else {
            ptr->prev = temp->prev;
            if(temp->prev != NULL)
                temp->prev->next = ptr;
            free(temp);
        }
    }

    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to be deleted : ");
    scanf("%d", &val);
    ptr = start;

   while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr != NULL && ptr->next != NULL) {
        temp = ptr->next;
        ptr->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = ptr;

        free(temp);
    }

    return start;
}

struct node *delete_list(struct node *start) {
    while(start != NULL)
        start = delete_beg(start);
    return start;
}



//**********************************************************************************************************


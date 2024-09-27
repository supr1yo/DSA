// Simple queue

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100


typedef struct Queue {
    int arr[MAX_SIZE];
    int front; // Head of the Queue
    int rear; // Tail/Back of the Queue
} Queue;


int initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = 0;
}

int isEmpty(Queue* queue) {
    if (queue->rear == 0) {

    }
}

int isFull(Queue* queue) {
    if (queue->rear == MAX_SIZE) {
        return 1;
    } else {
        return 0;
    }
}
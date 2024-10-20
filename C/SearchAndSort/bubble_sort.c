#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[]) {
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j+1]){
                 swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    
}
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Using Malloc
    int *A = (int *)malloc(5 * sizeof(int));

    for(int i = 0; i<5; i++) {
        scanf("%d", &A[i]);
    }

    printf("Printing:\n");
    
    for(int i = 0; i<5; i++) {
        printf("%d\n", A[i]);
    }
    int size = sizeof(A)/sizeof(A[0]);
    printf("%d", size);

    free(A);


    return 0;
}
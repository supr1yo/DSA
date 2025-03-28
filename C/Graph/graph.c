#include <stdio.h>
#include <stdlib.h>

void createGraph(int **adjMatrix, int vertices, int edges) {
    int i, src, dest;

    for(i=0; i < edges; i++) {
        printf("Enter edge %d (format: src dest): ", i+1);
        scanf("%d %d", &src, &dest);

        adjMatrix[src][dest] = 1;
    }
}

void display(int **adjMatrix, int vertices) {
    int i, j;
    printf("\nAdjacency Matrix (Directed Graph):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int vertices, edges, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges); 

    // Dynamically allocate memory for adjacency matrix
    int **adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (i = 0; i < vertices; i++) {
        adjMatrix[i] = (int *)calloc(vertices, sizeof(int));
    }


       // Create the directed graph
       createGraph(adjMatrix, vertices, edges);

       // Display adjacency matrix
       displayGraph(adjMatrix, vertices);

    return 0;
}
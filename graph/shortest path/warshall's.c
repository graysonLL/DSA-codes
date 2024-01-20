#include <stdio.h>

#define V 4

void printSolution(int graph[][V]) {
    printf("Transitive closure of the graph:\n");
    int i;
    for (i = 0; i < V; i++) {
    	int j;
        for (j = 0; j < V; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void warshall(int graph[][V]) {
    int closure[V][V];
	
	int i,j,k;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            closure[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (closure[i][j] == 0 && closure[i][k] && closure[k][j]) {
                    closure[i][j] = 1;
                }
            }
        }
    }

    printSolution(closure);
}

int main() {
    int graph[V][V] = {{1, 1, 0, 1},
                       {0, 1, 1, 0},
                       {0, 0, 1, 1},
                       {0, 0, 0, 1}};

    warshall(graph);
    return 0;
}

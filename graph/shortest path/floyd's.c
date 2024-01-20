#include <stdio.h>

#define V 4 // Number of vertices
#define INF 99999

void printSolution(int dist[][V]) {
    printf("Shortest distances between all pairs of vertices:\n");
    int i;
    for (i = 0; i < V; i++) {
    	int j;
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];

    // Initialize the distance matrix with the graph
    int i;
    for (i = 0; i < V; i++) {
    	int j;
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Find the shortest path between all pairs using all vertices as intermediate nodes
    int k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
        	int j;
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {{0, 3, INF, 7},
                       {8, 0, 2, INF},
                       {5, INF, 0, 1},
                       {2, INF, INF, 0}};

    floydWarshall(graph);
    return 0;
}

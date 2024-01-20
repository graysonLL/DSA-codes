#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int V;
    int E;

    struct Edge* edges;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    return graph;
}

// Function to compare edges by their weights (used for sorting)
int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

// Function to find the parent of a node (used in the Disjoint Set data structure)
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two subsets (used in the Disjoint Set data structure)
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    // Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for the parent and rank arrays (used in the Disjoint Set data structure)
    int* parent = (int*)malloc(V * sizeof(int));
    int* rank = (int*)malloc(V * sizeof(int));

    // Initialize parent and rank arrays (each node is a separate subset)
    int v;
    for (v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    // Print the edges of the minimum spanning tree
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d \tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(parent);
    free(rank);
}

int main() {
    // Create a graph with 4 vertices and 5 edges
    int V = 4;
    int E = 5;
    struct Graph* graph = createGraph(V, E);

    // Edge format: source, destination, weight
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    kruskalMST(graph);
    return 0;
}

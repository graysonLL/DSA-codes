#include <stdio.h>
#include <stdlib.h>
#define MAX 5


void dfsBST(int start) {
    int stack[MAX], top = -1;
    int current = start;

    while (current != -1 || top > -1) {
        while (current != -1) {
            stack[++top] = current;
            current = current->left; // Use left child
        }

        if (top > -1) {
            current = stack[top--];
            printf("%d ", current->data); // Process the current node
            current = current->right; // Use right child
        }
    }
}

void dfs(int matrix[][MAX],int start,int nodes) {
	int visited[nodes];
	
	int x;
	for(x=0;x<nodes;x++) {
		visited[x] = 0;
	}
	
	int stack[nodes],top = -1;
	stack[++top] = start;
	visited[start] = 1;
	
	while(top > -1) {
		int source = stack[top--];
		printf("%d ",source);
		
		int adj;
		for(adj = 0;adj<nodes;adj++) {
			if(matrix[source][adj] == 1 && visited[adj] == 0) {
				visited[adj] = 1;
				stack[++top] = adj;
			}
		}
	}
}





void bfs(int V, int source, int matrix[][MAX]) {
	int visited[MAX],x;
	
	for(x=0;x<V;x++) {
		visited[x] = 0;
	}
	
	int front = 0,rear = 0, queue[MAX];
	
	queue[rear++] = source;
	visited[source] = 1;
	
	while(front != rear) {
		source = queue[front++];
		printf("%d ",source);
		
		int adj;
		for(adj=0;adj<V;adj++) {
			if(matrix[source][adj] == 1 && visited[adj] == 0) {
				visited[adj] = 1;
				queue[rear++] = adj;
			}
		}
	}
}

void bfsBST(struct TreeNode* start) {
    struct TreeNode* queue[MAX];
    int front = 0, rear = 0;

    if (start != NULL) {DD
        queue[rear++] = start;
    }

    while (front < rear) {
        struct TreeNode* current = queue[front++];
        printf("%d ", current->data); // Process the current node

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}


void dfsbst(int start) {
	int stack[MAX], top = -1;
	int current = start;
	
	while(current != -1 || top > -1) {
		while(current != -1) {
			stack[++top] = current;
			current = LC;
		}
		
		if(top > -1) {
			current = stack[top--];
			printf("%d ",current);
			current = RC;
		}
	}	
}




















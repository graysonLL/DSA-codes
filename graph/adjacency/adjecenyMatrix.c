#include <stdio.h>
#define MAX 5
#include <stdbool.h>

typedef struct {
	char data[MAX];
	int matrix[MAX][MAX];
} matrix;

void init(matrix *A) {
	int x;
	for(x=0;x<MAX;x++) {
		int y;
		for(y=0;y<MAX;y++) {
			A->matrix[x][y] = 0;
		}
	}
	for(x=0;x<MAX;x++) {
		A->data[x] = 65+x;
	}
}

void display(matrix A) {
	int x;
	printf("  ");
	for(x=0;x<MAX;x++) {
		printf("%c ",A.data[x]);
	}
	printf("\n");
	for(x=0;x<MAX;x++) {
		printf("%c ",A.data[x]);
		int y;
		for(y=0;y<MAX;y++) {
			printf("%d ",A.matrix[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

void insert(matrix *A,int src,int dst) {
	if(src>=0 && src<MAX && dst>=0 && dst<MAX) {
		A->matrix[src][dst] = 1;
	}
}

void del(matrix *A,int src,int dst) {
	if(src>=0 && src<MAX && dst>=0 && dst<MAX) {
		A->matrix[src][dst] = 0;
	}
	else {
		printf("WTF");
	}
}

bool find(matrix A,int src,int dst) {
	return (A.matrix[src][dst] == 1) ? true : false;
} 

int main(void) {
	matrix A;
	init(&A);

	display(A);
	insert(&A,0,2);
	insert(&A,2,0);
	insert(&A,0,3);
	insert(&A,3,4);
	insert(&A,1,3);
	insert(&A,4,1);
	
	display(A);
	
	del(&A,0,0);
	
	display(A);
	
	printf(find(A,0,2)==true ? "wow" : "shit");

	return 0;
}

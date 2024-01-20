#include <stdio.h>
#define MAX 8

typedef struct {
	char data[MAX];
	int front;
	int rear;
} Q;

void init(Q *A) {
	A->front = 1;
	A->rear = 0;
}

void insert(Q *A,char elem) {
	if(A->front != (A->rear+2)%MAX) {
		printf("not full\n");
		A->data[++A->rear] = elem;
	} else {
		printf("FULL\n");
	}
}

void del(Q *A) {
	if(A->front != (A->rear+1)%MAX) {
		A->front++;
	}
}

void display(Q A) {
	int x;
	
	for(x=A.front;x!=(A.rear+1)%MAX;x=(x+1)%MAX) {
		printf("%c ",A.data[x]);
	}
	printf("\n");
}

int main(void) {
	Q Q;
	
	init(&Q);
	
	insert(&Q,'A');
	insert(&Q,'B');
	insert(&Q,'C');
	insert(&Q,'D');
	insert(&Q,'E');
	insert(&Q,'F');
	insert(&Q,'G');
	insert(&Q,'H');
	
	display(Q);
	
	return 0;
}

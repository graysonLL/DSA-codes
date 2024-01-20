#include <stdio.h>
#define MAX 10

typedef struct {
	int next;
	char elem;	
} Node;

typedef struct {
	int Avail;
	Node data[MAX];
} Vheap;

typedef struct {
	int front;
	int rear;
	int count;
	Vheap QV;
} Q;

void init(Q *A) {
	A->front = -1;
	A->rear = -1;
	
	int last = MAX-1,x;
	
	for(x=0;x<last;x++) {
		A->QV.data[x].next = x+1;
	}
	
	A->QV.data[x].next = x;
	A->QV.Avail = 0;
	A->count = 0;
}

void insert(Q *A, char elem) {
	if(A->count<MAX) {
		int space = A->QV.Avail;
		
		if(space!=-1) {
			A->QV.Avail = A->QV.data[space].next;
			A->QV.data[space].elem = elem;
			A->QV.data[space].next = -1;
			
			if(A->front == -1) {
				A->front = space;
			}
			else {
				A->QV.data[A->rear].next = space;
			}
			A->rear = space;
		}
	}
}

void del(Q *A) {
	if(A->front!=-1) {
		int temp = A->front;
		A->front = A->QV.data[A->front].next;
		A->QV.data[temp].next = A->QV.Avail;
		A->QV.Avail = temp;
	}
}

void display(Q A) {
	int x;
	for(x = A.front;x!=-1;x=A.QV.data[x].next) {
		printf("%c ",A.QV.data[x].elem);
	}
	printf("\n");
}

int main(void) {
	Q A;
	
	init(&A);
	
	insert(&A,'A');
	insert(&A,'B');
	insert(&A,'C');
	insert(&A,'D');
	insert(&A,'E');
	
	display(A);
	
	printf("%c %c",A.QV.data[A.front].elem,A.QV.data[A.rear].elem);
	
	return 0;
}

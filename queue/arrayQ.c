#include <stdio.h>
#define MAX 5

typedef enum {TRUE,FALSE} boolean;

typedef struct {
	int front;
	int rear;
	char data[MAX];
	int count;
} Q;

boolean isFull(Q A);
boolean isEmpty(Q A);
void init(Q *A);
void enqueue(Q *A,char elem);
void display(Q A);
void dequeue(Q *A);
char front(Q A);
char rear(Q A);

int main(void) {
	Q Q;
	init(&Q);
	
	enqueue(&Q,'A');
	enqueue(&Q,'B');
	enqueue(&Q,'C');
	enqueue(&Q,'D');

	
	display(Q);
	dequeue(&Q);
	display(Q);
	dequeue(&Q);
	display(Q);

	
	printf("%c ",rear(Q));
	
	return 0;
}

boolean isFull(Q A) {
	return A.front==(A.rear+2)%MAX ? TRUE : FALSE;
}
boolean isEmpty(Q A) {
	return A.front==(A.rear+1)%MAX  ? TRUE : FALSE;
}
void init(Q *A) {
	A->count=0;
	A->front=3;
	A->rear=2;
}
void enqueue(Q *A,char elem) {
	if(isFull(*A)==FALSE) {
		A->rear=(A->rear+1)%MAX;
		A->data[A->rear] = elem;
		A->count++;
	}
}

void display(Q A) {
	while(isEmpty(A)==FALSE) {
		printf("%c ",front(A));
		A.front=(A.front+1)%MAX;
	}
	printf("\n");
}

void dequeue(Q *A) {
	if(isEmpty(*A)==FALSE) {
		A->front=(A->front+1)%MAX;
		A->count--;
	}
}

char front(Q A) {
	return isEmpty(A)==FALSE ? A.data[A.front] : '\0';
}

char rear(Q A) {
	return isEmpty(A)==FALSE ? A.data[A.rear] : '\0';	
}



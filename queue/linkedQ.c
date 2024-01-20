#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef enum {TRUE,FALSE} boolean;

typedef struct node {
	struct node *next;
	char data;
} *Node;

typedef struct {
	int count;
	Node front;
	Node rear;
} Que;

boolean isFull(Que A);
boolean isEmpty(Que A);
void init(Que *A);
void enqueue(Que *A,char elem);
void dequeue(Que *A);
void display(Que A);
char front(Que A);
char rear(Que A);

int main(void) {
	Que Q;
	init(&Q);
	
	enqueue(&Q,'A');
	enqueue(&Q,'B');
	dequeue(&Q);
	enqueue(&Q,'C');
	enqueue(&Q,'D');
	
	display(Q);
	
	printf("%c %c ",Q.front->data,Q.rear->data);
	
	return 0;
}

boolean isFull(Que A) {
	return A.count == MAX ? 0 : 1;
}

boolean isEmpty(Que A) {
	return A.front==NULL ? 0 : 1;
}

void init(Que *A) {
	A->front=NULL;
	A->rear=NULL;
	A->count=0;
}

void enqueue(Que *A,char elem) {
	if(isFull(*A)==FALSE) {
		Node newNode = (Node)malloc(sizeof(struct node));
		if(newNode!=NULL) {
			newNode->data=elem;
			newNode->next=NULL;
			if(isEmpty(*A)==TRUE) {
				A->front=newNode;
			}
			else {
				A->rear->next=newNode;
			}
			A->rear=newNode;
			A->count++;
		}
	}
}

void dequeue(Que *A) {
	if(isEmpty(*A)==FALSE) {
		Node temp = A->front;
		A->front=temp->next;
		free(temp);
		A->count--;
	}
}

void display(Que A) {
	Node curr;
	for(curr=A.front;curr!=NULL;curr=curr->next) {
		printf("[%c] ",curr->data);
	}
	printf("\n");
}

char front(Que A) {
	return isEmpty(A)==FALSE ? A.front->data : '\0';
}

char rear(Que A) {
	return isEmpty(A)==FALSE ? A.rear->data : '\0';
}



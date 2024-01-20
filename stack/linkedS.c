#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef enum {TRUE,FALSE} boolean;

typedef struct node {
	char data;
	struct node *next;
} *NODE;

typedef struct {
	int count;
	NODE front;
} STACK;

boolean isFull(STACK A);
boolean isEmpty(STACK A);
void init(STACK *A);
void push(STACK *A,char elem);
void pop(STACK *A);
char top(STACK A);
void display(STACK A);
void makeNull(STACK *A);

int main(void) {
	STACK S;
	init(&S);
	
	push(&S,'A');
	push(&S,'B');
	push(&S,'C');
	push(&S,'D');
	push(&S,'E');	
	
	makeNull(&S);
	
	display(S);
	display(S);
	
	
	return 0;
}

boolean isFull(STACK A) {
	return A.count==MAX ? TRUE : FALSE;
}

boolean isEmpty(STACK A) {
	return A.count==0 && A.front==NULL ? TRUE : FALSE;
}

void init(STACK *A) {
	A->count=0;
	A->front=NULL;
}

void push(STACK *A,char elem) {
	if(isFull(*A)==FALSE) {
		NODE temp = (NODE)malloc(sizeof(struct node));
		if(temp!=NULL) {
			temp->next=A->front;
			temp->data=elem;
			A->front=temp;
			A->count++;
		}
	}
	else {
		printf("FULL");
	}
}

void pop(STACK *A) {
	if(isEmpty(*A)==FALSE) {
		NODE temp = A->front;
		A->front=temp->next;
		free(temp);
		A->count--;
	}
}

char top(STACK A) {
	return isEmpty(A)==FALSE ? A.front->data : '\0';
}

void display(STACK A) {
	if(isEmpty(A)==FALSE) {
		STACK dummy;
		int x,count=A.count;
		for(x=0;x<count;x++) {
			printf("%c ",top(A));
			push(&dummy,A.front->data);
			pop(&A);
		}
		printf("\n");
		for(x=0;x<count;x++) {
			printf("%c ",top(dummy));
			push(&A,dummy.front->data);
			pop(&dummy);
		}
	}
	else {
		printf("empty no display\n");
	}
	printf("\n");
}

void makeNull(STACK *A) {
	if(isEmpty(*A)==FALSE) {
		while(A->count>0) {
			pop(A);
		}
	}
}


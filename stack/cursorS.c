#include <stdio.h>
#define MAX 5

typedef enum {TRUE,FALSE} boolean;

typedef struct {
	char elem;
	int next;
} node;

typedef struct {
	int avail;
	int top;
	int count;
	node data[MAX];
} STACK;

boolean isFull(STACK A);
boolean isEmpty(STACK A);
int allocSpace(STACK *A);
void deallocSpace(STACK *A,int indx);
void init(STACK *A);
void push(STACK *A,char elem);
void pop(STACK *A);
void display(STACK A);
char top(STACK A);

int main(void) {
	STACK S;
	init(&S);
	
	push(&S,'A');
	push(&S,'B');
	push(&S,'C');
	push(&S,'D');
	display(S);
	
	pop(&S);
	pop(&S);
	pop(&S);
	display(S);
	
	push(&S,'B');
	push(&S,'C');
	push(&S,'D');
	display(S);
	
	return 0;
}

boolean isFull(STACK A) {
	return A.count==MAX ? TRUE : FALSE;
}

boolean isEmpty(STACK A) {
	return A.top==-1 ? TRUE : FALSE;
}

int allocSpace(STACK *A) {
	int retNdx = A->avail;
	if(retNdx!=-1) {
		A->avail = A->data[retNdx].next;
	}
	return retNdx;
}

void deallocSpace(STACK *A,int indx) {
	if(indx>=0&&indx<MAX) {
		A->data[indx].next=A->avail;
		A->avail=indx;
	}
}

void init(STACK *A) {
	A->count=0;
	A->top=-1;
	int x,lastNdx=MAX-1;
	for(x=0;x<lastNdx;x++) {
		A->data[x].next=x+1; 
	}
	A->data[x].next=-1;
	A->avail=0;
}

void push(STACK *A,char elem) {
	if(isFull(*A)==FALSE) {
		int space = allocSpace(A);
		if(space!=-1) {
			A->data[space].elem=elem;
			A->data[space].next=A->top;
			A->top=space;
			A->count++;
		}
	}
}

void pop(STACK *A) {
	if(isEmpty(*A)==FALSE) {
		int temp = A->top;
		A->top=A->data[temp].next;
		deallocSpace(A,temp);
		A->count--;
	}
}

void display(STACK A) {
	int x;
	for(x=A.top;x!=-1;x=A.data[x].next) {
		printf("[%c] ",A.data[x].elem);
	}
	printf("\n");
}

char top(STACK A) {
	return isEmpty(A)==FALSE ? A.data[A.top].elem : '\0';
}


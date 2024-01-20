#include <stdio.h>
#define MAX 5

typedef enum {TRUE,FALSE} boolean; 

typedef struct {
	char data[MAX];
	int count;
	int top;
} STACK;

boolean isFull(STACK A);
boolean isEmpty(STACK A);
void init(STACK *A);
void push(STACK *A, char elem);
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
	push(&S,'E');
	
	printf(" top: %c\n",top(S));
	
	display(S);
	display(S);
		
	return 0;
}


boolean isFull(STACK A) {
	return A.count==MAX ? TRUE : FALSE;
}

boolean isEmpty(STACK A) {
	return A.count==0 ? TRUE : FALSE;
}

void init(STACK *A) {
	A->count=0;
	A->top=-1;
}

void push(STACK *A, char elem) {
	isFull(*A)==FALSE ? A->data[++A->top]=elem,A->count++ : printf("FULL");
}

void pop(STACK *A) {
	isEmpty(*A)==FALSE ? A->top--,A->count-- : printf("EMPTY");
}

char top(STACK A) {
	return isEmpty(A)==FALSE ? A.data[A.top] : '\0';
}

void display(STACK A) {
	int x,count=A.count;
	STACK dummy;
	init(&dummy);
	
	for(x=0;x<count;x++) {
		printf("%c%d ",top(A),A.count);
		push(&dummy,A.data[A.top]);
		pop(&A);
		printf("pop:%d",A.count);
	}
	printf("\n");
	
	for(x=0;x<count;x++) {
		push(&A,dummy.data[dummy.top]);
		pop(&dummy);
		printf("%c:%d ",A.data[A.top],A.count);
	}
	printf("\n");
	printf("\n");
}

void makeNull(STACK *A) {
	A->count=0;
	A->top=-1;
}



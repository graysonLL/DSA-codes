#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef enum {TRUE,FALSE} boolean;
typedef char DATA[MAX];

typedef struct {
	int count;
	DATA data;
} SET;

void init(SET *A);
void insert(SET *A,char elem);
void display(SET A);
void del(SET *A,char elem);
boolean isMember(SET A,char elem);
SET unionset(SET A,SET B);
SET insersectionset(SET A,SET B);
SET differenceset(SET A,SET B);


int main(void) {
	SET A;
	init(&A);
	
	insert(&A,'A');
	insert(&A,'C');
	insert(&A,'B');
	insert(&A,'C');
	insert(&A,'E');
	insert(&A,'D');
	insert(&A,'F');
	

	
	del(&A,'B');
	display(A);
	
	if(isMember(A,'Z')==TRUE) {
		printf("TRUE\n");
	}
	
	
	SET B;
	init(&B);
	
	insert(&B,'X');
	insert(&B,'Y');
	insert(&B,'Z');
	insert(&B,'E');
	insert(&B,'D');
	insert(&B,'F');
	
	display(B);
	
	
	printf("UNION SET: ");
	SET U = unionset(A,B);
	display(U);
	
	printf("INTERSECTION SET: ");
	SET I = insersectionset(A,B);
	display(I);
	
	printf("DIFFERENCE SET: ");
	SET D = differenceset(B,A);
	display(D);
	
	return 0;
}

void init(SET *A) {
	int x;
	for(x=0;x<MAX;x++) {
		A->data[x] = '\0';
	}
	A->count=0;
}

void insert(SET *A,char elem) {
	if(A->count<MAX) {
		int x;
		for(x=0;x<A->count&&A->data[x]!=elem;x++) {}
		x>=A->count ? (A->data[A->count++] = elem) : printf("WHY");
	}
}

void display(SET A) {
	int x;
	for(x=0;x<A.count;x++) {
		printf("[%c] ",A.data[x]);
	}
	printf("\n");
}

void del(SET *A,char elem) {
	if(A->count>0) {
		int x;
		for(x=0;x<A->count&&A->data[x]!=elem;x++) {}
		if(x<A->count) {
			for(;x<A->count;x++) {
				A->data[x] = A->data[x+1];
			}
			A->count--;
		}
	}
}

boolean isMember(SET A,char elem) {
	int x;
	for(x=0;x<A.count&&A.data[x]!=elem;x++) {}
	return x<A.count ? TRUE : FALSE;
}

SET unionset(SET A,SET B) {
	SET C;
	init(&C);
	int x;
	for(x=0;x<A.count;x++) {
		C.data[C.count++] = A.data[x];
	}
	for(x=0;x<B.count;x++) {
		if(isMember(C,B.data[x])==FALSE) {
			C.data[C.count++] = B.data[x];
		}
	}
	
	return C;
}

SET insersectionset(SET A,SET B) {
	SET C;
	init(&C);
	
	int x;
	for(x=0;x<A.count;x++) {
		int y;
		for(y=0;y<B.count&&B.data[y]!=A.data[x];y++) {}
		if(y<B.count) {
			C.data[C.count++] = A.data[x];
		}
	}
	
	return C;
}

SET differenceset(SET A,SET B) {
	SET C;
	init(&C);
	
	int x;
	for(x=0;x<A.count;x++) {
		int y;
		for(y=0;y<B.count&&B.data[y]!=A.data[x];y++) {}
		if(y==B.count) {
			C.data[C.count++] = A.data[x];
		}
	}
	
	
	return C;
}



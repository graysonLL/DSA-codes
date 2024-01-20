#include <stdio.h>
#define MAX 6
#define EMPTY '!'
#define DELETED '@'

typedef struct {
	int next;
	char data;
} Node;

typedef struct {
	int last;
	int start;
	int avail;
	Node elems[MAX];
} CD;

int hash(char elem) {
	return elem%(MAX/2);
}

void init(CD *A) {
	int x,half=(MAX)/2,last = MAX-1;
	
	for(x=0;x<last;x++) {
		if(x<half) {
			A->elems[x].next = -1;
			A->elems[x].data = '!';
		} else {
			A->elems[x].data = ' ';
			A->elems[x].next = x+1;
		}
	}
	A->elems[x].data = ' ';
	A->elems[x].next = -1;
	
	A->avail = half;
	A->last = half;
	A->start = -1;
}

void insert(CD *A,char elem) {
	int index = hash(elem); 
	
	if(A->elems[index].data == EMPTY || A->elems[index].data == DELETED) {
		A->elems[index].data = elem;
	}
	else {
		int *curr;
		for(curr=&index;*curr!=-1 && A->elems[*curr].data != elem;curr=&A->elems[*curr].next) {}
			
		if(*curr==-1) {
			int space = A->avail;
			if(space!=-1) {
				A->avail = A->elems[space].next;
				
				A->elems[space].data = elem;
				A->elems[space].next = *curr;
				*curr = space;
				A->last++;
			}
		}
		
	}
}

void displayVheap(CD A) {
	int x;
	for(x=0;x<MAX;x++) {
		printf("[%d] %d\n",x,A.elems[x].next);
	}
	printf("\n");
}

void display(CD A) {
	int x;
	for(x=0;x<MAX/2;x++) {
		int curr;
		for(curr=x;curr!=-1;curr=A.elems[curr].next) {
			printf("[%d] data:%c next:%d\n",x,A.elems[curr].data,A.elems[curr].next);
		}
	}
	printf("\n");
}

int main(void) {
	CD A;
	init(&A);
	
	displayVheap(A);
	
	insert(&A,'A');
	insert(&A,'B');
	insert(&A,'C');
	insert(&A,'A');
	insert(&A,'D');
	insert(&A,'E');
	insert(&A,'E');
	insert(&A,'Z');
	display(A);
	
	
	return 0;
}

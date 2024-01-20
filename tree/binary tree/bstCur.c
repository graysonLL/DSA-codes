#include <stdio.h>
#define MAX 10

typedef struct {
	int LC;
	int RC;
	int data;
} node;

typedef node Nodes[MAX];

typedef struct {
	int avail;
	Nodes elems;
	int start;
} Vheap;

void init(Vheap *A) {
	int last = MAX-1,x;
	
	for(x=0;x<last;x++) {
		A->elems[x].LC = x+1;
		A->elems[x].RC = x+1;
	}
	A->elems[x].LC = -1;
	A->elems[x].RC = -1;
	A->avail = 0;
	A->start = -1;
}

void displayHeap(Vheap A) {
	int x;
	printf("LC RC\n_____\n");
	for(x=0;x<MAX;x++) {
		printf("%d  %d\n",A.elems[x].LC,A.elems[x].RC);
	}
}

void insert(Vheap *A,int elem) {
	int *curr;
	
	for(curr = &A->start;*curr!=-1 && A->elems[*curr].data != elem;) {
		curr = elem < A->elems[*curr].data ? &A->elems[*curr].LC : &A->elems[*curr].RC;
	}
	
	if(*curr == -1) {
		int space = A->avail;
		
		if(space != -1) {
			A->avail = A->elems[space].RC;
			
			A->elems[space].data = elem;
			A->elems[space].RC = -1;
			A->elems[space].LC = -1;
			*curr = space;
		}
	}
}

void del(Vheap *A,int elem) {
	int *curr;
	
	for(curr = &A->start;*curr!=-1 && A->elems[*curr].data != elem;) {
		curr = elem < A->elems[*curr].data ? &A->elems[*curr].LC : &A->elems[*curr].RC;
	}
	
	if(*curr != -1) {
		if(A->elems[*curr].RC != -1 && A->elems[*curr].LC != -1) {
			int *trav;
			for(trav = &A->elems[*curr].LC;A->elems[*trav].RC != -1;trav = &A->elems[*trav].RC) {}
			
			int temp = A->elems[*trav].data;
			A->elems[*trav].data = A->elems[*curr].data;
			A->elems[*curr].data = temp;
			
			temp = *trav;
			*trav = A->elems[*trav].LC;
			
			A->elems[temp].LC = A->avail;
			A->elems[temp].RC = A->avail;
			A->avail = temp;
		}
		else if(A->elems[*curr].LC != -1  || A->elems[*curr].RC != -1) {
			int temp = *curr;
			
			*curr = A->elems[*curr].LC != -1 ? A->elems[*curr].LC : A->elems[*curr].RC;
			
			A->elems[temp].LC = A->avail;
			A->elems[temp].RC = A->avail;
			A->avail = temp;
		}
		else if(A->elems[*curr].LC == -1  && A->elems[*curr].RC == -1) {
			int temp = *curr;
			*curr = -1;
			A->elems[*curr].LC = A->avail;
			A->elems[*curr].RC = A->avail;
			A->avail = *curr;
		}
	}
}

void inorder(Vheap A,int index) {
	if(index!=-1) {
		inorder(A,A.elems[index].LC);
		printf("%d ",A.elems[index].data);
		inorder(A,A.elems[index].RC);
	}
}

void displayA(Vheap A) {
	printf("\n%d\n",A.avail);
}

int main(void) {
	Vheap A;
	init(&A);
	
	displayHeap(A);
	
	insert(&A,10);
	insert(&A,6);
	insert(&A,8);
	insert(&A,4);
	insert(&A,7);
	insert(&A,12);
	insert(&A,13);
	printf("\n");
	inorder(A,A.start);
	printf("\n");
	del(&A,10);
	inorder(A,A.start);
	
	return 0;
}

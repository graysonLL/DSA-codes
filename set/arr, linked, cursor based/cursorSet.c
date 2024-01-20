#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	char data;
	int next;
} Node;

typedef struct {
	int avail;
	int count;
	int start;
	Node items[MAX];
} SET;

int allocSpace(SET *A);
void deallocSpace(SET *A,int index);
void init(SET *A);
void insert(SET *A,char elem);
void display(SET A);
void del(SET *A,char elem);
SET unionset(SET A,SET B);
SET intersectionset(SET A,SET B);
SET differenceset(SET A,SET B);


int main(void) {
	SET A;
	init(&A);
	
	insert(&A,'A');
	insert(&A,'C');
	insert(&A,'B');
	insert(&A,'F');
	insert(&A,'Z');
	
	del(&A,'C');

	display(A);
	
	SET B;
	init(&B);
	
	insert(&B,'A');
	insert(&B,'D');
	insert(&B,'X');
	insert(&B,'C');
	insert(&B,'Y');
	

	display(B);

	
	printf("UNION SET: ");
	SET U = unionset(A,B);
	display(U);
	
	
	printf("INTERSECTION SET: ");
	SET I = intersectionset(A,B);
	display(I);
	
	printf("DIFFERENCE SET: ");
	SET D = differenceset(A,B);
	display(D);

	return 0;
}

int allocSpace(SET *A) {
	int retIndx = A->avail;
	if(retIndx!=-1) {
		A->avail=A->items[retIndx].next;
	}
	return retIndx;
}

void deallocSpace(SET *A,int index) {
	if(index>=0&&index<MAX) {
		A->items[index].next=A->avail;
		A->avail=index;
	}
}

void init(SET *A) {
	A->count=0;
	A->start=-1;
	A->avail=0;
	int x,lastNdx=MAX-1;
	for(x=0;x<lastNdx;x++) {
		A->items[x].next=x+1;
	}
	A->items[x].next=-1;
}

void insert(SET *A,char elem) {
	if(A->count<MAX) {
		int *curr;
		for(curr=&A->start;*curr!=-1&&A->items[*curr].data<elem;curr=&A->items[*curr].next) {}
		if(*curr==-1||A->items[*curr].data!=elem) {
			int space = allocSpace(A);
			if(space!=-1) {
				A->items[space].data=elem;
				A->items[space].next=*curr;
				*curr=space;
				curr=&A->items[*curr].next;
				A->count++;
			}
		}
	}
}

void display(SET A) {
	int curr,x;
	for(curr = A.start,x=0;x<A.count;curr=A.items[curr].next,x++) {
		printf("[%c] ",A.items[curr].data);
	}
	printf("\n");
}

void del(SET *A,char elem) {
	int *curr;
	for(curr=&A->start;*curr!=-1&&A->items[*curr].data<elem;curr=&A->items[*curr].next) {}
	if(*curr!=-1 && A->items[*curr].data==elem) {
		int temp = *curr;
		*curr=A->items[*curr].next;
		deallocSpace(A,temp);
		A->count--;
	}
}

SET unionset(SET A,SET B) {
	SET C;
	init(&C);
	
	int *curr1,*curr2,*curr3;
	for(curr1=&A.start,curr2=&B.start,curr3=&C.start;*curr1!=-1&&*curr2!=-1;) {
		int space = allocSpace(&C);
		if(space!=-1) {
			if(A.items[*curr1].data<B.items[*curr2].data) {
				C.items[space].data=A.items[*curr1].data;
				curr1=&A.items[*curr1].next;
			}
			else if(A.items[*curr1].data>B.items[*curr2].data) {
				C.items[space].data=B.items[*curr2].data;
				curr2=&B.items[*curr2].next;
			}
			else {
				C.items[space].data=A.items[*curr1].data;
				curr1=&A.items[*curr1].next;
				curr2=&B.items[*curr2].next;
			}
			*curr3=space;
			curr3=&C.items[*curr3].next;
			C.count++;
		}
	}
	
	if(*curr1!=-1) {
		while(*curr1!=-1) {
			int space = allocSpace(&C);
			if(space!=-1) {
				C.items[space].data=A.items[*curr1].data;
				C.items[space].next=*curr3;
				*curr3=space;
				curr3=&C.items[*curr3].next;
				curr1=&A.items[*curr1].next;
				C.count++;
			}
		}
	}
	else {
		while(*curr2!=-1) {
			int space = allocSpace(&C);
			if(space!=-1) {
				C.items[space].data=B.items[*curr2].data;
				C.items[space].next=*curr3;
				*curr3=space;
				curr3=&C.items[*curr3].next;
				curr2=&B.items[*curr2].next;
				C.count++;
			}
		}
	}

	return C;
}

SET intersectionset(SET A,SET B) {
	SET C;
	init(&C);
	
	int *curr1,*curr2,*curr3;
	for(curr1=&A.start,curr2=&B.start,curr3=&C.start;*curr1!=-1&&*curr2!=-1;) {
		if(A.items[*curr1].data<B.items[*curr2].data) {
			curr1 = &A.items[*curr1].next;
		}
		else if(A.items[*curr1].data>B.items[*curr2].data) {
			curr2 = &B.items[*curr2].next;
		}
		else {
			int space = allocSpace(&C);
			if(space!=-1) {
				C.items[space].data=A.items[*curr1].data;
				C.items[space].next=*curr3;
				*curr3 = space;
				curr3 = &C.items[*curr3].next;
				curr1 = &A.items[*curr1].next;
				curr2 = &B.items[*curr2].next;
				C.count++;
			}
		}
	}
	
	return C;
}

SET differenceset(SET A,SET B) {
	SET C;
	init(&C);
	
	int *c1,*c2,*c3;
	for(c1=&A.start,c2=&B.start,c3=&C.start;*c1!=-1&&*c2!=-1;) {
		if(A.items[*c1].data<B.items[*c2].data) {
			int space = allocSpace(&C);
			if(space!=-1) {
				C.items[space].data=A.items[*c1].data;
				C.items[space].next=*c3;
				*c3=space;
				c3=&C.items[*c3].next;
				c1=&A.items[*c1].next;
				C.count++;
			}
		}
		else if(A.items[*c1].data>B.items[*c2].data) {
			c2 = &B.items[*c2].next;
		}
		else {
			c1=&A.items[*c1].next;
			c2 = &B.items[*c2].next;
		}
	}
	
	if(*c1!=-1) {
		while(*c1!=-1) {
			int space = allocSpace(&C);
			if(space!=-1) {
				C.items[space].data=A.items[*c1].data;
				C.items[space].next=*c3;
				*c3=space;
				c3=&C.items[*c3].next;
				c1=&A.items[*c1].next;
				C.count++;
			}
		}
	}
	
	return C;
}


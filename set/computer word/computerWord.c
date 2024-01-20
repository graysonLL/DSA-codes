#include <stdio.h>
#define MAX 8

typedef unsigned char bitmask;


typedef struct {
	bitmask bit;
	char data[MAX];	
} SET;


void insert(SET *A,char elem);
void display(SET A);
void displaySET(SET A);
void del(SET *A,char elem);
int hash(char elem);

int main(void) {
	SET A;
	A.bit=0;
	
	display(A);
	
	insert(&A,'A');
	display(A);
	displaySET(A);
	
	insert(&A,'B');
	insert(&A,'D');
	displaySET(A);
	
	return 0;
}


void insert(SET *A,char elem) {
	int index = hash(elem);
	bitmask mask = 1 << index;
	A->data[index] = elem;
	A->bit |= mask;
	printf("%d",index);
}

void display(SET A) {
	int x;
	bitmask mask;
	
	for(x=MAX-1;x>=0;x--) {
		printf(A.bit & (mask = 1 << x) ? "1" : "0");
		if(x%4==0) {
			printf(" ");
		}
	}
	printf("\n");
}

void displaySET(SET A) {
	int x;
	bitmask mask;
	for(x=MAX-1;x>=0;x--) {
		printf("%d: ",x);
		if(A.bit & (mask = 1 << x)) {
			printf("%c ",A.data[x]);
		}
		else {
			printf("EMPTY ");
		}
		printf("\n");
	}
	printf("\n");
}




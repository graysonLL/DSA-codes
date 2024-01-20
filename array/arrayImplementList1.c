#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node{
	char elements[SIZE];
	int count;
} List;

typedef enum {TRUE, FALSE} Boolean;

void initializeListA(List *L);
List initializeListB();
int findElem(List L,int elem);
void insertFirst(List *L,int elem);
void display(List L);
int deleteElem(List *L,int elem);

int main(void) {
	int i;
	
	List L;
	initializeListA(&L);	
	
	List B=initializeListB();
	
	for(i=0;i<5;i++) {
		B.elements[i]=i+1;
		B.count++;
	}
	printf("Return init: ");
	display(B);

	for(i=0;i<5;i++) {
		L.elements[i]=i+1;
		L.count++;
	}
	printf("Main init: ");
	display(L);
	
	
	int elem1=findElem(L,5);
	printf("Find elem: %d\n",elem1);
	display(L);
	
	
	insertFirst(&L,5);
	insertFirst(&L,4);
	insertFirst(&L,3);
	insertFirst(&L,2);
	insertFirst(&L,1);
	printf("Inserting front: ");
	display(L);
	
	
	printf("Deleting elem: ");
	deleteElem(&L,1);
	display(L);
		
	deleteElem(&L,1);
	deleteElem(&L,2);
	deleteElem(&L,2);
	deleteElem(&L,3);
	deleteElem(&L,3);
	deleteElem(&L,4);
	deleteElem(&L,4);
	deleteElem(&L,5);	
	display(L);
		
	return 0;
}

void initializeListA(List *L) {
	L->count=0;
}

List initializeListB() {
	List L;
	L.count=0;
	
	return L;
}

void display(List L) {
	int i;
	for(i=0;i<L.count;i++) {
		printf("%d ",L.elements[i]);
	}
	printf("\n");
}

int findElem(List L,int elem) {
	int num = -1,i;
	
	for(i=0;i<L.count&&L.elements[i]!=elem;i++) {}
	
	if(i!=L.count) {
		num = L.elements[i];
	}
	
	return num;
}

void insertFirst(List *L,int elem) {
	Boolean cond;
	int i;
	if(cond==L->count<SIZE) {
		for(i=L->count;i>0;i--) {
			L->elements[i]=L->elements[i-1];
		}
		L->elements[0]=elem;
		L->count++;
	}
}

int deleteElem(List *L,int elem) {
	int i,found=0;
	
	for(i=0;i<L->count&&L->elements[i]!=elem;i++) {}

	if(i<L->count) {
		int j;
		for(j=i;j<L->count-1;j++) {
			L->elements[j]=L->elements[j+1];
		}
		L->count--;
		found=1;
	}
	
	return found;
}



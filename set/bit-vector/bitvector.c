#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define NAME 20

typedef struct {
	char name[NAME];
	char course[NAME];
	int id;
} elem;

typedef struct node {
	elem data;
	int occ; // if present or not
} *Node;

typedef struct {
	Node elems[MAX];
	int count;
} SET;

void init(SET *A);
void insert(SET *A,elem data);
void del(SET *A,int id);
void display(SET A);

int main(void) {
	SET A;
	init(&A);
	
	insert(&A,(elem){"liam","BSCS",0});
	insert(&A,(elem){"liam","BSCS",1});
	insert(&A,(elem){"liam","BSCS",2});
	insert(&A,(elem){"liam","BSCS",4});
	insert(&A,(elem){"liam","BSCS",8});
	
	del(&A,4);
	
	display(A);
	
	return 0;
}

void init(SET *A) {
	int x;
	for(x=0;x<MAX;x++) {
		Node newNode = (Node)malloc(sizeof(struct node));
		if(newNode!=NULL) {
			A->elems[x] = newNode;
			A->elems[x]->occ=0;
			A->elems[x]->data.id=-1;
			strcpy(A->elems[x]->data.course, "");
			strcpy(A->elems[x]->data.name, "");
		}
	}
	A->count=0;
}

void insert(SET *A,elem data) {
	A->elems[data.id]->occ=1;
	A->elems[data.id]->data=data;
}

void del(SET *A,int id) {
	if(A->elems[id]->occ==1) {
		Node temp = A->elems[id];
		A->elems[id]->occ=0;
		free(temp);
	}
}

void display(SET A) {
	int x;
	for(x=0;x<MAX;x++) {
		if(A.elems[x]->occ==1) {
			printf("[%d] name: %s --- course: %s --- id: %d\n",x,A.elems[x]->data.course,A.elems[x]->data.name);
		}
	}
}


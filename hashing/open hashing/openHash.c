#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node {
	struct node *next;
	char data;
} *Node;

typedef Node dict[MAX];

void init(dict A) {
	int x;
	for(x=0;x<MAX;x++) {
		A[x] = NULL;
	}
}

int hash(char elem) {
	return elem%MAX;
}

void insert(dict A,char elem) {
	int index = hash(elem);
	
	Node *curr;
	for(curr=&A[index];*curr!=NULL && (*curr)->data < elem;curr = &(*curr)->next) {}
	
	if(*curr==NULL || (*curr)->data != elem) {
		Node newNode = (Node)malloc(sizeof(struct node));
		
		if(newNode!=NULL) {
			newNode->data = elem;
			newNode->next = *curr;
			*curr = newNode;
		}
	}
}

void del(dict A,char elem) {
	int index = hash(elem);
	
	Node *curr;
	
	for(curr = &A[index];*curr!=NULL && (*curr)->data < elem;curr = &(*curr)->next) {}
	
	if(*curr!=NULL && (*curr)->data == elem) {
		Node temp = *curr;
		*curr = (*curr)->next;
		free(temp);
	}
}

void display(dict A) {
	int x;
	for(x=0;x<MAX;x++) {
		printf("[%d] ",x);
		Node curr;
		for(curr = A[x];curr!=NULL;curr=curr->next) {
			printf("-> %c ",curr->data);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	dict A;
	init(A);
	
	insert(A,'Z');
	insert(A,'A');
	insert(A,'B');
	insert(A,'C');
	insert(A,'F');
	insert(A,'X');
	insert(A,'B');
	
	display(A);
	
	
	del(A,'F');
	del(A,'B');
	del(A,'X');
	display(A);
	

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#include <stdbool.h>

typedef struct node {
	char elem;
	struct node *next;
} *NODE;

typedef NODE list[MAX];

void init(list A) {
	int x;
	
	for(x=0;x<MAX;x++) {
		NODE newNode = (NODE)malloc(sizeof(struct node));
		
		if(newNode!=NULL) {
			newNode->elem = 65+x;
			newNode->next = NULL;
			A[x] = newNode;
		}
	}
}

void insert(list A,int src,int dst) {
	if(src >= 0 && src<MAX && dst >=0 && dst < MAX) {
		NODE *curr;
		
		for(curr = &A[src];*curr != NULL && (*curr)->elem != A[dst]->elem;curr = &(*curr)->next) {}
		
		if(*curr == NULL) {
			NODE newNode = (NODE)malloc(sizeof(struct node));
			if(newNode!=NULL) {
				newNode->elem = A[dst]->elem;
				newNode->next = *curr;
				*curr = newNode;
			}
		}
	}
}

void display(list A) {
	int x;
	NODE curr;
	for(x=0;x<MAX;x++) {
		for(curr = A[x];curr!=NULL;curr = curr->next) {
			printf("%c -> ",curr->elem);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	list A;
	init(A);
	
	display(A);
	
	insert(A,0,2);
	insert(A,2,0);
	insert(A,2,0);
	
	display(A);
	
	return 0;
}

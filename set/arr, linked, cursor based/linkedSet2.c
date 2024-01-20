#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	struct node *next;
	char elem;
} *Node;

typedef struct {
	Node data;
	int count;
} SET;

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
	insert(&A,'F');
	insert(&A,'A');
	insert(&A,'D');
	insert(&A,'E');
	insert(&A,'C');
	
	display(A);
	
	
	
	SET B;
	init(&B);
	
	insert(&B,'A');
	insert(&B,'F');
	insert(&B,'A');
	insert(&B,'X');
	insert(&B,'B');
	insert(&B,'Z');
	
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

void init(SET *A) {
	A->data = NULL;
	A->count=0;
}


void insert(SET *A,char elem) {
	if(A->count<MAX) {
		Node *curr;
		for(curr=&A->data;*curr!=NULL&&(*curr)->elem<elem;curr=&(*curr)->next) {}
		
		if(*curr==NULL || (*curr)->elem!=elem) {
			Node newNode = (Node)malloc(sizeof(struct node));
			if(newNode!=NULL) {
				newNode->elem=elem;
				newNode->next=*curr;
				*curr=newNode;
				A->count++;
			}	
		}
	}
}

void display(SET A) {
	Node curr;
	for(curr=A.data;curr!=NULL;curr=curr->next) {
		printf("[%c] ",curr->elem);
	}
	printf("\n");
}

void del(SET *A,char elem) {
	if(A->count>0) {
		Node *curr;
		for(curr=&A->data;*curr!=NULL&&(*curr)->elem<elem;curr=&(*curr)->next) {}
		if(*curr!=NULL && (*curr)->elem==elem) {
			Node temp = *curr;
			*curr=(*curr)->next;
			free(temp);
		}
	}
}

SET unionset(SET A,SET B) {
	SET C;
	init(&C);
	
	Node *curr1,*curr2,*curr3;
	for(curr1=&A.data,curr2=&B.data,curr3=&C.data;*curr1!=NULL&&*curr2!=NULL;) {
		if(C.count<MAX) {
			Node newNode = (Node)malloc(sizeof(struct node));
			if(newNode!=NULL) {
				if((*curr1)->elem<(*curr2)->elem) {
					newNode->elem=(*curr1)->elem;
					curr1 = &(*curr1)->next;
				}
				else if((*curr1)->elem>(*curr2)->elem) {
					newNode->elem=(*curr2)->elem;
					curr2 = &(*curr2)->next;
				}
				else {
					newNode->elem=(*curr1)->elem;
					curr1 = &(*curr1)->next;
					curr2 = &(*curr2)->next;
				}
				newNode->next=*curr3;
				*curr3=newNode;
				curr3=&(*curr3)->next;
			}
			C.count++;
		}
	}
	
	if(*curr1==NULL) {
		curr1=curr2;
	}
	
	while(*curr1!=NULL) {
		Node newNode = (Node)malloc(sizeof(struct node));
		if(newNode!=NULL) {
			newNode->elem=(*curr1)->elem;
			newNode->next=*curr3;
			*curr3=newNode;
			
			curr3=&(*curr3)->next;
			curr1=&(*curr1)->next;
		}
	}
	
	
	return C;
}

SET intersectionset(SET A,SET B) {
	SET C;
	init(&C);
	
	Node *curr1,*curr2,*curr3;
	for(curr1=&A.data,curr2=&B.data,curr3=&C.data;*curr1!=NULL&&*curr2!=NULL;) {
		if((*curr1)->elem<(*curr2)->elem) {
			curr1=&(*curr1)->next;
		}
		else if((*curr2)->elem<(*curr1)->elem) {
			curr2=&(*curr2)->next;
		}
		else {
			Node newNode = (Node)malloc(sizeof(struct node));
			if(newNode!=NULL) {
				newNode->elem=(*curr1)->elem;
				newNode->next=*curr3;
				*curr3=newNode;
				curr3=&(*curr3)->next;
				C.count++;
			}
			curr1=&(*curr1)->next;
			curr2=&(*curr2)->next;
		}
	}
	
	return C;
}

SET differenceset(SET A,SET B) {
	SET C;
	init(&C);
	
	Node *curr1,*curr2,*curr3;
	for(curr1=&A.data,curr2=&B.data,curr3=&C.data;*curr1!=NULL&&*curr2!=NULL;) {
		if((*curr1)->elem<(*curr2)->elem) {
			Node newNode = (Node)malloc(sizeof(struct node));
			if(newNode!=NULL) {
				newNode->elem=(*curr1)->elem;
				newNode->next=*curr3;
				*curr3=newNode;
				curr3=&(*curr3)->next;
				curr1=&(*curr1)->next;
				C.count++;
			}
		}
		else if((*curr2)->elem<(*curr1)->elem) {
			curr2=&(*curr2)->next;
		}
		else {
			curr1=&(*curr1)->next;
			curr2=&(*curr2)->next;
		}
	}
	
	if(*curr1!=NULL) {
		Node newNode=(Node)malloc(sizeof(struct node));
		if(newNode!=NULL) {
			newNode->elem = (*curr1)->elem;
			newNode->next=*curr3;
			*curr3=newNode;
			curr3=&(*curr3)->next;
			curr1=&(*curr1)->next;
			C.count++;
		}
	}
	
	
	
	return C;
}


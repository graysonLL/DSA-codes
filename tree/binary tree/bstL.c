#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *LC;
	struct node *RC;
	int data;
} *BST;

void insert(BST *A,int elem) {
	BST *curr;
	for(curr = A;*curr!=NULL && (*curr)->data != elem;) {
		curr = elem < (*curr)->data ? &(*curr)->LC : &(*curr)->RC;
	}
	
	if(*curr == NULL) {
		BST newNode = (BST)calloc(1,sizeof(struct node));
		
		if(newNode!=NULL) {
			newNode->data = elem;
			*curr = newNode;
		}
	}
}

void del(BST *A,int elem) {
	BST *curr,toDel;
	
	for(curr = A;*curr!=NULL && (*curr)->data != elem;) {
		curr = elem < (*curr)->data ? &(*curr)->LC : &(*curr)->RC;
	}
	
	if(*curr!=NULL) {
		if((*curr)->RC != NULL && (*curr)->LC != NULL) {
			BST *temp;
			
			for(temp = &(*curr)->LC;(*temp)->RC != NULL;temp = &(*temp)->RC) {}
			
			char tempVal = (*temp)->data;
			(*temp)->data = (*curr)->data;
			(*curr)->data = tempVal;
			
			toDel = *temp;
			*temp = (*temp)->LC;
			free(toDel);
		}
		else if((*curr)->RC != NULL || (*curr)->LC != NULL) {
			toDel = *curr;
			
			*curr = (*curr)->LC == NULL ? (*curr)->RC : (*curr)->LC;

			free(toDel);
		}
		else if((*curr)->RC == NULL && (*curr)->LC == NULL) {
			toDel = *curr;
			*curr = NULL;
			free(toDel);
		}
	}
}

void inorder(BST A) {
	if(A!=NULL) {
		inorder(A->LC);
		printf("%d ",A->data);
		inorder(A->RC);
	}
}

int main(void) {
	BST A = NULL;
	insert(&A,10);
	insert(&A,6);
	insert(&A,4);
	insert(&A,8);
	insert(&A,7);
	
	inorder(A);
	
	del(&A,4);
	printf("\n");
	inorder(A);
	
	return 0;
}

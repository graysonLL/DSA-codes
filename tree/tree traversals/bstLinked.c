#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int elem;
	struct node *LC;
	struct node *RC;
} nodeType, *BST;

void insert(BST *tree,int elem) {
	BST *trav = tree;
	while(*trav!=NULL && (*trav)->elem!=elem) {
		trav = elem < (*trav)->elem ? &(*trav)->LC : &(*trav)->RC;
	}
	
	if(*trav==NULL) {
		*trav = (BST)calloc(1,sizeof(nodeType));
		if(*trav!=NULL) {
			(*trav)->elem = elem;
		}
	}
}

void del(BST *tree,int elem) {
	BST *trav = tree,temp;
	while(*trav!=NULL && (*trav)->elem != elem) {
		trav = elem < (*trav)->elem ? &(*trav)->LC : &(*trav)->RC;
	}
	if(*trav!=NULL) {
		if((*trav)->LC == NULL && (*trav)->RC == NULL) {
			temp = *trav;
			*trav = NULL;
			free(temp);
		}
		else if((*trav)->LC != NULL && (*trav)->RC != NULL) {
			BST *suc = &(*trav)->LC;
			while((*suc)->RC!=NULL) {
				suc = &(*suc)->RC;
			}
			(*trav)->elem = (*suc)->elem;
			temp = *suc;
			*suc = NULL;
			free(temp);
		}
		else if((*trav)->LC != NULL || (*trav)->RC != NULL) {
			temp = *trav;
			if((*trav)->LC==NULL) {
				*trav = (*trav)->RC;
 			}
 			else {
 				*trav = (*trav)->LC;
			 }
 			free(temp);
		}
	}
}

void inorder(BST tree) {
	if(tree!=NULL) {
		inorder(tree->LC);
		printf("%d ",tree->elem);
		inorder(tree->RC);
	}
}

void preorder(BST tree) {
	if(tree!=NULL) {
		printf("%d ",tree->elem);
		preorder(tree->LC);
		preorder(tree->RC);
	}
}

void postorder(BST tree) {
	if(tree!=NULL) {
		postorder(tree->LC);
		postorder(tree->RC);
		printf("%d ",tree->elem);
	}
}

int main(void) {
	BST T = NULL;
	
	insert(&T,10);
	insert(&T,6);
	insert(&T,4);
	insert(&T,8);
	insert(&T,7);

	
	
	inorder(T);
	printf("\n");
	del(&T,6);
	inorder(T);
	
	return 0;
}

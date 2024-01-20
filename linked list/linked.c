#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* link;
} *LIST;

void insertSorted(LIST* C, int elem);
void display(LIST head);
void deleteElem(LIST *C, int elem);

int main(void) {
    LIST head = NULL; // Initialize head to NULL

    insertSorted(&head, 2);
    display(head);

    insertSorted(&head, 1);
    display(head);

    insertSorted(&head, 4);
    display(head);

    insertSorted(&head, 3);
    
    
    display(head);
    
    
    deleteElem(&head,4);
	display(head);
	
    return 0;
}

void insertSorted(LIST* C, int elem) {
    LIST* trav;
    for (trav = C; *trav != NULL && (*trav)->elem < elem; trav = &(*trav)->link) {}

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->elem = elem;
        newNode->link = *trav; 

        *trav = newNode; 
    }
}

void deleteElem(LIST *C, int elem) {
	LIST *trav,temp;
	for(trav=C;*trav!=NULL&&(*trav)->elem!=elem;trav=&(*trav)->link) {}
	
	if(*trav!=NULL) {
		temp=*trav;
		*trav=temp->link;
		free(temp);
	}
}

void display(LIST head) {
    LIST curr = head;
    
    while (curr != NULL) {
        printf("%d ", curr->elem);
        curr = curr->link;
    }
    
    printf("\n");
}

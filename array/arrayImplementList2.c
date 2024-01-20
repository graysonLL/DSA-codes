#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

typedef enum {TRUE, FALSE} Boolean;

typedef struct {
	char elements[SIZE];
	int count;
} List;

void initializeListA(List **L);
List *initializeListB();

int main(void) {
	List *LA;
	initializeListA(&LA);
	LA->elements[0]='A';
	printf("%d %c\n",LA->count,LA->elements[0]);
	
	
	List *LB = initializeListB();
	LB->elements[0]='B';
	printf("%d %c\n",LB->count,LB->elements[0]);
	
	
	return 0;
}

void initializeListA(List **L) {
	*L=(List*)malloc(sizeof(List));
	(*L)->count=0;
}

List *initializeListB() {
	List *L = (List*)malloc(sizeof(List));
	L->count=0;
	return L;
}


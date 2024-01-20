#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
	char *elemPtr;
	int count;
} List;

void initializeListA(List *L);
List initializeListB();

int main(void) {
	List A;
	initializeListA(&A);
	A.elemPtr[0] = 'A';
	A.elemPtr[1] = 'B';
	A.elemPtr[2] = 'C';
	A.count=3;
	int i;
	for(i=0;i<A.count;i++) {
		printf("%c ",A.elemPtr[i]);
	}
	printf("%d\n",A.count);
	
	List B = initializeListB();
	B.elemPtr[0] = 'X';
	B.elemPtr[1] = 'Y';
	B.elemPtr[2] = 'Z';
	B.count=3;
	for(i=0;i<B.count;i++) {
		printf("%c ",B.elemPtr[i]);
	}
	printf("%d\n",B.count);
	
	return 0;
}

void initializeListA(List *L) {
	L->count=0;
	L->elemPtr=(char*)malloc(sizeof(char)*SIZE);
}

List initializeListB() {
	List L;
	L.count=0;
	L.elemPtr=(char*)malloc(sizeof(char)*SIZE);
	
	return L;
}

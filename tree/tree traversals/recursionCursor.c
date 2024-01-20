#include <stdio.h>
#define MAX 10

typedef int point;

typedef struct {
	point LC;
	point RC;
	char data;
} Nodes;

typedef struct {
	Nodes values[MAX];
	point Avail;
	point start;
} VHeap;



void init(VHeap *VH) {
	int x,last = MAX-1;
	
	for(x=0;x<last;x++) {
		VH->values[x].RC = x+1;
		VH->values[x].LC = x+1;
	}
	VH->values[x].RC = -1;
	VH->values[x].LC = -1;
	VH->Avail = 0;
	VH->start = -1;
}

void insert(VHeap *VH,char elem) {
	point *curr;
		
	for(curr=&VH->start;*curr!=-1 && VH->values[*curr].data != elem;) {
		curr = elem < VH->values[*curr].data ? &VH->values[*curr].LC : &VH->values[*curr].RC;
	}
		
	if(*curr==-1) {
		point space = VH->Avail;
		if(space!=-1) {
			VH->Avail = VH->values[space].LC;
			
			VH->values[space].data = elem;
			VH->values[space].LC = -1;
			VH->values[space].RC = -1;
			*curr = space;
		}
	}
}


int del(VHeap *VH,char elem) {
	point *curr,retVal = '!';
	
	for(curr=&VH->start;*curr!=-1 && VH->values[*curr].data != elem;) {
		curr = elem < VH->values[*curr].data ? &VH->values[*curr].LC : &VH->values[*curr].RC;
	}
	
	if(*curr!=-1) {
		retVal = VH->values[*curr].data;
		if(VH->values[*curr].LC == -1 && VH->values[*curr].RC == -1) {
			VH->values[*curr].LC = *curr;
			VH->Avail = *curr;		
			printf("%d ",VH->Avail);
			*curr = -1;
		}
		else if(VH->values[*curr].LC != -1 && VH->values[*curr].RC != -1) {
			point *trav = &VH->values[*curr].LC;
			
			while(VH->values[*trav].RC!=-1) {
				trav = &VH->values[*trav].RC;
			}
			VH->values[*curr].data = VH->values[*trav].data;
			VH->values[*trav].LC = VH->Avail;
			VH->Avail = *trav;
			*trav = -1;
			printf("%d ",VH->Avail);
		}
		else if(VH->values[*curr].LC == -1 || VH->values[*curr].RC == -1) {
			point newPoint = VH->values[*curr].LC != -1 ? VH->values[*curr].LC : VH->values[*curr].RC;
			VH->Avail = *curr;
			printf("%d ",VH->Avail);
			*curr = VH->values[*curr].LC == -1 ? VH->values[*curr].RC : VH->values[*curr].LC;
			
		}
	}
	
	return retVal;
}

void inorder(VHeap VH,point index) {
	if(index!=-1) {
		inorder(VH,VH.values[index].LC);
		printf("%c ",VH.values[index].data);
		inorder(VH,VH.values[index].RC);
	}
}

void preorder(VHeap VH,point index) {
	if(index!=-1) {
		printf("%c ",VH.values[index].data);
		preorder(VH,VH.values[index].LC);
		preorder(VH,VH.values[index].RC);
	}
}

void postorder(VHeap VH,point index) {
	if(index!=-1) {
		postorder(VH,VH.values[index].LC);
		postorder(VH,VH.values[index].RC);
		printf("%c ",VH.values[index].data);
	}
}


int main(void) {
	VHeap V;
	init(&V);
	
	insert(&V,'D');
	insert(&V,'B');
	insert(&V,'A');
	insert(&V,'C');
	insert(&V,'F');
	insert(&V,'H');
	insert(&V,'G');
	insert(&V,'G');
	insert(&V,'I');
	
	inorder(V,V.start);
	printf("\n");
	del(&V,'A');
	del(&V,'B');
	inorder(V,V.start);
	
	
	return 0;
}

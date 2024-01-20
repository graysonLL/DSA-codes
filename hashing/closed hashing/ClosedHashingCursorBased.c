#include<stdio.h>
#include<stdlib.h>
#define MAX 12
#define EMPTY '!'
#define DELETED '#'

//VERSION 3 IMEPLEMENTATION (CURSOR BASED)

typedef struct{
	char elem;
	int next;	
}LIST;

typedef struct{
	LIST Clist[MAX]; 
	int avail; 
}Dictionary;

void displayDict(Dictionary D);
int Hash(char val);
void initDict(Dictionary *D);
void insertDict(Dictionary *D, char elem); 
void deleteDict(Dictionary *D, char elem);

int main(){
	
	Dictionary table;
	
	initDict(&table);
	insertDict(&table, 'A'); 
	insertDict(&table, 'B');
	insertDict(&table, 'C');
	insertDict(&table, 'D');
	insertDict(&table, 'E');
	
	displayDict(table); 
	
}

int Hash(char val){
	return val % MAX; 	
}

void displayDict(Dictionary D){
	
	int i,x,half = MAX/2; 
	
	for(i=0;i<half;i++){
		printf("[%d] => ", i); 
		x = i;
		while(x != -1){
			printf("%c ", D.Clist[x].elem);
			x = D.Clist[x].next;  
		}
		
		printf("\n"); 
		
		
	}
	
	
}

void initDict(Dictionary *D){
	
	int half = MAX/2, i;
	
	for(i=0;i<MAX;i++){
		if(i < half){
			D->Clist[i].elem = EMPTY;
			D->Clist[i].next = -1;
		}else{
			D->Clist[i].next = i+1;
		}
		
	}
	D->Clist[MAX - 1].next = -1; 
	D->avail = half; 
	 
}

//basically insertFirst
void insertDict(Dictionary *D, char elem){
	
	int temp, hashV = Hash(elem); 
	
	if(D->Clist[hashV].elem == EMPTY || D->Clist[hashV].elem == DELETED){
		D->Clist[hashV].elem = elem; 
	}else{
		temp = D->avail;
		if(temp != -1){
			D->avail = D->Clist[temp].next;
			D->Clist[temp].elem = elem;
			D->Clist[temp].next = D->Clist[hashV].next;
			D->Clist[hashV].next = temp; 
		}
		
		
	}	
}

void deleteDict(Dictionary *D, char elem){
	
	int *trav, temp, hashV = Hash(elem);
	
	if(D->Clist[hashV].elem == elem){
		D->Clist[hashV].elem = DELETED;
	}else{
		
		for(trav=&D->Clist[hashV].next;*trav != -1 && D->Clist[*trav].elem != elem;trav = trav=&D->Clist[*trav].next){
		}
		
		if(*trav != -1){
			temp = *trav;
			*trav = D->Clist[temp].next;
			D->Clist[temp].next = D->avail;
			D->avail = temp; 
		}
		
		
	}
	
	
	
}
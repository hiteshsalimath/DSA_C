#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3//size of hash table 
#define h(x) (x % m) //hash fn definition


typedef struct Node{
    int v;
    struct Node *next;
}Node;


Node *fill_table(Node *table, int table_range, int number);
Node *insert(Node *table, int hash_index, int v);
Node *del(Node *table,int table_range,int v);
void print_table(Node *table, int table_range);
void search_table(Node *table, int table_range, int v);

int main(){
    Node *table; 
    int n, i, j, choice, search;
    int hash_num, v;	 	

    
    table = (Node*) malloc(N*sizeof(Node));
//initializing all linked lists for keys as null    
    for(i = 0; i < N; i++){
    	table[i].next = NULL;
    }
	
    printf("--h(x) = xmod%d--\n",N);
    printf("\n\n");	 

    while(1){
    	printf("---------------------1.Insert some random numbers---------------------\n");
    	printf("---------------------2.Delete a number---------------------\n");
		printf("---------------------3.Search for a number---------------------\n");
		printf("---------------------4.Show the Hash Table---------------------\n");
		printf("---------------------0.Exit Program---------------------\n");		
		printf("\n--------\n");
		printf("Please enter your Choice: ");
		scanf("%d",&choice);
	
	switch(choice){
		case 0: return 0;
		case 1:
			
			printf("Lot to insert: ");
			scanf("%d", &n);
			table = fill_table(table, N, n);
			printf("Filled HashTable with %d random values\n", n);
			printf("\n--------\n");
			break;
		case 2:
			
			printf("Enter a number: ");
			scanf("%d",&search);
			table = del(table, N, search);
			printf("\n--------\n");	
			break;
		case 3:
			
			printf("Enter a number: ");
			scanf("%d",&search);			
			search_table(table, N, search);
			printf("\n--------\n");	
			break;
		case 4:
			
			printf("-HASHTABLE-\n\n");
			print_table(table, N);
			printf("\n--------\n");	
			break;	
	    }
	}	
	return 0;
}


Node *fill_table(Node *table, int table_range, int number){
    int i;
    int num;
    for(i=0; i<number; i++){
	num = rand()%10000; 
	table = insert(table, num % table_range, num);
    }
    return table;
}

void print_table(Node *table, int table_range){
    int i;
    Node* cur;
    for(i = 0; i < table_range; i++){ 
	if(table[i].next == NULL){ 
                printf("Table[%d] is empty!\n", i);
		continue;
	}
	cur = table[i].next;
	printf("Table[%d]", i);
	while(cur!=NULL){ 
		printf("->%d",cur->v);
		cur=cur->next; 
	}
	printf("\n");	
    }
}

Node *insert(Node *table, int hash_index, int v){
    Node *nn, *cur;

    nn = (Node*)malloc(sizeof(Node));
    nn->v=v;
    nn->next=NULL;
	
    if(table[hash_index].next == NULL){
	table[hash_index].next = nn;
	return table;
    }
	
    cur = table[hash_index].next;
    while(cur->next != NULL){
	cur=cur->next; //cur=cur+1;
    }
    cur->next = nn;
    return table;
}

void search_table(Node *table, int table_range, int v){
    int index = v % table_range;
    Node *cur;
	
    if(table[index].next == NULL){ // if empty
		printf("value %d not found cause Table[%d] is emtpy!\n", v,index);
                return;
    }

    cur = table[index].next;
    while(cur!=NULL){
	if(cur->v == v){
		printf("value %d was found!\n", v);
		return;
	}
	cur = cur->next;
    }
    printf("value %d not found in Hashtable!\n", v);
}

Node *del(Node *table, int table_range, int v){
    int index = v % table_range;
    Node *prev;
	
    if(table[index].next == NULL){ // if empty
	printf("value %d not found cause Table[%d] is emtpy!\n", v,index);
	return table;
    }
	
    if(table[index].next->v == v){ // if first item
	printf("value %d was found at table[%d] and Deleted!\n", v,index);
	table[index].next = table[index].next->next;
	return table;
    }

    prev = table[index].next;
    while(prev->next!=NULL){
	if(prev->next->v == v){
		prev->next = prev->next->next;
		printf("value %d was found at table[%d] and Deleted!\n", v,index);
		return table;
	}
	prev = prev->next;
    }
    printf("value %d was not found in Hashtable!\n", v);
    return table;
}

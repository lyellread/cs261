#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/
	int i;
	struct hashLink *temp;
	struct hashLink *temp2;
	for(i = 0; i < ht->tableSize; i++){
		temp = ht->table[i];
		while(temp != NULL){
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
	}
	free(ht->table);
	ht->count=0;
	ht->table=0;
	ht->tableSize=0;	
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	int bucket = stringHash2(k)%ht->tableSize;
	struct hashLink * newLink; 
	struct hashLink *temp;
	if(ht->table[bucket] == 0){
		newLink = (struct hashLink *) malloc(sizeof(struct hashLink));
		ht->table[bucket]=newLink;
		ht->table[bucket]->key=k;
		ht->table[bucket]->value=v;
		ht->table[bucket]->next=0;
		ht->count++;
	}else{
		temp=ht->table[bucket];
		while(temp!=0){
			if(strcmp(temp->key,k)==0){
				temp->value=v;
				return;
			}else{
				temp=temp->next;
			} 
		}
		newLink = (struct hashLink *) malloc(sizeof(struct hashLink));
		newLink->key=k;
		newLink->value=v;
		newLink->next=ht->table[bucket];
		ht->table[bucket]=newLink;
		ht->count++;
	}
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/
	int bucket = stringHash2(k)%ht->tableSize;
	struct hashLink *cur;
	if(ht->table[bucket] == 0){
		return 0;
	}else{
		cur=ht->table[bucket];
		while(cur!=0){
			if(strcmp(cur->key,k)==0){
				return &(cur->value);  
			}else{
				cur=cur->next;
			} 
		}
		return 0;
	}
}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	if (atMap(ht,k)==0){
		return 0;
	}else{
		return 1;
	}
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/
	int bucket = stringHash2(k)%ht->tableSize;
	struct hashLink *cur; 
	struct hashLink *prev;  
	if(ht->table[bucket] == 0){
		return;
	}else{
		cur=ht->table[bucket];
		prev=ht->table[bucket];
		while(cur!=0){
			if(strcmp(cur->key,k)==0){
				if(cur==ht->table[bucket]){
					ht->table[bucket]=cur->next;
					
				}else{
				prev->next=cur->next;
				}
				free(cur);
				ht->count--;
				return;
			}else{
				prev=cur;
				cur=cur->next;
			} 
		}
	}
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	return ht->count;
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
	int runner = 0;
	int i;
	for(i=0; i<ht->tableSize; i++){
		if(ht->table[i]==0){
			runner++;
		}
	}
	return runner;
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
	
	return (float)sizeMap(ht)/(float)capacityMap(ht);
}

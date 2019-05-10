#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i]; /*tea == eat*/
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

	int idx;
	for (idx = 0; idx < ht->tableSize; idx++){
		if (ht->table[idx] != NULL){
			/*need to free bucket*/
			struct hashLink * next_in_bucket = ht->table[idx];
			struct hashLink * current;
			while (next_in_bucket != NULL){
				free(next_in_bucket->key);
				
				current = next_in_bucket;
				next_in_bucket = next_in_bucket->next;
				free(current);
				
			}
		}
	}
	free(ht->table);
	
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/

	/* The function insertMap() overwrites any previous value associated with the input key*/
	
	/*calculate the location:*/
	
	int idx_in_map = stringHash2(k) % ht->tableSize;
	assert(idx_in_map >= 0);
	
	if (ht->table[idx_in_map] == NULL){
		ht->table[idx_in_map] = (struct hashLink *) malloc(sizeof(hashLink*)); /*allocate a link*/
		ht->table[idx_in_map]->value = v;
		ht->table[idx_in_map]->key = k;
		ht->table[idx_in_map]->next = NULL;
		ht->count++;
		return;
	}
	else{
		/* there is stuff there*/
		struct hashLink* nextlink = ht->table[idx_in_map];
		

		while (nextlink != NULL){
			if (strcmp(nextlink->key, k) == 0){ /* cannot be ptr comparison. Need more substantial comp*/

				free(k);/*key wont be used, so free*/
				nextlink->value++;
				/* overwrote one. Returingn*/
				return;
			}
			nextlink = nextlink->next;			
		}
		
		
		
		/*none with same key found*/
		
		nextlink = ht->table[idx_in_map];
		ht->table[idx_in_map] = (struct hashLink *) malloc(sizeof(hashLink*));
		ht->table[idx_in_map]->next = nextlink;
		ht->table[idx_in_map]->value = v;
		ht->table[idx_in_map]->key = k;
		ht->count++;
		return;
	}
	
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/

	int idx_in_map = stringHash2(k) % ht->tableSize;
	
	if (containsKey(ht, k))
		return &ht->table[idx_in_map]->value;
	else{
		printf("ERROR. KEY NOT IN MAP");
		return NULL;
	}
}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/

	int idx_in_map = stringHash2(k) % ht->tableSize;
	
	if (ht->table[idx_in_map] == NULL){
		return 0;
	}
	else{
		return 1;
	}
	
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/

	int idx_in_map = stringHash2(k) % ht->tableSize;

	if (containsKey(ht, k)){
		
		free(ht->table[idx_in_map]);
		ht->table[idx_in_map] = NULL;
		
	}
	
	else{
		assert(ht->table[idx_in_map] == NULL);
	}
	
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	
	/*
	int table_idx;
	int elem_count = 0;
	for (table_idx = 0; table_idx < ht->tableSize; table_idx++){
		
		
		if (ht->table[table_idx] != NULL){
			elem_count++;
			struct hashLink * next_element = ht->table[table_idx]->next;
			while (next_element != NULL){
				elem_count++;
				next_element = ht->table[table_idx]->next;
			}
		}
	}
	*/	
	
	return ht->count;
}
/*
void printMap(struct hashMap *ht){
	
	int table_idx;
	for (table_idx = 0; table_idx < ht->tableSize; table_idx++){
		
		printf("[%d] : ", table_idx);
		
		if (ht->table[table_idx] != NULL){
			struct hashLink * next_element = ht->table[table_idx]->next;
			
			printf("[v:%d] ->", ht->table[table_idx]->value);
			
			
			while (next_element != NULL){
				
				printf("[v:%d] ->", next_element->value);

				next_element =next_element->next;
				
			}
		}
		printf("[NULL]\n");
	}
}
*/

int capacityMap(struct hashMap *ht)
{  /*write this*/

	return ht->tableSize;
	
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/

	int elem_count = 0;
	int table_idx;
	for (table_idx = 0; table_idx < ht->tableSize; table_idx++){
		
		if (ht->table[table_idx] == NULL){
			elem_count++;
			
		}
	}
	
	return elem_count;
}


float tableLoad(struct hashMap *ht)
{  /*write this*/
	
	float hashlinks = (float) sizeMap(ht);
	float buckets = (float) capacityMap(ht);

	return ((float) hashlinks / buckets);

}

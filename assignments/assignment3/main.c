#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char * getWord(FILE *file){

	char * return_buf = malloc (32 * sizeof(char));
	
	char c;
	int index = 0;
	
	if (file == NULL){
		free(return_buf);
		return NULL;
	}

	fscanf(file, "%s", return_buf);
	while ((int) return_buf[0] == 0){
		
		fscanf(file, "%s", return_buf);
		printf("loop-%s-", return_buf);

	}
	
	printf("FSCANF'd into %s\n", return_buf);
	
	return return_buf;
	
}

/****************************************/

void print_bucket (struct hashLink * hl){
	
	
	/*printf("Frequency: %d - Word: ", hl->value);*/
	
	/*out = sprintf(hl->key);
	fflush(stdout);
	printf ("\r%s:		%d\n",hl->key, hl->value);
	fflush(stdout);
	*/
	
	char buffer[32];
	int iterator;
	for (iterator = 0; iterator < 30; iterator++){
		buffer[iterator] = hl->key[iterator];
	}
	printf("%d: %s\n", hl->value, buffer);
}

/*
	key: summer
	value: 4
*/

int main (int argc, const char * argv[]) {
    /*Write this function*/
	
	struct hashMap * ht_pointer = (struct hashMap*) malloc (sizeof(struct hashMap));
	FILE * fp;
	char * return_val;
	int it;
	int counter = 0;
	int ht_size = 10;
	struct hashLink * current_hashLink;
	
	printf("Program Started \n\n");
	
	fp = fopen(argv[1], "r");
	
	initMap(ht_pointer, ht_size);
	
	return_val = getWord(fp);
	
	while (!feof(fp)){
		
		insertMap(ht_pointer, return_val, 1);
		return_val = getWord(fp);
		
	}
	
	
	for (it = 0; it < ht_size; it++){
		
		current_hashLink = ht_pointer->table[it];
		
		if (current_hashLink!= NULL){
			
			print_bucket(current_hashLink);
			counter++;
			
			while (current_hashLink->next != NULL){
				
				current_hashLink = current_hashLink->next;
				print_bucket(current_hashLink);
				counter++;
				
			}
		}
	}
			

	
	printf("\nFound %d words. Quitting.\n", counter);
			
	freeMap(ht_pointer);
	free(ht_pointer);
	
	
	/*

	
	key1 = malloc(7 * sizeof(char));
	key1[0] = 'y';	key1[1] = 'e';	key1[2] = 'e';	key1[3] = 't';	key1[4] = 'u';	key1[5] = 's';
	
	
	key2 = malloc(7 * sizeof(char));
	key2[0] = 't';	key2[1] = 'e';	key2[2] = 'z';	key2[3] = 't';	key2[4] = '4';	key2[5] = 's';
	
	assert(ht_pointer != NULL);
	
	initMap(ht_pointer, 15);
	
	
	printMap(ht_pointer);
	
	insertMap(ht_pointer, key1, val1);
	insertMap(ht_pointer, key2, val2);
	
	printMap(ht_pointer);
	*/
	return 1;
}


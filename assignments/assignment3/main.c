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

	char * return_buf = malloc (200 * sizeof(char));
	int index;
	
	if (file == NULL){
		free(return_buf);
		return NULL;
	}

	fscanf(file, "%s", return_buf);
	while (return_buf[0] == '\0' && !feof(file)){
		
		fscanf(file, "%s", return_buf);
	}
	
	
	for (index = 0; index < 200; index++){
		
		if (!((int) return_buf[index] < 123 && (int) return_buf[index] > 96) && 
			!((int) return_buf[index]>64 && (int) return_buf[index] < 91) && 
			!((int) return_buf[index] == 39) &&
			!((int) return_buf[index] == '\0')){
			
			return_buf[index] = '\0';
			
		}
	}
	
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
	printf("%s: %d\n", buffer, hl->value);
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
	int ht_size = 20;
	struct hashLink * current_hashLink;
	
	if (argc != 2){
		printf("ERROR: ARGS NEEDED. QUITTING.");
		free(ht_pointer);
		exit(EXIT_FAILURE);
	}
	
	printf("Program Started \n\n");
	
	fp = fopen(argv[1], "r");
	
	initMap(ht_pointer, ht_size);
		
	do{
		return_val = getWord(fp);
		insertMap(ht_pointer, return_val, 1);
		
		
	}while (!feof(fp));
			
	fclose(fp);
	
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
	
	return 1;
}


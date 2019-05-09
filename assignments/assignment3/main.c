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
	
	while ((c = fgetc(file))){
		
		if ( c == '\n'){
			
			/*printf("\n<R>");*/
			return return_buf;
			
		}
		else if (c == EOF){
			return_buf[31] = '%';
			return return_buf;
		}
		else if (c == '.' || c == ';'){
			
			/*printf("<ignored>");*/
			
		}
		else if (c == ' '){
			
			/*printf("<R>");*/
			return return_buf;
			
		}
		else{
			
			if ((int) c < 90 && (int) c != 13 && (int)c != 39){
				c = (char)((int)c + 32);
			}
			return_buf[index] = c;
			index++;
			
			/*printf("%c", c);*/
			
		}
	}
	return return_buf;
	
}

/****************************************/

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
	int printf_it;
	int counter = 0;
	int ht_size = 2000;
	struct hashLink * temp_hl;
	
	fp = fopen(argv[1], "r");
	
	initMap(ht_pointer, ht_size);
	
	return_val = getWord(fp);
	
	while (fp != NULL){
		
		if (return_val[31] == '%'){
			fclose(fp);
			fp = NULL;
			return_val[31] = (char)0;
		}

		if (return_val[0] > 96){
			
			if (containsKey (ht_pointer, return_val)){
				/*summer already in there, with val n*/
				int current_value = *atMap(ht_pointer, return_val);
				current_value++;
				insertMap(ht_pointer, return_val, current_value);
			}
			
			else{
				insertMap(ht_pointer, return_val, 1);
			} 
		}
		else{ /*blank*/
			free(return_val);
		}
		
		return_val = getWord(fp);

	}
	
	printMap(ht_pointer);
	printf(" == Succ\n");
	
	
	for (it = 0; it < ht_size; it++){
		
		if (ht_pointer->table[it] != NULL){
			
			
			
			counter++;
			/*
			printf("Word\n");
			printf("[idx: %d]:\n", it);
			*/
			
			for (printf_it = 0; printf_it < 31; printf_it++){
				
				printf("%c", ht_pointer->table[it]->key[printf_it]);
			
			}
			
			temp_hl = ht_pointer->table[it]->next;
			
			while (temp_hl != NULL){
				
				printf("LL/Bucket -> \n");
				counter++;
				for (printf_it = 0; printf_it < 31; printf_it++){
				
					printf("%c", temp_hl->key[printf_it]);
			
				}
				
				temp_hl = temp_hl->next;
			}
			
			
			
			printf("\n");
			/*printf("\n*->count: %d\n\n", ht_pointer->table[it]->value);*/
			
		}
	}
	
	printf(" == Final Succ / %d", counter);
			
	
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


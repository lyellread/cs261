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
char* getWord(FILE *file); /* prototype */

/****************************************/

int main (int argc, const char * argv[]) {
    const char* filename;
    struct hashMap hashTable;
    struct hashLink *temp;
    char *tempK;
    int tableSize = 1000;
    clock_t timer;
    FILE *fileptr;
    int *occ;
    int i;
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.
     
     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input.txt"; /*specify your input text file here*/
    
    printf("opening file: %s\n", filename);
    
    timer = clock();
	
    initMap(&hashTable, tableSize);
   
	
    /*
     ... concordance code goes here ...
     */
	fileptr = fopen(filename,"r");
	
	while (!feof(fileptr)) {	

		tempK = getWord(fileptr);

		if(!tempK){
			break;
		}
		occ = atMap(&hashTable,tempK);
		
		if(occ!=0){
			(*occ)++;
		}else{
			insertMap(&hashTable,tempK,1);
		}
	}

	/*removeKey(&hashTable, "It");
	removeKey(&hashTable, "was");
	removeKey(&hashTable, "the");
	removeKey(&hashTable, "best");
	removeKey(&hashTable, "of");
	removeKey(&hashTable, "times");
	removeKey(&hashTable, "worst");*/


	for(i=0;i < hashTable.tableSize; i++){
		temp = hashTable.table[i];
			
		while(temp!=0){
			printf("%s:%d\n", temp->key,temp->value);
			temp=temp->next;
			
		}
	}
	fclose(fileptr);
	timer = clock() - timer;
	printf("concordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	printf("Table emptyBuckets = %d\n",emptyBuckets(&hashTable));
	printf("Table size = %d\n",sizeMap(&hashTable));
	printf("Table capacity = %d\n",capacityMap(&hashTable));
	printf("Table load = %f\n",tableLoad(&hashTable));
    return 0;
}



char* getWord(FILE *file)
{
	
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}

/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* Converts the input bag into a set using dynamic arrays 
	param: 	da -- pointer to a bag 	
	return value: void
        result: after exiting the function da points to a set 		
*/
void bag2set(struct DynArr *da)
{
	/*generate a new da to temp store result*/
	DynArr * set_da = newDynArr(da->capacity);
	
	while (sizeDynArr(da) != 0){
		
		/*pop top item from da into set_da*/
		pushDynArr(set_da, topDynArr(da));
		popDynArr(da);
		
		/*while there is still an instance of the value we just copied, remove it*/
		while (da->size > 0 && containsDynArr (da, topDynArr(set_da)) != -1){
			removeDynArr(da, topDynArr(set_da));			
		}
	}
	
	/*swap the data pointers*/
	TYPE * temp = da->data;
	da->data = set_da->data;
	set_da->data = temp;
	
	/*swap sizes*/
	int temp_size = da->size;
	da->size = set_da->size;
	set_da->size = temp_size;
	
	freeDynArr(set_da);
	
}


/* An example how to test your bag2set() */
int main(int argc, char* argv[]){

	int i;
        struct DynArr * da = newDynArr(100);  /* bag on the HEAP*/
        
        /*initDynArr(&da, 100);*/
        da->size = 10;
		
		/*
        da->data[0] = 1.3;
	for (i=1;i<da->size;i++){
	    da->data[i] = 1.2;
	 }
		*/
		
		da->data[0] = 180;
		da->data[1] = 3;
		da->data[2] = 3;
		da->data[3] = 12029340234;
		da->data[4] = 13;
		da->data[5] = 4;
		da->data[6] = 3;
		da->data[7] = -12;
		da->data[8] = 1;
		da->data[9] = 180;
		
        printf("Bag:\n\n");
	for (i=0;i<da->size;i++){
          printf("%g ", da->data[i]);
        }
        
        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(da);
	for (i=0;i<da->size;i++){
          printf("%g ", da->data[i]);
        }
    printf("\n");
	
	freeDynArr(da);
	
	return 0;	
}


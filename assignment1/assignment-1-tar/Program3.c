/* CS261- HW1 - Program3.c*/
/* Name:Lyell Read
 * Date:4/3/2019
 * Solution description:
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(int* number, int n){
    /*Sort the array of integeres of length n*/ 
	
	int j, k;
	for (j = 0; j < n; j++){
		for (k = 0; k < (n-1); k++){
			
			if (number[k] > number [k+1]){
				int temp = number[k];
				number[k] = number[k+1];
				number[k+1] = temp;
			}
		}
	}
}

int main(){
	
	srand(time(NULL));
	
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
	
    /*Allocate memory for an array of n integers using malloc.*/
    int * int_array = NULL;
	int_array = malloc (n * sizeof(int));
	
    /*Fill this array with random numbers, using rand().*/
    int i;
	for (i = 0; i < n; i++){
		
		int_array[i] = rand()%101;
		
	}
	
    /*Print the contents of the array.*/
	for (i = 0; i < n; i++){
		
		printf("%d, ", int_array[i]);
		
	}
	printf("\n");
	
    /*Pass this array along with n to the sort() function of part a.*/
    sort(int_array, n);
	
    /*Print the contents of the array.*/    
	for (i = 0; i < n; i++){
		
		printf("%d, ", int_array[i]);
		
	}
	printf("\n");

	/*free the memory*/
	free(int_array);
	
    return 0;
}

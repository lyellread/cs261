/* CS261- HW2 - Program3.c*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the array of integers of length n*/    
	
	int i,j,tmp;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(number[j]<number[i])
			{
				tmp=number[i];
				number[i]=number[j];
				number[j]=tmp;
			}
		}

	}
}

int main(){
	int i;
    /*Declare an integer n and assign it a value of 20.*/
	int n=20;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int *arr=(int *)malloc(sizeof(int)*n);
    
    /*Fill this array with random numbers, using rand().*/
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		arr[i]=rand();
	}

    
    /*Print the contents of the array.*/
	printf("Before Sorting:\n");
	for(i=0; i<n; i++)
	{
		printf("%d\n",arr[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(arr,n);
    
    /*Print the contents of the array.*/    
	printf("\nAfter Sorting:\n");
 	for(i=0; i<n; i++)
	{
		printf("%d\n",arr[i]);
	}
   
    return 0;
}

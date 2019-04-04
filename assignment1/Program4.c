/* CS261- HW1 - Program4.c*/
/* Name:Lyell Read
 * Date:4/3/2019
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/   

	int j, k;
	struct student temp;
	for (j = 0; j < n; j++){
		for (k = 0; k < (n-1); k++){
		
			
			
			if (students[k].initials[0] > students[k+1].initials[0]){
				temp = students[k];
				/*printf("%c, %c, %d\n", temp.initials[0], temp.initials[1], temp.score);*/
				students[k] = students[k+1];
				students[k+1] = temp;
			}
			
			else if (students[k].initials[0] == students[k+1].initials[0] && students[k].initials[1] > students[k+1].initials[1]){
				temp = students[k];
				/*printf("%c, %c, %d\n", temp.initials[0], temp.initials[1], temp.score);*/
				students[k] = students[k+1];
				students[k+1] = temp;
			}
			
			/*printf("k:%d, %c, %c, %d\n", k, students[k].initials[0], students[k].initials[1], students[k].score);*/
		}
	}	
}

int main(){
	/*Seed Random*/
	srand(time(NULL));
	
    /*Declare an integer n and assign it a value.*/
    int n = 20;
	
    /*Allocate memory for n students using malloc.*/
    struct student * student_array = NULL;
	student_array = malloc (n * sizeof(struct student));
	
    /*Generate random IDs and scores for the n students, using rand().*/
    int i;
	for (i = 0; i < n; ++i){
		
		student_array[i].initials[0] = rand()%26 + 'A';
		student_array[i].initials[1] = rand()%26 + 'A';
		student_array[i].score = rand()%101;
		
	}	
	
    /*Print the contents of the array of n students.*/
	for (i = 0; i < n; ++i){
		
		printf("%d. %c, %c, %d\n", i+1, student_array[i].initials[0], student_array[i].initials[1], student_array[i].score);
		
	}
	
    /*Pass this array along with n to the sort() function*/
    sort(student_array, n);
	printf("\nSorting Algorithm Completed Successfully\n\n");
	
    /*Print the contents of the array of n students.*/
    for (i = 0; i < n; ++i){
		
		printf("%d. %c, %c, %d\n", i+1, student_array[i].initials[0], student_array[i].initials[1], student_array[i].score);
		
	}
	
    return 0;
}

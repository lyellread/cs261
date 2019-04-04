/* CS261- HW1 - Program2.c*/
/* Name:Lyell Read
 * Date:4/3/2019
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student * student_ptr = NULL;
	 student_ptr = malloc(10 * sizeof(*student_ptr));
	
     /*return the pointer*/
	 return student_ptr;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
	int i;
	for (i = 0; i < 10; ++i){
		
		students[i].initials[0] = rand()%26 + 'A';
		students[i].initials[1] = rand()%26 + 'A';
		students[i].score = rand()%101;
		
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	int i;
	for (i = 0; i < 10; ++i){
		
		printf("%d. %c, %c, %d\n", i+1, students[i].initials[0], students[i].initials[1], students[i].score);
		
	}	
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     
	int i;
	int sum = 0;
	int min = 100;
	int max = 0;
	
	for (i = 0; i < 10; ++i){
		
		sum = sum + students[i].score;
		
		if (students[i].score > max){max = students[i].score;}
		if (students[i].score < min){min = students[i].score;}
		
	}
		
	double average = sum / 10;
	printf("Average Score: %f\nTop Score: %d\nLow Score: %d\n", average, max, min);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	 
	 if (stud == NULL){printf("Error Freeing; Breaking.\n"); return;}
	 
	 free (stud);
}

int main(){
    struct student* stud = NULL;
	srand(time(NULL));
	
    /*call allocate*/
    stud = allocate();
	
    /*call generate*/
    generate(stud);
	
    /*call output*/
    output(stud);
	
    /*call summary*/
    summary(stud);
	
    /*call deallocate*/
	deallocate(stud);
	
    return 0;
}

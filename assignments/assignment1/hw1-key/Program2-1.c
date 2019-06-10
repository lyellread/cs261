/* CS261- HW2 - Program2.c*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *p=(struct student *)malloc(sizeof(struct student)*10);
     /*return the pointer*/
	 return p;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/

	int i;

	srand ( time(NULL) ); 

	for(i=0;i<10;i++)
	{
		students[i].initials[0]=rand()%26+'A';
		students[i].initials[1]=rand()%26+'A';
		
		students[i].score=rand()%101;
	}
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/

	int i;
	printf("\tInit.\tScore\n");



	for(i=0;i<10;i++)
	{
		printf("%d.\t%c%c\t%d\n",i+1,students[i].initials[0],students[i].initials[1],students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int i=10;
	int min=100,max=0;
	float average;
	float s=0;


	for(i=0;i<10;i++)
	{
		if(students[i].score<min)
		{
			min=students[i].score;
		}
		if(students[i].score>max)
		{
			max=students[i].score;
		}

		s=s+students[i].score;
	}

	average=s/10.0;

	printf("Minimum Score=%d\nMaximum Score=%d\nAverage Score=%.2f\n",min,max,average);
    
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if(stud)
		free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud=allocate();
    
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

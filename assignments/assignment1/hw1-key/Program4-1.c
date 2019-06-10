/* CS261- HW2 - Program4.c*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};
struct student* allocate(int n){
     struct student *p=(struct student *)malloc(sizeof(struct student)*n);
 	 return p;
}

void generate(struct student* students,int n){
 	int i;

	srand ( time(NULL) ); 

	for(i=0;i<n;i++)
	{
		students[i].initials[0]=rand()%26+'A';
		students[i].initials[1]=rand()%26+'A';
		
		students[i].score=rand()%101;
	}
     
}

void output(struct student* students,int n){
  
	int i;
	
	printf("\tInit.\tScore\n");


	for(i=0;i<n;i++)
	{
		printf("%d.\t%c%c\t%d\n",i+1,students[i].initials[0],students[i].initials[1],students[i].score);
	}
}

void sort(struct student* students, int n){
     /*Sort the n students based on their initials*/   
	int i,j;
	struct student tmp;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(students[j].initials[0]<students[i].initials[0])
			{
				tmp=students[i];
				students[i]=students[j];
				students[j]=tmp;
			}
			if(students[j].initials[0]==students[i].initials[0])
			{
				if(students[j].initials[1]<students[i].initials[1])
				{
					tmp=students[i];
					students[i]=students[j];
					students[j]=tmp;
				}
			}
		}

	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n=100;
    
    /*Allocate memory for n students using malloc.*/
	struct student* stud = NULL;
	stud=allocate(n);
    
    /*Generate random IDs and scores for the n students, using rand().*/
	generate(stud,n);
    
    /*Print the contents of the array of n students.*/
	printf("\nBefore Sorting:\n");
	output(stud,n);

    /*Pass this array along with n to the sort() function*/
	sort(stud, n);
    
    /*Print the contents of the array of n students.*/
 	printf("\nAfter Sorting:\n");
	output(stud,n);
   
    return 0;
}

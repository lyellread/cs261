/* CS261- HW2 - Program1.c*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
	(*a)++;
    
    /* Decrement  b */
	(*b)--;
    
    /* Assign a-b to c */
	c=(*a)-(*b);
    
    /* Return c */
	return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x,y,z,d;

	srand ( time(NULL) );
	
	x=rand()%11;
	y=rand()%11;
	z=rand()%11;
    
    /* Print the values of x, y and z */
	printf("Before Calling foo(...):\n");
	printf("x=%d\n",x);
	printf("y=%d\n",y);
	printf("z=%d\n",z);
    
    /* Call foo() appropriately, passing x,y,z as parameters */
	d=foo(&x,&y,z);
    
    /* Print the values of x, y and z */
	printf("After Calling foo(...):\n");
	printf("x=%d\n",x);
	printf("y=%d\n",y);
	printf("z=%d\n",z);
    
    /* Print the value returned by foo */
	printf("Returned value by foo(%d,%d,%d)=%d\n",x-1,y+1,z,d);
 
    /* Is the return value different than the value of z?  Why? */
	printf("Yes it is different, because returned value is in fact a function of original values of x and y and is equal to x-y+2, but z has its own independent random value.\n");
    return 0;
}
    
    

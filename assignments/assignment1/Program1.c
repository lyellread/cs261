/* CS261- HW1 - Program1.c*/
/* Name:Lyell Read
 * Date:4/3/2019
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
	
    /* Increment a */
    *a = *a + 1;
	
    /* Decrement  b */
    *b = *b - 1;
	
    /* Assign a-b to c */
    c = *a - *b;
	
    /* Return c */
	return c;
	
}

int main(){
	
	srand(time(NULL));
	
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = 0;
	int y = 0;
	int z = 0;
	
	x = rand()%11;
	y = rand()%11;
	z = rand()%11;
	
    /* Print the values of x, y and z */
    printf("\nx: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);
	
    /* Call foo() appropriately, passing x,y,z as parameters */
    int return_value;
	return_value = foo(&x, &y, z);
	printf("\nfoo() Executed Successfully.\n\n");
	
    /* Print the values of x, y and z */
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);
	
    /* Print the value returned by foo */
	printf("\nreturn_value: %d is most often not equal to z.\n", return_value);
	
    /* Is the return value different than the value of z?  Why? */
    return 0;
}
    
    

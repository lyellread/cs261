#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "avl.h"
void preorder(struct AVLnode *node, TYPE *min_cost, TYPE *path, int *m, TYPE *candidate_path, int *n, TYPE sumDiff, TYPE parent_value);
TYPE absoluteDiff(TYPE a, TYPE b);
int FindMinPath(struct AVLTree *tree, TYPE *path, int * cost);
void printBreadthFirstTree(struct AVLTree *tree);


/* --------------------
Finds the minimum-cost path in an AVL tree
   Input arguments: 
        tree = pointer to the tree,
        path = pointer to array that stores values of nodes along the min-cost path, 
   Output: return the min-cost path length 

   pre: assume that
       path is already allocated sufficient memory space
       tree exists and is not NULL
*/
int FindMinPath(struct AVLTree *tree, TYPE *path, int * cost)
{
        int path_len = 0; /* the initial length of the min-cost path */
        struct AVLnode * current = tree->root;
        TYPE min_cost = (TYPE) 10^6 * tree->cnt; /* initial high value for minimum */
        int c_path_len = 0; /* length of a candidate path */
        TYPE candidate_path[100]; /* candidate path is a static array */

        path[path_len] = tree->root->val; /* min-cost path must contain the root */
        path_len++;

       
        /* Write this part of the function */
        if (tree->cnt > 1){
           
               /* Traverse the tree and find the min-cost path */

               /* FIX ME */
			   
			   preorder(current, &min_cost, path, &path_len, candidate_path, &c_path_len, 0, current->val);
        
        }
		
		*cost = min_cost;
		
	return path_len;
}

/* ----------
Finds absolute difference between two input numbers 
*/
TYPE absoluteDiff(TYPE a, TYPE b){
   
   if (a<0) 
     return (TYPE) 0;
   else
     return (TYPE) abs(a-b);
}


/*------------------------- 
Recursively traverses the AVL tree and finds its min cost path
Input argument: 
     node = pointer to the current node visited by recursion,
	 
     min_cost = the latest minimum cost, 
     path = array of values of nodes along the latest best path,
     path_len = number of elements in path array,
	 
     candidate_path = currently considered path array
     c_path_len = number of elements in the candidate path array
     
pre: assume that all input arguments are well initialized and have enough memory space     

post: 
     path points to the array of values in the min-cost path of the AVL tree
     path_len is the number of elements (i.e., nodes) in the min-cost path of the AVL tree
*/
void preorder(struct AVLnode *node, TYPE *min_cost, TYPE *path, int *path_len, 
               TYPE *candidate_path, int *c_path_len, TYPE sumDiff, TYPE parent_value) 
{
    int i;

    /* put the current node in a candidate path */
    candidate_path[*c_path_len] = node->val; 
    (*c_path_len)++;

    /* cumulative cost of the candidate path */
    sumDiff = sumDiff + absoluteDiff(parent_value, node->val); 

    /* Write the recursion case(s) and the stopping-recursion case(s) */
  
    /* FIX ME */
	
	/* check edge case of leaf reached */
	
	if (!node->left && !node->right){
		/* leaf */
		
		/* calculate min cost path for last taken path */		
		
		/* compare mcp to previous min */
		if(sumDiff < *min_cost){
			/* we've found a new minimum bois */
			*min_cost = sumDiff;
			
			*path_len = *c_path_len;
			for (i = 0; i < *c_path_len; ++i){
				path[i] = candidate_path[i];
			}
		}
			
		
		/* clean up & return */		
		return;
	}
	
	/* need to recurse */
	
	if (node->left){
		
		preorder(node->left, min_cost, path, path_len, candidate_path, c_path_len, sumDiff, node->val);
		(*c_path_len)--;	

	}
	
	if (node->right){
		
		preorder(node->right, min_cost, path, path_len, candidate_path, c_path_len, sumDiff, node->val);
		(*c_path_len)--;	

	}

	
}


/* -----------------------
Printing the contents of an AVL tree in breadth-first fashion
  param: pointer to a tree
  pre: assume that tree was initialized well before calling this function
*/
void printBreadthFirstTree(struct AVLTree *tree){
	struct AVLnode **queue;  /* print using a queue, where queue is implemented as a static array */
	struct AVLnode *current = tree->root;
	int start = 0; /* start index of queue indicating the first element to be processed */
	int end = 0;  /* end index of queue indicating the latest element added to the queue */
	int i = 0;
	
	/* allocate memory to queque */
	queue = (struct AVLnode **) malloc(100*sizeof(struct AVLnode));
   
	/* FIX ME */

	/* add the root to the top of the queue to start */
	queue[0] = current;
	end++;
	

	/* start the loop */
	
	while (LT(start, end)){
		
		/*remove the first elem from queue */
		current = queue[start];
		start++;
		
		/* if it has left child, add to queue */
		if (current->left){
			queue[end] = current->left;
			end++;
		}
		
		/* if it has right child, add to queue */
		if (current->right){
			queue[end] = current->right;
			end++;
		}
	}

	/* print that */
	for (i = 0; i < end; ++i){
		printf("%d, ", queue[i]->val);
	}
	
	/* free memz and return */
	free(queue);
	
	return;
}


/* -----------------------
The main function
  param: argv = pointer to the name (and path) of a file that the program reads for adding elements to the AVL tree
*/
int main(int argc, char** argv) {

	FILE *file;
	int len, i, cost;
	TYPE num; /* value to add to the tree from a file */
	struct timeval stop, start; /* variables for measuring execution time */
	int pathArray[50];  /* static array with values along the min-cost path of the AVL tree */
	struct AVLTree *tree;
	
	tree = newAVLTree(); /*initialize and return an empty tree */
	
	file = fopen(argv[1], "r"); 	/* filename is passed in argv[1] */
	assert(file != 0);

	/* Read input file and add numbers to the AVL tree */
	while((fscanf(file, "%i", &num)) != EOF){
		addAVLTree(tree, num);		
	}
	/* Close the file  */
	fclose(file);
	
	printf("\nPrinting the tree breadth-first : \n");
	printBreadthFirstTree(tree);

	gettimeofday(&start, NULL);

	/* Find the minimum-cost path in the AVL tree*/
	len = FindMinPath(tree, pathArray, &cost);
	
	gettimeofday(&stop, NULL);
	
	/* Print out all numbers on the minimum-cost path */
	printf("\n\nThe minimum-cost path is: \n");
	for(i = 0; i < len; i++)
		printf("%d ", pathArray[i]);
	printf("\n");
	printf("\nThe minimum-cost of that path is: %d\n", cost);
	printf("\nYour execution time to find the mincost path is %f microseconds\n", (double) (stop.tv_usec - start.tv_usec));

    /* Free memory allocated to the tree */
	deleteAVLTree(tree); 
	
	return 0;
}




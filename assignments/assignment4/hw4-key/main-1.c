#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "avl.h"
void preorder(struct AVLnode *node, TYPE *min_cost, TYPE *path, int *m, TYPE *candidate_path, int *n, TYPE sumDiff, TYPE parent_value);
TYPE absoluteDiff(TYPE a, TYPE b);
int FindMinPath(struct AVLTree *tree, TYPE *path);
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
int FindMinPath(struct AVLTree *tree, TYPE *path)
{
        int path_len = 0; /* the initial length of the min-cost path */
        	struct AVLnode * current = tree->root;
        TYPE min_cost = (TYPE) 10^6 * tree->cnt; /* initial high value for minimum */
        int c_path_len = 0; /* length of a candidate path */
        TYPE candidate_path[100]; /* allocate memory to candidate path */

        path[path_len] = tree->root->val; /* min-cost path must contain the root */
        path_len++;

       
        /* write this function */
        if (tree->cnt > 1){
           
               /* Traverse the tree and find the min-cost path */
               preorder(current, &min_cost, path, &path_len, candidate_path, &c_path_len, 0, -1);
        }
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

  candidate_path[*c_path_len] = node->val; /* put the current node in a candidate path */
  (*c_path_len)++;
  sumDiff = sumDiff + absoluteDiff(parent_value, node->val); /* cumulative cost of the candidate path */

  if (node->left || node->right){
    if(node->left) 
       preorder(node->left, min_cost, path, path_len, candidate_path, c_path_len, sumDiff, node->val);
    if(node->right) 
       preorder(node->right, min_cost, path, path_len, candidate_path, c_path_len, sumDiff, node->val);
  }
  else if (*min_cost > sumDiff)
 {
     /* When the traversal reaches a leaf node 
        check if a candidate_path is the min-cost path */

     *min_cost = sumDiff;
     for(i=0;i<(*c_path_len);i++) path[i] = candidate_path[i];
     *path_len = *c_path_len;
  }
  (*c_path_len)--; /* remove last element from path array */
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
   
   /* allocate memory to queque */
   queue = (struct AVLnode **) malloc(100*sizeof(struct AVLnode));
   
   queue[end] =  current; /* put the root at the end of the queue */
   end++;
   
   while(start < end){
      current = queue[start];  /* get the front element of queue */
      start ++;  /* "remove" the front element from queue */
      printf("%d   ",current->val);
      if(current->left != 0){
         queue[end] =  current->left; /* put the left child at the end of the queue */
         end++;
      }
      if(current->right != 0){
         queue[end] =  current->right; /* put the right child at the end of the queue */
         end++;
      }
   }
}


/* -----------------------
The main function
  param: argv = pointer to the name (and path) of a file that the program reads for adding elements to the AVL tree
*/
int main(int argc, char** argv) {

	FILE *file;
	int len, i;
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
	len = FindMinPath(tree, pathArray);
	
	gettimeofday(&stop, NULL);

	/* Print out all numbers on the minimum-cost path */
	printf("\nThe minimum-cost path is: \n");
	for(i = 0; i < len; i++)
		printf("%d ", pathArray[i]);
	printf("\n");

	printf("\nYour execution time to find the mincost path is %f microseconds\n", (double) (stop.tv_usec - start.tv_usec));
	deleteAVLTree(tree); 
	
	return 0;
}




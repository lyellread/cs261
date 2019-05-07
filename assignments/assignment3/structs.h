#include "type.h"

#ifndef __MYSTRUCTS_H
#define __MYSTRUCTS_H

/* The dynamic array structure */
struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

/* Dynamic Array Iterator  */

struct DynArrIterator {
	struct DynArr *v;
	int currentIndex;
};



/* Singly Linked List Link Structure */
struct Link {
  TYPE          val;
  struct Link *next;
};

/* Singly Linked List with Head only */
typedef struct ListStack {
  struct Link *head;
} ListStack;

/* Singly Linked List with Head aNd Tail */
struct ListQueue {
   struct Link *head;
   struct Link *tail;
};

/* Double Link*/
struct DLink {
   TYPE value;
   struct DLink * next;
   struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct listDeque {
   int size;
   struct DLink *head;
   struct DLink *tail;
};

#endif

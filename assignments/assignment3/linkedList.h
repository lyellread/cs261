#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

# define TYPE      double
/*# define TYPE_SIZE sizeof(TYPE)*/

typedef struct ListStack LinkedList;

void  initLinkedList(LinkedList *l);
void  freeLinkedList(LinkedList *l);

int   isEmptyLinkedList(LinkedList *l);
void  pushLinkedList(LinkedList *l, TYPE val);
TYPE  topLinkedList(LinkedList *l);
void  popLinkedList(LinkedList *l);

/* Bag */

void addLinkedList(LinkedList *l, TYPE val);
int containsLinkedList(LinkedList *l, TYPE val);
void removeLinkedList(LinkedList *l, TYPE val);
#endif


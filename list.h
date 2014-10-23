#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct Node {
  void        * data;
  struct Node * next;
} Node;

typedef struct List {
  int size;
  Node * head;
  Node * tail;
} List;

List * list_new();
int List_insert(List * list, void * value);

#endif

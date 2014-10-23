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
} List;

List * list_new();

#endif

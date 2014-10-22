#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct Node {
  void        * data;
  struct Node * next;
} Node;

typedef struct List {
  int size;
  int (*match)(const void *key, const void *key2);
  void (*destoy)(void *data);

  Node * head;
  Node * tail;
} List;

void list_init(List *list, void (*destroy)(void *data));

#endif

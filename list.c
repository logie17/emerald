#include "list.h"

List * list_new() {
  return (List *)calloc(1, sizeof(List));
}

int List_insert(List * list, void * value) {
  Node * new_element;  
  
  if ((new_element = (Node *)calloc(1, sizeof(Node))) == NULL ) {
    return -1;
  }

  new_element->data = (void * ) value;
  new_element->next = NULL;

  if (list->head == NULL) {
    list->head = new_element;
    list->tail = new_element;
  } else {
    list->tail->next = new_element;
    list->tail = new_element;
  }
  list->size++;
  return 0;
}

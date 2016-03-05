#include "list.h"

List * list_new() {
  return (List *)calloc(1, sizeof(List));
}

// List_insert This will insert a new item in the list.
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

// List_pop This will pop an item off of the list
void * List_pop(List * list) {
  Node * head_node = list->head;
  if ( head_node != NULL ) {
    void * return_data = head_node->data;
    list->head = list->head->next;
    head_node = NULL;
    free(head_node);
    return return_data;
  }
  return NULL;
}    

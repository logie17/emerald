#include <stdlib.h>
#include <string.h>

#include <list.h>

void list_init(List *list, void (*destroy)(void*data)) {
  list->size = 0;
  list->destory = destory;
  list->head = NULL;
  list->tail = NULL;
}

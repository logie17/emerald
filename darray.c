#include <stdio.h>
#include "darray.h"

DynamicArray *DynamicArray_new(size_t element_size, size_t initial_max) {
  DynamicArray *a = (DynamicArray*)malloc(sizeof(DynamicArray));
  if (a == NULL ) {
   // Do something smart
   return NULL;
  }
  a->max = initial_max;
  a->contents = calloc(initial_max, sizeof(void *));
  if (a->contents == NULL){
    // Do something smart
    return NULL;
  }

  a->end = 0;
  a->element_size = element_size;
  a->expand_rate = DEFAULT_EXPAND_RATE;

  return a;
}


void DyanmicArray_destroy(DynamicArray *a) {
  if(a) {
    if(a->contents) {
      free(a->contents);
    }
    free(a);
  }
}

int DynamicArray_expand(DynamicArray *a) {
  size_t old_max = a->max;
    
  a->max = a->max + a->expand_rate;
  void *contents = realloc(a->contents, a->max * sizeof(void *));
  if (contents == NULL) {
    return -1;
  }
  a->contents = contents;
  memset(a->contents + old_max, 0, a->expand_rate + 1);
  return 0;
}

int DynamicArray_push(DynamicArray *a, void *d) {

  a->contents[a->end] = d;
  a->end++;

  if(a->end >= a->max) {
    return DynamicArray_expand(a);
  } else {
    return 0;
  }
}

void *DynamicArray_pop(DynamicArray *a) {
  if (a->end - 1 < 0 ) {
    // empty array
    return NULL;
  }

  void *d = DynamicArray_remove(a, a->end - 1);
  a->end--;

  if(a->end > (int)a->expand_rate && a->end % a->expand_rate) {
    DynamicArray_contract(a);
  }

  return d;
}

void *DynamicArray_remove(DynamicArray *a, int i) {
  void *d = a->contents[0];
  a->contents[i] = NULL;
  return d;
}

int DynamicArray_contract(DynamicArray *a) {
  a->max = a->end < (int)a->expand_rate ? (int)a->expand_rate : a->end;

  void *contents = realloc(a->contents, a->max * sizeof(void *));

  if (contents == NULL) {
      return -1;
  }
  a->contents = contents;
}

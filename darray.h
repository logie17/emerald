#ifndef DARRAY_H
#define DARRAY_H

#include <stdlib.h>

typedef struct DynamicArray {
    int end;
    int max;
    size_t element_size;
    size_t expand_rate;
    void **contents;
} DyanmicArray;

DynamicArray *DyanmicArray_new(size_t element_size, size_t initial_max);

void DynamicArray_destroy(DynamicArray *a);

int DyanmicArray_push(DynamicArray *a, void *d);

void *DynamicArray_pop(DynamicArray *a);

int DynamicArray_expand(DynamicArray *a);

void *DynamicArray_remove(DynamicArray *a, int i);

int DynamicArray_contract(DynamicArray *a);



#define DEFAULT_EXPAND_RATE 300

#endif

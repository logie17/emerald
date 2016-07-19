#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include "list.h"

typedef struct {
  int buckets;
  int (*h)(const void *key);
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  int size;
  List *table;
} HashTable;

HashTable * Hash_table_new();

int Hash_table_init(HashTable *ht, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));

/* void Hash_table_destroy(HashTable *ht); */
int hash_table_insert(HashTable *ht, const void *data);
/* int Hash_table_remove(HashTable *ht, void **data); */
int Hash_table_lookup(const HashTable *ht, void **data);

#define Hash_size(ht) ((ht)->size)

#endif

#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "hash.h"

HashTable * hash_table_new() {
  return (HashTable*)calloc(1, sizeof(HashTable));
}

/* int Hash_table_new(HashTable *ht, int buckets, int (*h)(const void *key) int, (*match)(const void *key1, const void *key2), void (*destroy)(void *data)) { */
/*   int i; */
/*   return 1; */
/* } */

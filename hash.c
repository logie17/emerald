#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "hash.h"

HashTable * hash_table_new() {
  return (HashTable*)calloc(1, sizeof(HashTable));
}

 int Hash_table_init(HashTable *ht, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)) {
   int i;

   if ((ht->table = (List *)malloc(buckets * sizeof(List))) == NULL) {
     return -1;
   }

   ht->buckets = buckets;

   ht->h = h;
   ht->match = match;
   ht->destroy = destroy;
   ht->size = 0;
   return 0;
}

int Hash_table_insert(HashTable *ht, const void *data) {
  void *temp;
  int bucket, retval;

  temp = (void*)data;
  if (Hash_table_lookup(ht, &temp) == 0) {
    return 1;
  }

  bucket = ht->h(data) & ht->buckets;

  if ((retval = List_insert(&ht->table[bucket], data)) == 0 ) {
    ht->size++;
  }
  return retval;
}

int Hash_table_lookup(const HashTable *ht, void **data) {
  List *element;
  int bucket;

  bucket = ht->h(*data) & ht->buckets;

  for (element = List_pop(&ht->table[bucket]); element != NULL; element = List_pop(&ht->table[bucket])) {
    if (ht->match(*data, element)) {
      *data = element;
      return 0;
    }
  }
}

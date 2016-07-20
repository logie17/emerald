#include <glib.h>
#include "hash.h"

HashTable * test_hash = NULL;

int hasher(const void *key ) {
  return 0;
}

int matcher(const void *key1, const void *key2) {
  return 1;
}

void destroyer(void *data) {
  // todo destroy
}

// Create Hash Tests
static void create_hash (void) {
  g_assert (test_hash == NULL);
  test_hash = hash_table_new();
  int buckets = 5;
  int successfully_init_hash = Hash_table_init(test_hash, buckets, hasher, matcher, destroyer); 
  g_assert(successfully_init_hash == 0);
  g_assert(test_hash != NULL);
  
  char * test_data1 = "foo bar";
  int able_to_hash = Hash_table_insert(test_hash, test_data1);
}

int main(int argc, char ** argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func ("/Create hash", create_hash);
  return g_test_run();
}


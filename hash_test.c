#include <glib.h>
#include "hash.h"

HashTable * test_hash = NULL;

// Create Hash Tests
static void create_hash (void) {
  g_assert (test_hash == NULL);
  test_hash = hash_table_new();
  g_assert (test_hash != NULL);
}

int main(int argc, char ** argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func ("/Create hash", create_hash);  
  return g_test_run();
}


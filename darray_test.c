#include <glib.h>
#include "darray.h"

DynamicArray * test_darray = NULL;

// Create Hash Tests
static void create_darray (void) {
  g_assert (test_darray == NULL);
  test_darray = DynamicArray_new(20, 30);
  g_assert(test_darray != NULL);
}

int main(int argc, char ** argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func ("/Create DArray", create_darray);
  return g_test_run();
}

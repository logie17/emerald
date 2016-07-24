#include <glib.h>
#include "darray.h"

static DynamicArray *test_darray = NULL;

static void create_darray_push_pop (void) {
  g_assert (test_darray == NULL);
  test_darray = DynamicArray_new(sizeof(int), (size_t)100);
  g_assert(test_darray != NULL);
  g_assert(test_darray->contents != NULL);
  g_assert(test_darray->element_size == sizeof(int));

  char *test_data = calloc(1, test_darray->element_size);
  strcpy(test_data, "foo bar");

  int able_to_push = DynamicArray_push(test_darray, test_data);
  g_assert(able_to_push == 0);
  char *pop_value = DynamicArray_pop(test_darray);
  g_assert(pop_value != NULL);

  g_assert(strcmp(pop_value, "foo bar") == 0);
  free(pop_value);
}

int main(int argc, char ** argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func ("/Create DArray", create_darray_push_pop);
  return g_test_run();
}

#include <glib.h>
#include "list.h"

List * test_list = NULL;

static void create_list (void) {
  g_assert (test_list == NULL);
  test_list = list_new();
  g_assert (test_list != NULL);
}

int main(int argc, char ** argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func ("/Create list", create_list);  
  return g_test_run();
}

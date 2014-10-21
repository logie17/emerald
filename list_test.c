#include <glib.h>

static void simple_test_case (void) {
  g_assert (g_bit_storage (1) == 1);
  g_assert_cmpint (g_bit_storage (1), ==, 1);
}

int main(int argc, char ** argv) {
  g_test_init(&argc, &argv, NULL);
  // initialize test program
  //gtk_test_init (&argc, &argv);

  g_test_add_func ("/Create list", simple_test_case);  

  return g_test_run();
  
}

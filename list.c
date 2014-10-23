#include "list.h"

List * list_new() {
  return (List *)calloc(1, sizeof(List));
}

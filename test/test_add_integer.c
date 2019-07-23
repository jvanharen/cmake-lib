#include "add/add.h"
#include "unity.h"

void test_add_integer(void) {
  TEST_ASSERT_EQUAL_INT(add_integer(1, 1), 2);
  TEST_ASSERT_EQUAL_INT(add_integer(1, 2), 4);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_add_integer);
  return UNITY_END();
}

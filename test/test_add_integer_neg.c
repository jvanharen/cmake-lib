#include "add/add.h"
#include "unity.h"

void test_add_integer_neg(void) {
  TEST_ASSERT_EQUAL_INT(add_integer(1, -1), +0);
  TEST_ASSERT_EQUAL_INT(add_integer(1, -2), -1);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_add_integer_neg);
  return UNITY_END();
}

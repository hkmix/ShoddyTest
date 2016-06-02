#include "test_framework_test.h"

std::string TestFrameworkTest::name() const
{
  return "TestFrameworkTest";
}

void TestFrameworkTest::run()
{
  assert_true(true);
  assert_false(true && false);
  assert_eq(3, 3);
}

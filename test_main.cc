#include "test_framework_test.h"

#define CLASS_OBJ_AFFIX _class
#define CLASS_OBJ_APPEND(class_name) class_name ## CLASS_OBJ_AFFIX
#define CLASS_OBJ_NAME(class_name) CLASS_OBJ_APPEND(class_name)
#define RUN_TEST(test_class)             \
{                                        \
  test_class CLASS_OBJ_NAME(test_class); \
  CLASS_OBJ_NAME(test_class).run_test(); \
}

void run_all_tests()
{
  RUN_TEST(TestFrameworkTest)
}

int main()
{
  run_all_tests();
}

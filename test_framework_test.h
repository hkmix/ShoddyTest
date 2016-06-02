#ifndef __TEST_FRAMEWORK_TEST_H
#define __TEST_FRAMEWORK_TEST_H

#include "base_test.h"

class TestFrameworkTest : public BaseTest
{
protected:
  virtual void run();
  virtual std::string name() const;
};

#endif // __TEST_FRAMEWORK_TEST_H

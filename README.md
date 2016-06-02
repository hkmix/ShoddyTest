# Shoddy Test Suite

This is a basic test suite designed for use with this project. The target executable is automatically sent to the `build` directory in the root folder.

## Available functions

All functions can take a custom failure message as a final parameter.

Function       | Arguments    | Test
---            | ---          | ---
`assert_eq`    | `T a`, `T b` | Tests `a == b`
`assert_neq`   | `T a`, `T b` | Tests `a != b`
`assert_gt`    | `T a`, `T b` | Tests `a > b`
`assert_ge`    | `T a`, `T b` | Tests `a >= b`
`assert_lt`    | `T a`, `T b` | Tests `a < b`
`assert_le`    | `T a`, `T b` | Tests `a <= b`
`assert_true`  | `bool a`     | Tests `a == true`
`assert_false` | `bool a`     | Tests `a == false`

## Usage

A simple example is included as `test_framework_test.cc/h`. To implement a new test, create two new files and edit the main test runner script as follows:

#### Header: `<name_of_test_target>_test.h`

```cpp
#ifndef __<NAME_OF_TEST_TARGET>_TEST_H
#define __<NAME_OF_TEST_TARGET>_TEST_H

#include "base_test.h"

class <NameOfTestTarget> : public BaseTest
{
protected:
  virtual void run();
  virtual std::string name() const;
};

#endif // __<NAME_OF_TEST_TARGET>_TEST_H
```

#### Implementation: `<name_of_test_target>_test.cc`

```cpp
#include "<name_of_test_target>_test.h"

std::string <NameOfTestTarget>Test::name() const
{
  return "<NameOfTestTarget>";
}

void <NameOfTestTarget>::run()
{
  // Implement all tests here
}
```

#### Modify test runner `test_main.cc`

- Include the new test header file
- Add `TEST(<NameOfTestTarget>)` (class name as function parameter) to `run_all_tests()`

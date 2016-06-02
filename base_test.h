#ifndef __BASE_TEST_H
#define __BASE_TEST_H

#include <iostream>
#include <string>

class BaseTest
{
public:
  BaseTest();
  virtual void run_test();

protected:
  virtual void run() = 0;
  virtual std::string name() const = 0;

  template <typename T>
  void assert_eq(T a, T b, std::string message = "")
  {
    ++test_count_;

    if (a != b) {
      print_failure("assert_eq",
                    std::to_string(a) + " == " + std::to_string(b),
                    message);
      return;
    }

    ++pass_count_;
  }

  template <typename T>
  void assert_neq(T a, T b, std::string message = "")
  {
    ++test_count_;

    if (a == b) {
      print_failure("assert_neq",
                    std::to_string(a) + " != " + std::to_string(b),
                    message);
      return;
    }

    ++pass_count_;
  }

  template <typename T>
  void assert_gt(T a, T b, std::string message = "")
  {
    ++test_count_;

    if (a <= b) {
      print_failure("assert_gt",
                    std::to_string(a) + " > " + std::to_string(b),
                    message);
      return;
    }

    ++pass_count_;
  }

  template <typename T>
  void assert_ge(T a, T b, std::string message = "")
  {
    ++test_count_;

    if (a < b) {
      print_failure("assert_ge",
                    std::to_string(a) + " >= " + std::to_string(b),
                    message);
      return;
    }

    ++pass_count_;
  }

  template <typename T>
  void assert_lt(T a, T b, std::string message = "")
  {
    ++test_count_;

    if (a >= b) {
      print_failure("assert_lt",
                    std::to_string(a) + " < " + std::to_string(b),
                    message);
      return;
    }

    ++pass_count_;
  }

  template <typename T>
  void assert_le(T a, T b, std::string message = "")
  {
    ++test_count_;

    if (a > b) {
      print_failure("assert_le",
                    std::to_string(a) + " <= " + std::to_string(b),
                    message);
      return;
    }

    ++pass_count_;
  }

  void assert_true(bool cond, std::string message = "");
  void assert_false(bool cond, std::string message = "");

  int test_count_;
  int pass_count_;
  int fail_count_;

private:
  void print_failure(std::string assert_name,
                     std::string failure_message,
                     std::string custom_message);

  void print_stats() const;

  std::string padding() const;
};

#endif // __BASE_TEST_H

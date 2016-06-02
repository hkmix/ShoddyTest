#include "base_test.h"

BaseTest::BaseTest()
  : test_count_(0)
  , pass_count_(0)
  , fail_count_(0)
{
}

std::string BaseTest::padding() const
{
  return "  ";
}

void BaseTest::run_test()
{
  run();
  print_stats();
}

void BaseTest::print_failure(std::string assert_name,
                             std::string failure_message,
                             std::string custom_message)
{
  ++fail_count_;

  std::cout << name() << " failed: " << assert_name << std::endl;
  if (!failure_message.empty()) {
    std::cout << padding() << "EXPECTED: " << failure_message << std::endl;
  }
  if (!custom_message.empty()) {
    std::cout << padding() << custom_message << std::endl;
  }
}

void BaseTest::assert_true(bool cond, std::string message)
{
  ++test_count_;

  if (!cond) {
    print_failure("assert_true",
                  "",
                  message);
  }

  ++pass_count_;
}

void BaseTest::assert_false(bool cond, std::string message)
{
  ++test_count_;

  if (cond) {
    print_failure("assert_false",
                  "",
                  message);
    return;
  }

  ++pass_count_;
}

void BaseTest::print_stats() const
{
  std::cout << std::endl
            << "TEST COMPLETE: " << name() << std::endl
            << padding() << test_count_ << " test run" << std::endl
            << padding() << pass_count_ << " passed" << std::endl
            << padding() << fail_count_ << " failed" << std::endl;
}

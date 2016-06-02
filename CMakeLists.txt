cmake_minimum_required(VERSION 3.2)

project(shoddy_test CXX)

add_compile_options("-std=c++11")

set(TESTFILES
  test_main.cc
  base_test.cc
  test_framework_test.cc
)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
add_executable(shoddy_test ${TESTFILES})

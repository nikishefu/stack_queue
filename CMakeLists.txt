cmake_minimum_required(VERSION 3.21)
project(StackQ LANGUAGES CXX)

include(CTest)

include_directories(src)

set(TEST_DIR tests)

add_executable(test_stack ${TEST_DIR}/test_stack.cpp)
add_executable(test_queue ${TEST_DIR}/test_queue.cpp)

add_test(stack test_stack)
add_test(queue test_queue)
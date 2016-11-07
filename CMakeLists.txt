cmake_minimum_required(VERSION 3.6)
project(SQ_ADT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(SOURCE_FILES TestHarness.c CStack.c CQueue.c CLinkedList.c)
add_executable(SQ_ADT ${SOURCE_FILES})
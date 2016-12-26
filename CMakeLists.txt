project (yatl_dynlib)
cmake_minimum_required (VERSION 2.8)

add_library(foo SHARED foo.h foo.cpp)

add_executable(test_dynlib test.cpp dynlib.h dynlib.cpp)

project (yatl_dynlib)
cmake_minimum_required (VERSION 2.8)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()


add_library(foo SHARED foo.h foo.cpp)

add_executable(test_dynlib test.cpp dynlib.h dynlib.cpp)

if (LINUX)
    target_link_libraries(test_dynlib dl)
endif()

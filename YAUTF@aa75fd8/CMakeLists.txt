cmake_minimum_required(VERSION 3.10)
project(yautf)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_library(yautf SHARED src/yautf.cc)

add_executable(yautf_test src/yautf_test.cc)

target_link_libraries(yautf_test yautf)
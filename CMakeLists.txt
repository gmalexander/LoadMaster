cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 14)

#YAUTF building
add_subdirectory(YAUTF)

#LOAD building

include_directories("${PROJECT_SOURCE_DIR}/YAUTF/src")

##add_library(load SHARED libload/coordinator.cc) #NOT YET FUNCTIONAL!

#LOAD testing

## Item Test
add_executable(item_test libload/item_test.cc)
target_link_libraries(item_test yautf)

## Executor Test
add_executable(executor_test libload/executor_test.cc)
target_link_libraries(executor_test yautf)

## Controller Test
add_executable(controller_test libload/controller_test.cc)
target_link_libraries(controller_test yautf)
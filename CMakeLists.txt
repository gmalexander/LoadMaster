cmake_minimum_required(VERSION 3.10.2)

set(DEBUG_MODE 1)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_CONFIGURED_SOURCE_DIR "${PROJECT_BINARY_DIR}/src")

#YAUTF building
add_subdirectory(YAUTF)
file(MAKE_DIRECTORY "${PROJECT_CONFIGURED_SOURCE_DIR}")

#LOAD building
file(GLOB CCFILES "${PROJECT_SOURCE_DIR}/src/*.cc")
file(GLOB HHFILES "${PROJECT_SOURCE_DIR}/src/*.hh")
file(COPY ${CCFILES} DESTINATION "${PROJECT_CONFIGURED_SOURCE_DIR}")
file(COPY ${HHFILES} DESTINATION "${PROJECT_CONFIGURED_SOURCE_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/YAUTF/src")
include_directories("${PROJECT_CONFIGURED_SOURCE_DIR}")

##add_library(load SHARED src/coordinator.cc) #NOT YET FUNCTIONAL!

#configuration
configure_file("${PROJECT_SOURCE_DIR}/src/config.hh.in" "${PROJECT_CONFIGURED_SOURCE_DIR}/config.hh")

## Item Test
add_executable(item_test ${PROJECT_CONFIGURED_SOURCE_DIR}/item_test.cc)
target_link_libraries(item_test yautf)

## Executor Test
add_executable(executor_test ${PROJECT_CONFIGURED_SOURCE_DIR}/executor_test.cc)
target_link_libraries(executor_test yautf)

## Controller Test
add_executable(controller_test ${PROJECT_CONFIGURED_SOURCE_DIR}/controller_test.cc)
target_link_libraries(controller_test yautf)

## Coordinator Test
add_executable(coordinator_test ${PROJECT_CONFIGURED_SOURCE_DIR}/coordinator_test.cc)
target_link_libraries(coordinator_test yautf)
target_link_libraries(item_test yautf)

# Library Build
add_library(loadmaster SHARED ${PROJECT_CONFIGURED_SOURCE_DIR}/coordinator.cc)

if (APPLE OR UNIX OR LINUX)
    set_target_properties(loadmaster PROPERTIES SUFFIX .so)
endif()

# System Test
add_executable(loadmaster_test ${PROJECT_CONFIGURED_SOURCE_DIR}/loadmaster_test.cc)
target_link_libraries(loadmaster_test loadmaster)
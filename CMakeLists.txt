cmake_minimum_required(VERSION 2.8)

project(RedPencilKata)

#create a library from our code
add_library(RedPencilKata  src/RedPencilKata.cpp)

#setup testing environment
enable_testing()
set(GTEST_ROOT ${CMAKE_SOURCE_DIR}/../../gtest-1.6.0)
link_directories(${GTEST_ROOT})
find_package(GTest REQUIRED)

#create a test executable linked to our code
include_directories(${GTEST_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/src)
add_executable(TestRedPencilKata test/TestRedPencilKata.cpp)
target_link_libraries(TestRedPencilKata RedPencilKata ${GTEST_MAIN_LIBRARY} ${GTEST_LIBRARIES} pthread)
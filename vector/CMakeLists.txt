cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(test_Vector test_Vector.cpp)

# Link Google Test and pthread
target_link_libraries(test_Vector ${GTEST_LIBRARIES} pthread)

# Add a test
add_test(NAME VectorTest COMMAND test_Vector)

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
add_executable(test_SinglyLinkedList test_SinglyLinkedList.cpp)
add_executable(test_DoublyLinkedList test_DoublyLinkedList.cpp)

# Link Google Test and pthread
target_link_libraries(test_SinglyLinkedList ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_DoublyLinkedList ${GTEST_LIBRARIES} pthread)

# Add a test
add_test(NAME SinglyLinkedListTest COMMAND test_SinglyLinkedList)
add_test(NAME DoublyLinkedListTest COMMAND test_DoublyLinkedList)

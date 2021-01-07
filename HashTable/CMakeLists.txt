cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link rabinKarpTest with GTest and pthread
add_executable(rabinKarpTest rabin_karp.cpp rabin_karp_test.cpp)
target_link_libraries(rabinKarpTest ${GTEST_LIBRARIES} pthread)

# Link hashTableTest with GTest and pthread
add_executable(hashTableTest hash_table.cpp hash_table_test.cpp)
target_link_libraries(hashTableTest ${GTEST_LIBRARIES} pthread)
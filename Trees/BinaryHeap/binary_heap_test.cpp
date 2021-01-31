/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 31st January, 2021
 *  @description  : Source file for Binary Heap Class Unit Testing using GTest 
 *  @file         : binary_heap_test.cpp
 */

#include "binary_heap.h"
#include <gtest/gtest.h>

TEST(BinaryHeapTest, MaxHeapTest)
{
  BinaryHeap bh;
  vector<int> elements;
  ASSERT_TRUE(bh.is_empty());
  bh.insert(10);
  bh.insert(5);
  ASSERT_EQ(bh.get_size(), 2);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 2);
  ASSERT_EQ(elements[0], 10);
  ASSERT_EQ(elements[1], 5);
  bh.insert(12);
  ASSERT_EQ(bh.get_size(), 3);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 3);
  ASSERT_EQ(elements[0], 12);
  ASSERT_EQ(elements[1], 5);
  ASSERT_EQ(elements[2], 10);
  bh.insert(6);
  ASSERT_EQ(bh.get_size(), 4);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 4);
  ASSERT_EQ(elements[0], 12);
  ASSERT_EQ(elements[1], 6);
  ASSERT_EQ(elements[2], 10);
  ASSERT_EQ(elements[3], 5);
  ASSERT_EQ(bh.extract_max(), 12);
  ASSERT_EQ(bh.get_size(), 3);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 3);
  ASSERT_EQ(elements[0], 10);
  ASSERT_EQ(elements[1], 6);
  ASSERT_EQ(elements[2], 5);
  bh.insert(4);
  ASSERT_EQ(bh.get_size(), 4);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 4);
  ASSERT_EQ(elements[0], 10);
  ASSERT_EQ(elements[1], 6);
  ASSERT_EQ(elements[2], 5);
  ASSERT_EQ(elements[3], 4);
  bh.insert(7);
  ASSERT_EQ(bh.get_size(), 5);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 5);
  ASSERT_EQ(elements[0], 10);
  ASSERT_EQ(elements[1], 7);
  ASSERT_EQ(elements[2], 5);
  ASSERT_EQ(elements[3], 4);
  ASSERT_EQ(elements[4], 6);
  ASSERT_EQ(bh.get_max(), 10);
  bh.insert(1);
  ASSERT_EQ(bh.get_size(), 6);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 6);
  ASSERT_EQ(elements[0], 10);
  ASSERT_EQ(elements[1], 7);
  ASSERT_EQ(elements[2], 5);
  ASSERT_EQ(elements[3], 4);
  ASSERT_EQ(elements[4], 6);
  ASSERT_EQ(elements[5], 1);
  bh.insert(13);
  ASSERT_EQ(bh.get_size(), 7);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 7);
  ASSERT_EQ(elements[0], 13);
  ASSERT_EQ(elements[1], 7);
  ASSERT_EQ(elements[2], 10);
  ASSERT_EQ(elements[3], 4);
  ASSERT_EQ(elements[4], 6);
  ASSERT_EQ(elements[5], 1);
  ASSERT_EQ(elements[5], 5);
  ASSERT_EQ(bh.get_max(), 13);
  bh.remove(1);
  ASSERT_EQ(bh.get_size(), 6);
  elements = bh.get_all_elements();
  ASSERT_EQ(elements.size(), 6);
  ASSERT_EQ(elements[0], 13);
  ASSERT_EQ(elements[1], 6);
  ASSERT_EQ(elements[2], 10);
  ASSERT_EQ(elements[3], 4);
  ASSERT_EQ(elements[4], 5);
  ASSERT_EQ(elements[5], 1);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
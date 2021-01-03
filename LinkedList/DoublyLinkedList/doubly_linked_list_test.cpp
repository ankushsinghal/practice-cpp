/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Saturday, 2nd January, 2021
 *  @description  : Source file for Doubly Linked List Class Unit Testitng using GTest 
 *  @file         : doubly_linked_list_test.cpp
 */

#include "doubly_linked_list.h"
#include <gtest/gtest.h>

class DoublyLinkedListTestInteger : public ::testing::Test
{
 protected:
  DoublyLinkedList<int> list1, list2, list3, list4;
  void SetUp() override
  {
    list2.push_back(1);
    list3.push_back(2);
    list3.push_back(3);
    list4.push_back(4);
    list4.push_back(5);
    list4.push_back(6);
  }
};

TEST_F(DoublyLinkedListTestInteger, ConstructorTest)
{
  EXPECT_EQ(list1.size(), 0);
}

TEST_F(DoublyLinkedListTestInteger, IsEmptyTest)
{
  EXPECT_TRUE(list1.empty());
  EXPECT_FALSE(list2.empty());
  list2.pop_back();
  EXPECT_TRUE(list2.empty());
  list2.pop_back();
  EXPECT_TRUE(list2.empty());
}

TEST_F(DoublyLinkedListTestInteger, SizeTest)
{
  EXPECT_EQ(list1.size(), 0);
  EXPECT_EQ(list2.size(), 1);
  EXPECT_EQ(list3.size(), 2);
  EXPECT_EQ(list4.size(), 3);
}

TEST_F(DoublyLinkedListTestInteger, ValueAtTest)
{
  EXPECT_EQ(list4.value_at(0), 4);
  EXPECT_EQ(list4.value_at(1), 5);
  EXPECT_EQ(list4.value_at(2), 6);
  list4.pop_back();
  EXPECT_EQ(list4.value_at(0), 4);
  EXPECT_EQ(list4.value_at(1), 5);
  list4.pop_front();
  EXPECT_EQ(list4.value_at(0), 5);
}

TEST_F(DoublyLinkedListTestInteger, PushFrontTest)
{
  list1.push_front(10);
  EXPECT_EQ(list1.size(), 1);
  EXPECT_EQ(list1.value_at(0), 10);
  list4.push_front(10);
  EXPECT_EQ(list4.size(), 4);
  EXPECT_EQ(list4.value_at(0), 10);
  EXPECT_EQ(list4.value_at(1), 4);
  EXPECT_EQ(list4.value_at(2), 5);
  EXPECT_EQ(list4.value_at(3), 6);
}

TEST_F(DoublyLinkedListTestInteger, PopFrontTest)
{
  EXPECT_EQ(list2.pop_front(), 1);
  EXPECT_EQ(list2.size(), 0);
  EXPECT_EQ(list3.pop_front(), 2);
  EXPECT_EQ(list3.size(), 1);
  EXPECT_EQ(list3.pop_front(), 3);
  EXPECT_EQ(list3.size(), 0);
}

TEST_F(DoublyLinkedListTestInteger, PushBackTest)
{
  list1.push_back(10);
  EXPECT_EQ(list1.value_at(0), 10);
  EXPECT_EQ(list1.size(), 1);
  list2.push_back(10);
  list2.push_back(11);
  EXPECT_EQ(list2.value_at(0), 1);
  EXPECT_EQ(list2.value_at(1), 10);
  EXPECT_EQ(list2.value_at(2), 11);
  EXPECT_EQ(list2.size(), 3);
}

TEST_F(DoublyLinkedListTestInteger, PopBackTest)
{
  EXPECT_EQ(list2.pop_back(), 1);
  EXPECT_EQ(list2.size(), 0);
  EXPECT_EQ(list3.pop_back(), 3);
  EXPECT_EQ(list3.size(), 1);
  EXPECT_EQ(list3.pop_back(), 2);
  EXPECT_EQ(list3.size(), 0);
}

TEST_F(DoublyLinkedListTestInteger, FrontTest)
{
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list3.front(), 2);
  list3.pop_front();
  EXPECT_EQ(list3.front(), 3);
  EXPECT_EQ(list4.front(), 4);
  list4.pop_back();
  EXPECT_EQ(list4.front(), 4);
}

TEST_F(DoublyLinkedListTestInteger, BackTest)
{
  EXPECT_EQ(list2.back(), 1);
  EXPECT_EQ(list3.back(), 3);
  list3.pop_back();
  EXPECT_EQ(list3.back(), 2);
  EXPECT_EQ(list4.back(), 6);
  list4.pop_front();
  EXPECT_EQ(list4.back(), 6);
}

TEST_F(DoublyLinkedListTestInteger, InsertTest)
{
  list4.insert(1, 10);
  EXPECT_EQ(list4.size(), 4);
  EXPECT_EQ(list4.value_at(0), 4);
  EXPECT_EQ(list4.value_at(1), 10);
  EXPECT_EQ(list4.value_at(2), 5);
  EXPECT_EQ(list4.value_at(3), 6);
  list4.insert(0, 11);
  EXPECT_EQ(list4.size(), 5);
  EXPECT_EQ(list4.value_at(0), 11);
  EXPECT_EQ(list4.value_at(1), 4);
  EXPECT_EQ(list4.value_at(2), 10);
  EXPECT_EQ(list4.value_at(3), 5);
  EXPECT_EQ(list4.value_at(4), 6);
  list4.insert(5, 12);
  EXPECT_EQ(list4.size(), 6);
  EXPECT_EQ(list4.value_at(0), 11);
  EXPECT_EQ(list4.value_at(1), 4);
  EXPECT_EQ(list4.value_at(2), 10);
  EXPECT_EQ(list4.value_at(3), 5);
  EXPECT_EQ(list4.value_at(4), 6);
  EXPECT_EQ(list4.value_at(5), 12);
}

TEST_F(DoublyLinkedListTestInteger, EraseTest)
{
  list4.erase(1);
  EXPECT_EQ(list4.size(), 2);
  EXPECT_EQ(list4.value_at(0), 4);
  EXPECT_EQ(list4.value_at(1), 6);
  list4.erase(0);
  EXPECT_EQ(list4.size(), 1);
  EXPECT_EQ(list4.value_at(0), 6);
  list4.erase(0);
  EXPECT_EQ(list4.size(), 0);
}

TEST_F(DoublyLinkedListTestInteger, ValueNFromEndTest)
{
  list4.push_back(10);
  EXPECT_EQ(list4.value_n_from_end(1), 10);
  EXPECT_EQ(list4.value_n_from_end(2), 6);
  EXPECT_EQ(list4.value_n_from_end(3), 5);
  EXPECT_EQ(list4.value_n_from_end(4), 4);
}

TEST_F(DoublyLinkedListTestInteger, ReverseTest)
{
  list4.push_back(10);
  list4.reverse();
  EXPECT_EQ(list4.size(), 4);
  EXPECT_EQ(list4.value_at(0), 10);
  EXPECT_EQ(list4.value_at(1), 6);
  EXPECT_EQ(list4.value_at(2), 5);
  EXPECT_EQ(list4.value_at(3), 4);
}

TEST_F(DoublyLinkedListTestInteger, RemoveValueTest)
{
  list4.push_back(5);
  list4.remove_value(5);
  EXPECT_EQ(list4.size(), 3);
  EXPECT_EQ(list4.value_at(0), 4);
  EXPECT_EQ(list4.value_at(1), 6);
  EXPECT_EQ(list4.value_at(2), 5);
  list4.remove_value(4);
  EXPECT_EQ(list4.size(), 2);
  EXPECT_EQ(list4.value_at(0), 6);
  EXPECT_EQ(list4.value_at(1), 5);
  list4.remove_value(7);
  EXPECT_EQ(list4.size(), 2);
  EXPECT_EQ(list4.value_at(0), 6);
  EXPECT_EQ(list4.value_at(1), 5);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
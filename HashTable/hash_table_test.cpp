/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Thursday, 7th January, 2021
 *  @description  : Source file for Hash Table Unit Testitng using GTest 
 *  @file         : hash_table_test.cpp
 */

#include "hash_table.h"
#include <gtest/gtest.h>

TEST(HashTableTest, AllTests)
{
  HashTable ht;
  ht.insert_item("Ankush", 1);
  ht.insert_item("Ayush", 2);
  ht.insert_item("Vivek", 3);
  ht.insert_item("jyoti", 4);
  ht.insert_item("Ankush1", 5);
  ht.insert_item("Ayush1", 6);
  ht.insert_item("Vivek1", 7);
  ht.insert_item("jyoti1", 8);
  ht.insert_item("Ankush2", 9);
  ht.insert_item("Ayush2", 10);
  ht.insert_item("Vivek2", 11);
  ht.insert_item("jyoti2", 12);
  ht.insert_item("Ankush3",13);
  ht.insert_item("Ayush3", 14);
  ht.insert_item("Vivek3", 15);
  ASSERT_EQ(ht.size(), 15);
  ht.delete_item("Ankush");
  ASSERT_EQ(ht.size(), 14);
  ASSERT_TRUE(ht.exists_item("Vivek"));
  ASSERT_EQ(ht.search_item("Vivek"), 3);
  ASSERT_FALSE(ht.exists_item("Ankush"));
  ASSERT_EQ(ht.search_item("Ankush"), -1);
  ht.delete_item("Ayush");
  ASSERT_EQ(ht.size(), 13);
  ht.delete_item("Vivek");
  ASSERT_EQ(ht.size(), 12);
  ht.delete_item("jyoti");
  ASSERT_EQ(ht.size(), 11);
  ht.delete_item("Ankush1");
  ASSERT_EQ(ht.size(), 10);
  ht.delete_item("Ayush1");
  ASSERT_EQ(ht.size(), 9);
  ht.delete_item("Vivek1");
  ASSERT_EQ(ht.size(), 8);
  ht.delete_item("jyoti1");
  ASSERT_EQ(ht.size(), 7);
  ht.delete_item("Ankush2");
  ASSERT_EQ(ht.size(), 6);
  ht.delete_item("Ayush2");
  ASSERT_EQ(ht.size(), 5);
  ht.delete_item("Vivek2");
  ASSERT_EQ(ht.size(), 4);
  ht.delete_item("jyoti2");
  ASSERT_EQ(ht.size(), 3);
  ht.delete_item("Ankush3");
  ASSERT_EQ(ht.size(), 2);
  ht.delete_item("Ayush3");
  ASSERT_EQ(ht.size(), 1);
  ht.delete_item("Vivek3");
  ASSERT_EQ(ht.size(), 0);
  ASSERT_FALSE(ht.exists_item("Ankush"));
  ASSERT_FALSE(ht.exists_item("Ayush"));
  ASSERT_FALSE(ht.exists_item("Vivek"));
  ASSERT_FALSE(ht.exists_item("jyoti"));
  ASSERT_FALSE(ht.exists_item("Ankush1"));
  ASSERT_FALSE(ht.exists_item("Ayush1"));
  ASSERT_FALSE(ht.exists_item("Vivek1"));
  ASSERT_FALSE(ht.exists_item("jyoti1"));
  ASSERT_FALSE(ht.exists_item("Ankush2"));
  ASSERT_FALSE(ht.exists_item("Ayush2"));
  ASSERT_FALSE(ht.exists_item("Vivek2"));
  ASSERT_FALSE(ht.exists_item("jyoti2"));
  ASSERT_FALSE(ht.exists_item("Ankush3"));
  ASSERT_FALSE(ht.exists_item("Ayush3"));
  ASSERT_FALSE(ht.exists_item("Vivek3"));
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
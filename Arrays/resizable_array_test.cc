/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 19th May, 2019
 *  @description  : Source file for Resizable Array Class Unit Testitng using GTest 
 *  @file         : resizable_array_test.cpp
 */

#include "resizable_array.h"
#include <gtest/gtest.h>

TEST(ResizableArrayTest, ConstructorTest)
{
  ResizableArray resizable_array;
  ASSERT_EQ(resizable_array.size(), 0);
  ASSERT_EQ(resizable_array.capacity(), kMinArraySize);
}

TEST(ResizableArrayTest, ConstructorCapacityTest)
{
  ResizableArray resizable_array(25);
  ASSERT_EQ(resizable_array.size(), 0);
  ASSERT_EQ(resizable_array.capacity(), 25);
}

TEST(ResizableArrayTest, IsEmptyTest)
{
  ResizableArray resizable_array;
  ASSERT_TRUE(resizable_array.isEmpty());
  resizable_array.push(5);
  ASSERT_FALSE(resizable_array.isEmpty());
  resizable_array.pop();
  ASSERT_TRUE(resizable_array.isEmpty());
  resizable_array.pop();
  ASSERT_TRUE(resizable_array.isEmpty());
}

TEST(ResizableArrayTest, AtTest)
{
  ResizableArray resizable_array;
  resizable_array.push(5);
  ASSERT_EQ(resizable_array.at(2), kErrorValue);
  resizable_array.push(7);
  resizable_array.push(8);
  ASSERT_EQ(resizable_array.at(0), 5);
  ASSERT_EQ(resizable_array.at(1), 7);
  ASSERT_EQ(resizable_array.at(2), 8);
  ASSERT_EQ(resizable_array.at(-1), kErrorValue);
  ASSERT_EQ(resizable_array.at(3), kErrorValue);
  ASSERT_EQ(resizable_array.at(5), kErrorValue);
}

TEST(ResizableArrayTest, PushTest)
{
  ResizableArray resizable_array;
  for(int i = 0; i < kMinArraySize; i++){
    resizable_array.push(i);
  }
  ASSERT_EQ(resizable_array.size(), kMinArraySize);
  ASSERT_EQ(resizable_array.capacity(), kMinArraySize);
  resizable_array.push(20);
  ASSERT_EQ(resizable_array.size(), kMinArraySize + 1);
  ASSERT_EQ(resizable_array.capacity(), kMinArraySize * kMultiplyFactor);
  ASSERT_EQ(resizable_array.at(kMinArraySize), 20);
}

TEST(ResizableArrayTest, InsertTest)
{
  ResizableArray resizable_array;
  for (int i = 0; i < kMinArraySize; i++)
  {
    resizable_array.push(i);
  }
  ASSERT_EQ(resizable_array.size(), kMinArraySize);
  ASSERT_EQ(resizable_array.capacity(), kMinArraySize);
  resizable_array.insert(kMinArraySize - 2, 20);
  ASSERT_EQ(resizable_array.at(kMinArraySize - 2), 20);
  ASSERT_EQ(resizable_array.at(kMinArraySize - 1), kMinArraySize - 2);
  ASSERT_EQ(resizable_array.at(kMinArraySize), kMinArraySize - 1);
  ASSERT_EQ(resizable_array.size(), kMinArraySize + 1);
  ASSERT_EQ(resizable_array.capacity(), kMinArraySize * kMultiplyFactor);
}

TEST(ResizableArrayTest, PrependTest)
{
  ResizableArray resizable_array;
  resizable_array.push(5);
  resizable_array.push(7);
  resizable_array.push(8);
  resizable_array.prepend(20);
  ASSERT_EQ(resizable_array.at(0), 20);
  ASSERT_EQ(resizable_array.at(1), 5);
  ASSERT_EQ(resizable_array.at(2), 7);
  ASSERT_EQ(resizable_array.at(3), 8);
  ASSERT_EQ(resizable_array.size(), 4);
}

TEST(ResizableArrayTest, PopTest)
{
  ResizableArray resizable_array;
  resizable_array.push(5);
  resizable_array.push(7);
  resizable_array.push(8);
  ASSERT_EQ(resizable_array.pop(), 8);
  ASSERT_EQ(resizable_array.pop(), 7);
  ASSERT_EQ(resizable_array.pop(), 5);
  ASSERT_EQ(resizable_array.pop(), kErrorValue);
}

TEST(ResizableArrayTest, DeleteAtTest)
{
  ResizableArray resizable_array;
  resizable_array.push(5);
  resizable_array.push(7);
  resizable_array.push(8);
  resizable_array.push(20);
  resizable_array.deleteAt(1);
  ASSERT_EQ(resizable_array.at(0), 5);
  ASSERT_EQ(resizable_array.at(1), 8);
  ASSERT_EQ(resizable_array.at(2), 20);
  ASSERT_EQ(resizable_array.size(), 3);
  resizable_array.deleteAt(3);
  ASSERT_EQ(resizable_array.size(), 3);
  resizable_array.deleteAt(2);
  ASSERT_EQ(resizable_array.at(0), 5);
  ASSERT_EQ(resizable_array.at(1), 8);
  ASSERT_EQ(resizable_array.size(), 2);
}

TEST(ResizableArrayTest, RemoveTest)
{
  ResizableArray resizable_array;
  resizable_array.push(5);
  resizable_array.push(7);
  resizable_array.push(8);
  resizable_array.push(7);
  resizable_array.push(9);
  resizable_array.push(7);
  resizable_array.remove(7);
  ASSERT_EQ(resizable_array.at(0), 5);
  ASSERT_EQ(resizable_array.at(1), 8);
  ASSERT_EQ(resizable_array.at(2), 9);
  ASSERT_EQ(resizable_array.size(), 3);
  resizable_array.remove(7);
  ASSERT_EQ(resizable_array.at(0), 5);
  ASSERT_EQ(resizable_array.at(1), 8);
  ASSERT_EQ(resizable_array.at(2), 9);
  ASSERT_EQ(resizable_array.size(), 3);
}

TEST(ResizableArrayTest, FindTest)
{
  ResizableArray resizable_array;
  resizable_array.push(5);
  resizable_array.push(7);
  resizable_array.push(8);
  resizable_array.push(7);
  resizable_array.push(9);
  resizable_array.push(7);
  ASSERT_EQ(resizable_array.find(5), 0);
  ASSERT_EQ(resizable_array.find(7), 1);
  ASSERT_EQ(resizable_array.find(8), 2);
  ASSERT_EQ(resizable_array.find(9), 4);
  ASSERT_EQ(resizable_array.find(20), -1);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
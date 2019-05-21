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

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
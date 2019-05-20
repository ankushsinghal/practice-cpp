/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 19th May, 2019
 *  @description  : Source file for Resizable Array Class Unit Testitng using GTest 
 *  @file         : resizable_array_test.cpp
 */

#include "resizable_array.h"
#include <gtest/gtest.h>

TEST(ResizableArrayTest, InitializationTest){
    ResizableArray resizable_array;
    ASSERT_EQ(resizable_array.size(), 0);
    ASSERT_EQ(resizable_array.capacity(), 16);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
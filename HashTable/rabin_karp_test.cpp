/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Thursday, 7th January, 2021
 *  @description  : Source file for Rabin Karp Unit Testitng using GTest 
 *  @file         : rabin_karp_test.cpp
 */

#include "rabin_karp.h"
#include <gtest/gtest.h>

TEST(RabinKarpTest, SearchTest1)
{
	RabinKarp rk;
	string text = "AABAACAADAABAABA";
	string substring = "AABA";
	vector<int> answer = rk.substring_search(text, substring, 29);
	ASSERT_EQ(answer.size(), 3);
	ASSERT_EQ(answer[0], 0);
	ASSERT_EQ(answer[1], 9);
	ASSERT_EQ(answer[2], 12);
}

TEST(RabinKarpTest, SearchTest2)
{
	RabinKarp rk;
	string text = "THIS IS A TEST TEXT";
	string substring = "TEST";
	vector<int> answer = rk.substring_search(text, substring, 29);
	ASSERT_EQ(answer.size(), 1);
	ASSERT_EQ(answer[0], 10);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Monday, 4th January, 2021
 *  @description  : Source file for Queue Class Unit Testitng using GTest 
 *  @file         : queue_test.cpp
 */

#include "queue.h"
#include <gtest/gtest.h>

TEST(QueueTest, ConstructorTest)
{
	Queue<int> q;
	EXPECT_TRUE(q.empty());
}

TEST(QueueTest, EmptyTest)
{
	Queue<int> q;
	q.enqueue(1);
	EXPECT_FALSE(q.empty());
	q.enqueue(2);
	q.dequeue();
	EXPECT_FALSE(q.empty());
	q.dequeue();
	EXPECT_TRUE(q.empty());
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.dequeue();
	q.dequeue();
	EXPECT_FALSE(q.empty());
	q.dequeue();
	EXPECT_FALSE(q.empty());
	q.dequeue();
	EXPECT_TRUE(q.empty());
}

TEST(QueueTest, FullTest)
{
	Queue<int> q;
	q.enqueue(1);
	EXPECT_FALSE(q.full());
	q.enqueue(2);
	EXPECT_FALSE(q.full());
	q.enqueue(3);
	q.enqueue(4);
	EXPECT_TRUE(q.full());
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.enqueue(5);
	q.enqueue(6);
	EXPECT_FALSE(q.full());
	q.enqueue(7);
	q.enqueue(8);
	EXPECT_TRUE(q.full());
}

TEST(QueueTest, EnqueueAndDequeueTest)
{
	Queue<int> q;
	q.enqueue(1);
	EXPECT_EQ(q.at(0), 1);
	q.enqueue(2);
	EXPECT_EQ(q.at(1), 2);
	q.enqueue(3);
	EXPECT_EQ(q.at(2), 3);
	EXPECT_EQ(q.dequeue(), 1);
	EXPECT_EQ(q.dequeue(), 2);
	q.enqueue(4);
	EXPECT_EQ(q.at(3), 4);
	q.enqueue(5);
	EXPECT_EQ(q.at(4), 5);
	EXPECT_EQ(q.dequeue(), 3);
	EXPECT_EQ(q.dequeue(), 4);
	q.enqueue(6);
	EXPECT_EQ(q.at(0), 6);
	q.enqueue(7);
	EXPECT_EQ(q.at(1), 7);
	EXPECT_EQ(q.dequeue(), 5);
	EXPECT_EQ(q.dequeue(), 6);
	EXPECT_EQ(q.dequeue(), 7);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Monday, 11th January, 2021
 *  @description  : Source file for Binary Search Tree Class Unit Testitng using GTest 
 *  @file         : binary_search_tree_test.cpp
 */

#include "binary_search_tree.h"
#include <gtest/gtest.h>

class BinarySearchTreeTestInteger : public ::testing::Test
{
 protected:
  BinarySearchTree<int> bst;
  void SetUp() override
  {
    // Tree taken from 
    // http://lcm.csa.iisc.ernet.in/dsa/node91.html#:~:text=An%20Example%3A%20Figure%204.14%20shows,sorted%20sequence%20of%20the%20values.
    bst.insert(17);
    bst.insert(13);
    bst.insert(21);
    bst.insert(15);
    bst.insert(10);
    bst.insert(16);
    bst.insert(4);
    bst.insert(11);
    bst.insert(24);
    bst.insert(27);
    bst.insert(23);
    bst.insert(25);
    bst.insert(26);
  }
};

TEST(BinarySearchTreeTest, ConstructorTest)
{
  BinarySearchTree<int> bst;
  ASSERT_EQ(bst.get_node_count(), 0);
  ASSERT_EQ(bst.get_root(), nullptr);
}

TEST(BinarySearchTreeTest, InsertTest)
{
  BinarySearchTree<int> bst;
  bst.insert(50);
  bst.insert(30);
  bst.insert(20);
  bst.insert(40);
  bst.insert(70);
  bst.insert(60);
  bst.insert(80);
  ASSERT_EQ(bst.get_node_count(), 7);
  Node<int> *a = bst.get_root();
  ASSERT_EQ(a->get_data(), 50);
  Node<int> *b = a->get_left();
  Node<int> *c = a->get_right();
  ASSERT_EQ(b->get_data(), 30);
  ASSERT_EQ(c->get_data(), 70);
  Node<int> *d = b->get_left();
  Node<int> *e = b->get_right();
  ASSERT_EQ(d->get_data(), 20);
  ASSERT_EQ(e->get_data(), 40);
  Node<int> *f = c->get_left();
  Node<int> *g = c->get_right();
  ASSERT_EQ(f->get_data(), 60);
  ASSERT_EQ(g->get_data(), 80);
}

TEST_F(BinarySearchTreeTestInteger, GetNodeCountTest)
{
  ASSERT_EQ(bst.get_node_count(), 13);
}

TEST_F(BinarySearchTreeTestInteger, DeleteTreeTest)
{
  bst.delete_tree();
  ASSERT_EQ(bst.get_node_count(), 0);
  ASSERT_EQ(bst.get_root(), nullptr);
}

TEST_F(BinarySearchTreeTestInteger, IsInTreeTest)
{
  ASSERT_TRUE(bst.is_in_tree(23));
  ASSERT_TRUE(bst.is_in_tree(26));
  ASSERT_TRUE(bst.is_in_tree(17));
  ASSERT_TRUE(bst.is_in_tree(13));
  ASSERT_FALSE(bst.is_in_tree(12));
}

TEST_F(BinarySearchTreeTestInteger, GetHeightTest)
{
  ASSERT_EQ(bst.get_height(), 6);
}

TEST_F(BinarySearchTreeTestInteger, GetMinTest)
{
  ASSERT_EQ(bst.get_min(), 4);
}

TEST_F(BinarySearchTreeTestInteger, GetMaxTest)
{
  ASSERT_EQ(bst.get_max(), 27);
}

TEST_F(BinarySearchTreeTestInteger, IsBinarySearchTreeTest)
{
  ASSERT_TRUE(bst.is_binary_search_tree());
}

TEST_F(BinarySearchTreeTestInteger, DeleteValueTest)
{
  bst.delete_value(4);
  ASSERT_EQ(bst.get_node_count(), 12);
  Node<int> *a = bst.get_root();
  Node<int> *b = a->get_left();
  Node<int> *c = b->get_left();
  ASSERT_EQ(c->get_left(), nullptr);
  
  bst.delete_value(10);
  ASSERT_EQ(bst.get_node_count(), 11);
  a = bst.get_root();
  b = a->get_left();
  c = b->get_left();
  ASSERT_NE(c, nullptr);
  ASSERT_EQ(c->get_data(), 11);
  
  bst.delete_value(27);
  ASSERT_EQ(bst.get_node_count(), 10);
  a = bst.get_root();
  b = a->get_right();
  c = b->get_right();
  Node<int> *d = c->get_right();
  ASSERT_NE(d, nullptr);
  ASSERT_EQ(d->get_data(), 25);
  Node<int> *e = d->get_right();
  ASSERT_NE(e, nullptr);
  ASSERT_EQ(e->get_data(), 26);

  bst.delete_value(13);
  ASSERT_EQ(bst.get_node_count(), 9);
  a = bst.get_root();
  b = a->get_left();
  ASSERT_NE(b, nullptr);
  ASSERT_EQ(b->get_data(), 15);
  c = b->get_left();
  d = b->get_right();
  ASSERT_NE(c, nullptr);
  ASSERT_EQ(c->get_data(), 11);
  ASSERT_NE(d, nullptr);
  ASSERT_EQ(d->get_data(), 16);
}

TEST_F(BinarySearchTreeTestInteger, GetSuccessorTest)
{
  ASSERT_EQ(bst.get_successor(15), 16);
  ASSERT_EQ(bst.get_successor(11), 13);
  ASSERT_EQ(bst.get_successor(26), 27);
  ASSERT_EQ(bst.get_successor(4), 10);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
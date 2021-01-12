/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Monday, 11th January, 2021
 *  @description  : Header file for Binary Search Tree Class
 *  @file         : binary_search_tree.h
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
#include <stdio.h>
#include <malloc.h>

template <class T>
class Node
{
 private:
  T data_;
  Node *left_;
  Node *right_;
 
 public:
  Node(T data);
  void set_data(T data);
  void set_left(Node<T> *left);
  void set_right(Node<T> *right);
  T get_data();
  Node<T> *get_left();
  Node<T> *get_right();
};

template <class T>
class BinarySearchTree
{
 private:
  Node<T> *root_;
  int size_;

 public:

  // defualt constructor
  BinarySearchTree();

  // insert value into tree
  void insert(T value);
  Node<T> *insertUtil(Node<T> *root, T value);

  // get count of values stored
  int get_node_count();

  // prints the values in the tree, from min to max
  void print_values();

  // deletes the entire tree
  void delete_tree();
  
  // returns true if given value exists in the tree
  bool is_in_tree(T value);

  // returns the height in nodes (single node's height is 1)
  int get_height();

  // returns the minimum value stored in the tree
  T get_min();

  // returns the maximum value stored in the tree
  T get_max();

  // returns true if the tree is a binary search tree
  bool is_binary_search_tree();

  // deletes the value from the tree
  void delete_value(T value);

  // returns next-highest value in tree after given value, -1 if none
  T get_successor(T value);

  // returns root node - Only for testing purposes
  Node<T> *get_root();
};



template <class T>
Node<T>::Node(T data)
{
  data_ = data;
  left_ = NULL;
  right = NULL;
}

template <class T>
void Node<T>::set_data(T data)
{
  data_ = data;
}

template <class T>
void Node<T>::set_left(Node *left)
{
  left_ = left;
}

template <class T>
void Node<T>::set_right(Node *right)
{
  right_ = right;
}

template <class T>
T Node<T>::get_data()
{
  return data_;
}

template <class T>
Node<T> *Node<T>::get_left()
{
  return left_;
}

template <class T>
Node<T> *Node<T>::get_right()
{
  return right_;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
  root_ = NULL;
  size_ = 0;
}

template <class T>
int BinarySearchTree<T>::get_node_count()
{
  return size_;
}

template <class T>
void BinarySearchTree<T>::insert(T value)
{
  insertUtil(root_);
}

template <class T>
Node<T> *BinarySearchTree<T>::insertUtil(Node<T> *root, T value)
{
  if (root = NULL)
  {
    root = new Node<T>::Node(value);
  }
  else if (value < root->get_left())
  {
    root->set_left(insertUtil(root->get_left(), value));
  }
  else
  {
    root->set_right(insertUtil(root->get_right()), value);
  }
  return root;
}

#pragma GCC diagnostic pop

#endif //BINARY_SEARCH_TREE_H
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
  voif set_data(T data);
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
  insert(T value);

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

#pragma GCC diagnostic pop

#endif //BINARY_SEARCH_TREE_H
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
#include <algorithm>

template <class T>
class Node
{
 private:
  T data_;
  Node<T> *left_;
  Node<T> *right_;
 
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

  void insertUtil(Node<T> **root, T value);
  Node<T> *deleteValueUtil(Node<T> *root, T value);
  T getMinUtil(Node<T> *root);
  T getMaxUtil(Node<T> *root);
  bool isBinarySearchTreeUtil(Node<T> *root);
  bool isInTreeUtil(Node<T> *root, T value);
  int getHeightUtil(Node<T> *root);
  void printValuesUtil(Node<T> *root);
  Node<T> *findNode(Node<T> *root, T value);
  void deleteTreeUtil(Node<T> **root);

 public:

  // defualt constructor
  BinarySearchTree();

  // insert value into tree
  void insert(T value);

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

  // returns next-highest value in tree after given value
  T get_successor(T value);

  // returns root node - Only for testing purposes
  Node<T> *get_root();
};


template <class T>
Node<T> *BinarySearchTree<T>::get_root()
{
  return root_;
}

template <class T>
Node<T>::Node(T data)
{
  data_ = data;
  left_ = NULL;
  right_ = NULL;
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
  insertUtil(&root_, value);
}

template <class T>
void BinarySearchTree<T>::insertUtil(Node<T> **root, T value)
{
  if ((*root) == NULL)
  {
    (*root) = new Node<T>(value);
    size_++;
  }
  else if (value < (*root)->get_data())
  {
    Node<T> *temp_left = (*root)->get_left();
    if (temp_left == NULL)
    {
      (*root)->set_left(new Node<T>(value));
      size_++;
    }
    else
    {
      insertUtil(&temp_left, value);
    }
  }
  else
  {
    Node<T> *temp_right = (*root)->get_right();
    if (temp_right == NULL)
    {
      (*root)->set_right(new Node<T>(value));
      size_++;
    }
    else
    {
      insertUtil(&temp_right, value);
    }
  }
}

template <class T>
T BinarySearchTree<T>::get_min()
{
  return getMinUtil(root_);
}

template <class T>
T BinarySearchTree<T>::getMinUtil(Node<T> *root)
{
  if (root != NULL)
  {
    if (root->get_left() == NULL)
    {
      return root->get_data();
    }
    else
    {
      return getMinUtil(root->get_left());
    }
  }
}

template <class T>
T BinarySearchTree<T>::get_max()
{
  return getMaxUtil(root_);
}

template <class T>
T BinarySearchTree<T>::getMaxUtil(Node<T> *root)
{
  if (root != NULL)
  {
    if (root->get_right() == NULL)
    {
      return root->get_data();
    }
    else
    {
      return getMaxUtil(root->get_right());
    }
  }
}

template <class T>
void BinarySearchTree<T>::delete_value(T value)
{
  deleteValueUtil(root_, value);
}

template <class T>
Node<T> *BinarySearchTree<T>::deleteValueUtil(Node<T> *root, T value)
{
  if (root != NULL)
  {
    if (value == root->get_data())
    {
      if (root->get_left() == NULL && root->get_right() == NULL)
      {
        delete root;
        root = NULL;
        size_--;
      }
      else if (root->get_left() == NULL)
      {
        Node<T> *temp_right = root->get_right();
        delete root;
        root = temp_right;
        size_--;
      }
      else if (root->get_right() == NULL)
      {
        Node<T> *temp_left = root->get_left();
        delete root;
        root = temp_left;
        size_--;
      }
      else
      {
        T new_root_value = getMinUtil(root->get_right());
        delete_value(new_root_value);
        root->set_data(new_root_value);
      }
    }
    else if (value < root->get_data())
    {
      Node<T> *temp_left = root->get_left();
      root->set_left(deleteValueUtil(temp_left, value));
    }
    else
    {
      Node<T> *temp_right = root->get_right();
      root->set_right(deleteValueUtil(temp_right, value));
    }
  }
  return root;
}

template <class T>
bool BinarySearchTree<T>::is_binary_search_tree()
{
  return isBinarySearchTreeUtil(root_);
}

template <class T>
bool BinarySearchTree<T>::isBinarySearchTreeUtil(Node<T> *root)
{
  if (root == NULL)
  {
    return true;
  }
  else
  {
    Node<T> *temp_left = root->get_left();
    Node<T> *temp_right = root->get_right();
    bool left_less, right_more;
    if (temp_left)
    {
      if (temp_left->get_data() < root->get_data())
      {
        left_less = true;
      }
      else
      {
        left_less = false;
      }
    }
    else
    {
      left_less = true;
    }
    if (temp_right)
    {
      if (temp_right->get_data() >= root->get_data())
      {
        right_more = true;
      }
      else
      {
        right_more = false;
      }
    }
    else
    {
      right_more = true;
    }
    
    if (left_less && right_more && isBinarySearchTreeUtil(temp_left) && isBinarySearchTreeUtil(temp_right))
    {
      return true;
    }
    return false;
  }
}

template <class T>
bool BinarySearchTree<T>::is_in_tree(T value)
{
  return isInTreeUtil(root_, value);
}

template <class T>
bool BinarySearchTree<T>::isInTreeUtil(Node<T> *root, T value)
{
  if (root == NULL)
  {
    return false;
  }
  else
  {
    if (value == root->get_data())
    {
      return true;
    }
    else if (value < root->get_data())
    {
      return isInTreeUtil(root->get_left(), value);
    }
    else
    {
      return isInTreeUtil(root->get_right(), value);
    }
  }
}

template <class T>
int BinarySearchTree<T>::get_height()
{
  return getHeightUtil(root_);
}

template <class T>
int BinarySearchTree<T>::getHeightUtil(Node<T> *root)
{
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    if (root->get_left() == NULL && root->get_right() == NULL)
    {
      return 1;
    }
    else
    {
      int left_height = getHeightUtil(root->get_left());
      int right_height = getHeightUtil(root->get_right());
      return 1 + std::max(left_height, right_height);
    }
  }
}

template <class T>
void BinarySearchTree<T>::print_values()
{
  printValuesUtil(root_);
}

template <class T>
void BinarySearchTree<T>::printValuesUtil(Node<T> *root)
{
  if (root != NULL)
  {
    printValuesUtil(root->get_left());
    printf("%d ", root->get_data());
    printValuesUtil(root->get_right());
  }
}

template <class T>
Node<T> *BinarySearchTree<T>::findNode(Node<T> *root, T value)
{
  if (root == NULL)
  {
    return NULL;
  }
  else
  {
    if (value == root->get_data())
    {
      return root;
    }
    else if (value < root->get_data())
    {
      return findNode(root->get_left(), value);
    }
    else
    {
      return findNode(root->get_right(), value);
    }
  }
}

template <class T>
T BinarySearchTree<T>::get_successor(T value)
{
  Node<T> *current_node = findNode(root_, value);
  if (current_node != NULL)
  {
    if (current_node->get_right() != NULL)
    {
      return getMinUtil(current_node->get_right());
    }
    else
    {
      Node<T> *successor_node = NULL;
      Node<T> *ancestor_node = root_;
      while (ancestor_node != current_node)
      {
        if (current_node->get_data() < ancestor_node->get_data())
        {
          successor_node = ancestor_node;
          ancestor_node = ancestor_node->get_left();
        }
        else
        {
          ancestor_node = ancestor_node->get_right();
        }
      }
      if (successor_node != NULL)
      {
        return successor_node->get_data();
      }
    }
  }
}

template <class T>
void BinarySearchTree<T>::delete_tree()
{
  deleteTreeUtil(&root_);
}

template <class T>
void BinarySearchTree<T>::deleteTreeUtil(Node<T> **root)
{
  if (root != NULL)
  {
    Node<T> *temp_left = (*root)->get_left();
    Node<T> *temp_right = (*root)->get_right();
    if (temp_left)
    {
      deleteTreeUtil(&temp_left);
    }
    if (temp_right)
    {
      deleteTreeUtil(&temp_right);
    }
    delete (*root);
    (*root) = NULL;
    size_--;
  }
}

#pragma GCC diagnostic pop

#endif //BINARY_SEARCH_TREE_H
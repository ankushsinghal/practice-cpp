/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Saturday, 2nd January, 2021
 *  @description  : Header file for Singly Linked List Class
 *  @file         : singly_linked_list.h
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include <stdio.h>
#include <malloc.h>

template <class T>
class Node
{
 private:
  // The data object of DataType T present at the Node
  T data_;

  // The pointer to the next Node of DataType T
  Node *next_;

 public:
  // Default Constructor for Node
  Node();

  // Constructor with data for Node
  Node(T data);

  // Setter for Node data
  void setData(T data);

  // Getter for Node data
  T getData();

  // Setter for Node next pointer
  void setNext(Node *next);

  // Getter for Node next pointer
  Node *getNext();
};

template <class T>
class SinglyLinkedList
{
 private:
  // The head of the linked list
  Node<T> *head_;

  // The size counter of the linked list
  int size_;

 public:
  // Default Constructor for SinglyLinkedList
  SinglyLinkedList();

  // Constructor with head pointer for SinglyLinkedList
  SinglyLinkedList(Node<T> *head);

  // Returns the current size of the linked list
  int size();

  // Returns true if empty
  bool empty();

  // Returns the value of the item at index (starting at 0 for first)
  T value_at(int index);

  // Adds an item to the front of the list
  void push_front(T value);

  // Remove front item and return its value
  T pop_front();

  // Adds an item at the end
  void push_back(T value);

  // Removes end item and returns its value
  T pop_back();

  // Get value of front item
  T front();

  // Get value of end item
  T back();

  // insert value at index, so current item at that index is pointed to by new item at index
  void insert(int index, T value);

  // Removes node at given index
  void erase(int index);

  // Returns the value of the node at nth position from the end of the list
  T value_n_from_end(int index);

  // Reverses the list
  void reverse();

  // Removes the first item in the list with this value
  void remove_value(T value);
};

#endif //SINGLY_LINKED_LIST_H
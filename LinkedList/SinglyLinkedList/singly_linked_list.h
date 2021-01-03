/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Saturday, 2nd January, 2021
 *  @description  : Header file for Singly Linked List Class
 *  @file         : singly_linked_list.h
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
#include <stdio.h>
#include <malloc.h>

template <class T>
class Node
{
 public:
  // The data object of DataType T present at the Node
  T data_;

  // The pointer to the next Node of DataType T
  Node *next_;

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

template <class T>
Node<T>::Node()
{
  next_ = NULL;
}

template <class T>
Node<T>::Node(T data)
{
  data_ = data;
  next_ = NULL;
}

template <class T>
void Node<T>::setData(T data)
{
  data_ = data;
}

template <class T>
T Node<T>::getData()
{
  return data_;
}

template <class T>
void Node<T>::setNext(Node *next)
{
  next_ = next;
}

template <class T>
Node<T> *Node<T>::getNext()
{
  return next_;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  size_ = 0;
  head_ = NULL;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(Node<T> *head)
{
  size_ = 0;
  head_ = head;
}

template <class T>
int SinglyLinkedList<T>::size()
{
  return size_;
}

template <class T>
bool SinglyLinkedList<T>::empty()
{
  if (size_ == 0)
  {
    return true;
  }
  return false;
}

template <class T>
T SinglyLinkedList<T>::value_at(int index)
{
  if (index < size_)
  {
    Node<T> *currentNode = head_;
    for (int i = 0; i < index; i++)
    {
      currentNode = currentNode->getNext();
    }
    return currentNode->getData();
  }
}

template <class T>
void SinglyLinkedList<T>::push_front(T value)
{
  Node<T> *newNode = new Node<T>(value);
  newNode->setNext(head_);
  head_ = newNode;
  size_++;
}

template <class T>
T SinglyLinkedList<T>::pop_front()
{
  if (size_ > 0)
  {
    Node<T> *currentNode = head_;
    T currentData = currentNode->getData();
    head_ = head_->getNext();
    delete currentNode;
    size_--;
    return currentData;
  }
}

template <class T>
void SinglyLinkedList<T>::push_back(T value)
{
  Node<T> *newNode = new Node<T>(value);
  Node<T> **pHead = &head_;
  while (*pHead != NULL)
  {
    pHead = &((*pHead)->next_);
  }
  *pHead = newNode;
  size_++;
}

template <class T>
T SinglyLinkedList<T>::pop_back()
{
  if (size_ > 0)
  {
    Node<T> **pHead = &head_;
    while ((*pHead)->getNext() != NULL)
    {
      pHead = &((*pHead)->next_);
    }
    Node<T> *deleteNode = (*pHead);
    T deleteData = deleteNode->getData();
    delete deleteNode;
    *pHead = NULL;
    size_--;
    return deleteData;
  }
}

template <class T>
T SinglyLinkedList<T>::front()
{
  if (size_ > 0)
  {
    return head_->getData();
  }
}

template <class T>
T SinglyLinkedList<T>::back()
{
  if(size_ > 0)
  {
    Node<T> **pHead = &head_;
    while ((*pHead)->getNext() != NULL)
    {
      pHead = &((*pHead)->next_);
    }
    return (*pHead)->getData();
  }
}

template <class T>
void SinglyLinkedList<T>::insert(int index, T value)
{
  if (index <= size_)
  {
    Node<T> *newNode = new Node<T>(value);
    if (index == 0)
    {
      newNode->setNext(head_);
      head_ = newNode;
    }
    else
    {
      Node<T> *currentNode = head_;
      for (int i = 1; i < index; i++)
      {
        currentNode = currentNode->getNext();
      }
      newNode->setNext(currentNode->getNext());
      currentNode->setNext(newNode);
    }
    size_++;
  }
}

template <class T>
void SinglyLinkedList<T>::erase(int index)
{
  if (index < size_)
  {
    if (index == 0)
    {
      Node<T> *deleteNode = head_;
      head_ = head_->getNext();
      delete deleteNode;
    }
    else
    {
      Node<T> *currentNode = head_;
      for (int i = 1; i < index; i++)
      {
        currentNode = currentNode->getNext();
      }
      Node<T> *deleteNode = currentNode->getNext();
      currentNode->setNext(deleteNode->getNext());
      delete deleteNode;
    }
    size_--;
  }
}

template <class T>
T SinglyLinkedList<T>::value_n_from_end(int index)
{
  if (index <= size_)
  {
    return value_at(size_ - index);
  }
}

template <class T>
void SinglyLinkedList<T>::reverse()
{
  if (size_ > 1)
  {
    Node<T> *prevNode = NULL;
    Node<T> *currentNode = head_;
    Node<T> *nextNode = head_->getNext();
    while (currentNode != NULL)
    {
      currentNode->setNext(prevNode);
      prevNode = currentNode;
      currentNode = nextNode;
      if (nextNode != NULL)
      {
        nextNode = nextNode->getNext();
      }
    }
    head_ = prevNode;
  }
}

template <class T>
void SinglyLinkedList<T>::remove_value(T value)
{
  for (Node<T> **pHead = &head_; *pHead != NULL; pHead = &((*pHead)->next_))
  {
    if ((*pHead)->getData() == value)
    {
      Node<T> *deleteNode = *pHead;
      *pHead = (*pHead)->getNext();
      delete deleteNode;
      size_--;
      break;
    }
  }
}

#pragma GCC diagnostic pop

#endif //SINGLY_LINKED_LIST_H
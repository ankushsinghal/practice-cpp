/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Saturday, 2nd January, 2021
 *  @description  : Header file for Doubly Linked List Class
 *  @file         : doubly_linked_list.h
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

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

  // the pointer to the previous Node of DataType T
  Node *prev_;

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

  // Setter for Node prev pointer
  void setPrev(Node *prev);

  // Getter for Node prev pointer
  Node *getPrev();
};

template <class T>
class DoublyLinkedList
{
 private:
  // The head of the linked list
  Node<T> *head_;

  // The tail of the linked list
  Node<T> *tail_;

  // The size counter of the linked list
  int size_;

 public:
  // Default Constructor for DoublyLinkedList
  DoublyLinkedList();

  // Constructor with head pointer for DoublyLinkedList
  DoublyLinkedList(Node<T> *head);

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
  prev_ = NULL;
}

template <class T>
Node<T>::Node(T data)
{
  data_ = data;
  next_ = NULL;
  prev_ = NULL;
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
void Node<T>::setPrev(Node *prev)
{
  prev_ = prev;
}

template <class T>
Node<T> *Node<T>::getPrev()
{
  return prev_;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size_ = 0;
  head_ = NULL;
  tail_ = NULL;
}

template <class T>
int DoublyLinkedList<T>::size()
{
  return size_;
}

template <class T>
bool DoublyLinkedList<T>::empty()
{
  if (size_ == 0)
  {
    return true;
  }
  return false;
}

template <class T>
T DoublyLinkedList<T>::value_at(int index)
{
  if (index < size_)
  {
    if (index < size_/2)
    {
      Node<T> *currentNode = head_;
      for (int i = 0; i < index; i++)
      {
        currentNode = currentNode->getNext();
      }
      return currentNode->getData();
    }
    else
    {
      int new_index = size_ - 1 - index;
      Node<T> *currentNode = tail_;
      for (int i = 0; i < new_index; i++)
      {
        currentNode = currentNode->getPrev();
      }
      return currentNode->getData();
    }
    
  }
}

template <class T>
void DoublyLinkedList<T>::push_front(T value)
{
  Node<T> *newNode = new Node<T>(value);
  Node<T> *currentNode = head_;
  if (head_ == NULL)
  {
    head_ = newNode;
    tail_ = newNode;
  }
  else
  {
    newNode->setNext(head_);
    head_->setPrev(newNode);
    head_ = newNode;
  }
  size_++;
}

template <class T>
T DoublyLinkedList<T>::pop_front()
{
  if (size_ > 0)
  {
    Node<T> *deleteNode = head_;
    T deleteData = deleteNode->getData();
    head_ = head_->getNext();
    if (head_ == NULL)
    {
      tail_ = NULL;
    }
    else
    {
      head_->setPrev(NULL);
    }
    
    delete deleteNode;
    size_--;
    return deleteData;
  }
}

template <class T>
void DoublyLinkedList<T>::push_back(T value)
{
  Node<T> *newNode = new Node<T>(value);
  Node<T> *currentNode = tail_;
  if (currentNode == NULL)
  {
    tail_ = newNode;
    head_ = newNode;
  }
  else
  {
    currentNode->setNext(newNode);
    newNode->setPrev(currentNode);
    tail_ = newNode;
  }
  size_++;
}

template <class T>
T DoublyLinkedList<T>::pop_back()
{
  if (size_ > 0)
  {
    Node<T> *deleteNode = tail_;
    T deleteData = deleteNode->getData();
    tail_ = tail_->getPrev();
    if (tail_ == NULL)
    {
      head_ = NULL;
    }
    else
    {
      tail_->setNext(NULL);
    }

    delete deleteNode;
    size_--;
    return deleteData;
  }
}

template <class T>
T DoublyLinkedList<T>::front()
{
  if (size_ > 0)
  {
    return head_->getData();
  }
}

template <class T>
T DoublyLinkedList<T>::back()
{
  if(size_ > 0)
  {
    return tail_->getData();
  }
}

template <class T>
void DoublyLinkedList<T>::insert(int index, T value)
{
  if (index <= size_)
  {
    Node<T> *newNode = new Node<T>(value);
    if (index == 0)
    {
      newNode->setNext(head_);
      if (head_ == NULL)
      {
        tail_ = newNode;
      }
      else
      {
        head_->setPrev(newNode);
      }
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
      if (currentNode->getNext() == NULL)
      {
        tail_ = newNode;
      }
      else
      {
        currentNode->getNext()->setPrev(newNode);
      }
      
      currentNode->setNext(newNode);
      newNode->setPrev(currentNode);
    }
    size_++;
  }
}

template <class T>
void DoublyLinkedList<T>::erase(int index)
{
  if (index < size_)
  {
    if (index == 0)
    {
      Node<T> *deleteNode = head_;
      head_ = head_->getNext();
      if (head_ == NULL)
      {
        tail_ = NULL;
      }
      else
      {
        head_->setPrev(NULL);
      }
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
      if (deleteNode->getNext() == NULL)
      {
        tail_ = currentNode;
        currentNode->setNext(NULL);
      }
      else
      {
        currentNode->setNext(deleteNode->getNext());
        deleteNode->getNext()->setPrev(currentNode);
      }
      delete deleteNode;
    }
    size_--;
  }
}

template <class T>
T DoublyLinkedList<T>::value_n_from_end(int index)
{
  if (index <= size_)
  {
    return value_at(size_ - index);
  }
}

template <class T>
void DoublyLinkedList<T>::reverse()
{
  if (size_ > 1)
  {
    Node<T> *currentNode = head_;

    Node<T> *temp = head_;
    head_ = tail_;
    tail_ = temp;
    
    while (currentNode != NULL)
    {
      Node<T> *nextNode = currentNode->getNext();
      Node<T> *prevNode = currentNode->getPrev();
      currentNode->setPrev(nextNode);
      currentNode->setNext(prevNode);
      currentNode = nextNode;
    }
  }
}

template <class T>
void DoublyLinkedList<T>::remove_value(T value)
{
  Node<T> *currentNode = head_;
  while (currentNode != NULL)
  {
    if (currentNode->getData() == value)
    {
      if (currentNode->getPrev() == NULL)
      {
        head_ = currentNode->getNext();
        if (head_ == NULL)
        {
          tail_ == NULL;
        }
        else
        {
          head_->setPrev(NULL);
        }
      }
      else if (currentNode->getNext() == NULL)
      {
        tail_ = currentNode->getPrev();
        if (tail_ == NULL)
        {
          head_ = NULL;
        }
        else
        {
          tail_->setNext(NULL);
        }
      }
      else{
        currentNode->getPrev()->setNext(currentNode->getNext());
        currentNode->getNext()->setPrev(currentNode->getPrev());
      }
      delete currentNode;
      size_--;
      break;
    }
    currentNode = currentNode->getNext();
  }
}

#pragma GCC diagnostic pop

#endif //DOUBLY_LINKED_LIST_H
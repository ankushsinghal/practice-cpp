/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 3rd January, 2021
 *  @description  : Source file for Singly Linked List Class
 *  @file         : singly_linked_list.cpp
 */

#include "singly_linked_list.h"

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
  Node<T> *newNode = new Node<T>::Node(value);
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
  Node<T> *newNode = new Node<T>::Node(value);
  Node<T> **pHead = &head_;
  while (*pHead != NULL)
  {
    pHead = &((*pHead)->getNext());
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
      pHead = &((*pHead)->getNext());
    }
    Node<T> *deleteNode = (*pHead);
    delete deleteNode;
    pHead = NULL;
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
      pHead = &((*pHead)->getNext());
    }
    return (*pHead)->getData();
  }
}

template <class T>
void SinglyLinkedList<T>::insert(int index, T value)
{
  if (index <= size_)
  {
    Node<T> *newNode = new Node<T>::Node(value);
    if (index == 0)
    {
      newNode->setNext_(head_);
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
  if (index < size)
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
  for (Node<T> **pHead = &head_; *pHead != NULL; pHead = &((*pHead)->getNext()))
  {
    if ((*pHead)->getData() == value)
    {
      Node<T> *deleteNode = *pHead;
      *pHead = (*pHead)->getNext();
      delete deleteNode;
    }
  }
}
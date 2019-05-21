/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 19th May, 2019
 *  @description  : Source file for Resizable Array Class
 *  @file         : resizable_array.cpp
 */

#include "resizable_array.h"

ResizableArray::ResizableArray()
{
  this->size_ = 0;
  this->capacity_ = kMinArraySize;
  this->arr_ = new int[this->capacity_];
}

ResizableArray::ResizableArray(int cap)
{
  this->size_ = 0;
  this->capacity_ = cap;
  this->arr_ = new int[this->capacity_];
}

ResizableArray::~ResizableArray()
{
  delete[] this->arr_;
}

int ResizableArray::size()
{
  return this->size_;
}

int ResizableArray::capacity()
{
  return this->capacity_;
}

bool ResizableArray::isEmpty()
{
  if (this->size_ == 0)
  {
    return true;
  }
  return false;
}

int ResizableArray::at(int index)
{
  if (index < 0 || index >= this->size_)
  {
    std::cout << "Index out of bounds!" << std::endl;
    return kErrorValue;
  }
  return *(this->arr_ + index);
}

void ResizableArray::increaseCapacity()
{
  int new_capacity = this->capacity_ * kMultiplyFactor;
  int *new_array = new int[new_capacity];
  for (int i = 0; i < this->capacity_; i++)
  {
    *(new_array + i) = *(this->arr_ + i);
  }
  this->capacity_ = new_capacity;
  delete[] this->arr_;
  this->arr_ = new_array;
}

void ResizableArray::push(int elem)
{
  if (this->size_ >= this->capacity_)
  {
    this->increaseCapacity();
  }
  *(this->arr_ + this->size_) = elem;
  this->size_++;
}

void ResizableArray::insert(int index, int elem)
{
  if (index < 0 || index >= this->size_)
  {
    std::cout << "Index out of bounds!" << std::endl;
    return;
  }
  else
  {
    if (this->size_ >= this->capacity_)
    {
      this->increaseCapacity();
    }
    for (int i = index; i < this->size_; i++)
    {
      *(this->arr_ + i + 1) = *(this->arr_ + i);
    }
    *(this->arr_ + index) = elem;
  }
}

void ResizableArray::prepend(int elem)
{
  this->insert(0, elem);
}

int ResizableArray::pop()
{
  if (this->isEmpty())
  {
    std::cout<<"Nothing to pop!"<<std::endl;
    return kErrorValue;
  } 
  else
  {
    this->size_--;
    return *(this->arr_ + this->size_);
  }
}

void ResizableArray::deleteAt(int index)
{
  if (this->isEmpty())
  {
    std::cout<<"Nothing to delete!"<<std::endl;
    return;
  }
  else if (index >= this->size_)
  {
    std::cout<<"Index out of bounds"<<std::endl;
    return;
  }
  else
  {
    for(int i = index; i < this->size_ - 1; i++){
      *(this->arr_ + i) = *(this->arr_ + i + 1);
    }
    this->size_--;
  }
}

void ResizableArray::remove(int elem)
{
  if (this->isEmpty())
  {
    std::cout<<"Nothing to remove!"<<std::endl;
    return;
  }
  else
  {
    int i = 0;
    int size = this->size_;
    while (i < size)
    {
      if (*(this->arr_ + i) == elem)
      {
        this->deleteAt(i);
        size = this->size_;
      }
      else
      {
        i++;
      }
    }
  }
}

int ResizableArray::find(int elem)
{
  if (this->isEmpty())
  {
    std::cout<<"Nothing to find!"<<std::endl;
    return -1;
  }
  else
  {
    for (int i = 0; i < this->size_; i++)
    {
      if (*(this->arr_ + i) == elem)
      {
        return i;
      }
    }
  }
  std::cout<<"Element not found!"<<std::endl;
  return -1;
}
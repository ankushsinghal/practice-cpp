/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 31st January, 2021
 *  @description  : Source file for Binary Heap Class
 *  @file         : binary_heap.cpp
 */

#include "binary_heap.h"

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

BinaryHeap::BinaryHeap()
{
  size_ = 0;
}

int BinaryHeap::get_parent(int index)
{
  if (index == 0)
  {
    return 0;
  }
  else
  {
    return (index - 1) / 2;
  }
}

void BinaryHeap::percolate_up(int index)
{
  if (index == 0 || index >= size_)
  {
    return;
  }
  int parent = get_parent(index);
  if (elems_[parent] < elems_[index])
  {
    swap(&elems_[index], &elems_[parent]);
    percolate_up(parent);
  }
  else
  {
    return;
  }
}

void BinaryHeap::percolate_down(int index)
{
  int child_index1 = 2 * index + 1;
  int child_index2 = 2 * index + 2;

  if (child_index2 >= size_)
  {
    if (child_index1 >= size_)
    {
      return;
    }
    else
    {
      if (elems_[child_index1] > elems_[index])
      {
        swap(&elems_[child_index1], &elems_[index]);
        percolate_down(child_index1);
      }
      else
      {
        return;
      }
    }
  }
  else
  {
    if (elems_[child_index1] > elems_[child_index2])
    {
      if (elems_[child_index1] > elems_[index])
      {
        swap(&elems_[child_index1], &elems_[index]);
        percolate_down(child_index1);
      }
      else
      {
        return;
      }
    }
    else
    {
      if (elems_[child_index2] > elems_[index])
      {
        swap(&elems_[child_index2], &elems_[index]);
        percolate_down(child_index2);
      }
      else
      {
        return;
      }
    }
  } 
}

void BinaryHeap::insert(int elem)
{
  elems_.push_back(elem);
  size_++;
  percolate_up(size_ - 1);
}

int BinaryHeap::get_max()
{
  if (size_ > 0)
  {
    return elems_[0];
  }
  else
  {
    return kErrorValue;
  } 
}

int BinaryHeap::extract_max()
{
  if (size_ > 0)
  {
    int answer = elems_[0];
    elems_[0] = elems_[size_ - 1];
    size_--;
    elems_.pop_back();
    percolate_down(0);
    return answer;
  }
  else
  {
    return kErrorValue;
  }
}

bool BinaryHeap::is_empty()
{
  if (size_ == 0)
  {
    return true;
  }
  return false;
}

int BinaryHeap::get_size()
{
  return size_;
}

void BinaryHeap::remove(int index)
{
  if (size_ > 0 && index < size_)
  {
    elems_[index] = elems_[size_ - 1];
    size_--;
    elems_.pop_back();
    percolate_down(index);
    return;
  }
  else
  {
    return;
  }
}

vector<int> BinaryHeap::get_all_elements()
{
  return elems_;
}
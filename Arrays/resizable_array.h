/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 19th May, 2019
 *  @description  : Header file for Resizable Array Class
 *  @file         : resizable_array.h
 */

#ifndef RESIZABLE_ARRAY_H
#define RESIZABLE_ARRAY_H

#include <iostream>
#include <stdio.h>
#include <malloc.h>

// Initial minimum size of the resizable array
const int kMinArraySize = 16;

// The factor by which we want to resize the array if it fills up
const int kMultiplyFactor = 2;

class ResizableArray
{

 private:
  // The total capacity of the resizable array
  int capacity_;

  // The current size of the resizable array
  int size_;

  // the data of the resizable array
  int *arr_;

  // private method to increase the capacity of the resizable array when it fills
  void increaseCapacity();

 public:
  ResizableArray();
  ResizableArray(int cap);
  ~ResizableArray();

  // size_ variable accessor method
  int size();

  // capacity_ variable accessor method
  int capacity();

  // Method to tell whether the array is empty or not
  bool isEmpty();

  // Method to return the value of array at given index
  int at(int index);

  // Method to push the elem at the end of the array
  void push(int elem);

  // Method to insert the elem at the given index, thus shifting other elemnets to their right
  void insert(int index, int elem);

  // Method to insert the elem at the starting of the array
  void prepend(int elem);
};

#endif // RESIZABLE_ARRAY_H
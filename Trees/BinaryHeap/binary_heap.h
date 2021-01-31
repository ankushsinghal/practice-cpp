/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 31st January, 2021
 *  @description  : Header file for Binary Heap Class
 *  @file         : binary_heap.h
 */

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <vector>

#define kErrorValue -404

using namespace std;

// Creating a class for Max heap
class BinaryHeap
{
 private:
  int size_;
  vector<int> elems_;

  // Helper method to get parent of the index
  int get_parent(int index);

  // Helper method to percolate up the newly inserted value
  void percolate_up(int index);

  // Helper method to percolate down the value at given index
  void percolate_down(int index);
  
 public:
  // Constructor
  BinaryHeap();

  // Insert elem into to max heap
  void insert(int elem);

  // Return the Max element without removing it
  int get_max();

  // Return the max element and also remove it from heap
  int extract_max();

  // Check if heap is empty
  bool is_empty();

  // Return the size of heap
  int get_size();

  // Remove element at index
  void remove(int index);

  // Heapify the array
  void heapify();

  // Sort the elements of the heap and return a vector containing sorted elements
  vector<int> heap_sort();

  // get all elements vector. Only to be used for testing
  vector<int> get_all_elements();
};


#pragma GCC diagnostic pop

#endif //BINARY_HEAP_H
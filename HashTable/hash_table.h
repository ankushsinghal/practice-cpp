/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Thursday, 7th January, 2021
 *  @description  : Header file for Hash Table Class
 *  @file         : hash_table.h
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <vector>
#include <math.h>

#define kHashTableStartingSize 13
#define kEmptyValue -1
#define kDeleteValue -2
#define kHash2Prime 7

using namespace std;

// Hash Table with key as "name"(string) and value as "age"(int)
class HashTable
{
 private:
  string *key_table_;
  int *value_table_;
  int max_table_size_;
  int size_;
  int pre_hash(string key, int prime);
  int hash1(int key, int prime);
  int hash2(int key);
  void increase_table_size();
 public:
  HashTable();
  ~HashTable();
  int size();
  void insert_item(string key, int value);
  int search_item(string key);
  bool exists_item(string key);
  void delete_item(string key);
  void print_table();
};

#pragma GCC diagnostic pop

#endif //HASH_TABLE_H
/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Thursday, 7th January, 2021
 *  @description  : Source file for Hash Table Class
 *  @file         : hash_table.cpp
 */

#include "hash_table.h"

int mod(int a, int b)
{
  int answer = a % b;
  if (answer >= 0)
  {
    return answer;
  }
  else
  {
    return answer + b;
  }
}

bool is_prime(int a)
{
  for (int i = 3; i <= ceil(sqrt(a)); i++)
  {
    if (a % i == 0)
    {
      return false;
    }
  }
  return true;
}

int next_prime(int a)
{
  int num = a;
  bool prime_result = is_prime(num);
  while (!prime_result)
  {
    num++;
    prime_result = is_prime(num);
  }
  return num;
}

HashTable::HashTable()
{
  size_ = 0;
  max_table_size_ = kHashTableStartingSize;
  key_table_ = (string *)malloc(sizeof(string) * max_table_size_);
  value_table_ = (int *)malloc(sizeof(int) * max_table_size_);
  for (int i = 0; i < kHashTableStartingSize; i++)
  {
    value_table_[i] = kEmptyValue;
  }
}

HashTable::~HashTable()
{
  free(key_table_);
  free(value_table_);
  key_table_ = NULL;
  value_table_ = NULL;
}

int HashTable::size()
{
  return size_;
}

int HashTable::pre_hash(string key, int prime)
{
  int base = 256;
  int value = 0;

  for (int i = 0; i < key.size(); i++)
  {
    value = mod((value * base) + key[i], prime);
  }

  return value;
}

int HashTable::hash1(int key, int prime)
{
  return key % prime;
}

int HashTable::hash2(int key)
{
  return kHash2Prime - (key % kHash2Prime);
}

void HashTable::increase_table_size()
{
  int old_max_table_size = max_table_size_;
  string *temp_old_key_table = (string *)malloc(sizeof(string) * max_table_size_);
  int *temp_old_value_table = (int *)malloc(sizeof(int) * max_table_size_);

  for (int i = 0; i < max_table_size_; i++)
  {
    temp_old_value_table[i] = kEmptyValue;
    if (value_table_[i] != kEmptyValue && value_table_[i] != kDeleteValue)
    {
      temp_old_key_table[i] = key_table_[i];
      temp_old_value_table[i] = value_table_[i];
    }
  }

  int new_max_table_size = (max_table_size_ * 2) + 1;
  new_max_table_size = next_prime(new_max_table_size);

  string *new_key_table = (string *)malloc(sizeof(string) * new_max_table_size);
  int *new_value_table = (int *)malloc(sizeof(int) * new_max_table_size);
  for (int i = 0; i < new_max_table_size; i++)
  {
    new_value_table[i] = kEmptyValue;
  }

  max_table_size_ = new_max_table_size;
  free(key_table_);
  free(value_table_);
  key_table_ = new_key_table;
  value_table_ = new_value_table;
  size_ = 0;

  for (int i = 0; i < old_max_table_size; i++)
  {
    if (temp_old_value_table[i] != kEmptyValue && temp_old_value_table[i] != kDeleteValue)
    {
      insert_item(temp_old_key_table[i], temp_old_value_table[i]);
    }
  }

  free(temp_old_key_table);
  free(temp_old_value_table);
}

void HashTable::insert_item(string key, int value)
{

  if (2 * size_ > max_table_size_)
  {
    increase_table_size();
  }

  int pre_hash_value = pre_hash(key, max_table_size_);
  int hash_value = (hash1(pre_hash_value, max_table_size_)) % max_table_size_;

  if (key_table_[hash_value] == key)
  {
    value_table_[hash_value] = value;
    return;
  }

  int i = 1;
  while (value_table_[hash_value] != kEmptyValue && value_table_[hash_value] != kDeleteValue && i < max_table_size_)
  {
    hash_value = (hash1(pre_hash_value, max_table_size_) + i * hash2(pre_hash_value)) % max_table_size_;
    if (key_table_[hash_value] == key)
    {
      value_table_[hash_value] = value;
      return;
    }
    i++;
  }

  if (i < max_table_size_)
  {
    key_table_[hash_value] = key;
    value_table_[hash_value] = value;
    size_++;
    return;
  }
}

bool HashTable::exists_item(string key)
{
  int pre_hash_value = pre_hash(key, max_table_size_);
  int hash_value = (hash1(pre_hash_value, max_table_size_)) % max_table_size_;

  if (value_table_[hash_value] == kEmptyValue)
  {
    return false;
  }

  int i = 1;
  while (value_table_[hash_value] != kEmptyValue && i < max_table_size_)
  {
    if (key_table_[hash_value] == key)
    {
      return true;
    }

    hash_value = (hash1(pre_hash_value, max_table_size_) + i * hash2(pre_hash_value)) % max_table_size_;
    if (value_table_[hash_value] == kEmptyValue)
    {
      return false;
    }
    i++;
  }

  return false;
}

int HashTable::search_item(string key)
{
  int pre_hash_value = pre_hash(key, max_table_size_);
  int hash_value = (hash1(pre_hash_value, max_table_size_)) % max_table_size_;

  if (value_table_[hash_value] == kEmptyValue)
  {
    return kEmptyValue;
  }

  int i = 1;
  while (value_table_[hash_value] != kEmptyValue && i < max_table_size_)
  {
    if (key_table_[hash_value] == key)
    {
      return value_table_[hash_value];
    }

    hash_value = (hash1(pre_hash_value, max_table_size_) + i * hash2(pre_hash_value)) % max_table_size_;
    if (value_table_[hash_value] == kEmptyValue)
    {
      return kEmptyValue;
    }
    i++;
  }
  return kEmptyValue;
}

void HashTable::delete_item(string key)
{
  int pre_hash_value = pre_hash(key, max_table_size_);
  int hash_value = (hash1(pre_hash_value, max_table_size_)) % max_table_size_;

  if (value_table_[hash_value] == kEmptyValue)
  {
    return;
  }

  int i = 1;
  while (value_table_[hash_value] != kEmptyValue && i < max_table_size_)
  {
    if (key_table_[hash_value] == key)
    {
      key_table_[hash_value] = "";
      value_table_[hash_value] = kDeleteValue;
      size_--;
    }

    hash_value = (hash1(pre_hash_value, max_table_size_) + i * hash2(pre_hash_value)) % max_table_size_;
    if (value_table_[hash_value] == kEmptyValue)
    {
      return;
    }
    i++;
  }
}

void HashTable::print_table()
{
  for (int i = 0; i < max_table_size_; i++)
  {
    printf("%d - ", i);
    if (value_table_[i] != kEmptyValue && value_table_[i] != kDeleteValue)
    {
      printf("%s : ", key_table_[i].c_str());
      printf("%d", value_table_[i]);
    }
    printf("\n");
  }
}
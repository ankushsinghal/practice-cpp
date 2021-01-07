/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Thursday, 7th January, 2021
 *  @description  : Header file for Rabin Karp Class
 *  @file         : rabin_karp.h
 */

#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <vector>

#define kSizeOfAlphabet 256

using namespace std;

class RabinKarp
{
 private:
  int hash_function(string substring, int prime);
 public:
  vector<int> substring_search(string text, string substring, int prime);
};

#pragma GCC diagnostic pop

#endif //RABIN_KARP_H
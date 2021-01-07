/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Thursday, 7th January, 2021
 *  @description  : Source file for Rabin Karp Class
 *  @file         : rabin_karp.cpp
 */

#include "rabin_karp.h"

int mod(int a, int b)
{
  int temp = a % b;
  if (temp >= 0)
  {
    return temp;
  }
  else
  {
    return temp + b;
  }
  
}

int RabinKarp::hash_function(string substring, int prime)
{
  int value = 0;
  for (int i = 0; i < substring.size(); i++)
  {
    value = mod(((value * kSizeOfAlphabet) + substring[i]), prime);
  }
  return value;
}

vector<int> RabinKarp::substring_search(string text, string substring, int prime)
{
  vector<int> answer;
  int text_length = text.size();
  int substring_length = substring.size();

  if (text_length == 0 || substring_length == 0 || text_length < substring_length)
  {
    return answer;
  }

  int removing_factor = 1;
  for (int i = 0; i < substring_length - 1; i++)
  {
    removing_factor = mod((removing_factor * kSizeOfAlphabet), prime);
  }

  int substring_hash = hash_function(substring, prime);
  string text_substring = text.substr(0, substring_length);
  int text_hash = hash_function(text_substring, prime);

  if (substring_hash == text_hash)
  {
    if (substring == text_substring)
    {
      answer.push_back(0);
    }
  }

  for (int i = 0; i < text_length - substring_length; i++)
  {
    text_hash = mod((kSizeOfAlphabet * (text_hash - removing_factor * text_substring[0])) + text[i + substring_length], prime);
    text_substring =  text_substring.substr(1) + text[i + substring_length];
    if (substring_hash == text_hash)
    {
      if (substring == text_substring)
      {
        answer.push_back(i + 1);
      }
    }
  }
  
  return answer;

}
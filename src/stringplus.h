/*
*   stringplus library - Funny and minimal string library, inspired by underscore.string
*   License: MIT License
*   C++ version: C++11
*   Repository address: github.com/mahdavipanah/stringplus
*   Author: Hamidreza Mahdavipanah
*           Github account : github.com/mahdavipanah
*/
#ifndef STRINGPLUS_H
#define STRINGPLUS_H

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// this namespace contains the functions for having fun with strings
namespace stringplus {

  /*
  * Replaces lower case alphabetical chars with upper case
  * Example: "abcd" -> 'ABCD'
  */
  string to_upper(const string& str) {
    string ret_val = str;
    for_each(ret_val.begin(), ret_val.end(), [](char& c) { c = (char)toupper(c);});
    return ret_val;
  }

  /*
  * Replaces upper case alphabetical chars with lower case
  * Example: "ABCD" -> 'abcd'
  */
  string to_lower(const string& str) {
    string ret_val = str;
    for_each(ret_val.begin(), ret_val.end(), [](char& c) { c = (char)tolower(c);});
    return ret_val;
  }

  /*
  * Returns true if all chars in the string are alphabetical
  * Example: "abcd" -> true
  * Example: "Abn4" -> false
  */
  bool is_alpha(const string& str) {
    for(char c : str)
      if(!isalpha(c))
        return false;
    return true;
  }
} // stringplus

#endif // STRINGPLUS_H

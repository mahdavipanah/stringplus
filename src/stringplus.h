/**
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

  string to_upper(const string&);
  string to_lower(const string&);
  bool is_alpha(const string&);
  bool is_digit(const string&);
  bool is_alpha_digit(const string&);
  bool is_lower(const string&);
  bool is_upper(const string&);
  string capitalize(const string&, bool = false);
  string decapitalize(const string&);
  vector<string> chop(const string&, int);
  string clean(const string&);
  string swap_case(const string&);
} // stringplus

#endif // STRINGPLUS_H

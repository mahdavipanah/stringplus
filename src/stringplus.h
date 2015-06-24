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
  string reverse(const string&);
  string truncate(const string&, int, const string& = "...");
  string surround(const string&, const string&);
  string repeat(const string&, int, const string& = "");
  string pad(const string&, int, char = ' ', string = "left");
  string lpad(const string&, int, char = ' ');
} // stringplus

#endif // STRINGPLUS_H

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

  /*
  * Returns true if all chars in the string are digits
  * Example: "1234" -> true
  * Example: "34n4" -> false
  */
  bool is_digit(const string& str) {
    for(char c : str)
      if(!isdigit(c))
        return false;
    return true;
  }

  /*
  * Returns true if all chars in the string are digits or an uppercase or lowercase letter
  * Example: "1234" -> true
  * Example: "34n4" -> true
  * Example: "34n[" -> false
  */
  bool is_alpha_digit(const string& str) {
    for(char c : str)
      if(!isalnum(c))
        return false;
    return true;
  }

  /*
  * Returns true if all alpha chars in the string are lowercases
  * Example: "1234" -> true
  * Example: "34n4" -> true
  * Example: "34M" -> false
  */
  bool is_lower(const string& str) {
    for(char c : str)
      if(isalpha(c))
        if(!islower(c))
          return false;
    return true;
  }

  /*
  * Returns true if all alpha chars in the string are uppercases
  * Example: "1234" -> true
  * Example: "34N4" -> true
  * Example: "34n" -> false
  */
  bool is_upper(const string& str) {
    for(char c : str)
      if(isalpha(c))
        if(!isupper(c))
          return false;
    return true;
  }

  /*
  * Converts first letter of the string to uppercase.
  * If true is passed as second argument the rest of the string will be converted to lower case
  * Example: "abcd" -> "Abcd"
  * Example: "aBCD" -> "ABCD"
  * Example: lower_case_reset = true: "aBCD" -> "Abcd"
  */
  string capitalize(const string& str, bool lower_case_reset = false) {
    string ret_val = str;
    ret_val[0] = toupper(ret_val[0]);
    if(lower_case_reset)
      for_each(ret_val.begin() + 1, ret_val.end(), [](char& c) {
        c = tolower(c);
      });
    return ret_val;
  }
} // stringplus

#endif // STRINGPLUS_H

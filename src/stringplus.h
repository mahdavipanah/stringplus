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

  /**
  * Replaces lower case alphabetical chars with upper case.
  *
  * @example "abcd" "ABCD"
  */
  string to_upper(const string& str) {
    string ret_val = str;
    for_each(ret_val.begin(), ret_val.end(), [](char& c) { c = (char)toupper(c);});
    return ret_val;
  }

  /**
  * Replaces upper case alphabetical chars with lower case.
  *
  * @example "ABCD" 'abcd'
  */
  string to_lower(const string& str) {
    string ret_val = str;
    for_each(ret_val.begin(), ret_val.end(), [](char& c) { c = (char)tolower(c);});
    return ret_val;
  }

  /**
  * Returns true if all chars in the string are alphabetical.
  *
  * @example "abcd" true
  * @example "Abn4" false
  */
  bool is_alpha(const string& str) {
    for(char c : str)
      if(!isalpha(c))
        return false;
    return true;
  }

  /**
  * Returns true if all chars in the string are digits.
  *
  * @example "1234" true
  * @example "34n4" false
  */
  bool is_digit(const string& str) {
    for(char c : str)
      if(!isdigit(c))
        return false;
    return true;
  }

  /**
  * Returns true if all chars in the string are digits or an uppercase or lowercase letter.
  *
  * @example "1234" true
  * @example "34n4" true
  * @example "34n[" false
  */
  bool is_alpha_digit(const string& str) {
    for(char c : str)
      if(!isalnum(c))
        return false;
    return true;
  }

  /**
  * Returns true if all alpha chars in the string are lowercases.
  *
  * @example "1234" true
  * @example "34n4" true
  * @example "34M" false
  */
  bool is_lower(const string& str) {
    for(char c : str)
      if(isalpha(c))
        if(!islower(c))
          return false;
    return true;
  }

  /**
  * Returns true if all alpha chars in the string are uppercases.
  *
  * @example "1234" true
  * @example "34N4" true
  * @example "34n" false
  */
  bool is_upper(const string& str) {
    for(char c : str)
      if(isalpha(c))
        if(!isupper(c))
          return false;
    return true;
  }

  /**
  * Converts first letter of the string to uppercase.
  *
  * @param lower_case_reset bool If true is passed, the rest of the string will be converted to lower case.
  *
  * @example "abcd" "Abcd"
  * @example "aBCD" "ABCD"
  * @example "aBCD", true "Abcd"
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

  /**
  * Converts first letter of the string to lowercase.
  *
  * @example "ABCD" "aBCD"
  */
  string decapitalize(const string& str) {
    string ret_val = str;
    ret_val[0] = tolower(ret_val[0]);
    return ret_val;
  }
} // stringplus

#endif // STRINGPLUS_H

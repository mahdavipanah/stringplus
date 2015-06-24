/**
*   stringplus library - Funny and minimal string library, inspired by underscore.string
*   License: MIT License
*   C++ version: C++11
*   Repository address: github.com/mahdavipanah/stringplus
*   Author: Hamidreza Mahdavipanah
*           Github account : github.com/mahdavipanah
*/
#include "stringplus.h"

using namespace std;

// this namespace contains the functions for having fun with strings
namespace stringplus {

  /**
  * Replaces lower case alphabetical chars with upper case.
  *
  * @example "abcd" => "ABCD"
  */
  string to_upper(const string& str) {
    string ret_val = str;
    for_each(ret_val.begin(), ret_val.end(), [](char& c) { c = (char)toupper(c);});
    return ret_val;
  }

  /**
  * Replaces upper case alphabetical chars with lower case.
  *
  * @example "ABCD" => 'abcd'
  */
  string to_lower(const string& str) {
    string ret_val = str;
    for_each(ret_val.begin(), ret_val.end(), [](char& c) { c = (char)tolower(c);});
    return ret_val;
  }

  /**
  * Returns true if all chars in the string are alphabetical.
  *
  * @example "abcd" => true
  * @example "Abn4" => false
  */
  bool is_alpha(const string& str) {
    for (char c : str)
      if (!isalpha(c))
        return false;
    return true;
  }

  /**
  * Returns true if all chars in the string are digits.
  *
  * @example "1234" => true
  * @example "34n4" => false
  */
  bool is_digit(const string& str) {
    for (char c : str)
      if (!isdigit(c))
        return false;
    return true;
  }

  /**
  * Returns true if all chars in the string are digits or an uppercase or lowercase letter.
  *
  * @example "1234" => true
  * @example "34n4" => true
  * @example "34n[" => false
  */
  bool is_alpha_digit(const string& str) {
    for (char c : str)
      if (!isalnum(c))
        return false;
    return true;
  }

  /**
  * Returns true if all alpha chars in the string are lowercases.
  *
  * @example "1234" => true
  * @example "34n4" => true
  * @example "34M" => false
  */
  bool is_lower(const string& str) {
    for (char c : str)
      if (isalpha(c))
        if (!islower(c))
          return false;
    return true;
  }

  /**
  * Returns true if all alpha chars in the string are uppercases.
  *
  * @example "1234" => true
  * @example "34N4" => true
  * @example "34n" => false
  */
  bool is_upper(const string& str) {
    for (char c : str)
      if (isalpha(c))
        if (!isupper(c))
          return false;
    return true;
  }

  /**
  * Converts first letter of the string to uppercase.
  *
  * @param lower_case_reset bool If true is passed, the rest of the string will be converted to lower case.
  *
  * @example "abcd" => "Abcd"
  * @example "aBCD" => ABCD"
  * @example "aBCD", true => "Abcd"
  */
  string capitalize(const string& str, bool lower_case_reset) {
    string ret_val = str;
    ret_val[0] = toupper(ret_val[0]);
    if (lower_case_reset)
      for_each(ret_val.begin() + 1, ret_val.end(), [](char& c) {
        c = tolower(c);
      });
    return ret_val;
  }

  /**
  * Converts first letter of the string to lowercase.
  *
  * @example "ABCD" => "aBCD"
  */
  string decapitalize(const string& str) {
    string ret_val = str;
    ret_val[0] = tolower(ret_val[0]);
    return ret_val;
  }

  /**
  * Chops the string to a vector.
  *
  * @param step int Chops the string with this step.
  *
  * @return vector<string> The vector that contains choped pieces.
  *
  * @example "whitespace", 3 => ["whi", "tes", "pac", "e"]
  */
  vector<string> chop(const string& str, int step) {
    vector<string> ret_val;
    int step_counter = 0;
    string step_string = ""; // contains every step's string
    for (char c : str) {
      if (step_counter < step) {
        step_string += c;
        step_counter++;
      } else {
        ret_val.push_back(step_string);
        step_string = c;
        step_counter = 1;
      }
    }
    ret_val.push_back(step_string); // adds the last step string to the vector
    ret_val.shrink_to_fit(); // removes the unused spaces from the vector
    return ret_val;
  }

  /**
  * Trims and replaces multiple spaces with a single space.
  *
  * @example " foo    bar   " => "foo bar"
  */
  string clean(const string& str) {
    string ret_val = str;
    for(auto it = ret_val.begin(); *it == ' ';)
      ret_val.erase(it);
    for(auto it = ret_val.end() - 1; *it == ' '; it--)
      ret_val.erase(it);
    for (auto first_it = ret_val.begin(); first_it != ret_val.end(); first_it++)
      if (*first_it == ' ')
        for (auto second_it = first_it + 1; *second_it == ' ' ; second_it = first_it + 1)
          ret_val.erase(second_it);
    return ret_val;
  }

  /**
  * Returns a copy of the string in which all the case-based characters have had their case swapped.
  *
  * @example "hELLO" => "Hello"
  */
  string swap_case(const string& str) {
    string ret_val = str;
    for(char& c : ret_val)
      if(isupper(c))
        c = tolower(c);
      else if(islower(c))
        c = toupper(c);
    return ret_val;
  }

  /**
  * Returns reversed string.
  *
  * @example "Hello" => "olleH"
  * @example "12345" => "54321"
  */
  string reverse(const string& str) {
    string ret_val = str;
    reverse(ret_val.begin(), ret_val.end()); // Using std::reverse
    return ret_val;
  }

  /**
  * Truncates the strings with the length greater than the given length with the given string
  *
  * @example "Hello world", 5 => "Hello..."
  * @example "Hello", 10 => "Hello"
  * @example "Hello world", 5, " read more" => "Hello read more"
  */
  string truncate(const string& str, int length, const string& truncate_string) {
    if(str.length() <= length)
      return str;
    string ret_val = "";
    int index = 0;
    for(char c : str) {
      if(index == length)
        break;
      ret_val += c;
      index++;
    }
    ret_val += truncate_string;
    return ret_val;
  }
} // stringplus

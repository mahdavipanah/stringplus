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
  * Truncates the strings with the length greater than the given length with the given string.
  *
  * @example "Hello world", 5 => "Hello..."
  * @example "Hello", 10 => "Hello"
  * @example "Hello world", 5, " read more" => "Hello read more"
  */
  string truncate(const string& str, unsigned int length, const string& truncate_string) {
    if(str.length() <= length)
      return str;
    string ret_val = "";
    unsigned int index = 0;
    for(char c : str) {
      if(index == length)
        break;
      ret_val += c;
      index++;
    }
    ret_val += truncate_string;
    return ret_val;
  }

  /**
  * Surrounds a string with another string.
  *
  * @example "foo", "bar" => "barfoobar"
  */
  string surround(const string& str, const string& wrap) {
    return wrap+str+wrap;
  }

  /**
  * Repeats a string count times, seperated by given string.
  *
  * @example "foo", 3, "bar" => "foobarfoobarfoo"
  */
  string repeat(const string& str, int count, const string& seperator) {
    string ret_val;
    for (int i = 1; i < count; i++)
      ret_val += str+seperator;
    ret_val += str;
    return ret_val;
  }

  /**
  * pads the string with character until the total string length is equal to the passed length parameter. By default, pads on the left with the space char (" ").
  *
  * @example "1", 8 => "       1"
  * @exmaple "1", 8, '0' => "00000001"
  * @exmaple "1", 8, '0', "right" => "10000000"
  * @exmaple "1", 8, '0', "both" => "00001000"
  */
  string pad(const string& str, unsigned int length, char pad_char, string type) {
    if (type != "left" && type != "right" && type != "both")
      type = "left";
    bool both_determiner = 0;
    string ret_val = str;
    while (ret_val.length() < length) {
      if (type == "left")
        ret_val = pad_char + ret_val;
      else if (type == "right")
        ret_val = ret_val + pad_char;
      else {
        if (both_determiner == 0) {
          ret_val = pad_char + ret_val;
          both_determiner = 1;
        } else {
          ret_val = ret_val + pad_char;
          both_determiner = 0;
        }
      }
    }
    return ret_val;
  }

  /**
  * left-pad a string. Alias for pad(string, int, char, "left")
  *
  * @exmaple "1", 8, '0' => "00000001"
  */
  string lpad(const string& str, int length, char pad_char) {
    return pad(str, length, pad_char, "left");
  }

  /**
  * right-pad a string. Alias for pad(string, int, char, "right")
  *
  * @exmaple "1", 8, '0' => "10000000"
  */
  string rpad(const string& str, int length, char pad_char) {
    return pad(str, length, pad_char, "right");
  }

  /**
  * left/right-pad a string. Alias for pad(string, int, char, "both")
  *
  * @exmaple "1", 8, '0' => "00001000"
  */
  string lrpad(const string& str, int length, char pad_char) {
    return pad(str, length, pad_char, "both");
  }

  /**
  * Checks whether the string begins with starts at position (default: 0).
  *
  * @example "image.gif", "image" => true
  * @example ".vimrc", "vim" => false
  * @example ".vimrc", "vim", 1 => true
  */
  bool starts_with(const string& str, const string& starts, int position) {
    if(str.substr(position, starts.length()) == starts)
      return true;
    return false;
  }

  /**
  * Checks whether the string ends with ends at position (default: str.length).
  *
  * @example "image.gif", "gif" => true
  * @example "image.old.gif", "old" => false
  * @example "image.old.gif", "old", 9 => true
  */
  bool ends_with(const string& str, const string& ends, int position) {
    if(position == -1)
      position = str.length();
    if(str.substr(position - ends.length(), ends.length()) == ends)
      return true;
    return false;
  }

  /**
  * Joins strings together with given separator.
  *
  * @example " ", {"foo", "bar"} => "foo bar"
  */
  string join(const string& seperator, const vector<string>& strings) {
    string ret_val = "";
    for(auto str = strings.begin(); str != strings.end(); str++) {
      ret_val += *str;
      if(str != strings.end() - 1)
        ret_val += seperator;
    }
    return ret_val;
  }

  /**
  * Returns number of occurrences of substring in a string.
  *
  * @example "Hello world", "l" => 3
  */
  int count(const string& str, const string& substr) {
    if(substr == "" || str == "")
      return 0;
    int ret_val = 0;
    size_t pos = -1;
    while((pos = str.find(substr, pos+1)) != string::npos)
		  ret_val++;
    return ret_val;
  }
} // stringplus

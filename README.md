# stringplus
The aim of this project is not to make a very complicated library. I am trying to make it as simple as possible. Simple but powerful. Considering [underscore.string][] is a very awesome javascript library for working with strings, stringplus tries to do things similar.


[underscore.string]: https://github.com/epeli/underscore.string "underscore.string github repository"

## Usage

To use stringplus you have to include stringplus.h wherever you need it <br />

```C++
#include "stringplus.h"
```

and then all the functionalities are available in the stringplus namespace. <br />
If you don't want to use the namespace every time:

```C++
using namespace stringplus;
```

Then you have to compile stringplus.cc with your program. For example:
```Shell
g++ -std=c++11 main.cc stringplus.cc
```

## API

### Individual functions

#### to_upper(string) => string
Replaces lower case alphabetical chars with upper case.

```C++
stringplus::to_upper("foo bar");
// => "FOO BAR"
```

#### to_lower(string) => string
Replaces upper case alphabetical chars with lower case.

```C++
stringplus::to_lower("FOO BAR");
// => "foo bar"
```

#### is_alpha(string) => bool
Returns true if all chars in the string are alphabetical.

```C++
stringplus::is_alpha("abcd");
// => true

stringplus::is_alpha("Abn4");
// => false
```

#### is_digit(string) => bool
Returns true if all chars in the string are digits.

```C++
stringplus::is_digit("1234");
// => true

stringplus::is_digit("34n4");
// => false
```

#### is_alpha_digit(string) => bool
Returns true if all chars in the string are digits or an uppercase or lowercase letter.

```C++
stringplus::is_alpha_digit("1234");
// => true

stringplus::is_alpha_digit("34n4");
// => true

stringplus::is_alpha_digit("34n[");
// => false
```

#### is_lower(string) => bool
Returns true if all alpha chars in the string are lowercases.

```C++
stringplus::is_lower("1234");
// => true

stringplus::is_lower("34n4");
// => true

stringplus::is_lower("34M");
// => false
```

#### is_upper(string) => bool
Returns true if all alpha chars in the string are uppercases.

```C++
stringplus::is_upper("1234");
// => true

stringplus::is_upper("34N4");
// => true

stringplus::is_upper("34n");
// => false
```

#### capitalize(string, [bool = false]) => string
Converts first letter of the string to uppercase. If true is passed as second argument the rest of the string will be converted to lower case.

```C++
stringplus::capitalize("abcd");
// => "Abcd"

stringplus::capitalize("aBCD");
// => "ABCD"

stringplus::capitalize("aBCD", true);
// => "Abcd"
```

#### decapitalize(string) => string
Converts first letter of the string to lowercase.

```C++
stringplus::decapitalize("ABCd");
// => "aBCD"
```

#### chop(string, int step) => std::vector\<string\>
Chops the string to a vector with the given step.

```C++
stringplus::chop("whitespace", 3);
// => ["whi", "tes", "pac", "e"]
```

#### clean(string) => string
Trim and replace multiple spaces with a single space.

```C++
stringplus::clean(" foo    bar   ");
// => "foo bar"
```

#### swap_case(string) => string
Returns a copy of the string in which all the case-based characters have had their case swapped.

```C++
stringplus::swap_case("hELLO");
// => "Hello"
```

#### reverse(string) => string
Return reversed string:

```C++
stringplus::reverse("Hello");
// => "olleH"

stringplus::reverse("12345");
// => "54321"
```

#### truncate(string, int, [string = "..."]) => string
Truncates the strings with the length greater than the given length with the given string.

```C++
stringplus::truncate("Hello world", 5);
// => "Hello..."

stringplus::truncate("Hello", 10);
// => "Hello"

stringplus::truncate("Hello world", 5, " read more");
// => "Hello read more"
```

#### surround(string, string) => string
Surrounds a string with another string.

```C++
stringplus::surround("foo", "bar");
// => "barfoobar"
```

#### repeat(string, int, [string = ""]) => string
Repeats a string count times, seperated by given string.

```C++
stringplus::repeat("foo", 3, "bar");
// => "foobarfoobarfoo"
```

####pad(string, int, [char = ' ', string = "left"]) => string
pads the string with character until the total string length is equal to the passed length parameter. By default, pads on the left with the space char (" ").

```C++
stringplus::pad("1", 8);
// => "       1"

stringplus::pad("1", 8, "0");
// => "00000001"

stringplus::pad("1", 8, "0", "right");
// => "10000000"

stringplus::pad("1", 8, "0", "both");
// => "00001000"
```
#### lpad(string, int, [char]) => string
left-pad a string. Alias for pad(string, int, char, "left")

```C++
stringplus::lpad("1", 8, "0");
// => "00000001"
```
#### rpad(string, int, [char]) => string
right-pad a string. Alias for pad(string, int, char, "right")

```C++
stringplus::rpad("1", 8, "0");
// => "10000000"
```
#### lrpad(string, int, [char]) => string
left/right-pad a string. Alias for pad(string, int, char, "both")

```C++
stringplus::lrpad("1", 8, "0");
// => "00001000"
```

#### starts_with(string, string, [int = 0]) => bool
Checks whether the string begins with starts at position.

```C++
stringplus::starts_with("image.gif", "image");
// => true

stringplus::starts_with(".vimrc", "vim");
// => false

stringplus::starts_with(".vimrc", "vim", 1);
// => true
```

#### ends_with(string str, string, [int = -1]) => bool
Checks whether the string ends with ends at position (default: str.length()).

```C++
stringplus::ends_with("image.gif", "gif");
// => true

stringplus::ends_with("image.old.gif", "old");
// => false

stringplus::ends_with("image.old.gif", "old", 9);
// => true
```

#### join(string, vector\<string\>) => string
Joins strings together with given separator.

```C++
stringplus::join(" ", {"foo", "bar"});
// => "foo bar"
```

#### count(string, string) => int
Returns number of occurrences of substring in a string.

```C++
stringplus::count("Hello world", "l");
// => 3
```

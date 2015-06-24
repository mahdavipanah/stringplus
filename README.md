# stringplus
The aim of this project is not to make a very complicated library. We are trying to make it as simple as possible. Simple but powerful. While [underscore.string][] is a very awesome and professional javascript library for working with strings, we are trying to do things similar.
With stringplus you can do a lot things to strings! and meanwhile we want the code to be very clean so everyone can read and contribute to it.

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
g++ main.cc stringplus.cc
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

#### capitalize(string, [bool lowercaseRest=false]) => string
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

```
stringplus::reverse("Hello");
// => "olleH"

stringplus::reverse("12345");
// => "54321"
```

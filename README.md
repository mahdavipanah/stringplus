# stringplus
The aim of this project is not to make a very complicated library. We are trying to make it as simple as possible. Simple but powerful. While [underscore.string][] is a very awesome and professional javascript library for working with strings, we are trying to do things similar.
With stringplus you can do a lot things to strings! and meanwhile we want the code to be very clean so everyone can read and contribute to it.

[underscore.string]: https://github.com/epeli/underscore.string "underscore.string github repository"

## Usage

To sake of simplicity, we are holding everything in a single file: stringplus.h <br />
So you only need to include it once in your code:

```C++
#include "stringplus.h"
```

and then all the functionalities are available in the stringplus namespace. <br />
If you don't want to use the namespace every time:

```C++
using namespace stringplus;
```

## API

### Individual functions

#### to_upper(string) => string
Replaces lower case alphabetical chars with upper case.

```C++
stringplus::to_upper("foo bar");
// => "FOO BAR"
```

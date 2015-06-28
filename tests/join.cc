#include "Catch/catch.hpp"

#include "../src/stringplus.h"
#include <vector>
using namespace stringplus;
using namespace std;

TEST_CASE( "join", "[join]" ) {
  REQUIRE( join("", {"Hello", " ", "world", "!"}) == "Hello world!" );
  REQUIRE( join(" ", {"foo", "bar"}) == "foo bar" );
}

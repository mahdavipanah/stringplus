#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "repeat", "[repeat]" ) {
  REQUIRE( repeat("foo", 3, "bar") == "foobarfoobarfoo" );
  REQUIRE( repeat("foo", 3) == "foofoofoo" );
}

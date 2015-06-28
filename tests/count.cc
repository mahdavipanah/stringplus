#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "count", "[count]" ) {
  REQUIRE( count("Hello world", "l") == 3 );
  REQUIRE( count("Hello world", "Hello") == 1 );
  REQUIRE( count("Hello world", "foo") == 0 );
  REQUIRE( count("x.xx....x.x", "x") == 5 );
  REQUIRE( count("x.xx....x.x", "") == 0 );
}

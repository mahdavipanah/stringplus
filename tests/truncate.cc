#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "truncate", "[truncate]" ) {
  REQUIRE( truncate("Hello world", 5) == "Hello..." );
  REQUIRE( truncate("Hello", 10) == "Hello" );
  REQUIRE( truncate("Hello world", 5, " read more") == "Hello read more" );
}

#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "clean", "[clean]" ) {
  REQUIRE( clean(" foo    bar   ") == "foo bar" );
  REQUIRE( clean("") == "" );
  REQUIRE( clean(" ") == "" );
}

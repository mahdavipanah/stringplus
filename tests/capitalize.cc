#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "capitalize", "[capitalize]" ) {
  REQUIRE( capitalize("abcd") == "Abcd" );
  REQUIRE( capitalize("aBCD", true) == "Abcd" );
}

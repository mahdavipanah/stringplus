#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "pad", "[pad]" ) {
  REQUIRE( pad("1", 8) == "       1" );
  REQUIRE( pad("1", 8, '0', "right") == "10000000" );
  REQUIRE( pad("1", 8, '0', "both") == "00001000" );
  REQUIRE( pad("1", 8, '0', "left") == "00000001" );
  REQUIRE( pad("1", 8, '0') == "00000001" );
}

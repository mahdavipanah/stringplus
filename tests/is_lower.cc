#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "is_lower", "[is_lower]" ) {
  REQUIRE( is_lower("1234") == true );
  REQUIRE( is_lower("34n4") == true );
  REQUIRE( is_lower("34M") == false );
}

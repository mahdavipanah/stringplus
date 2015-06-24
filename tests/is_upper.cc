#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "is_upper", "[is_upper]" ) {
  REQUIRE( is_upper("1234") == true );
  REQUIRE( is_upper("34N4") == true );
  REQUIRE( is_upper("34n") == false );
}

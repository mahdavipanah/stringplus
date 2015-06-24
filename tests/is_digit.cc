#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "is_digit", "[is_digit]" ) {
  REQUIRE( is_digit("1234") == true );
  REQUIRE( is_digit("34n4") == false );
}

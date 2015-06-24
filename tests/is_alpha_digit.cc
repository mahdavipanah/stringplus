#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "is_alpha_digit", "[is_alpha_digit]" ) {
  REQUIRE( is_alpha_digit("1234") == true );
  REQUIRE( is_alpha_digit("34n4") == true );
  REQUIRE( is_alpha_digit("34n[") == false );
}

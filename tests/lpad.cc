#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "lpad", "[lpad]" ) {
  REQUIRE( lpad("1", 8, '0') == "00000001" );
}

#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "lrpad", "[lrpad]" ) {
  REQUIRE( lrpad("1", 8, '0') == "00001000" );
}

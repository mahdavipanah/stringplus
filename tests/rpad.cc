#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "rpad", "[rpad]" ) {
  REQUIRE( rpad("1", 8, '0') == "10000000" );
}

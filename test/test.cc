#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()
#include "CATCH/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "to_upper", "[to_upper]" ) {
  REQUIRE( to_upper("abcd") == "ABCD" );
  REQUIRE( to_upper("ABCD") == "ABCD" );
  REQUIRE( to_upper("1234[") == "1234[" );
}

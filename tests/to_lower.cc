#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "to_lower", "[to_lower]" ) {
  REQUIRE( to_lower("ABCD") == "abcd" );
  REQUIRE( to_lower("abcd") == "abcd" );
  REQUIRE( to_lower("1234[") == "1234[" );
}

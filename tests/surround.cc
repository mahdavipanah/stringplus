#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "surround", "[surround]" ) {
  REQUIRE( surround("foo", "bar") == "barfoobar" );
}

#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "reverse", "[reverse]" ) {
  REQUIRE( reverse("Hello") == "olleH" );
  REQUIRE( reverse("12345") == "54321" );
}

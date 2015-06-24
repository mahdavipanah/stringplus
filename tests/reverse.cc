#include "Catch/catch.hpp"

#include "../src/stringplus.h"
#include <algorithm>
using namespace stringplus;
using namespace std;

TEST_CASE( "reverse", "[reverse]" ) {
  REQUIRE( reverse("Hello") == "olleH" );
  REQUIRE( reverse("12345") == "54321" );
}

#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "ends_with", "[ends_with]" ) {
  REQUIRE( ends_with("image.gif", "gif") == true );
  REQUIRE( ends_with("image.old.gif", "old") == false );  
  REQUIRE( ends_with("image.old.gif", "old", 9) == true );
}

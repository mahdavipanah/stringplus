#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "decapitalize", "[decapitalize]" ) {
  REQUIRE( decapitalize("ABCD") == "aBCD" );
}

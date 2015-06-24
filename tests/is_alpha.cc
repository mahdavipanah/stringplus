#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "is_alpha", "[is_alpha]" ) {
  REQUIRE( is_alpha("abcd") == true );
  REQUIRE( is_alpha("Abn4") == false );
}

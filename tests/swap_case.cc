#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "swap_case", "[swap_case]" ) {
  REQUIRE( swap_case("AaBbCcDdEe") == "aAbBcCdDeE" );
  REQUIRE( swap_case("Hello World") == "hELLO wORLD" );
  REQUIRE( swap_case("123456") == "123456" );
  REQUIRE( swap_case("+-~_[})") == "+-~_[})" );
}

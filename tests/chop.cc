#include "Catch/catch.hpp"

#include "../src/stringplus.h"
#include <vector>
using namespace stringplus;
using namespace std;

TEST_CASE( "chop", "[chop]" ) {
  REQUIRE( chop("whitespace", 3) == vector<string>({"whi", "tes", "pac", "e"}) );
  REQUIRE( chop("12345", 1) == vector<string>({"1" ,"2", "3", "4", "5"}) );
}

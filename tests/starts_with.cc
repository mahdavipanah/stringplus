#include "Catch/catch.hpp"

#include "../src/stringplus.h"
using namespace stringplus;

TEST_CASE( "starts_with", "[starts_with]" ) {
  REQUIRE( starts_with("image.gif", "image") == true );
  REQUIRE( starts_with(".vimrc", "vim") == false );
  REQUIRE( starts_with(".vimrc", "vim", 1) == true );
}

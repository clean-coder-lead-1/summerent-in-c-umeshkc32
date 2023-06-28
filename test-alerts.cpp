#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits for too low") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits for too high") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits for normal") {
  REQUIRE(inferBreach(24, 20, 30) == NORMAL);
}

TEST_CASE("classify temperature breach for too low") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
}

TEST_CASE("classify temperature breach for too high") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 36) == TOO_HIGH);
}

TEST_CASE("classify temperature breach for normal") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 10) == NORMAL);
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Student.hpp"

TEST_CASE("greet returns correct message") {
    CHECK(greet("Avi")   == "Welcome to CPP course, Avi!");
    CHECK(greet("Erel")     == "Welcome to CPP course, Erel!");
    CHECK(greet("Elina") == "Welcome to CPP course, Elina!");
    CHECK(greet("Herut") == "Welcome to CPP course, Herut!");
    CHECK(greet("Shachar") == "Welcome to CPP course, Shachar!");
}

TEST_CASE("greet works with any name") {
    CHECK(greet("Dana")  == "Welcome to CPP course, Dana!");
    CHECK(greet("Eve")   == "Welcome to CPP course, Eve!");
}

TEST_CASE("greet output is not empty") {
    CHECK(!greet("Alice").empty());
}

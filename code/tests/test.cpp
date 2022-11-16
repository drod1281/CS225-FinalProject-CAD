#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "DrawGraph.h"

TEST_CASE("Correct something idk", "[weight=5]") {
    V2D roster = file_to_V2D("../tests/data/c5_s10_3_roster.csv"); //change to find the right vector of ratee

    //change to be the vectors we wrote down
    const V2D correct_roster = {{"CS577", "JydY", "MnWd", "tnkL"},\
    {"CS591", "gpDS", "94Ol", "tnkL"}, \
    {"CS386", "SjC0", "EYge", "Nvu1"}, \
    {"CS500", "MnWd", "uAcT", "EYge"}, \
    {"CS395", "gpDS", "EYge", "MnWd"}
    }; 

    REQUIRE(roster == correct_roster);

}
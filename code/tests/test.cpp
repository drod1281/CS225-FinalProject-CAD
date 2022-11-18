#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "DrawGraph.h"
#include "BTCGraph.h"

TEST_CASE("Test id 69,100,26,781 work with default constructor") {
    BTCGraph* graph = new BTCGraph();
    std::vector<std::pair<std::string, int>> list69 = graph->getAdjacencyList("69");
    std::vector<std::pair<std::string, int>> correct69 = {std::make_pair("35", 1), std::make_pair("39", 2), std::make_pair("23", 1), std::make_pair("28", 3), std::make_pair("62", 1), std::make_pair("81", 2), std::make_pair("99", 1), std::make_pair("1185", 1), std::make_pair("115", 3)};

    REQUIRE(list69 == correct69);

    std::vector<std::pair<std::string, int>> list100 = graph->getAdjacencyList("100");
    std::vector<std::pair<std::string, int>> correct100 = {std::make_pair("7", 2), std::make_pair("132", 1), std::make_pair("111", 1), std::make_pair("64", 1), std::make_pair("60", 2), std::make_pair("202", 1), std::make_pair("781", 1), std::make_pair("1810", 1)};

    REQUIRE(list100 == correct100);

    std::vector<std::pair<std::string, int>> list26 = graph->getAdjacencyList("26");
    std::vector<std::pair<std::string, int>> correct26 = {std::make_pair("4", 1), std::make_pair("680", 1), std::make_pair("626", 2), std::make_pair("780", 2), std::make_pair("937", 2), std::make_pair("1863", 2), std::make_pair("1985", 2), std::make_pair("2130", 1), std::make_pair("2128", 2), std::make_pair("35", 1), std::make_pair("804", 1)};

    REQUIRE(list26 == correct26);

    std::vector<std::pair<std::string, int>> list781 = graph->getAdjacencyList("781");
    std::vector<std::pair<std::string, int>> correct781 = {std::make_pair("100", 1), std::make_pair("748", 1), std::make_pair("687", 1), std::make_pair("537", 1), std::make_pair("827", 3), std::make_pair("202", 1), std::make_pair("1127", 1), std::make_pair("1162", 1), std::make_pair("667", 2), std::make_pair("1053", 1), std::make_pair("1376", -5)};

    REQUIRE(list781 == correct781);
}

TEST_CASE("Test id 69,100,26,781 work with parameterized constructor") {
    BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");
    std::vector<std::pair<std::string, int>> list69 = graph->getAdjacencyList("69");
    std::vector<std::pair<std::string, int>> correct69 = {std::make_pair("35", 1), std::make_pair("39", 2), std::make_pair("23", 1), std::make_pair("28", 3), std::make_pair("62", 1), std::make_pair("81", 2), std::make_pair("99", 1), std::make_pair("1185", 1), std::make_pair("115", 3)};

    REQUIRE(list69 == correct69);

    std::vector<std::pair<std::string, int>> list100 = graph->getAdjacencyList("100");
    std::vector<std::pair<std::string, int>> correct100 = {std::make_pair("7", 2), std::make_pair("132", 1), std::make_pair("111", 1), std::make_pair("64", 1), std::make_pair("60", 2), std::make_pair("202", 1), std::make_pair("781", 1), std::make_pair("1810", 1)};

    REQUIRE(list100 == correct100);

    std::vector<std::pair<std::string, int>> list26 = graph->getAdjacencyList("26");
    std::vector<std::pair<std::string, int>> correct26 = {std::make_pair("4", 1), std::make_pair("680", 1), std::make_pair("626", 2), std::make_pair("780", 2), std::make_pair("937", 2), std::make_pair("1863", 2), std::make_pair("1985", 2), std::make_pair("2130", 1), std::make_pair("2128", 2), std::make_pair("35", 1), std::make_pair("804", 1)};

    REQUIRE(list26 == correct26);

    std::vector<std::pair<std::string, int>> list781 = graph->getAdjacencyList("781");
    std::vector<std::pair<std::string, int>> correct781 = {std::make_pair("100", 1), std::make_pair("748", 1), std::make_pair("687", 1), std::make_pair("537", 1), std::make_pair("827", 3), std::make_pair("202", 1), std::make_pair("1127", 1), std::make_pair("1162", 1), std::make_pair("667", 2), std::make_pair("1053", 1), std::make_pair("1376", -5)};

    REQUIRE(list781 == correct781);
}

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
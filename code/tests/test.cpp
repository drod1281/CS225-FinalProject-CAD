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

TEST_CASE("Test id 2688, 257, 4434, 3025, 2877, 257, 420, 397 work with default constructor") {
    BTCGraph* graph = new BTCGraph();
    std::vector<std::pair<std::string, int>> list2688 = graph->getAdjacencyList("2688");
    std::vector<std::pair<std::string, int>> correct2688 = {std::make_pair("304", 1), std::make_pair("2879", -10), std::make_pair("2866", 10), std::make_pair("3034", 1), std::make_pair("2402", 1), std::make_pair("2658", 1), std::make_pair("2934", 2), std::make_pair("3036", 1), std::make_pair("2880", 1), std::make_pair("2763", 2), std::make_pair("2795", -1), std::make_pair("2725", 1), std::make_pair("1317", 1), std::make_pair("2125", 1), std::make_pair("2296", 1), std::make_pair("3239", 1), std::make_pair("2028", 5), std::make_pair("312", -10), std::make_pair("2648", 2), std::make_pair("1810", -3)};

    REQUIRE(list2688.at(0) == correct2688.at(0));
    REQUIRE(list2688.at(list2688.size() - 1) == correct2688.at(correct2688.size() - 1));

    std::vector<std::pair<std::string, int>> list257 = graph->getAdjacencyList("257");
    std::vector<std::pair<std::string, int>> correct257 = {std::make_pair("60", 10), std::make_pair("224", 4), std::make_pair("314", 4), std::make_pair("346", 1), std::make_pair("359", 3), std::make_pair("372", 5), std::make_pair("41", 2), std::make_pair("339", 4), std::make_pair("400", 5), std::make_pair("333", 4), std::make_pair("397", 5), std::make_pair("406", 1), std::make_pair("284", 4), std::make_pair("309", 2), std::make_pair("361", 1), std::make_pair("415", 4), std::make_pair("2897", -1), std::make_pair("2877", -1)};

    REQUIRE(list257 == correct257);

    std::vector<std::pair<std::string, int>> list4434 = graph->getAdjacencyList("4434");
    std::vector<std::pair<std::string, int>> correct4434 = {std::make_pair("3892", 1), std::make_pair("4402", 1), std::make_pair("35", 2), std::make_pair("3642", 1), std::make_pair("4291", 1), std::make_pair("4511", 1), std::make_pair("2942", 1), std::make_pair("4304", 1), std::make_pair("2642", 2), std::make_pair("4554", 1), std::make_pair("1971", 1), std::make_pair("4172", -10), std::make_pair("4551", -10)};

    REQUIRE(list4434 == correct4434);

    std::vector<std::pair<std::string, int>> list3025 = graph->getAdjacencyList("3025");
    std::vector<std::pair<std::string, int>> correct3025 = {std::make_pair("539", -1), std::make_pair("1396", -2), std::make_pair("1318", 1), std::make_pair("135", -10), std::make_pair("361", -1), std::make_pair("2388", 10)};

    REQUIRE(list3025 == correct3025);

    std::vector<std::pair<std::string, int>> list2877 = graph->getAdjacencyList("2877");
    std::vector<std::pair<std::string, int>> correct2877 = {std::make_pair("2028", 1), std::make_pair("1810", 1), std::make_pair("135", -2), std::make_pair("630", -2), std::make_pair("1648", -1)};

    REQUIRE(list2877.at(0) == correct2877.at(0));
    REQUIRE(list2877.at(list2877.size() - 1) == correct2877.at(correct2877.size() - 1));

    std::vector<std::pair<std::string, int>> list397 = graph->getAdjacencyList("397");
    std::vector<std::pair<std::string, int>> correct397 = {std::make_pair("257", 5)};

    REQUIRE(list397 == correct397);

    std::vector<std::pair<std::string, int>> list420 = graph->getAdjacencyList("420");
    std::vector<std::pair<std::string, int>> correct420 = {std::make_pair("257", 6)};

    REQUIRE(list420 == correct420);
}

TEST_CASE("Test id 2688, 257, 4434, 3025, 2877, 257, 420, 397 work with parameterized constructor") {
    BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");
    std::vector<std::pair<std::string, int>> list2688 = graph->getAdjacencyList("2688");
    std::vector<std::pair<std::string, int>> correct2688 = {std::make_pair("304", 1), std::make_pair("2879", -10), std::make_pair("2866", 10), std::make_pair("3034", 1), std::make_pair("2402", 1), std::make_pair("2658", 1), std::make_pair("2934", 2), std::make_pair("3036", 1), std::make_pair("2880", 1), std::make_pair("2763", 2), std::make_pair("2795", -1), std::make_pair("2725", 1), std::make_pair("1317", 1), std::make_pair("2125", 1), std::make_pair("2296", 1), std::make_pair("3239", 1), std::make_pair("2028", 5), std::make_pair("312", -10), std::make_pair("2648", 2), std::make_pair("1810", -3)};

    REQUIRE(list2688 == correct2688);
    REQUIRE(list2688.at(list2688.size() - 1) == correct2688.at(correct2688.size() - 1));

    std::vector<std::pair<std::string, int>> list257 = graph->getAdjacencyList("257");
    std::vector<std::pair<std::string, int>> correct257 = {std::make_pair("60", 10), std::make_pair("224", 4), std::make_pair("314", 4), std::make_pair("346", 1), std::make_pair("359", 3), std::make_pair("372", 5), std::make_pair("41", 2), std::make_pair("339", 4), std::make_pair("400", 5), std::make_pair("333", 4), std::make_pair("397", 5), std::make_pair("406", 1), std::make_pair("284", 4), std::make_pair("309", 2), std::make_pair("361", 1), std::make_pair("415", 4), std::make_pair("2897", -1), std::make_pair("2877", -1)};

    REQUIRE(list257 == correct257);

    std::vector<std::pair<std::string, int>> list4434 = graph->getAdjacencyList("4434");
    std::vector<std::pair<std::string, int>> correct4434 = {std::make_pair("3892", 1), std::make_pair("4402", 1), std::make_pair("35", 2), std::make_pair("3642", 1), std::make_pair("4291", 1), std::make_pair("4511", 1), std::make_pair("2942", 1), std::make_pair("4304", 1), std::make_pair("2642", 2), std::make_pair("4554", 1), std::make_pair("1971", 1), std::make_pair("4172", -10), std::make_pair("4551", -10)};

    REQUIRE(list4434 == correct4434);

    std::vector<std::pair<std::string, int>> list3025 = graph->getAdjacencyList("3025");
    std::vector<std::pair<std::string, int>> correct3025 = {std::make_pair("539", -1), std::make_pair("1396", -2), std::make_pair("1318", 1), std::make_pair("135", -10), std::make_pair("361", -1), std::make_pair("2388", 10)};

    REQUIRE(list3025 == correct3025);

    std::vector<std::pair<std::string, int>> list2877 = graph->getAdjacencyList("2877");
    std::vector<std::pair<std::string, int>> correct2877 = {std::make_pair("2028", 1), std::make_pair("1810", 1), std::make_pair("135", -2), std::make_pair("630", -2), std::make_pair("1648", -1)};

    REQUIRE(list2877.at(0) == correct2877.at(0));
    REQUIRE(list2877.at(list2877.size() - 1) == correct2877.at(correct2877.size() - 1));

    std::vector<std::pair<std::string, int>> list397 = graph->getAdjacencyList("397");
    std::vector<std::pair<std::string, int>> correct397 = {std::make_pair("257", 5)};

    REQUIRE(list397 == correct397);

    std::vector<std::pair<std::string, int>> list420 = graph->getAdjacencyList("420");
    std::vector<std::pair<std::string, int>> correct420 = {std::make_pair("257", 6)};

    REQUIRE(list420 == correct420);
}

TEST_CASE("Test id 72, 111, 767, 921, 347 work with default constructor") {
    BTCGraph* graph = new BTCGraph();
 
    std::vector<std::pair<std::string, int>> list72 = graph->getAdjacencyList("72");
    std::vector<std::pair<std::string, int>> correct72 = {std::make_pair("4", 4), std::make_pair("7", 2), std::make_pair("132", 3), std::make_pair("943", 2), std::make_pair("579", 1), std::make_pair("113", 1), std::make_pair("667", 1), std::make_pair("1162", 1), std::make_pair("1701", 5), std::make_pair("2398", 1), std::make_pair("2328", 1)};
 
    REQUIRE(list72 == correct72);
 
    std::vector<std::pair<std::string, int>> list111 = graph->getAdjacencyList("111");
    std::vector<std::pair<std::string, int>> correct111 = {std::make_pair("7", 1), std::make_pair("100", 1), std::make_pair("1", 2), std::make_pair("499", 10), std::make_pair("104", 4), std::make_pair("3129", 1)};
 
    REQUIRE(list111 == correct111);
 
    std::vector<std::pair<std::string, int>> list767 = graph->getAdjacencyList("767");
    std::vector<std::pair<std::string, int>> correct767 = {std::make_pair("132", 5), std::make_pair("535", 1), std::make_pair("739", 1), std::make_pair("687", 1), std::make_pair("725", 1), std::make_pair("227", 1),std::make_pair("546", 2),std::make_pair("933", 1), std::make_pair("273", 1), std::make_pair("1043", 1), std::make_pair("3735", 1), std::make_pair("3738", 2)};
 
    REQUIRE(list767.at(0) == correct767.at(0));
    REQUIRE(list767.at(list767.size() - 1) == correct767.at(correct767.size() - 1));
 
    std::vector<std::pair<std::string, int>> list921 = graph->getAdjacencyList("921");
    std::vector<std::pair<std::string, int>> correct921 = {std::make_pair("920", 2), std::make_pair("1310", 2), std::make_pair("1267", 10), std::make_pair("1384", 2), std::make_pair("80", 3), std::make_pair("1399", 1),std::make_pair("350", 1), std::make_pair("1252", 3), std::make_pair("1396", 4), std::make_pair("468", 3), std::make_pair("204", 4),std::make_pair("592", 3)};
 
    REQUIRE(list921 == correct921);
 
    std::vector<std::pair<std::string, int>> list347 = graph->getAdjacencyList("347");
    std::vector<std::pair<std::string, int>> correct347 = {std::make_pair("29", 1), std::make_pair("357", 2), std::make_pair("393", 1), std::make_pair("405", 1), std::make_pair("202", 2), std::make_pair("350", 3),std::make_pair("1478", 1), std::make_pair("4172", -10)};
 
    REQUIRE(list347 == correct347);
}
 
TEST_CASE("Test id 72, 111, 767, 921, 347 work with parameterized constructor") {
    BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");
 
    std::vector<std::pair<std::string, int>> list72 = graph->getAdjacencyList("72");
    std::vector<std::pair<std::string, int>> correct72 = {std::make_pair("4", 4), std::make_pair("7", 2), std::make_pair("132", 3), std::make_pair("943", 2), std::make_pair("579", 1), std::make_pair("113", 1), std::make_pair("667", 1), std::make_pair("1162", 1), std::make_pair("1701", 5), std::make_pair("2398", 1), std::make_pair("2328", 1)};
 
    REQUIRE(list72 == correct72);
 
    std::vector<std::pair<std::string, int>> list111 = graph->getAdjacencyList("111");
    std::vector<std::pair<std::string, int>> correct111 = {std::make_pair("7", 1), std::make_pair("100", 1), std::make_pair("1", 2), std::make_pair("499", 10), std::make_pair("104", 4), std::make_pair("3129", 1)};
 
    REQUIRE(list111 == correct111);
 
    std::vector<std::pair<std::string, int>> list767 = graph->getAdjacencyList("767");
    std::vector<std::pair<std::string, int>> correct767 = {std::make_pair("132", 5), std::make_pair("535", 1), std::make_pair("739", 1), std::make_pair("687", 1), std::make_pair("725", 1), std::make_pair("227", 1),std::make_pair("546", 2),std::make_pair("933", 1), std::make_pair("273", 1), std::make_pair("1043", 1), std::make_pair("3735", 1), std::make_pair("3738", 2)};
 
    REQUIRE(list767.at(0) == correct767.at(0));
    REQUIRE(list767.at(list767.size() - 1) == correct767.at(correct767.size() - 1));
 
    std::vector<std::pair<std::string, int>> list921 = graph->getAdjacencyList("921");
    std::vector<std::pair<std::string, int>> correct921 = {std::make_pair("920", 2), std::make_pair("1310", 2), std::make_pair("1267", 10), std::make_pair("1384", 2), std::make_pair("80", 3), std::make_pair("1399", 1),std::make_pair("350", 1), std::make_pair("1252", 3), std::make_pair("1396", 4), std::make_pair("468", 3), std::make_pair("204", 4),std::make_pair("592", 3)};
 
    REQUIRE(list921 == correct921);
 
    std::vector<std::pair<std::string, int>> list347 = graph->getAdjacencyList("347");
    std::vector<std::pair<std::string, int>> correct347 = {std::make_pair("29", 1), std::make_pair("357", 2), std::make_pair("393", 1), std::make_pair("405", 1), std::make_pair("202", 2), std::make_pair("350", 3),std::make_pair("1478", 1), std::make_pair("4172", -10)};
 
    REQUIRE(list347 == correct347);
}

TEST_CASE("Test averages") {
    BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");

    double avg2688 = graph->getAverage("2688");
    double correctAvg2688 = ((1.0 - 10.0 + 10.0 + 1.0 + 1.0 + 1.0 + 2.0 + 1.0 + 1.0 + 2.0 - 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 5.0 - 10.0 + 2.0 - 3.0) / 20.0);
 
    REQUIRE(avg2688 == correctAvg2688);
 
    double avg257 = graph->getAverage("257");
    double correctAvg257 = ((10.0 + 4.0 + 4.0 + 1.0 + 3.0 + 5.0 + 2.0 + 4.0 + 5.0 + 4.0 + 5.0 + 1.0 + 4.0 + 2.0 + 1.0 + 4.0 - 1.0 - 1.0) / 18.0);
 
    REQUIRE(avg257 == correctAvg257);

    double avg4434 = graph->getAverage("4434");
    double correctAvg4434 = ((1.0 + 1.0 + 2.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 2.0 + 1.0 + 1.0 - 10.0 - 10.0) / 13.0);
 
    REQUIRE(avg4434 == correctAvg4434);

    double avg3025 = graph->getAverage("3025");
    double correctAvg3025 = ((1.0 - 1.0 - 2.0 - 10.0 - 1.0 + 10.0) / 6.0);
 
    REQUIRE(avg3025 == correctAvg3025); //BFS doesn't reach

    double avg2877 = graph->getAverage("2877");
    double correctAvg2877 = ((1.0 + 1.0 - 2.0 - 2.0 - 1.0) / 5.0);
 
    REQUIRE(avg2877 == correctAvg2877);

    double avg397 = graph->getAverage("397");
    double correctAvg397 = (5.0);
 
    REQUIRE(avg397 == correctAvg397);

    double avg420 = graph->getAverage("420");
    double correctAvg420 = (6.0);
 
    REQUIRE(avg420 == correctAvg420); //BFS doesn't reach

 
}


TEST_CASE("test averages 69, 100, 26, 781") {
    BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");
    
    double avg69 = graph->getAverage("69");
    double correctAvg69 = ((1.0 + 2.0 + 1.0 + 3.0 + 1.0 + 2.0 + 1.0 + 1.0 + 3.0) / 9.0);
 
    REQUIRE(avg69 == correctAvg69);
    
    double avg100 = graph->getAverage("100");
    double correctAvg100 = ((2.0 + 1.0 + 1.0 + 1.0 + 2.0 + 1.0 + 1.0 + 1.0) / 8.0);
 
    REQUIRE(avg100 == correctAvg100);

    double avg26 = graph->getAverage("26");
    double correctAvg26 = ((1.0 + 1.0 + 2.0 + 2.0 + 2.0 + 2.0 + 2.0 + 1.0 + 2.0 + 1.0 + 1.0) / 11.0);
 
    REQUIRE(avg26 == correctAvg26);
    
    double avg781 = graph->getAverage("781");
    double correctAvg781 = ((1.0 + 1.0 + 1.0 + 1.0 + 3.0 + 1.0 + 1.0 + 1.0 + 2.0 + 1.0 - 5.0) / 11.0);
 
    REQUIRE(avg781 == correctAvg781);
}


TEST_CASE("test avg 72, 111, 767, 921, 347"){
   BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");

    double avg72 = graph->getAverage("72");
    double correctAvg72 = ((4.0 + 2.0 + 3.0 + 2.0 + 1.0 + 1.0 + 1.0 + 1.0 + 5.0 + 1.0 + 1.0) / 11.0);
 
    REQUIRE(avg72 == correctAvg72);
    
    double avg111 = graph->getAverage("111");
    double correctAvg111 = ((1.0 + 1.0 + 2.0 + 10.0 + 4.0 + 1.0) / 6.0);
 
    REQUIRE(avg111 == correctAvg111);
    
    double avg767 = graph->getAverage("767");
    double correctAvg767 = ((5.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 2.0 + 1.0 + 1.0 + 1.0+ 1.0 + 2.0) / 12.0);
 
    REQUIRE(avg767 == correctAvg767);

    double avg921 = graph->getAverage("921");
    double correctAvg921 = ((2.0 + 2.0 + 10.0 + 2.0 + 3.0 + 1.0 + 1.0 + 3.0 + 4.0 + 3.0 + 4.0 + 3.0) / 12.0);
 
    REQUIRE(avg921 == correctAvg921);

    double avg347 = graph->getAverage("347");
    double correctAvg347 = ((1.0 + 2.0 + 1.0 + 1.0 + 2.0 + 3.0 + 1.0 - 10.0) / 8.0);
 
    REQUIRE(avg347 == correctAvg347); 
 
}

TEST_CASE("prim"){
    BTCGraph* graph = new BTCGraph("../data/soc-sign-bitcoinotc.csv");
    Prim* prim = new Prim(graph, "420");
    std::unordered_map<string, std::vector<std::pair<std::string, int>>> mst = prim.getMST();

    for (int i = 0; i < (int) mst.size(); ++i){
        std::cout << "{ ";
        for(int j = 0; j < (int) mst[i].size()-1; ++j){
        std::cout << "\"" << mst[i][j] << "\", ";
        }
        std::cout << "\"" << mst[i][mst[i].size()-1] << "\"}, \\" << std::endl;
    }
}
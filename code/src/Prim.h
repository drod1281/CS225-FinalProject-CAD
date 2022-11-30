#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Prim {
    public:
        PrimMST();
        PrimMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph, unordered_map<string, double> & averages_, string & startPoint);
        unordered_map<string, std::pair<std::string, int>> getMST();
        void buildMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph, unordered_map<string, double> & averages_, string & startPoint);

    private:
        unordered_map<string, std::pair<std::string, int>> mst; //help
};
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
#include <map>
#include <limits>

using namespace std;

class Prim {
    public:
        Prim();
        Prim(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph,  string & startPoint);
        unordered_map<string, std::vector<std::pair<std::string, int>>> getMST();
        void buildMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph,  string & startPoint);

    private:
        std::unordered_map<string, std::vector<std::pair<std::string, int>>> mst;
};
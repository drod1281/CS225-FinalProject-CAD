#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class BTCGraph {
    public:
    BTCGraph();
    BTCGraph(std::string filename);
    ~BTCGraph();
    std::vector<std::pair<std::string, int>> getAdjacencyList(std::string node);
    
    private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph_;
    
};
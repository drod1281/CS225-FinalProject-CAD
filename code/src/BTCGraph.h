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
    
    private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph_;
    
};
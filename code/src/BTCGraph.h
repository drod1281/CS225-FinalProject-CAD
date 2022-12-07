#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
// #include <Graphviz/bin/cgraph.exp>
// #include <Graphviz/bin/gvc.exp>

using namespace std;

class BTCGraph {
    public:
        BTCGraph();
        BTCGraph(std::string filename);
        ~BTCGraph();
        std::vector<std::pair<std::string, int>> getAdjacencyList(std::string node);
        double getAverage(std::string node);
        void makeAverageMap();
        unordered_map<string, std::vector<std::pair<std::string, int>>> getGraph();
        void printGraph();
    
    private:
        unordered_map<string, vector<pair<string, int>>> graph_;
        unordered_map<string, double> averages_;
        string startPoint;
    
};
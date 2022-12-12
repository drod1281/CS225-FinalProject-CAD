#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

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
<<<<<<< HEAD
        unordered_map<string, vector<pair<string, int>>> graph_;
        unordered_map<string, double> averages_;
        string startPoint;
=======
        unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph_;
        unordered_map<std::string, double> averages_;
        std::vector<std::string> keys;
        std::string startPoint;
>>>>>>> d315eed4ecc7628334dbdb3a321f7b12933f1482
    
};
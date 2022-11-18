#include "BTCGraph.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>

BTCGraph::BTCGraph(std::string filename) {
    std::ifstream ifs;
    ifs.open(filename, std::ifstream::in);
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;
    
    if(ifs.is_open()) {
        while(getline(ifs, line)) {
            row.clear();
            
            stringstream str(line);
            
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            content.push_back(row);
        }
    }

    for(int i = 0; i < (int)content.size(); i++) {
        std::vector<std::string> iter = content[i];
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = graph_.find(iter[1]);
        int rating = stoi(iter[2]);
        if (it != graph_.end()) {
            it->second.push_back(std::make_pair(iter[0], rating));
        } else {
            std::vector<std::pair<std::string, int>> vect;
            vect.push_back(std::make_pair(iter[0], rating));
            graph_[iter[1]] = vect;
        }
    }
}

BTCGraph::~BTCGraph(){}

BTCGraph::BTCGraph() {
    std::ifstream ifs;
    ifs.open("../data/soc-sign-bitcoinotc.csv", std::ifstream::in);
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;
    
    if(ifs.is_open()) {
        while(getline(ifs, line)) {
            row.clear();
            
            stringstream str(line);
            
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            content.push_back(row);
        }
    }

    for(int i = 0; i < (int)content.size(); i++) {
        std::vector<std::string> iter = content[i];
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = graph_.find(iter[1]);
        int rating = stoi(iter[2]);
        if (it != graph_.end()) {
            it->second.push_back(std::make_pair(iter[0], rating));
        } else {
            std::vector<std::pair<std::string, int>> vect;
            vect.push_back(std::make_pair(iter[0], rating));
            graph_[iter[1]] = vect;
        }
    }
}

std::vector<std::pair<std::string, int>> BTCGraph::getAdjacencyList(std::string node) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = graph_.find(node);
    return it->second;
}
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
        if (i == 0) {
            startPoint = iter[1];
        }
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
    makeAverageMap();
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
        if (i == 0) {
            startPoint = iter[1];
        }
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
    makeAverageMap();
}

std::vector<std::pair<std::string, int>> BTCGraph::getAdjacencyList(std::string node) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = graph_.find(node);
    if (it != graph_.end()) {
        return it->second;
    } else {
        std::vector<std::pair<std::string, int>> empty;
        return empty;
    }
}

void BTCGraph::makeAverageMap(){ //make sure we have destination vertex in graph, the vertices that dont get reached dont send out any ratings.
    std::queue<std::string> q;
    std::set<std::string> inside;
    q.push(startPoint);
    inside.insert(startPoint);
    while (!q.empty()) {
        std::string curr = q.front();
        q.pop();
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator iter = graph_.find(curr);
        if (iter != graph_.end()) {
            std::vector<std::pair<std::string, int>> list = iter->second;
            double sum = 0;
            for (size_t i = 0; i < list.size(); i++) {
                if (inside.find(list[i].first) == inside.end()) {
                    q.push(list[i].first);
                    inside.insert(list[i].first);
                }
                sum += (double)list[i].second;
            }
            double average = sum / (double)list.size();
            averages_[iter->first] = average;
        }

    }
}

double BTCGraph::getAverage(std::string node) {
    std::unordered_map<std::string, double>::iterator it = averages_.find(node);
    if (it != averages_.end()) {
        return it->second;
    } else {
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator iter = graph_.find(node);
        if (iter != graph_.end()) {
            std::vector<std::pair<std::string, int>> list = iter->second;
            double sum = 0;
            for (size_t i = 0; i < list.size(); i++) {
                sum += (double)list[i].second;
            }
            double average = sum / (double)list.size();
            averages_[iter->first] = average;
            return average;
        } else {
            return -11.0;
        }
    }
}

unordered_map<string, std::vector<std::pair<std::string, int>>> BTCGraph::getGraph() {
    return graph_;
}

void BTCGraph::printGraph() {
    
}
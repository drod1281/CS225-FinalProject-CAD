#include "BTCGraph.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"

using cs225::HSLAPixel;
using cs225::PNG;

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
        keys.push_back(iter[1]);
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
        keys.push_back(iter[1]);
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

std::vector<std::string> BTCGraph::getKeys() {
    return keys;
}

void BTCGraph::printGraph() {
    // Agraph_t* graph = agopen("graph", Agstrictdirected, nullptr);
    // std::queue<std::string> q;
    // std::set<std::string> inside;
    // q.push(startPoint);
    // inside.insert(startPoint);
    // while (!q.empty()) {
    //     std::string curr = q.front();
    //     q.pop();
    //     std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator iter = graph_.find(curr);
    //     if (iter != graph_.end()) {
    //         std::vector<std::pair<std::string, int>> list = iter->second;
    //         Agnode_t* node = agnode(graph, const_cast<char*>(iter->first.c_str()), 1);
    //         for (std::pair<std::string, int> dest : list) {
    //             AGnode_t* dNode = agnode(graph, const_cast<char*>(dest.first.c_str()), 1);
    //             Agedge_t* edge = agedge(graph, node, dNode, nullptr, 1);
    //             agsafeset(edge, "weight", to_string(dest.second).c_str(), "");
    //         }
    //     }

    // }

    PNG graphPNG(width, height);

    std::map<std::string, std::pair<int, int>> idToCoord;
    for(std::string v : keys) {
        int x = (std::rand() % graphPNG.width());
        int y = (std::rand() % graphPNG.height());
        
        bool coordNotInCircle = true;
        for(std::string coord : idToCoord){
            int xInPng = coord.first;
            int yInPng = coord.second;
            if( (x >= (xInPng - r)) && (x <= (xInPng + r)) && (y >= (yInPng - r)) && (y <= (yInPng + r)) ){
                coordNotInCircle = false;
                break;
            }
        }

        if(coordNotInCircle == true) {
            idToCoord[v] = (x, y);
            for(unsigned int i = (x - r); i <= (x + r); i++){
                for(unsigned int j = (y - r); j<= (y + r); j++){
                    if( ( (i - x) * (i - x) ) + ( (j - y) * (j - y) ) <= (r * r) ){
                        graphPNG.getPixel(i, j) = HSLAPixel(0, 1, 0.5);
                    }
                }
            }
        }
    }

    //for(std::pair<std::string, >)

    graphPNG.writeToFile("../drawnGraph.png");
}
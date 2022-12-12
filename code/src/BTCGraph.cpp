#include "BTCGraph.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <map>
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

    PNG graphPNG((graph_.size() * 2.5), (graph_.size() * 2.5));

    std::map<std::string, std::pair<int, int>> idToCoord;
    int r = 5;

    for(std::string v : keys) {
        int x = (std::rand() % graphPNG.width());
        int y = (std::rand() % graphPNG.height());
        
        while (x < 0 || x >= (int)graphPNG.width() || y < 0 || y >= (int)graphPNG.height()) {
            x = (std::rand() % graphPNG.width());
            y = (std::rand() % graphPNG.height());
        }

        bool coordNotInCircle = true;
        for(std::pair<std::string, std::pair<int, int>> vert : idToCoord){
            std::pair<int, int> coord = vert.second;
            int xInPng = coord.first;
            int yInPng = coord.second;
            if( (x >= (xInPng - r)) && (x <= (xInPng + r)) && (y >= (yInPng - r)) && (y <= (yInPng + r)) ){
                coordNotInCircle = false;
                break;
            }
        }

        if(coordNotInCircle == true) {
            idToCoord[v] = std::make_pair(x, y);
            for(int i = (x - r); i <= (x + r); i++){
                for(int j = (y - r); j<= (y + r); j++){
                    if((i >= 0) && (i < (int)graphPNG.width()) && (j >= 0) && (j < (int)graphPNG.height())){
                        if( ( (i - x) * (i - x) ) + ( (j - y) * (j - y) ) <= (r * r) ){
                            graphPNG.getPixel(i, j) = HSLAPixel(0, 1, 0.5);
                        }
                    }
                }
            }
        }
    }

    for(std::pair<std::string, std::vector<std::pair<std::string, int>>> pairVE : graph_) {

        std::pair<int, int> coord1 = idToCoord[pairVE.first];
        int x1 = coord1.first;
        int y1 = coord1.second;
        for(unsigned long i = 0; i < pairVE.second.size(); i++){
                std::pair<int, int> coord2 = idToCoord[pairVE.second[i].first];
                int x2 = coord2.first;
                int y2 = coord2.second;
                
                int dx = (x2 - x1);
                int dy = (y2 - y1);
                int sx = (dx >= 0) ? 1 : -1;
                int sy = (dy >= 0) ? 1 : -1;
                dx = abs(dx);
                dy = abs(dy);

                if(dx == dy){
                    for(int i = 0; i < dx; i++){
                        graphPNG.getPixel(x1 + i * sx, y1 + i * sy) = HSLAPixel(0, 4, 0.5);
                    }
                }
                //can add counter that gets added to H, S, L to have a different line color per vertix to its vector of edges
                else {
                    int d = ((dy << 1) - dx);
                    int d1 = (dy << 1);
                    int d2 = ((dy - dx) << 1);
                    int x = x1;
                    int y = y1;
                    if((x >= 0) && (x < (int)graphPNG.width()) && (y >= 0) && (y < (int)graphPNG.height())){
                        graphPNG.getPixel(x, y) = HSLAPixel(0, 4, 0.5);
                    }
                    if(dx > dy) {
                        int p = (d - dx);
                        while (x != x2) {
                            x = (x + sx);
                            if(p > 0){
                                y = (y + sy);
                                p = (p + d2);
                            }
                            else {
                                p = (p + d1);
                            }
                            if((x >= 0) && (x < (int)graphPNG.width()) && (y >= 0) && (y < (int)graphPNG.height())){
                                graphPNG.getPixel(x, y) = HSLAPixel(0, 4, 0.5);
                            }
                        }
                    }
                    else {
                        int  p = (d - dy);
                        while (y != y2) {
                            y = (y + sy);
                            if(p > 0) {
                                x = (x + sx);
                                p = (p + d2);
                            }
                            else {
                                p = (p + d1);
                            }
                            if((x >= 0) && (x < (int)graphPNG.width()) && (y >= 0) && (y < (int)graphPNG.height())){
                                graphPNG.getPixel(x, y) = HSLAPixel(0, 4, 0.5);
                            }
                        }
                    }
                }
        }
    }

    graphPNG.writeToFile("../drawnGraph.png");
}
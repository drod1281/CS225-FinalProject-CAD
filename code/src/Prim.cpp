#include "Prim.h"
#include "heap.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

Prim::PrimMST(){}

Prim::PrimMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph, unordered_map<string, double> & averages_, string & startPoint){
    buildMST(graph, averages_, startPoint);
}   


void Prim::buildMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph, unordered_map<string, double> & averages_, string & startPoint) {
    auto vert_selector = [](auto pair){return pair.first};
    
    vector<string> vert(graph.size());
    std::transform(graph.begin(), graph.end(), vert.begin(), vert_selector);
    std::set<std::string> inside;

    heap<string> heap;
    heap.buildHeap(vert);


    while (inside.size() != graph.size()){
        string m = heap.pop(); //removeMin, make minHeap
        inside.insert(m);
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = graph.find(m);
        if (it != graph.end()) {
            std::vector<std::pair<std::string, int>> copy;
            for (size_t i = 0; i < it->second.size(); i++) {
                if (inside.find(it->second.at(i)) == inside.end()) {
                    copy.push_back(it->second.at(i));
                }
            }
            std::pair<std::string, int> least = copy.at(0);
            for (std::pair<std::string, int> x : copy) {
                if (x.second < least.second) {
                    least = x;
                }
            }
            mst[m] = least;
        }
    }

    return mst;
}

unordered_map<string, std::pair<std::string, int>> Prim::getMST() {
    return mst;
}

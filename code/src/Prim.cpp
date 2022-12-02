#include "Prim.h"
#include "heap.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

Prim::PrimMST(){}

Prim::PrimMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph,  string & startPoint){
    buildMST(graph, startPoint);
}   


void Prim::buildMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph, string & startPoint) {
    auto vert_selector = [](auto pair){return pair.first};
    
    vector<string> vert(graph.size());
    std::transform(graph.begin(), graph.end(), vert.begin(), vert_selector);
    std::set<std::string> inside;

    std::map<std::string, int> d;
    std::map<std::string, std::string> p;

    for (std::string v : vert) {
        d[v] = std::numeric_limits<int>::max();
        p[v] = " ";
    }
    d[startPoint] = 0;

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
            for (std::pair<std::string, int> x : copy) {
                if (x.second < d[x]) {
                    d[x] = x.second;
                    p[x] = m;
                }
            }
        }
    }

    for (std::map<std::string, std::string>::iterator it = p.begin(); it != p.end(); it++) {
        std::map<std::string, int>::iterator rating = d.find(it->first);
        if (rating != d.end()) {
            unordered_map<string, std::vector<std::pair<std::string, int>>>::iterator m = mst.find(it->second);
            if (m != mst.end()) {
                m->second.push_back(std::make_pair(it->first, rating->second));
            } else {
                std::vector<std::pair<std::string, int>> vect;
                vect.push_back(std::make_pair(it->first, rating->second));
                mst[it->second] = vect;
            }
        }
    }
}

unordered_map<string, std::pair<std::string, int>> Prim::getMST() {
    return mst;
}

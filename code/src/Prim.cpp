#include "Prim.h"
#include "heap.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

Prim::Prim(){}

Prim::Prim(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph,  string startPoint){
    buildMST(graph, startPoint);
}   


void Prim::buildMST(unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph, string startPoint) {
    
    std::set<std::string> inside;
    std::vector<std::string> keys;

    for (auto kv : graph) {
        keys.push_back(kv.first);
    }

    std::map<std::string, int> d;
    std::map<std::string, std::string> p;

    for (std::string v : keys) {
        d[v] = std::numeric_limits<int>::max();
        p[v] = " ";
    }
    d[startPoint] = 0;

    heap<string> heap(keys);


    while (inside.size() != graph.size()){
        string m = heap.pop(); //removeMin, make minHeap
        inside.insert(m);
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = graph.find(m);
        if (it != graph.end()) {
            std::vector<std::pair<std::string, int>> copy;
            std::vector<std::pair<std::string, int>> list = it->second;
            for (size_t i = 0; i < list.size(); i++) {
                std::set<std::string>::iterator curr = inside.find(list.at(i).first);
                if (curr == inside.end()) {
                    copy.push_back(list.at(i));
                }
            }
            for (std::pair<std::string, int> x : copy) {
                std::map<std::string, int>::iterator search = d.find(x.first);
                if (search != d.end()) {
                    if (x.second < search->second) {
                        d[x.first] = x.second;
                        p[x.first] = m;
                    }
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

unordered_map<string, std::vector<std::pair<std::string, int>>> Prim::getMST() {
    return mst;
}

std::vector<std::pair<std::string, int>> Prim::getList(std::string node) {
    unordered_map<string, std::vector<std::pair<std::string, int>>>::iterator it = mst.find(node);
    if (it != mst.end()) {
        return it->second;
    } else {
        std::vector<std::pair<std::string, int>> list;
        return list;
    }
}

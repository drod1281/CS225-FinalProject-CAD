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

    std::map<std::string, std::vector<std::pair<std::string, int>>> newGraph(graph.begin(), graph.end());
    for (std::map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = newGraph.begin(); it != newGraph.end(); it++) { //this for loop makes the graph undirected by adding sinks to sources edge list
        for (std::pair<std::string, int> x : it->second) {
            std::map<std::string, std::vector<std::pair<std::string, int>>>::iterator search = newGraph.find(x.first);
            if (search != newGraph.end()) {
                bool in = false;
                for (std::pair<std::string, int> s : search->second) { 
                    if (it->first == s.first) { //checks if sink is already in sources adjacency list
                        in = true;
                        break;
                    }
                }
                if (!in) { //if it's not then we push it back
                    search->second.push_back(std::make_pair(it->first, x.second));
                }
            } else {
                std::vector<std::pair<std::string, int>> insert;
                insert.push_back(std::make_pair(it->first, x.second));
                newGraph[x.first] = insert;
            }
        }
    }
    
    std::set<std::string> inside;
    std::vector<std::string> keys;

    for (auto kv : newGraph) { //gets all the keys in the graph
        keys.push_back(kv.first);
    }

    std::map<std::string, int> d;
    std::map<std::string, std::string> p;

    for (std::string v : keys) { //sets distance map to max distance and predecessor to no one
        d[v] = std::numeric_limits<int>::max();
        p[v] = " ";
    }
    d[startPoint] = 0;

    heap<string> heap(keys);


    while (inside.size() != newGraph.size()){ //stops when set has every key inside of it
        string m = heap.pop(); //removeMin, make minHeap
        inside.insert(m);
        std::map<std::string, std::vector<std::pair<std::string, int>>>::iterator it = newGraph.find(m);
        if (it != newGraph.end()) {
            std::vector<std::pair<std::string, int>> copy;
            std::vector<std::pair<std::string, int>> list = it->second;
            for (size_t i = 0; i < list.size(); i++) { //makes list of nodes not already in the MST
                std::set<std::string>::iterator curr = inside.find(list.at(i).first);
                if (curr == inside.end()) {
                    copy.push_back(list.at(i));
                }
            }
            for (std::pair<std::string, int> x : copy) { //iterates through list of nodes not in MST and updates their distance and predecessor if needed
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

    for (std::map<std::string, std::string>::iterator it = p.begin(); it != p.end(); it++) { //iterates tghrough predecessor map to populate the MST using map manipulation
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

std::vector<std::pair<std::string, int>> Prim::getList(std::string node) { //returns adjacency list for a node
    unordered_map<string, std::vector<std::pair<std::string, int>>>::iterator it = mst.find(node);
    if (it != mst.end()) {
        return it->second;
    } else {
        std::vector<std::pair<std::string, int>> list;
        return list;
    }
}

#include "Prim.h"
#include "heap.h"
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

Prim::PrimMST(){}

Prim::PrimMST(unordered_map<string, double> & averages_, string & startPoint){
    auto vert_selector = [](auto pair){return pair.first;};
    
    vector<string> vert(averages_.size());
    vector<double> d(averages_.size());
    vector<string> p(averages_.size());

    std::transform(averages.begin(), averages_.end(), vert.begin(), vert_selector);

    for(auto string v: averages_){
        d[v] = +inf;
        p[v] = NULL;
    }
    d[startPoint] = 0

    heap<string> heap;
    heap.buildHeap(vert);


    for(int i = 0; i < n; i++){
        string m = heap.pop(); //removeMin, make minHeap
        mst.push_back(m);
        for(string v : ) //find neighbors of m
            if(const(v, m) < d[v])
                d[v] = cost(v, m);
                p[v] = m;
    }

    return mst;
}   
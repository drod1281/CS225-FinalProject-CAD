#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <BTCGraph.h>

using namespace std;

class BFS : public BTCGraph{
//all of these may be wrong, no idea
    public:
        BFS();

        void add(const BTCGraph & BTCGraph);
        BTCGraph pop();
        BTCGraph peek() const;
        bool empty() const;

    private:

};
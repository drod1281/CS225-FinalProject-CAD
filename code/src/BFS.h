#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include </code/BTCGraph.h>

using namespace std;

class BFS : public BTCGraph{
//all of these may be wrong, no idea
    BFS();

    void add(const BTCGraph & BTCGraph);
    BTCGraph pop();
    BTCGraph peek() const;
    bool empty() const;

    private:

};
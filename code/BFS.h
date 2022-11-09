#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <../BTCGraph.h>

using namespace std;

class BFS : public BTCGraph{
//all of these may be wrong, no idea
    BFS();

    void add(const Point & point);
    Point pop();
    Point peek() const;
    bool empty() const;

    private:

};
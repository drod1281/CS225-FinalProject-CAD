#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <BTCGraph.h>

using namespace std;

class BFS : public BTCGraph{
    public:
        BFS();

        void add(const std::string& str);
        std::string pop();
        std::string peek() const;
        bool empty() const;

    private:
        std::queue<std::string> bfs_;
};
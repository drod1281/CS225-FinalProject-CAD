#include <cassert>
#include <iostream>

#include "BTCGraph.h"

int main() {
    BTCGraph* graph = new BTCGraph();
    std::vector<std::pair<std::string, int>> list2688 = graph->getAdjacencyList("2688");
    for (std::pair<std::string, int> x : list2688) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    return 0;
}
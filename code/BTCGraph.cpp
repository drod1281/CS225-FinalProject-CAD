#include "BTCGraph.h"


BTCGraph::BTCGraph() {}

BTCGraph::~BTCGraph(){}

BTCGraph::BTCGraph() {
    std::ifstream ifs ("soc-sign-bitcoinotc.csv", std::ifstream::in);
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;
    
    if(ifs.is_open()) {
        while(getline(ifs, line)) {
            row.clear();
            
            stringstream str(line);
            
            while(getline(str, word, ',')) {
                row.push_back(word);
                content.push_back(row);
            }
        }
    }

    for(int i = 0; i < content.size(); i++) {
        std::vector<std::string> iter = content[i];
        std::map<std::string, std::vector<std::pair<std::string, int>>>::const_iterator it = graph_.find(iter[1]);
        int rating = stoi(iter[2]);
        if (it != graph_.end()) {
            it->second.push_back(std::make_pair(iter[0], rating));
        } else {
            std::vector<std::pair<std::string, int>> vect;
            vect.push_back(std::make_pair(iter[0], rating));
            graph_[iter[1]] = vect;
        }
    }
}
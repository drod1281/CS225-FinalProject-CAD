#include "BFS.h"

BFS::BFS(){}

void BFS::add(const std::string& str){
    bfs_.push(str);
}

std::string BFS::pop(){
    std::string currentPoint = bfs_.front();
    bfs_.pop();
    return currentPoint;
}

std::string BFS::peek() const{
    return bfs_.front();
}

bool BFS::empty() const{
    return bfs_.empty();
}

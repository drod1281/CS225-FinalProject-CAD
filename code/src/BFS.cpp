#include "BFS.h"

BFS::BFS(){}

void BFS::add(const std::string& str){
    bfs_.push(str);
}

BTCGraph BFS::pop(){
    BTCGraph currentPoint = bfs_.front(); //might not be BTCGraph type but list
    bfs_.pop();
    return currentPoint;
}

BTCGraph BFS::peek() const{
    return bfs_.front();
}

bool BFS::empty() const{
    return bfs_.empty();
}

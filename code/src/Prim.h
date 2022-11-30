#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

class Prim {
    public:
        void PrimMST();
        void PrimMST(unordered_map<string, double> & averages_, string & startPoint);
        double cost(string & v, string & m);

    private:
        unordered_map<string, double> mst; //help
};
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
        PrimMST();
        PrimMST(unordered_map<string, double> & averages_, string & startPoint);
        cost(string & v, string & m);

    private:
        idk<string, double> mst; //help
};
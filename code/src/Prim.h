#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

class BTCGraph {
    public:
        PrimMST();
        PrimMST(unordered_map<string, double> & averages_, string & startPoint);

    private:
};
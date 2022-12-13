#include <cassert>
#include <iostream>

#include "BTCGraph.h"
#include "Prim.h"

int main() {
    // If you would like to use your own data structure, please put the csv file in the data folder in the form of
    // source, sink, edgeweight. then put the file name in the in the filename variable in the form ../data/filename
    // leave the filename variable as " " if you're not using you're own data to ensure the program works properly
    std::string filename = " ";
    if (filename == " ") {
        BTCGraph* graph = new BTCGraph();
        std::cout << "Hello! The data has already been put into the graph data structure, for our data file, there are 5881 nodes starting with id 1, there are some id values greater than 5881 so be aware that there are some id's in between 1 and 5882 that don't exist." << std::endl;
        std::cout << "Please Input an id that you would like to see the average rating for." << std::endl;
        std::string input;
        std::cin >> input;
        bool done = false;
        while (!done) {
            double rating = graph->getAverage(input);
            if (rating != -11.0) {
                std::cout << "The average rating for id " << input << " is: " << rating << std::endl;
            } else {
                std::cout << "It seems like the id you chose isn't a valid id in the graph." << std::endl;
            }

            std::cout << " " << std::endl;
            std::cout << "would you like to search for another average rating? 1 for yes, 0 for no" << std::endl;
            int i;
            std::cin >> i;
            if (i == 0) {
                done = true;
            } else {
                std::cout << " " << std::endl;
                std::cout << "Please Input an id that you would like to see the average rating for." << std::endl;
                std::cin >> input;
            }
        }

        std::cout << " " << std::endl;
        std::cout << "Would you like to see a list of the lowest rating a particular id has received? 1 for yes, 0 for no" << std::endl;
        int i;
        std::cin >> i;
        if (i == 1) {
            Prim* mst = new Prim(graph->getGraph(), graph->getStart());
            std::cout << " " << std::endl;
            std::cout << "Please input an id to see a list of the lowest ratings they have received" << std::endl;
            std::string in;
            std::cin >> in;
            bool done = false;
            while (!done) {
                std::vector<std::pair<std::string, int>> copy = mst->getList(in);
                if (copy.empty()) {
                    std::cout << " " << std::endl;
                    std::cout << "It seems like the id you chose isn't a valid id in the graph." << std::endl;
                } else {
                    std::cout << " " << std::endl;
                    for (std::pair<std::string, int> x : copy) {
                        std::cout << x.first << ", " << x.second << std::endl;
                    }
                    std::cout << " " << std::endl;
                }

                std::cout << "would you like to search for another node's list of lowest ratings? 1 for yes, 0 for no" << std::endl;
                int i;
                std::cin >> i;
                if (i == 0) {
                    done = true;
                } else {
                    std::cout << " " << std::endl;
                    std::cout << "Please Input an id that you would like to see the average rating for:" << std::endl;
                    std::cin >> in;
                }
            }
        }
        
        std::cout << " " << std::endl;
        std::cout << "Would you like to see the directed graph drawing of the graph? 1 for yes, 0 for no" << std::endl;
        int s;
        std::cin >> s;
        if (s == 1) {
            graph->printGraph();
            std::cout << " " << std::endl;
            std::cout << "The graph has been outputted to the drawnGraph.png file at the bottom of the code directory." << std::endl;
        }

        std::cout << "That is all, Thank you!" << std::endl;

    } else {
        BTCGraph* graph = new BTCGraph(filename);
    }
    return 0;
}
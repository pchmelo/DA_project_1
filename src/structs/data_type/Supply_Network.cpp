//
// Created by pchmelo on 06-03-2024.
//

#include "Supply_Network.h"
#include "string"
#include "fstream"
#include "sstream"

using namespace std;

void Supply_Network::add_vertex(std::vector<Stations> stations) {
    for(Stations s : stations){
        this->supply_network.addVertex(s);
    }
}

void Supply_Network::read_lines() {
    string input = "../src/Project1DataSetSmall/Project1DataSetSmall/Pipes_Madeira.csv";
    ifstream MyReadFile(input);

    string line;
    Stations station;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            std::string subtr;
            getline(ss, subtr, ',');
            values.push_back(subtr);
        }
        auto it_1 = this->supply_network.findVertex(values[0]);
        auto it_2 = this->supply_network.findVertex(values[1]);

        this->supply_network.addEdge(values[0], values[1], stod(values[2]));

        if(values[3][0] == '0'){
            this->supply_network.addEdge(values[1], values[0], stod(values[2]));
        }

    }
}
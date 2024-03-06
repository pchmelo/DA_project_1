//
// Created by pchmelo on 06-03-2024.
//

#ifndef PROJETO_1_SUPPLY_NETWORK_H
#define PROJETO_1_SUPPLY_NETWORK_H

#include "Stations.h"
#include "Reservoir.h"
#include "City.h"
#include "Graph.h"
#include "vector"

class Supply_Network {
    public:
        Graph<Stations> supply_network;

        void add_vertex(std::vector<Stations> stations);
        void read_lines();
};


#endif //PROJETO_1_SUPPLY_NETWORK_H

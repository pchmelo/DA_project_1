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
#include "limits"

class Supply_Network {
    public:
        Graph<Stations> supply_network;

        void add_vertex(std::vector<Stations> stations);
        void read_lines();

        void create_super_sink(HashReservatorio hashReservatorio);
        void edmondsKarp(Stations source, Stations target);
        bool findAugmentingPath(Vertex<Stations> *s, Vertex<Stations> *t);
        void testAndVisit(std::queue< Vertex<Stations>*> &q, Edge<Stations> *e, Vertex<Stations> *w, double residual);
        double findMinResidualAlongPath(Vertex<Stations> *s, Vertex<Stations> *t);
        void augmentFlowAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, double f);
        std::vector<std::pair<std::string , double>> processAllCitiesMaxFlow(HashCidade hashCidade, HashReservatorio hashReservatorio);
        std::pair<std::string, double> calculeMaxFlow(Stations target);
};


#endif //PROJETO_1_SUPPLY_NETWORK_H

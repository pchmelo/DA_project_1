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

struct Supply_Network {

        Graph<Stations> supply_network;

        void add_vertex(std::vector<Stations> stations);
        void read_lines();

        void create_super_source(HashReservatorio &hashReservatorio);
        void create_super_target(HashCidade &hashCidade);

        void edmondsKarp(Stations source, Stations target, HashReservatorio &hashReservatorio);
        bool findAugmentingPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio);
        void testAndVisit(std::queue< Vertex<Stations>*> &q, Edge<Stations> *e, Vertex<Stations> *w, double residual, HashReservatorio &hashReservatorio);
        double findMinResidualAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio);
        void augmentFlowAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, double f);

        std::vector<std::pair<std::string , double>> processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio);
        std::vector<std::pair<std::string, double>> calculeMaxFlow(HashCidade &hashCidade);

};


#endif //PROJETO_1_SUPPLY_NETWORK_H

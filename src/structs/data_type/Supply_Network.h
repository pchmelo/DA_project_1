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
#include "functions.h"
#include "map"

struct stations_affected;

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

        std::map<std::string, double> processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio);
        std::map<std::string, double>  calculeMaxFlow(HashCidade &hashCidade);

        //3.2
        std::vector<stations_affected> station_desativation(HashStation &hashStation, HashReservatorio &hashReservatorio, HashCidade &hashCidade);

};


struct stations_affected{
    Stations stations;
    std::map<std::string, double> cities_affect;
};

struct trio{
    std::string first;
    std::string second;
    int third;
};

struct save_station{
    std::string code;
    std::vector<trio> edges;


    save_station save(Vertex<Stations>* v){
        trio trio_t;
        save_station s;
        s.code = v->getInfo().get_code();

        for(Edge<Stations>* e: v->getAdj()){
            trio_t.first = e->getOrig()->getInfo().get_code();
            trio_t.second = e->getDest()->getInfo().get_code();
            trio_t.third = e->getFlow();

            s.edges.push_back(trio_t);
        }
        for(Edge<Stations>* e: v->getIncoming()){
            trio_t.first = e->getOrig()->getInfo().get_code();
            trio_t.second = e->getDest()->getInfo().get_code();
            trio_t.third = e->getFlow();

            s.edges.push_back(trio_t);
        }
        return s;
    }

    void restore(save_station s, Graph<Stations> &g){
        g.addVertex(Stations(s.code));
        for(auto e: s.edges){
            g.addEdge(Stations(e.first), Stations(e.second), e.third);
        }
    }
};



#endif //PROJETO_1_SUPPLY_NETWORK_H

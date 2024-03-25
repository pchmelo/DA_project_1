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
#include "math.h"

struct stations_affected;
struct edge;
struct pipes_affected;
struct reservoir_affected;

struct Supply_Network {

        Graph<Stations> supply_network;

        void add_vertex(std::vector<Stations> stations);
        void read_lines(bool data_set);

        void create_super_source(HashReservatorio &hashReservatorio);
        void create_super_target(HashCidade &hashCidade);

        void edmondsKarp(Stations source, Stations target, HashReservatorio &hashReservatorio);
        bool findAugmentingPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio);
        void testAndVisit(std::queue< Vertex<Stations>*> &q, Edge<Stations> *e, Vertex<Stations> *w, double residual, HashReservatorio &hashReservatorio);
        double findMinResidualAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio);
        void augmentFlowAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, double f);

        std::map<std::string, double> processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio);
        std::map<std::string, double>  calculeMaxFlow(HashCidade &hashCidade);

        //2.3
        double average();
        double variance();
        edge max_difference(std::vector<edge> &below_average, std::vector<edge> &above_average);

        //3.1
        std::vector<reservoir_affected> reservoir_desativation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);
        std::vector<reservoir_affected> reservoir_desativation_especific(HashReservatorio &hashReservatorio, HashCidade &hashCidade, std::string code);

        //3.2
        std::vector<stations_affected> station_desativation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);

        //3.3
        std::map<std::string, pipes_affected> pipes_desativation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);
};

struct double_3{
    double first;
    double second;
    double third;
};

struct reservoir_affected{
    Stations reservoir;
    std::map<std::string, double_3> cities_affect;
};

struct stations_affected{
    Stations stations;
    std::map<std::string, double_3> cities_affect;
};

struct pipes_affected{
    std::string orig;
    std::string dest;
    std::map<std::string, double_3> cities_affect;
};

struct trio{
    std::string first;
    std::string second;
    int third;
};

struct save_station{
    Stations stations;
    std::vector<trio> edges;


    void save(Vertex<Stations>* v){
        trio trio_t;
        this->stations = v->getInfo();

        for(Edge<Stations>* e: v->getAdj()){
            trio_t.first = e->getOrig()->getInfo().get_code();
            trio_t.second = e->getDest()->getInfo().get_code();
            trio_t.third = e->getWeight();

            this->edges.push_back(trio_t);
        }
        for(Edge<Stations>* e: v->getIncoming()){
            trio_t.first = e->getOrig()->getInfo().get_code();
            trio_t.second = e->getDest()->getInfo().get_code();
            trio_t.third = e->getWeight();

            this->edges.push_back(trio_t);
        }
    }

    void restore(Graph<Stations> &g, char type){
        g.addVertex(stations);
        for(auto e: this->edges){
            g.addEdge(Stations(e.first), Stations(e.second), e.third);
        }
        this->edges.clear();
    }
};


struct edge{
    Stations orig;
    Stations dest;

    double flow;
    double diff;
    double t;

    bool operator ==(const edge &b) const{
        return orig.get_code() == b.orig.get_code() && dest.get_code() == b.dest.get_code();
    }
};

struct cities_station{
    std::string city;
    std::vector<Stations> stations = {};
    int count = 0;

    bool operator==(const std::string &rhs) const {
        return city == rhs;
    }
};

struct cities_pipes{
    std::string city;
    std::vector<edge> pipes = {};

    bool operator==(const std::string &rhs) const {
        return city == rhs;
    }
};

#endif //PROJETO_1_SUPPLY_NETWORK_H

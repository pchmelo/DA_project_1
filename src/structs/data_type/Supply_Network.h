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

        /** @brief Function that read lines from the dataset.
         *
         *  @param data_set Boolean to indicate which dataset to read.
         */

        void read_lines(bool data_set);

        /** @brief Function that creates a super source.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         */

        void create_super_source(HashReservatorio &hashReservatorio);

        /** @brief Function that creates a super target.
         *
         *  @param hashCidade Hash table with the cities.
         */

        void create_super_target(HashCidade &hashCidade);

        /** @brief Function that uses Edmonds Karp to find the max flow.
         *
         *  @param source The source station.
         *  @param target The target station.
         *  @param hashReservatorio Hash table with the reservoirs.
         */

        void edmondsKarp(Stations source, Stations target, HashReservatorio &hashReservatorio);

        /** @brief Function that finds the augmenting path between two vectors of stations.
         *
         *  @param s The source station.
         *  @param t The target station.
         *  @param hashReservatorio Hash table with the reservoirs.
         *
         *  @return Boolean indicating if the path was found.
         */

        bool findAugmentingPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio);

        /** @brief Function that tests and visits a station.
         *
         *  @param q Queue with the stations to visit.
         *  @param e The edge to visit.
         *  @param w The station to visit.
         *  @param residual The residual flow.
         *  @param hashReservatorio Hash table with the reservoirs.
         */

        void testAndVisit(std::queue< Vertex<Stations>*> &q, Edge<Stations> *e, Vertex<Stations> *w, double residual, HashReservatorio &hashReservatorio);

        /** @brief Function that finds the minimum residual along a path.
         *
         *  @param s The source station.
         *  @param t The target station.
         *  @param hashReservatorio Hash table with the reservoirs.
         *
         *  @return The minimum residual along the path.
         */

        double findMinResidualAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio);

        /** @brief Function that augments the flow along a path.
         *
         *  @param s The source station.
         *  @param t The target station.
         *  @param f The flow to augment.
         */

        void augmentFlowAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, double f);

        /** @brief Function that finds the max flow for all cities.
         *
         *  @param hashCidade Hash table with the cities.
         *  @param hashReservatorio Hash table with the reservoirs.
         *
         *  @return A map with the max flow for each city.
         */

        std::map<std::string, double> processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio);

        /** @brief Function that finds the max flow for a specific city.
         *
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A map with the max flow for the city.
         */

        std::map<std::string, double>  calculateMaxFlow(HashCidade &hashCidade);

        //3.1
        std::vector<reservoir_affected> reservoir_desativation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);
        std::vector<reservoir_affected> reservoir_desativation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade, std::string code);

        //3.2
        /** @brief Function that finds the most affected stations after deactivating a reservoir.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A vector with the most affected stations.
         */

        std::vector<stations_affected> station_desativation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);

        //3.3
        /** @brief Function that finds the most affected pipes after deactivating a reservoir.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A map with the most affected pipes.
         */
        std::map<std::string, pipes_affected> pipes_desativation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);
};

struct double_3{
    double first;
    double second;
    double third;
};

/** @brief Struct that represents the affected cities upon deactivating a reservoir.
 *
 *  This struct contains the deactivated reservoir and the cities affected by it.
 */

struct reservoir_affected{
    Stations reservoir;
    std::map<std::string, double_3> cities_affect;
};

/** @brief Struct that represents the affected cities upon deactivating a station.
 *
 *  This struct contains the deactivated station and the cities affected by it.
 */

struct stations_affected{
    Stations stations;
    std::map<std::string, double_3> cities_affect;
};

/** @brief Struct that represents the affected pipes upon deactivating a reservoir.
 *
 *  This struct contains the deactivated pipes, represented by their origin and destination, and the cities affected by them.
 */

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

/** @brief Struct that represents the stations and edges to save.
 *
 *  This struct contains the stations and edges to save.
 */

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

/** @brief Struct that represents the edges.
 *
 *  This struct contains the origin station and the destination station of the edge, its flow, its difference (!!!!!!)
 */

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

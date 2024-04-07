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
struct pipes_affected;
struct pipe;

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
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param source The source station.
         *  @param target The target station.
         *  @param hashReservatorio Hash table with the reservoirs.
         */

        void edmondsKarp(Stations source, Stations target, HashReservatorio &hashReservatorio);

        /** @brief Function that finds the augmenting path between two vectors of stations.
         *
         *  Complexity: O(V*E), where V is the number of vertices and E is the number of edges.
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
         *  Complexity: O(1).
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
         *  Complexity: O(V), where V is the number of vertices.
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
         *  Complexity: O(V), where V is the number of vertices.
         *
         *  @param s The source station.
         *  @param t The target station.
         *  @param f The flow to augment.
         */

        void augmentFlowAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, double f);

        /** @brief Function that finds the max flow for all cities.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashCidade Hash table with the cities.
         *  @param hashReservatorio Hash table with the reservoirs.
         *
         *  @return A map with the max flow for each city.
         */

        std::map<std::string, double> processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio);

        /** @brief Function that finds the max flow for a specific city.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A map with the max flow for the city.
         */

        std::map<std::string, double>  calculateMaxFlow(HashCidade &hashCidade);

        //3.1
        /** @brief Function that finds the most affected cities after deactivating every reservoir, one by one.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A vector with the struct reservoir_affected.
         */

        std::vector<reservoir_affected> reservoir_deactivation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);

        /** @brief Function that finds the most affected cities after deactivating a specific reservoir.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *  @param code The code of the reservoir to deactivate.
         *
         *  @return A vector with the struct reservoir_affected.
         */

        std::vector<reservoir_affected> reservoir_deactivation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade, string code);

        //3.2
        /** @brief Function that finds the most affected cities after deactivating every station, one by one.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A vector with the struct stations_affected.
         */

        std::vector<stations_affected> station_deactivation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);

        /** @brief Function that finds the most affected cities after deactivating a specific station.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *  @param reservoir The reservoir to deactivate.
         *
         *  @return A vector with the struct stations_affected.
         */

        std::vector<stations_affected> station_deactivation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade, Stations stations);

        //3.3
        /** @brief Function that finds the most affected cities after deactivating every pipe, one by one.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *
         *  @return A map with the city name and the struct pipes_affected.
         */

        std::map<std::string, pipes_affected> pipes_deactivation(HashReservatorio &hashReservatorio, HashCidade &hashCidade);

        /** @brief Function that finds the most affected cities after deactivating a specific pipe.
         *
         *  Complexity: O(V*E^2), where V is the number of vertices and E is the number of edges.
         *
         *  @param hashReservatorio Hash table with the reservoirs.
         *  @param hashCidade Hash table with the cities.
         *  @param pipes The pipes to deactivate.
         *
         *  @return A map with the city name and the struct pipes_affected.
         */

        std::map<std::string, pipes_affected> pipes_deactivation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade, std::vector<pipe> pipes);
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

/** @brief Struct that represents a pipe.
 *
 *  This struct contains the pipes, represented by their origin and destination.
 */

struct pipe{
    Stations orig;
    Stations dest;
    int weight;

    bool operator==(const pipe e) const{
        return orig.get_code() == e.orig.get_code() && dest.get_code() == e.dest.get_code();
    }

    bool operator!=(const pipe e) const{
        return !(*this == e);
    }
};

/** @brief Struct that represents the affected cities upon deactivating a pipe.
 *
 *  This struct contains the deactivated pipe and the cities affected by it.
 */

struct pipes_affected{
    std::vector<pipe> pipes;
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
    std::map<std::pair<std::string, std::string>,double> edges;

    /*
    void save_1(Vertex<Stations>* v){
        this->stations = v->getInfo();
        std::pair<std::string, std::string> p;
        for(Edge<Stations>* e: v->getAdj()){
            p.first = e->getOrig()->getInfo().get_code();
            p.second = e->getDest()->getInfo().get_code();

            this->edges[p] = e->getWeight();
        }
        for(Edge<Stations>* e: v->getIncoming()){
            p.first = e->getOrig()->getInfo().get_code();
            p.second = e->getDest()->getInfo().get_code();

            this->edges[p] = e->getWeight();
        }
    }
    */
    /** @brief Function that deactivates a station, setting the weight of the incoming and outcoming edges to zero.
     *
     *  Complexity: O(n) where n is the number of edges.
     *
     *  @param v The vertex to save.
     */
    void save_2(Vertex<Stations>* v){
        this->stations = v->getInfo();
        std::pair<std::string, std::string> p;
        for(Edge<Stations>* e: v->getAdj()){
            p.first = e->getOrig()->getInfo().get_code();
            p.second = e->getDest()->getInfo().get_code();

            this->edges[p] = e->getWeight();
            e->setWeight(0);
        }
        for(Edge<Stations>* e: v->getIncoming()){
            p.first = e->getOrig()->getInfo().get_code();
            p.second = e->getDest()->getInfo().get_code();

            this->edges[p] = e->getWeight();
            e->setWeight(0);
        }
    }

    /*
    void restore_1(Graph<Stations> &g, char type){
        g.addVertex(stations);
        for(auto e: this->edges){
            g.addEdge(Stations(e.first.first), Stations(e.first.second), e.second);
        }
        this->edges.clear();
    }
    */

    /** @brief Function that activates a station, setting the weight of the incoming and outcoming edges to the original one.
     *
     *  Complexity: O(n) where n is the number of edges.
     *
     *  @param v The vertex to restore.
     */
    void restore_2(Vertex<Stations>* v){
        for(Edge<Stations>* e: v->getAdj()){
            e->setWeight(this->edges[std::make_pair(e->getOrig()->getInfo().get_code(), e->getDest()->getInfo().get_code())]);
        }
        for(Edge<Stations>* e: v->getIncoming()){
            e->setWeight(this->edges[std::make_pair(e->getOrig()->getInfo().get_code(), e->getDest()->getInfo().get_code())]);

        }
        this->edges.clear();
    }
};

/** @brief Struct that represents the edges.
 *
 *  This struct contains the pipes and what affected them (flow before, flow after, and the difference).
 */
struct edge{
    std::vector<pipe> pipe_;
    double_3 stats;

    bool operator ==(const edge &b) const{
        if(pipe_.size() != b.pipe_.size()){
            return false;
        }

        for(int i = 0; i < this->pipe_.size(); i++){
            if(this->pipe_.at(i) != b.pipe_.at(i)){
                return false;
            }
        }
        return true;
    }

};

/** @brief Struct that represents the stations that affect a given city.
 *
 *  This struct contains the city and the stations that affect it.
 */
struct cities_station{
    std::string city;
    std::vector<Stations> stations = {};
    int count = 0;

    bool operator==(const std::string &b) const {
        return city == b;
    }
};

/** @brief Struct that represents the pipes that affect a given city.
 *
 *  This struct contains the city and the pipes that affect it.
 */
struct cities_pipes{
    std::string city;
    std::vector<edge> pipes = {};

    bool operator==(const std::string &city) const {
        return this->city == city;
    }

};

#endif //PROJETO_1_SUPPLY_NETWORK_H

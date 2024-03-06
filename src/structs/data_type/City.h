//
// Created by pchmelo on 05-03-2024.
//

#ifndef PROJETO_1_CITY_H
#define PROJETO_1_CITY_H

#include "string"
#include "unordered_set"
#include "Stations.h"

class City : public Stations{
    private:
        std::string city;
        double demand;
        double population;

    public:
        City();
        City(int id);
        City(std::string city, int id, std::string code, double demand, double population);

        std::string get_city() const;
        double get_demand() const;
        double get_population() const;

        void set_city(std::string city);
        void set_demand(double demand);
        void set_population(double population);

        void print() const;
};

struct cidadeHash{
    int operator() (const City& b) const {
        return b.get_id() % 11;
    }
    bool operator()(const City &b1, const City &b2) const {
        return b1.get_id() == b2.get_id();
    }
};

typedef std::unordered_set<City, cidadeHash, cidadeHash> CidadeTable;

class HashCidade{
    public:
        CidadeTable cidadeTable;
        void readLines();
};


#endif //PROJETO_1_CITY_H

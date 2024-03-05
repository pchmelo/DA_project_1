//
// Created by pchmelo on 05-03-2024.
//

#ifndef PROJETO_1_CIDADE_H
#define PROJETO_1_CIDADE_H

#include "string"
#include "unordered_set"

class Cidade {
    private:
        std::string city;
        int id;
        std::string code;
        double demand;
        double population;

    public:
        Cidade();
        Cidade(int id);
        Cidade(std::string city, int id, std::string code, double demand, double population);

        std::string get_city() const;
        int get_id() const;
        std::string get_code() const;
        double get_demand() const;
        double get_population() const;

        void set_city(std::string city);
        void set_id(int id);
        void set_code(std::string code);
        void set_demand(double demand);
        void set_population(double population);

        void print() const;
};

struct cidadeHash{
    int operator() (const Cidade& b) const {
        return b.get_id() % 11;
    }
    bool operator()(const Cidade &b1, const Cidade &b2) const {
        return b1.get_id() == b2.get_id();
    }
};

typedef std::unordered_set<Cidade, cidadeHash, cidadeHash> CidadeTable;

class HashCidade{
    public:
        CidadeTable cidadeTable;
        void readLines();
};


#endif //PROJETO_1_CIDADE_H

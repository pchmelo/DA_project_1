//
// Created by pchmelo on 05-03-2024.
//

#ifndef PROJETO_1_RESERVOIR_H
#define PROJETO_1_RESERVOIR_H

#include "string"
#include "unordered_set"
#include "Stations.h"

class Reservoir : public Stations{
    private:
        std::string reservoir;
        std::string municipality;
        int maxDelivery;

    public:
        Reservoir();
        Reservoir(int id);
        Reservoir(std::string reservoir, std::string municipality, int id, std::string code, int maxDelivery);

        std::string get_reservoir() const;
        std::string get_municipality() const;
        int get_maxDelivery() const;

        void set_reservoir(std::string reservoir);
        void set_municipality(std::string municipality);
        void set_maxDelivery(int maxDelivery);

        void print() const;
};

struct reservatorioHash{
    int operator() (const Reservoir& b) const {
        return b.get_id() % 10;
    }
    bool operator()(const Reservoir &b1, const Reservoir &b2) const {
        return b1.get_id() == b2.get_id();
    }
};

typedef std::unordered_set<Reservoir, reservatorioHash, reservatorioHash> ReservatorioTable;

class HashReservatorio{
    public:
        ReservatorioTable reservatorioTable;
        void readLines();
};

#endif //PROJETO_1_RESERVOIR_H

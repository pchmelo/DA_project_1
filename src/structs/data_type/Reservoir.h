//
// Created by pchmelo on 05-03-2024.
//

#ifndef PROJETO_1_RESERVOIR_H
#define PROJETO_1_RESERVOIR_H

#include "string"
#include "unordered_set"
#include "Stations.h"
#include "vector"
#include "unordered_map"


class Reservoir : public Stations{
    private:
        std::string reservoir;
        std::string municipality;
        int maxDelivery;
        int t_maxDelivery;

    public:
        Reservoir();
        Reservoir(int id);
        Reservoir(std::string code);
        Reservoir(std::string reservoir, std::string municipality, int id, std::string code, int maxDelivery);

        std::string get_reservoir() const;
        std::string get_municipality() const;
        int get_maxDelivery() const;
        int get_t_maxDelivery() const;

        void set_reservoir(std::string reservoir);
        void set_municipality(std::string municipality);
        void set_maxDelivery(int maxDelivery);
        void set_t_maxDelivery(int t_maxDelivery);

        void print() const;
};

/*
struct reservatorioHash{
    int operator() (const Reservoir& b) const {
        const std::string& code = b.get_code();
        unsigned  int hash = 37;

        for(char c: b.get_code()){
            hash = 33*hash + static_cast<unsigned int>(c);
        }

        return hash % 449;
    }
    bool operator()(const Reservoir &b1, const Reservoir &b2) const {
        return b1.get_code() == b2.get_code();
    }
};
*/

typedef std::unordered_map<std::string, Reservoir> ReservatorioTable;

class HashReservatorio{
    public:
        ReservatorioTable reservatorioTable;
        void readLines(std::vector<Stations> &stations, bool data_set);
        void reseatMaxDelivery();
};

#endif //PROJETO_1_RESERVOIR_H

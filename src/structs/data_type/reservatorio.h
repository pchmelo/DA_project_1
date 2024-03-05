//
// Created by pchmelo on 05-03-2024.
//

#ifndef PROJETO_1_RESERVATORIO_H
#define PROJETO_1_RESERVATORIO_H

#include "string"
#include "unordered_set"

class Reservatorio {
    private:
        std::string reservoir;
        std::string municipality;
        int id;
        std::string code;
        int maxDelivery;

    public:
        Reservatorio();
        Reservatorio(int id);
        Reservatorio(std::string reservoir, std::string municipality, int id, std::string code, int maxDelivery);

        std::string get_reservoir() const;
        std::string get_municipality() const;
        int get_id() const;
        std::string get_code() const;
        int get_maxDelivery() const;

        void set_reservoir(std::string reservoir);
        void set_municipality(std::string municipality);
        void set_id(int id);
        void set_code(std::string code);
        void set_maxDelivery(int maxDelivery);

        void print() const;
};

struct reservatorioHash{
    int operator() (const Reservatorio& b) const {
        return b.get_id() % 10;
    }
    bool operator()(const Reservatorio &b1, const Reservatorio &b2) const {
        return b1.get_id() == b2.get_id();
    }
};

typedef std::unordered_set<Reservatorio, reservatorioHash, reservatorioHash> ReservatorioTable;

class HashReservatorio{
    public:
        ReservatorioTable reservatorioTable;
        void readLines();
};

#endif //PROJETO_1_RESERVATORIO_H

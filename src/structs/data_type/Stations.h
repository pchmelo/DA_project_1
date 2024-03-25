//
// Created by pchmelo on 05-03-2024.
//

#ifndef PROJETO_1_STATIONS_H
#define PROJETO_1_STATIONS_H

#include "string"
#include "unordered_set"
#include "vector"
#include "unordered_map"

class Stations {
    protected:
        int id;
        std::string code;
        char type;

    public:
        Stations();
        Stations(int id);
        Stations(std::string code);
        Stations(std::string code, char type);
        Stations(int id, std::string code, char type);

        int get_id() const;
        std::string get_code() const;
        char get_type() const;

        void set_id(int id);
        void set_code(std::string code);
        void set_type(char type);

        void print() const;

    bool operator==(Stations b){
        return this->get_code() == b.get_code();
    }

};


/*
struct stationHash{
    int operator() (const Stations& b) const {
        return b.get_id() % 10;
    }
    bool operator()(const Stations &b1, const Stations &b2) const {
        return b1.get_id() == b2.get_id();
    }
};
*/

typedef std::unordered_map<std::string, Stations> StationTable;

class HashStation{
public:
    StationTable stationTable;
    void readLines(std::vector<Stations> &stations, bool data_set);
};

#endif //PROJETO_1_STATIONS_H

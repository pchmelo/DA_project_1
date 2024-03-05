//
// Created by pchmelo on 05-03-2024.
//

#include "reservatorio.h"
#include "sstream"
#include "fstream"
#include "vector"
#include "iostream"

using namespace std;

Reservatorio::Reservatorio() {
    this->reservoir = "";
    this->municipality = "";
    this->id = -1;
    this->code = "";
    this->maxDelivery = -1;
}

Reservatorio::Reservatorio(int id) {
    this->reservoir = "";
    this->municipality = "";
    this->id = id;
    this->code = "";
    this->maxDelivery = -1;
}

Reservatorio::Reservatorio(std::string reservoir, std::string municipality, int id, std::string code, int maxDelivery) {
    this->reservoir = reservoir;
    this->municipality = municipality;
    this->id = id;
    this->code = code;
    this->maxDelivery = maxDelivery;
}

std::string Reservatorio::get_reservoir() const{
    return this->reservoir;
}

std::string Reservatorio::get_municipality() const{
    return this->municipality;
}

int Reservatorio::get_id() const{
    return this->id;
}

std::string Reservatorio::get_code() const{
    return this->code;
}

int Reservatorio::get_maxDelivery() const{
    return this->maxDelivery;
}

void Reservatorio::set_reservoir(std::string reservoir) {
    this->reservoir = reservoir;
}

void Reservatorio::set_municipality(std::string municipality) {
    this->municipality = municipality;
}

void Reservatorio::set_id(int id) {
    this->id = id;
}

void Reservatorio::set_code(std::string code) {
    this->code = code;
}

void Reservatorio::set_maxDelivery(int maxDelivery) {
    this->maxDelivery = maxDelivery;
}

void Reservatorio::print() const{
    cout << this->reservoir << " " << this->municipality << " " << this->id << " " << this->code << " " << this->maxDelivery << "\n";
}

void HashReservatorio::readLines() {
    string input = "../src/Project1DataSetSmall/Project1DataSetSmall/Reservoirs_Madeira.csv";
    ifstream MyReadFile(input);

    string line;
    Reservatorio reservatorio;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            std::string subtr;
            getline(ss, subtr, ',');
            values.push_back(subtr);
        }

        reservatorio = Reservatorio(values[0], values[1], stoi(values[2]), values[3], stoi(values[4]));
        this->reservatorioTable.insert(reservatorio);

    }
}


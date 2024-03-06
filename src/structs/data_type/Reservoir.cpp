//
// Created by pchmelo on 05-03-2024.
//

#include "Reservoir.h"
#include "sstream"
#include "fstream"
#include "vector"
#include "iostream"

using namespace std;

Reservoir::Reservoir() : Stations() {
    this->reservoir = "";
    this->municipality = "";
    this->maxDelivery = -1;
}

Reservoir::Reservoir(int id) : Stations(id){
    this->reservoir = "";
    this->municipality = "";
    this->maxDelivery = -1;
}

Reservoir::Reservoir(std::string reservoir, std::string municipality, int id, std::string code, int maxDelivery) : Stations(id, code, 'R') {
    this->reservoir = reservoir;
    this->municipality = municipality;
    this->maxDelivery = maxDelivery;
}

std::string Reservoir::get_reservoir() const{
    return this->reservoir;
}

std::string Reservoir::get_municipality() const{
    return this->municipality;
}


int Reservoir::get_maxDelivery() const{
    return this->maxDelivery;
}

void Reservoir::set_reservoir(std::string reservoir) {
    this->reservoir = reservoir;
}

void Reservoir::set_municipality(std::string municipality) {
    this->municipality = municipality;
}


void Reservoir::set_maxDelivery(int maxDelivery) {
    this->maxDelivery = maxDelivery;
}

void Reservoir::print() const{
    cout << this->reservoir << " " << this->municipality << " " << this->id << " " << this->code << " " << this->maxDelivery << "\n";
}

void HashReservatorio::readLines() {
    string input = "../src/Project1DataSetSmall/Project1DataSetSmall/Reservoirs_Madeira.csv";
    ifstream MyReadFile(input);

    string line;
    Reservoir reservatorio;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            std::string subtr;
            getline(ss, subtr, ',');
            values.push_back(subtr);
        }

        reservatorio = Reservoir(values[0], values[1], stoi(values[2]), values[3], stoi(values[4]));
        this->reservatorioTable.insert(reservatorio);

    }
}


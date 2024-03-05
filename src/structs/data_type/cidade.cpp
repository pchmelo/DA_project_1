//
// Created by pchmelo on 05-03-2024.
//

#include "cidade.h"
#include "sstream"
#include "fstream"
#include "vector"
#include "iostream"
#include "algorithm"
#include "string"

using namespace std;

Cidade::Cidade() {
    this->city = "";
    this->id = -1;
    this->code = "";
    this->demand = -1;
    this->population = -1;
}

Cidade::Cidade(int id) {
    this->city = "";
    this->id = id;
    this->code = "";
    this->demand = -1;
    this->population = -1;
}

Cidade::Cidade(std::string city, int id, std::string code, double demand, double population) {
    this->city = city;
    this->id = id;
    this->code = code;
    this->demand = demand;
    this->population = population;
}

std::string Cidade::get_city() const {
    return this->city;
}

int Cidade::get_id() const {
    return this->id;
}

std::string Cidade::get_code() const {
    return this->code;
}

double Cidade::get_demand() const {
    return this->demand;
}

double Cidade::get_population() const {
    return this->population;
}

void Cidade::set_city(std::string city) {
    this->city = city;
}

void Cidade::set_id(int id) {
    this->id = id;
}

void Cidade::set_code(std::string code) {
    this->code = code;
}

void Cidade::set_demand(double demand) {
    this->demand = demand;
}

void Cidade::set_population(double population) {
    this->population = population;
}

void Cidade::print() const{
    cout << this->city << " " << this->id << " " << this->code << " " << this->demand << " " << this->population << "\n";
}

void HashCidade::readLines() {
    string input = "../src/Project1DataSetSmall/Project1DataSetSmall/Cities_Madeira.csv";
    ifstream MyReadFile(input);
    int i = 0;

    string line;
    Cidade cidade;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            std::string subtr;

            if(i == 4){
                getline(ss, subtr, '"');
                i++;

            }
            else if(i == 5){
                getline(ss, subtr, '"');
                subtr.erase(remove(subtr.begin(), subtr.end(), ','), subtr.end());
                values.push_back(subtr);
                break;
            }
            else{
                getline(ss, subtr, ',');
                i++;
                values.push_back(subtr);
            }

        }

        cidade = Cidade(values[0], stoi(values[1]), values[2], stod(values[3]), stod(values[4]));
        this->cidadeTable.insert(cidade);
        i = 0;
    }
}

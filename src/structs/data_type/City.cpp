#include "City.h"
#include "sstream"
#include "fstream"
#include "vector"
#include "iostream"
#include "algorithm"
#include "string"

using namespace std;

City::City() : Stations() {
    this->city = "";
    this->demand = -1;
    this->population = -1;
}

City::City(int id) : Stations(id){
    this->city = "";
    this->demand = -1;
    this->population = -1;
}

City::City(std::string code) : Stations(code) {
    this->city = "";
    this->demand = -1;
    this->population = -1;
}

City::City(std::string city, int id, std::string code, double demand, double population) : Stations(id, code, 'C'){
    this->city = city;
    this->demand = demand;
    this->population = population;
}

std::string City::get_city() const {
    return this->city;
}

double City::get_demand() const {
    return this->demand;
}

double City::get_population() const {
    return this->population;
}

void City::set_city(std::string city) {
    this->city = city;
}

void City::set_demand(double demand) {
    this->demand = demand;
}

void City::set_population(double population) {
    this->population = population;
}

void City::print() const{
    cout << this->city << " " << this->id << " " << this->code << " " << this->demand << " " << this->population << "\n";
}

void HashCidade::readLines(vector<Stations> &stations, bool data_set){
    string input;

    if(data_set){
        input = "../src/Data/Project1LargeDataSet/Cities.csv";
    }
    else{
        input = "../src/Data/Project1DataSetSmall/Cities_Madeira.csv";
    }

    ifstream MyReadFile(input);
    int i = 0;

    string line;
    City cidade;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            std::string subtr;

            if(data_set){
                getline(ss, subtr, ',');
                values.push_back(subtr);
            }
            else{
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
        }

        cidade = City(values[0], stoi(values[1]), values[2], stod(values[3]), stod(values[4]));
        this->cidadeTable[values[2]] = cidade;
        stations.push_back(Stations(stoi(values[1]), values[2], 'C'));

        i = 0;
    }
}

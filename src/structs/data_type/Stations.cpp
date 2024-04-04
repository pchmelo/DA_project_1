#include "Stations.h"
#include "iostream"
#include "sstream"
#include "fstream"
#include "vector"

using namespace std;

Stations::Stations() {
    this->id = -1;
    this->code = "";
    this->type = 'x';
}

Stations::Stations(int id) {
    this->id = id;
    this->code = "";
    this->type = 'x';

}

Stations::Stations(std::string code, char type) {
    this->id = -1;
    this->code = code;
    this->type = type;
}

Stations::Stations(std::string code) {
    this->id = -1;
    this->code = code;
    this->type = 'x';
}

Stations::Stations(int id, std::string code, char type) {
    this->id = id;
    this->code = code;
    this->type = type;
}

int Stations::get_id() const{
    return this->id;
}

std::string Stations::get_code() const{
    return this->code;
}

char Stations::get_type() const {
    return this->type;
}

void Stations::set_id(int id) {
    this->id = id;
}

void Stations::set_code(std::string code) {
    this->code = code;
}

void Stations::set_type(char type) {
    this->type = type;
}

void Stations::print() const{
    cout << this->id << " " << this->code << "\n";
}

void HashStation::readLines(vector<Stations> &stations, bool data_set) {
    string input;

    if(data_set){
        input = "../src/Data/Project1LargeDataSet/Stations.csv";
    }
    else{
        input = "../src/Data/Project1DataSetSmall/Stations_Madeira.csv";
    }

    ifstream MyReadFile(input);
    int i = 0;

    string line;
    Stations station;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            if(!data_set){
                if(i == 2){
                    i = 0;
                    break;
                }
            }

            std::string subtr;
            getline(ss, subtr, ',');

            values.push_back(subtr);
            i++;
        }
        if(values[0] == ""){
            break;
        }

        /*
        if(data_set){
            values[1].pop_back();
        }
        */

        station = Stations(stoi(values[0]), values[1], 'S');
        this->stationTable[values[1]] = station;
        stations.push_back(station);

    }
}

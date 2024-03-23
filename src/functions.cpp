//
// Created by pchmelo on 08-03-2024.
//

#include <iostream>
#include "functions.h"
#include "sstream"
#include "fstream"
#include "iostream"

using  namespace std;

void functions::file_ouput(std::map<std::string, double> vec_lines) {
    string dir_file = "../src/Project1DataSet/output.txt";
    ofstream fout(dir_file,ios::out | ios::trunc);

    fout << "City_code,value\n";

    auto inicio = vec_lines.begin();
    while(inicio != vec_lines.end()){
       fout << inicio->first << "," << inicio->second << "\n";
       inicio++;
    }

    fout.close();
}

std::map<std::string, double>  functions::file_input() {
    std::map<std::string, double> res;

    string dir_file = "../src/Project1DataSetSmall/output.txt";
    ifstream MyReadFile(dir_file);
    bool flag = true;

    string line;


    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            if(flag){
                flag = false;
                continue;
            }

            std::string subtr;
            getline(ss, subtr, ',');

            values.push_back(subtr);
        }
        if(values[0] == ""){
            break;
        }
        res.insert(pair{values[0], stoi(values[1])});

    }
    return res;
}


void functions::print_result(std::map<std::string, double>  vec_lines, HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34mCity Name \033[0m";
    cout << "\033[0;33mID \033[0m";
    cout << "\033[0;32mCode \033[0m";
    cout << "\033[0;31mMax Flow\033[0m\n\n";

    auto inicio = vec_lines.begin();
    while(inicio != vec_lines.end()){
      auto city = hashCidade.cidadeTable.find(inicio->first);
        cout << "\033[1;34m" << city->second.get_city() << " " << "\033[0m";
        cout << "\033[1;33m" << city->second.get_id() << " " << "\033[0m";
        cout << "\033[1;32m" << city->second.get_code() << " " << "\033[0m";
        cout << "\033[1;31m" << inicio->second <<"\033[0m\n\n";
        inicio++;
    }
}


void functions::print_deficit(std::map<std::string, double> vec_lines) {
    cout << endl;
    cout << "\033[0;32mCode \033[0m";
    cout << "\033[0;31mDeficit\033[0m\n\n";

    auto inicio = vec_lines.begin();
    while(inicio != vec_lines.end()){
        cout << "\033[1;32m" << inicio->first << " " << "\033[0m";
        cout << "\033[1;31m" << inicio->second <<"\033[0m\n\n";

    }
}

std::map<std::string, double> functions::calculate_difference(std::map<std::string, double> comp_1, std::map<std::string, double> comp_2) {
    std::map<std::string, double> res;
    auto it_1 = comp_1.begin();
    int t;

    while (it_1 != comp_1.end()){
        t = comp_2[it_1->first] - it_1->second;

        if(t != 0){
            res[it_1->first] = t;
        }
        it_1++;
    }

    return res;
}

vector<cities_station> functions::cities_most_affected_stations(std::vector<stations_affected> stations_affected) {
    vector<cities_station> res;
    auto it_1 = stations_affected.begin();

    while (it_1 != stations_affected.end()){
        auto it_2 = it_1->cities_affect.begin();
        while (it_2 != it_1->cities_affect.end()){
            auto it_3 = find(res.begin(), res.end(), it_2->first);
            if(it_3 == res.end()){
                cities_station c;
                c.city = it_2->first;
                c.stations = {it_1->stations};
                c.count++;
                res.push_back(c);
            }
            else{
                it_3->stations.push_back(it_1->stations);
                it_3->count++;
            }
            it_2++;
       }
        it_1++;
    }

    std::sort(res.begin(), res.end(), [](const cities_station& a, const cities_station& b) {
        return a.count > b.count;
    });

    return res;
}
std::map<std::string, double>  functions::water_deficit(std::map<std::string, double> city_supply,
                                                        HashCidade hashCidade) {
    map<string, double> noWater;

    auto inicio = city_supply.begin();
    while (inicio != city_supply.end()) {
        string city = inicio->first;
        double value = inicio->second;
        auto cidade = hashCidade.cidadeTable.find(city);
        if (cidade->second.get_demand() - value < 0) {
            inicio->second = value - cidade->second.get_demand();
        }
        noWater.insert(*inicio);
    }
    return noWater;
}

std::vector<cities_pipes> functions::cities_most_affected_pipes(std::map<std::string, pipes_affected> pipes_affected) {
    vector<cities_pipes> res;
    auto it_1 = pipes_affected.begin();

    while (it_1 != pipes_affected.end()){
        auto it_2 = it_1->second.cities_affect.begin();

        while(it_2 != it_1->second.cities_affect.end()){
            auto it_3 = find(res.begin(), res.end(), it_2->first);
            if(it_3 == res.end()){
                cities_pipes c;
                c.city = it_2->first;
                c.pipes = {edge{it_1->second.orig, it_1->second.dest, 0, it_2->second}};
                res.push_back(c);
            }
            else{
                it_3->pipes.push_back(edge{it_1->second.orig, it_1->second.dest, 0, it_2->second});
            }

            it_2++;
        }

        it_1++;
    }

    return res;
}
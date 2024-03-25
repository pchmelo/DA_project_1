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
    cout << "\033[0;32mCode \033[0m";
    cout << "\033[0;31mMax Flow\033[0m\n\n";

    auto inicio = vec_lines.begin();
    while(inicio != vec_lines.end()){
      auto city = hashCidade.cidadeTable.find(inicio->first);
        cout << "\033[1;32m" << city->second.get_code() << " " << "\033[0m";
        cout << "\033[1;31m" << inicio->second <<"\033[0m\n\n";
        inicio++;
    }
}

void functions::print_result_specific_city_by_ID(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade){
    cout << endl;
    cout << "\033[0;32mID \033[0m";
    cout << "\033[0;31mMax Flow\033[0m\n\n";

    auto cidade = hashCidade.cidadeTable.find(code);
    auto city = vec_lines.find(code);
    cout << "\033[1;32m" << cidade->second.get_id() << " " << "\033[0m";
    cout << "\033[1;31m" << city->second <<"\033[0m\n\n";
}

void functions::print_result_specific_city_by_name(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade){
    cout << endl;
    cout << "\033[0;32mName \033[0m";
    cout << "\033[0;31mMax Flow\033[0m\n\n";

    auto cidade = hashCidade.cidadeTable.find(code);
    auto city = vec_lines.find(code);
    cout << "\033[1;32m" << cidade->second.get_city() << " " << "\033[0m";
    cout << "\033[1;31m" << city->second <<"\033[0m\n\n";
}

void functions::print_result_specific_city_by_code(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade){
    cout << endl;
    cout << "\033[0;32mCode \033[0m";
    cout << "\033[0;31mMax Flow\033[0m\n\n";

    auto cidade = hashCidade.cidadeTable.find(code);
    auto city = vec_lines.find(code);
    cout << "\033[1;32m" << cidade->second.get_code() << " " << "\033[0m";
    cout << "\033[1;31m" << city->second <<"\033[0m\n\n";
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

std::map<std::string, double_3> functions::calculate_difference(std::map<std::string, double> comp_1, std::map<std::string, double> comp_2) {
    std::map<std::string, double_3> res;
    auto it_1 = comp_1.begin();
    double_3 t;

    while (it_1 != comp_1.end()){
        t.first = it_1->second;
        t.second = comp_2[it_1->first];
        t.third = comp_2[it_1->first] - t.first;

        if(t.third != 0){
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

std::vector<cities_pipes> functions::cities_most_affected_pipes(std::map<std::string, pipes_affected> pipes_affected, HashCidade hashCidade) {
    vector<cities_pipes> res;
    auto it_1 = pipes_affected.begin();

    while (it_1 != pipes_affected.end()){
        auto it_2 = it_1->second.cities_affect.begin();

        while(it_2 != it_1->second.cities_affect.end()){
            auto it_3 = find(res.begin(), res.end(), it_2->first);
            auto cidade = hashCidade.cidadeTable.find(it_2->first);

            if(it_3 == res.end()){
                cities_pipes c;
                c.city = it_2->first;
                c.pipes = {edge{it_1->second.orig, it_1->second.dest, it_2->second.first, it_2->second.second, it_2->second.third}};
                res.push_back(c);
            }
            else{
                it_3->pipes.push_back(edge{it_1->second.orig, it_1->second.dest, it_2->second.first, it_2->second.second, it_2->second.third});
            }

            it_2++;
        }

        it_1++;
    }

    return res;
}

void functions::print_cities_station(std::vector<cities_station> vec, HashCidade hashCidade) {
    if(vec.size() == 0){
        cout << "\033[0;32mNao existe nenhuma cidade afetada com a remocao de uma Station \033[0m\n";
    }
    else{
        cout << endl;
        cout << "\033[0;32mCom a remocao de uma station existe alteracao da agua chegada nas cidades\033[0m\n";
        cout << "\033[0;35mAs cidades mais afetadas sao:\033[0m\n\n";


        auto it_1 = vec.begin();
        while(it_1 != vec.end()){
            auto cidade = hashCidade.cidadeTable.find(it_1->city);

            cout << "\033[1;32mPara a cidade: \033[0m\n";
            cout << "\033[1;34mCity Name \033[0m";
            cout << "\033[0;33mID \033[0m";
            cout << "\033[0;31mCode \033[0m\n";
            cout << "\033[1;34m" << cidade->second.get_city() << " " << "\033[0m";
            cout << "\033[1;33m" << cidade->second.get_id() << " " << "\033[0m";
            cout << "\033[1;31m" << cidade->second.get_code() << " " << "\033[0m\n\n";
            cout << "\033[1;35mSao \033[0m";
            cout << "\033[1;31m"<< it_1->count << " " <<"\033[0m";
            cout << "\033[1;35mstations que afetam esta cidade e sao:\033[0m\n";
            cout << "\033[1;34mId \033[0m";
            cout << "\033[1;33mCode \033[0m\n";

            auto it_2 = it_1->stations.begin();
            while(it_2 != it_1->stations.end()) {
                cout << "\033[1;34m" << it_2->get_id() << " " << "\033[0m";
                cout << "\033[1;33m" << it_2->get_code() << " " << "\033[0m\n";

                it_2++;
            }
            it_1++;
            cout << endl;
        }
    }
}

void functions::print_stations_affected(std::vector<stations_affected> vec, HashCidade hashCidade) {
    if(vec.size() != 0){
        auto it_1 = vec.begin();
        while(it_1 != vec.end()){
            cout << endl;
            cout << "\033[0;35mCom a remocao da estacao:\033[0m\n";
            cout << "\033[1;34mId \033[0m";
            cout << "\033[1;33mCode \033[0m\n";
            cout << "\033[1;34m" << it_1->stations.get_id() << " " << "\033[0m";
            cout << "\033[1;33m" << it_1->stations.get_code() << " " << "\033[0m\n\n";
            cout << "\033[0;35mAs seguintes cidades sao afetadas da seguinte forma:\033[0m\n\n";
            cout << "\033[1;34mCity Name \033[0m";
            cout << "\033[0;33mID \033[0m";
            cout << "\033[0;31mCode \033[0m";
            cout << "\033[0;32mDemanda \033[0m";
            cout << "\033[0;36mFlow antes \033[0m";
            cout << "\033[0;37mFlow depois \033[0m";
            cout << "\033[0;38mDefict \033[0m\n";

            auto it_2 = it_1->cities_affect.begin();

            while(it_2 != it_1->cities_affect.end()){
                auto cidade = hashCidade.cidadeTable.find(it_2->first);
                cout << "\033[1;34m" << cidade->second.get_city() << " " << "\033[0m";
                cout << "\033[1;33m" << cidade->second.get_id() << " " << "\033[0m";
                cout << "\033[1;31m" << cidade->second.get_code() << " " << "\033[0m";
                cout << "\033[1;32m" << cidade->second.get_demand() << " " << "\033[0m";
                cout << "\033[1;36m" << it_2->second.first << " " << "\033[0m";
                cout << "\033[1;37m" << it_2->second.second << " " << "\033[0m";
                cout << "\033[1;38m" << it_2->second.third << " " << "\033[0m\n";
                it_2++;
            }
            it_1++;
            cout << endl;
        }
    }
}

void functions::print_cities_pipes(std::vector<cities_pipes> vec, HashCidade hashCidade) {
    if(vec.size() != 0){
        auto it_1 = vec.begin();
        while(it_1 != vec.end()){
            auto cidade = hashCidade.cidadeTable.find(it_1->city);

            cout << endl;
            cout << "\033[0;35mPara a cidade:\033[0m\n";
            cout << "\033[1;34mCity Name \033[0m";
            cout << "\033[0;33mID \033[0m";
            cout << "\033[0;31mCode \033[0m";
            cout << "\033[0;32mDemanda \033[0m\n";

            cout << "\033[1;34m" << cidade->second.get_city() << " " << "\033[0m";
            cout << "\033[1;33m" << cidade->second.get_id() << " " << "\033[0m";
            cout << "\033[1;31m" << cidade->second.get_code() << " " << "\033[0m";
            cout << "\033[1;32m" << cidade->second.get_demand() << " " << "\033[0m\n\n";

            cout << "\033[1;34mDest \033[0m";
            cout << "\033[0;33mOrig \033[0m";
            cout << "\033[0;32mFlow antes \033[0m";
            cout << "\033[0;31mFlow depois \033[0m";
            cout << "\033[0;36mDefict \033[0m\n";

            auto it_2 = it_1->pipes.begin();
            while(it_2 != it_1->pipes.end()){
                cout << "\033[1;34m" << it_2->orig.get_code() << " " << "\033[0m";
                cout << "\033[1;33m" << it_2->dest.get_code() << " " << "\033[0m";
                cout << "\033[1;32m" << it_2->flow << " " << "\033[0m";
                cout << "\033[1;31m" << it_2->diff << " " << "\033[0m";
                cout << "\033[1;36m" << it_2->t << " " << "\033[0m\n";

                it_2++;
            }

            cout << endl;
            it_1++;
        }
    }
}

void functions::print_pipes_affected(std::map<std::string, pipes_affected> lines, HashCidade hashCidade) {
    if(lines.size() != 0){
        auto it_1 = lines.begin();
        while(it_1 != lines.end()){
            cout << endl;
            cout << "\033[0;34mPara a pipe com comeco em \033[0m";
            cout << "\033[1;33m" << it_1->second.orig << " " << "\033[0m";
            cout << "\033[0;34me fim em \033[0m";
            cout << "\033[1;31m" << it_1->second.dest << " " << "\033[0m\n";

            cout << "\033[0;35mSao afetadas as seguintes cidades:\033[0m\n\n";

            cout << "\033[1;34mCity Name \033[0m";
            cout << "\033[0;33mID \033[0m";
            cout << "\033[0;31mCode \033[0m";
            cout << "\033[0;32mDemanda \033[0m";
            cout << "\033[0;36mFlow antes \033[0m";
            cout << "\033[0;37mFlow depois \033[0m";
            cout << "\033[0;38mDefict \033[0m\n";

            auto it_2 = it_1->second.cities_affect.begin();
            while (it_2 != it_1->second.cities_affect.end()){
                auto cidade = hashCidade.cidadeTable.find(it_2->first);

                cout << "\033[1;34m" << cidade->second.get_city() << " " << "\033[0m";
                cout << "\033[1;33m" << cidade->second.get_id() << " " << "\033[0m";
                cout << "\033[1;31m" << cidade->second.get_code() << " " << "\033[0m";
                cout << "\033[1;32m" << cidade->second.get_demand() << " " << "\033[0m";
                cout << "\033[1;36m" << it_2->second.first << " " << "\033[0m";
                cout << "\033[1;37m" << it_2->second.second << " " << "\033[0m";
                cout << "\033[1;38m" << it_2->second.third << " " << "\033[0m\n";

                it_2++;
            }

            cout << endl;
            it_1++;
        }
    }
}

void functions::print_cities_reservoir(std::vector<reservoir_affected> vec, HashCidade hashCidade) {
    if(vec.size() != 0){
        auto it_1 = vec.begin();
        while (it_1 != vec.end()){
            cout << endl;
            cout << "\033[0;34mCom a remoção do reservatorio com codigo \033[0m";
            cout << "\033[1;31m"<< it_1->reservoir.get_code() <<"\033[0m\n";
            cout << "\033[0;34mAs seguintes cidades sao afetadas: \033[0m\n\n";

            cout << "\033[1;34mCity Name \033[0m";
            cout << "\033[0;33mID \033[0m";
            cout << "\033[0;31mCode \033[0m";
            cout << "\033[0;32mDemanda \033[0m";
            cout << "\033[0;36mFlow antes \033[0m";
            cout << "\033[0;37mFlow depois \033[0m";
            cout << "\033[0;38mDefict \033[0m\n";

            auto it_2 = it_1->cities_affect.begin();
            while (it_2 != it_1->cities_affect.end()){
                auto cidade = hashCidade.cidadeTable.find(it_2->first);

                cout << "\033[1;34m" << cidade->second.get_city() << " " << "\033[0m";
                cout << "\033[1;33m" << cidade->second.get_id() << " " << "\033[0m";
                cout << "\033[1;31m" << cidade->second.get_code() << " " << "\033[0m";
                cout << "\033[1;32m" << cidade->second.get_demand() << " " << "\033[0m";
                cout << "\033[1;36m" << it_2->second.first << " " << "\033[0m";
                cout << "\033[1;37m" << it_2->second.second << " " << "\033[0m";
                cout << "\033[1;38m" << it_2->second.third << " " << "\033[0m\n";

                it_2++;
            }
            cout << endl;
            it_1++;
        }
    }
}
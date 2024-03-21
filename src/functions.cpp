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
    string dir_file = "../src/Project1DataSetSmall/output.txt";
    ofstream fout(dir_file,ios::out | ios::trunc);

    fout << "City_code,value\n";

    for(int i = 0; i < vec_lines.size(); i++){
       // fout << vec_lines[i].first << "," << vec_lines[i].second << "\n";
    }

    fout.close();
}

std::map<std::string, double>  functions::file_input() {
    std::map<std::string, double> res_new;

    string dir_file = "../src/Project1DataSetSmall/output.txt";
    ifstream MyReadFile(dir_file);
    bool flag = true;

    string line;
    vector<std::pair<std::string, double>> res;

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
        res.push_back(pair{values[0], stoi(values[1])});

    }
    return res_new;
}


void functions::print_result(std::map<std::string, double>  vec_lines, HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34mCity Name \033[0m";
    cout << "\033[0;33mID \033[0m";
    cout << "\033[0;32mCode \033[0m";
    cout << "\033[0;31mMax Flow\033[0m\n\n";


    for(int i = 0; i < vec_lines.size(); i++){
      //  auto city = hashCidade.cidadeTable.find(vec_lines[i].first);
     //   cout << "\033[1;34m" << city->second.get_city() << " " << "\033[0m";
     //   cout << "\033[1;33m" << city->second.get_id() << " " << "\033[0m";
      //  cout << "\033[1;32m" << city->second.get_code() << " " << "\033[0m";
     //   cout << "\033[1;31m" << vec_lines[i].second <<"\033[0m\n\n";

    }
}

std::map<std::string, double>  functions::water_deficit(std::vector<std::pair<std::string, int>> city_supply, HashCidade hashCidade){
    std::map<std::string, double> res;

    vector<pair<string, int>> noWater;
    for(auto info: city_supply){
        string city = info.first;
        int value = info.second;

        auto cidade = hashCidade.cidadeTable.at(city);
        if(cidade.get_demand() - value < 0){
            info.second = value - cidade.get_demand();
            noWater.push_back(info);
        }
    }
    return res;
}
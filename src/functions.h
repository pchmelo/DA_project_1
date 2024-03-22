//
// Created by pchmelo on 08-03-2024.
//

#ifndef PROJETO_1_FUNCTIONS_H
#define PROJETO_1_FUNCTIONS_H

#include "vector"
#include "string"
#include "structs/data_type/City.h"
#include "map"


class functions {
    public:
        static void file_ouput(std::map<std::string, double> vec_lines);
        static std::map<std::string, double> file_input();

        static void print_result(std::map<std::string, double>  vec_lines, HashCidade hashCidade);
        static std::map<std::string, double>  water_deficit(std::vector<std::pair<std::string, int>> city_supply, HashCidade hashCidade);
        static void print_deficit(std::vector<std::pair<std::string, double>> vec_lines);
};


#endif //PROJETO_1_FUNCTIONS_H

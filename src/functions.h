//
// Created by pchmelo on 08-03-2024.
//

#ifndef PROJETO_1_FUNCTIONS_H
#define PROJETO_1_FUNCTIONS_H

#include "vector"
#include "string"
#include "structs/data_type/City.h"
#include "map"
#include "structs/data_type/Supply_Network.h"


class functions {
    public:
        static void file_ouput(std::map<std::string, double> vec_lines);
        static std::map<std::string, double> file_input();

        static void print_result(std::map<std::string, double>  vec_lines, HashCidade hashCidade);

        static std::map<std::string, double> calculate_difference(std::map<std::string, double> comp_1, std::map<std::string, double> comp_2);
        static std::map<std::string, double> cities_most_affected_stations(std::vector<stations_affected> stations_affected);
        static std::map<std::string, double>  water_deficit(std::map<std::string, double> city_supply, HashCidade hashCidade);
        static void print_deficit(std::map<std::string, double> vec_lines);
};


#endif //PROJETO_1_FUNCTIONS_H

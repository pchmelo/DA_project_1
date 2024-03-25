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


struct stations_affected;
struct cities_station;
struct cities_pipes;
struct pipes_affected;
struct double_3;
struct reservoir_affected;

class functions {
    public:
        static void file_ouput(std::map<std::string, double> vec_lines);
        static std::map<std::string, double> file_input();

        static void print_result(std::map<std::string, double>  vec_lines, HashCidade hashCidade);
        static void print_result_specific_city_by_ID(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade);
        static void print_result_specific_city_by_name(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade);
        static void print_result_specific_city_by_code(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade);
        //3
        static std::map<std::string, double_3> calculate_difference(std::map<std::string, double> comp_1, std::map<std::string, double> comp_2);

        //3.1
        static void print_cities_reservoir(std::vector<reservoir_affected> vec, HashCidade hashCidade);

        //3.2
        static std::vector<cities_station> cities_most_affected_stations(std::vector<stations_affected> stations_affected);
        static void print_cities_station(std::vector<cities_station> vec, HashCidade hashCidade);
        static void print_stations_affected(std::vector<stations_affected> vec, HashCidade hashCidade);

        //3.3
        static std::vector<cities_pipes> cities_most_affected_pipes(std::map<std::string, pipes_affected> pipes_affected, HashCidade hashCidade);
        static void print_cities_pipes(std::vector<cities_pipes> vec, HashCidade hashCidade);
        static void print_pipes_affected(std::map<std::string, pipes_affected> lines, HashCidade hashCidade);


        static std::map<std::string, double>  water_deficit(std::map<std::string, double> city_supply, HashCidade hashCidade);
        static void print_deficit(std::map<std::string, double> vec_lines);
};


#endif //PROJETO_1_FUNCTIONS_H

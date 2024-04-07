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
        static void file_output(std::map<std::string, double> vec_lines);

        /**
         * @brief Function to read the file and return a map with the values
         *
         * Complexity: O(n) where n is the number of lines in the file.
         *
         * @return A map with the values of the file.
         *
         */
        static std::map<std::string, double> file_input();

        static void print_result(std::map<std::string, double>  vec_lines, HashCidade hashCidade);
        static void print_result_specific_city_by_ID(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade);
        static void print_result_specific_city_by_name(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade);
        static void print_result_specific_city_by_code(std::map<std::string, double>  vec_lines, std::string code, HashCidade hashCidade);

        //3
        /**
         * @brief Function to calculate the difference between the results of applying the Edmonds-Karp algorithm to the normal dataset and the
         * dataset with alterations.
         *
         * Complexity: O(n) where n is the number of elements in the map.
         *
         * @param comp_1 A map with the results of applying the Edmonds-Karp algorithm to the normal dataset.
         * @param comp_2 A map with the results of applying the Edmonds-Karp algorithm to the dataset with alterations.
         *
         * @return A map with the differences between the two maps.
         *
         */
        static std::map<std::string, double_3> calculate_difference(std::map<std::string, double> comp_1, std::map<std::string, double> comp_2);

        //3.1
        static void print_cities_reservoir(std::vector<reservoir_affected> vec, HashCidade hashCidade);

        //3.2
        /**
         * @brief Function to calculate the cities most affected by the stations
         *
         * Complexity: O(n) where n is the number of elements in the vector.
         *
         * @param stations_affected A vector with the struct stations_affected.
         *
         * @return A vector with the cities most affected by the stations.
         */
        static std::vector<cities_station> cities_most_affected_stations(std::vector<stations_affected> stations_affected);

        static void print_cities_station(std::vector<cities_station> vec, HashCidade hashCidade);
        static void print_stations_affected(std::vector<stations_affected> vec, HashCidade hashCidade);

        //3.3
        /**
         * @brief Function to calculate the cities most affected by the pipes
         *
         * Complexity: O(n) where n is the number of elements in the map.
         *
         * @param pipes_affected A map with the struct pipes_affected.
         *
         * @return A vector with the cities most affected by the pipes.
         *
         */
        static std::vector<cities_pipes> cities_most_affected_pipes(std::map<std::string, pipes_affected> pipes_affected, HashCidade hashCidade);

        static void print_cities_pipes(std::vector<cities_pipes> vec, HashCidade hashCidade);
        static void print_pipes_affected(std::map<std::string, pipes_affected> lines, HashCidade hashCidade);

        /**
         * @brief Function to calculate the water deficit
         *
         * Complexity: O(n) where n is the number of elements in the map.
         *
         * @param city_supply A map with the supply of water for each city.
         *
         * @return A map with the water deficit for each city.
         *
         */
        static std::map<std::string, double>  water_Deficit(std::map<std::string, double> city_supply, HashCidade hashCidade);

        static void print_Deficit(std::map<std::string, double> vec_lines, HashCidade hashCidade);

};


#endif //PROJETO_1_FUNCTIONS_H

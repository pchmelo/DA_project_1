//
// Created by pchmelo on 08-03-2024.
//

#ifndef PROJETO_1_FUNCTIONS_H
#define PROJETO_1_FUNCTIONS_H

#include "vector"
#include "string"
#include "structs/data_type/City.h"

class functions {
    public:
        static void file_ouput(std::vector<std::pair<std::string, int>> vec_lines);
        static std::vector<std::pair<std::string, int>> water_deficit(std::vector<std::pair<std::string, int>> city_supply, HashCidade hashCidade);
};


#endif //PROJETO_1_FUNCTIONS_H

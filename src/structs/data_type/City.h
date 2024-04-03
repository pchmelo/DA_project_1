#ifndef PROJETO_1_CITY_H
#define PROJETO_1_CITY_H

#include "string"
#include "unordered_set"
#include "Stations.h"
#include "vector"
#include "unordered_map"

class City : public Stations{
    private:
        std::string city;
        double demand;
        double population;

    public:

    /**
     * @brief Default constructor for the City class
     *
     * This constructor initializes the City object with default values.
     * The default values for city, demand, and population are "", -1, and -1, respectively.
     */

        City();

    /**
     * @brief Constructor for the City class
     *
     * This constructor initializes the City object with the given id,
     * and default values for city, demand, and population.
     *
     * @param id The id of the city.
     */

        City(int id);

    /**
     * @brief Overloaded constructor for the City class.
     *
     * This constructor initializes the City object with the given code,
     * and default values for city, demand, and population.
     *
     * @param code The code of the city.
     */

        City(std::string code);

    /**
     * @brief Overloaded constructor for the City class.
     *
     * This constructor initializes the City object with the specified values.
     *
     * @param city The name of the city.
     * @param id The id of the city.
     * @param code The code of the city.
     * @param demand The demand of the city.
     * @param population The population of the city.
     */

        City(std::string city, int id, std::string code, double demand, double population);

    /**
     * @brief Get the code of the city.
     *
     * @return A string representing the code of the city.
     */

        std::string get_city() const;

    /**
     * @brief Get the demand of the city.
     *
     * @return A double representing the demand of the city.
     */

        double get_demand() const;

    /**
     * @brief Get the population of the city.
     *
     * @return A double representing the population of the city.
     */

        double get_population() const;

    /**
     * @brief Set the code of the city.
     *
     * @param city The name of the city.
     */

        void set_city(std::string city);

    /**
     * @brief Set the demand of the city.
     *
     * @param demand The demand of the city.
     */

        void set_demand(double demand);

    /**
     * @brief Set the population of the city.
     *
     * @param population The population of the city.
     */

        void set_population(double population);

    /**
     * @brief Print the City object.
     */

        void print() const;
};


/*
struct cidadeHash{
    int operator() (const City& b) const {
        const std::string& code = b.get_code();
        unsigned  int hash = 37;

        for(char c: b.get_code()){
            hash = 33*hash + static_cast<unsigned int>(c);
        }

        return hash % 449;
    }
    bool operator()(const City &b1, const City &b2) const {
        return b1.get_code() == b2.get_code();
    }
};
*/

typedef std::unordered_map<std::string, City> CidadeTable;

class HashCidade{
    public:
        CidadeTable cidadeTable;
        void readLines(std::vector<Stations> &stations, bool data_set);
};


#endif //PROJETO_1_CITY_H

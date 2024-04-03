#ifndef PROJETO_1_RESERVOIR_H
#define PROJETO_1_RESERVOIR_H

#include "string"
#include "unordered_set"
#include "Stations.h"
#include "vector"
#include "unordered_map"


class Reservoir : public Stations{
    private:
        std::string reservoir;
        std::string municipality;
        int maxDelivery;
        int t_maxDelivery;

    public:

    /**
     * @brief Default constructor for the Reservoir class.
     *
     * This constructor initializes the Reservoir object with default values.
     * The default values for reservoir, municipality, maxDelivery, and t_maxDelivery are "", "", -1, and -1, respectively.
     */

        Reservoir();

    /**
     * @brief Parameterized constructor for the Reservoir class.
     *
     * This constructor initializes the Reservoir object with the given id,
     * and default values for reservoir, municipality, and maxDelivery.
     *
     * @param id The id of the reservoir.
     */

        Reservoir(int id);

    /**
     * @brief Overloaded constructor for the Reservoir class.
     *
     * This constructor initializes the Reservoir object with the given code,
     * and default values for reservoir, municipality, maxDelivery, and t_maxDelivery.
     *
     * @param code The code of the reservoir.
     */

        Reservoir(std::string code);

    /**
     * @brief Overloaded constructor for the Reservoir class.
     *
     * This constructor initializes the Reservoir object with the specified values.
     *
     * @param reservoir The name of the reservoir.
     * @param municipality The municipality of the reservoir.
     * @param id The id of the reservoir.
     * @param code The code of the reservoir.
     * @param maxDelivery The maximum delivery of the reservoir.
     */

        Reservoir(std::string reservoir, std::string municipality, int id, std::string code, int maxDelivery);

    /**
     * @brief Get the name of the reservoir.
     *
     * @return A string representing the name of the reservoir.
     */

        std::string get_reservoir() const;

    /**
     * @brief Get the municipality of the reservoir.
     *
     * @return A string representing the municipality of the reservoir.
     */

        std::string get_municipality() const;

    /**
     * @brief Get the maximum delivery of the reservoir.
     *
     * @return An integer representing the maximum delivery of the reservoir.
     */

        int get_maxDelivery() const;

    /**
     * @brief Get the t_maxDelivery of the reservoir.
     *
     * @return An integer representing the t_maxDelivery of the reservoir.
     */

        int get_t_maxDelivery() const;

    /**
     * @brief Set the name of the reservoir.
     *
     * @param reservoir The name of the reservoir.
     */

        void set_reservoir(std::string reservoir);

    /**
     * @brief Set the municipality of the reservoir.
     *
     * @param municipality The municipality of the reservoir.
     */

        void set_municipality(std::string municipality);

    /**
     * @brief Set the maximum delivery of the reservoir.
     *
     * @param maxDelivery The maximum delivery of the reservoir.
     */

        void set_maxDelivery(int maxDelivery);

    /**
     * @brief Set the t_maxDelivery of the reservoir.
     *
     * @param t_maxDelivery The t_maxDelivery of the reservoir.
     */

        void set_t_maxDelivery(int t_maxDelivery);

    /**
     * @brief Print the Reservoir object.
     */

        void print() const;
};

typedef std::unordered_map<std::string, Reservoir> ReservatorioTable;

/** @brief Class that stores the reservoirs in a hash table.
 *
 */

class HashReservatorio{
    public:
        ReservatorioTable reservatorioTable;

    /** @brief Function that reads the reservoirs from the file.
     *
     * @param stations The vector of stations.
     * @param data_set A boolean that indicates if the data set is being read.
     */

        void readLines(std::vector<Stations> &stations, bool data_set);

    /** @brief Function that resets the maxDelivery of the reservoirs.
     *
     */
        void resetMaxDelivery();
};

#endif //PROJETO_1_RESERVOIR_H

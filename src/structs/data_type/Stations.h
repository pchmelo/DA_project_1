#ifndef PROJETO_1_STATIONS_H
#define PROJETO_1_STATIONS_H

#include "string"
#include "unordered_set"
#include "vector"
#include "unordered_map"

class Stations {
    protected:
        int id;
        std::string code;
        char type;

    public:

    /**
     * @brief Default constructor for the Stations class.
     *
     * This constructor initializes the Stations object with default values.
     * The default values for id, code, and type are -1, "", and 'x', respectively.
     */

        Stations();

    /**
     * @brief Parameterized constructor for the Stations class.
     *
     * This constructor initializes the Stations object with the given id,
     * and default values for code and type.
     *
     * @param id The id of the station.
     */

        Stations(int id);

    /**
     * @brief Overloaded constructor for the Stations class.
     *
     * This constructor initializes the Stations object with the given code,
     * and default values for id and type.
     *
     * @param code The code of the station.
     */

        Stations(std::string code);

    /**
     * @brief Overloaded constructor for the Stations class.
     *
     * This constructor initializes the Stations object with the specified code and type values,
     * and default value for id.
     *
     * @param code The code of the station.
     * @param type The type of the station.
     */

        Stations(std::string code, char type);

    /**
     * @brief Overloaded constructor for the Stations class.
     *
     * This constructor initializes the Stations object with the specified values.
     *
     * @param id The id of the station.
     * @param code The code of the station.
     * @param type The type of the station.
     */

        Stations(int id, std::string code, char type);

    /**
     * @brief Get the id of the station.
     *
     * @return An integer representing the id of the station.
     */

        int get_id() const;

    /**
     * @brief Get the code of the station.
     *
     * @return A string representing the code of the station.
     */

        std::string get_code() const;

    /**
     * @brief Get the type of the station.
     *
     * @return A character representing the type of the station.
     */

        char get_type() const;

    /**
     * @brief Set the id of the station.
     *
     * @param id The id of the station.
     */

        void set_id(int id);

    /**
     * @brief Set the code of the station.
     *
     * @param code The code of the station.
     */

        void set_code(std::string code);

    /**
     * @brief Set the type of the station.
     *
     * @param type The type of the station.
     */

        void set_type(char type);

    /**
     * @brief Print the station.
     */

        void print() const;


    /**
     * @brief Equality comparison operator for the Stations class.
     *
     * This operator checks if the code of the current station is equal to the code of the given station.
     *
     * @param b The station to compare with.
     * @return True if the codes are equal, false otherwise.
     */

    bool operator==(Stations b){
        return this->get_code() == b.get_code();
    }

};

typedef std::unordered_map<std::string, Stations> StationTable;

/** @brief Class that stores the stations in a hash table.
 *
 */

class HashStation{
    public:
        StationTable stationTable;

    /** @brief Function that reads the stations from the file.
     *
     * @param stations The vector of stations.
     * @param data_set A boolean that indicates if the data set is being read.
     */

        void readLines(std::vector<Stations> &stations, bool data_set);
};

#endif //PROJETO_1_STATIONS_H

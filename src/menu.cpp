//
// Created by pchmelo on 07-03-2024.
//

#include "menu.h"
#include "functions.h"

Supply_Network new_one;
std::map<std::string, double> max_flow;
std::map<std::string, double> water_suply;
std::map<std::string, double> deficit;
std::vector<reservoir_affected> remove_reservoir;
std::vector<reservoir_affected> remove_reservoir_by_ID;
std::vector<reservoir_affected> remove_reservoir_by_name;
std::vector<reservoir_affected> remove_reservoir_by_code;
std::vector<stations_affected> station_affect;
std::vector<cities_station> cities_most_affected_by_stations;
std::map<std::string, pipes_affected> pipe_affect;
std::vector<cities_pipes> cities_most_affected_by_pipes;
std::vector<pair<string, string>> Pipe;

int Menu::Terminal(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                   HashCidade &hashCidade) {

    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Basic Service Metrics" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Reliability and Sensitivity to Failures" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Ambiente de Teste" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                BasicServiceMetrics(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                ReliabilityAndSensitivityToFailures(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 3:
                AmbienteTeste(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::BasicServiceMetrics(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade){
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Max-Flow" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Water Suply" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Pipes capacity reduction" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                MaxFlow(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                WaterSuply(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::MaxFlow(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                  HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "For each city" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "For a specific city" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                new_one.supply_network = supplyNetwork.supply_network;
                max_flow = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
                functions::file_ouput(max_flow);
                functions::print_result(max_flow, hashCidade);
                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 2:
                MaxFlowForSpecificCity(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}


int Menu::MaxFlowForSpecificCity(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                 HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Select by ID" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "Select by Name" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << "Select by Code" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                MaxFlowForSpecificCityByID(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                MaxFlowForSpecificCityByName(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 3:
                MaxFlowForSpecificCityByCode(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                MaxFlowForSpecificCity(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::MaxFlowForSpecificCityByID(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                     HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    int i = 1;
    cout << "\033[1;34mPlease choose the ID of your city:\033[0m\n";
    for(auto city: hashCidade.cidadeTable){
        cout << "\033[1;36m[ " << i << " ]\033[0m" << city.second.get_id() << endl;
        codes.push_back(city.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string city;
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else {
        new_one.supply_network = supplyNetwork.supply_network;
        max_flow = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
        functions::print_result_specific_city_by_ID(max_flow, codes[decision - 1], hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }
    return 0;

}

int Menu::MaxFlowForSpecificCityByName(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                       HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    int i = 1;
    cout << "\033[1;34mPlease choose the name of your city:\033[0m\n";
    for(auto city: hashCidade.cidadeTable){
        cout << "\033[1;36m[ " << i << " ]\033[0m" << city.second.get_city() << endl;
        codes.push_back(city.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string city;
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else {
        new_one.supply_network = supplyNetwork.supply_network;
        max_flow = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
        functions::print_result_specific_city_by_name(max_flow, codes[decision - 1], hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }
    return 0;

}

int Menu::MaxFlowForSpecificCityByCode(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                       HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    int i = 1;
    cout << "\033[1;34mPlease choose the code of your city:\033[0m\n";
    for(auto city: hashCidade.cidadeTable){
        cout << "\033[1;36m[ " << i << " ]\033[0m" << city.second.get_code() << endl;
        codes.push_back(city.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string city;
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else {
        new_one.supply_network = supplyNetwork.supply_network;
        max_flow = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
        functions::print_result_specific_city_by_code(max_flow, codes[decision - 1], hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }
    return 0;

}

int Menu::WaterSuply(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                     HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Cities with water deficit" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
               water_suply = functions::file_input();
                if(water_suply.size() == 0){
                    new_one.supply_network = supplyNetwork.supply_network;
                    water_suply = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
                    functions::file_ouput(water_suply);
                }
                deficit = functions::water_deficit(water_suply, hashCidade);
                functions::print_deficit(deficit);
                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::ReliabilityAndSensitivityToFailures(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade){
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Remove a Water Reservoir" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Remove Pumping Stations" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Remove Pipes" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                RemoveWaterReservoir(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                RemovePumpingStation(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 3:
                RemovePipes(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveWaterReservoir(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                               HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "For each water reservoir" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "For a specific water reservoir" << endl;
    cout << "\033[1;36m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                remove_reservoir = supplyNetwork.reservoir_desativation(hashReservatorio, hashCidade);
                functions::print_cities_reservoir(remove_reservoir, hashCidade);
                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 2:
                RemoveSpecificWaterReservoir(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveSpecificWaterReservoir(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                 HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Select by ID" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "Select by Name" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << "Select by Code" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                RemoveSpecificWaterReservoirByID(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                RemoveSpecificWaterReservoirByName(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 3:
                RemoveSpecificWaterReservoirByCode(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveSpecificWaterReservoirByID(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                             HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for(auto reservoir: hashReservatorio.reservatorioTable) {
        cout << "\033[1;36m[ " <<  i << " ]\033[0m" << reservoir.second.get_id() << endl;
        codes.push_back(reservoir.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        remove_reservoir_by_ID = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade,
                                                                               codes[decision - 1]);
        functions::print_cities_reservoir(remove_reservoir_by_ID, hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }

    return 0;
}

int Menu::RemoveSpecificWaterReservoirByName(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                             HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for(auto reservoir: hashReservatorio.reservatorioTable) {
        cout << "\033[1;36m[ " <<  i << " ]\033[0m" << reservoir.second.get_reservoir() << endl;
        codes.push_back(reservoir.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        remove_reservoir_by_name = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade,
                                                                                 codes[decision - 1]);
        functions::print_cities_reservoir(remove_reservoir_by_name, hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }

    return 0;
}

int Menu::RemoveSpecificWaterReservoirByCode(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                               HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for(auto reservoir: hashReservatorio.reservatorioTable) {
        cout << "\033[1;36m[ " <<  i << " ]\033[0m" << reservoir.second.get_code() << endl;
        codes.push_back(reservoir.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        remove_reservoir_by_code = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade,
                                                                                 codes[decision - 1]);
        functions::print_cities_reservoir(remove_reservoir_by_code, hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }

    return 0;
}

int Menu::RemovePumpingStation(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                               HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Cities affected for each pumping station" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "Most affected cities" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "For a sepcific pumping station" << endl;
    cout << "\033[1;36m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                station_affect = supplyNetwork.station_desativation(hashReservatorio, hashCidade);
                functions::print_stations_affected(station_affect, hashCidade);
                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 2:
                station_affect = supplyNetwork.station_desativation(hashReservatorio, hashCidade);
                cities_most_affected_by_stations = functions::cities_most_affected_stations(station_affect);

                functions::print_cities_station(cities_most_affected_by_stations, hashCidade);

                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 3:
                RemoveSpecificPumpingStation(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveSpecificPumpingStationByID(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                           HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for(auto station: hashStation.stationTable) {
        cout << "\033[1;36m[ " <<  i << " ]\033[0m" << station.second.get_id() << endl;
        codes.push_back(station.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        station_affect = supplyNetwork.station_desativation(hashReservatorio, hashCidade);
        functions::print_stations_affected(station_affect, hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }

    return 0;
}

int Menu::RemoveSpecificPumpingStationByCode(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                           HashCidade &hashCidade) {
    std::vector<string> codes;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for(auto station: hashStation.stationTable) {
        cout << "\033[1;36m[ " <<  i << " ]\033[0m" << station.second.get_code() << endl;
        codes.push_back(station.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    if(decision == 0){
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        auto station_chosen = hashStation.stationTable.at(codes[decision-1]);
        station_affect = supplyNetwork.station_desativation(hashReservatorio, hashCidade);
        functions::print_stations_affected(station_affect, hashCidade);
        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    break;
                default:
                    break;
            }

            return 0;

        }
    }

    return 0;
}

int Menu::RemovePipes(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                      HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Cities affected for each pipe" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "Most affected cities" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << "For a specific pipe" << endl;
    cout << "\033[1;36m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                pipe_affect = supplyNetwork.pipes_desativation(hashReservatorio, hashCidade);
                functions::print_pipes_affected(pipe_affect, hashCidade);
                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 2:
                pipe_affect = supplyNetwork.pipes_desativation(hashReservatorio, hashCidade);
                cities_most_affected_by_pipes = functions::cities_most_affected_pipes(pipe_affect, hashCidade);

                functions::print_cities_pipes(cities_most_affected_by_pipes, hashCidade);

                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                while (true) {

                    switch (decision) {
                        case 1:
                            Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                            break;
                        case 0:
                            break;
                        default:
                            break;
                    }

                    return 0;

                }
            case 3:
                RemoveSpecificPipe(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveSpecificPumpingStation(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                       HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Select by ID" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "Select by Code" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                RemoveSpecificPumpingStationByID(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                RemoveSpecificPumpingStationByCode(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveSpecificPipe(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                                       HashCidade &hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Select from Reservoir" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "Select from Station" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                RemoveSpecificPipeReservoir(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
               RemoveSpecificPipeStation(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 0:
                Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::RemoveSpecificPipeReservoir(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade) {
    std::vector<string> codes;
    std::vector<string> codes1;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for (auto reservoir: hashReservatorio.reservatorioTable) {
        cout << "\033[1;36m[ " << i << " ]\033[0m" << reservoir.second.get_code() << endl;
        codes.push_back(reservoir.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision1;
    cin >> decision1;
    cout << endl;
    if (decision1 == 0) {
        Menu::Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    } else {
        auto chosen = supplyNetwork.supply_network.findVertex(codes[decision1 - 1]);
        cout << endl;
        cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
        int i = 1;
        for (auto destino: chosen->getAdj()) {
            cout << "\033[1;36m[ " << i << " ]\033[0m" << destino->getDest()->getInfo().get_code() << endl;
            codes1.push_back(destino->getDest()->getInfo().get_code());
            i++;
        }
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        int decision2;
        cin >> decision2;
        cout << endl;

        Pipe.push_back(pair(codes[decision1 - 1], codes1[decision2 - 1]));

        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Remove more pipes" << endl;
        cout << "\033[1;36m[ 0 ]\033[0m" << " Finish process" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        int decision;
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Menu::RemoveSpecificPipe(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    cout << "LIBERTEM O MACACO! \n";
                    Pipe.clear();

                    cout << endl;
                    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                    cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    while (true) {

                        switch (decision) {
                            case 1:
                                Menu::Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                                break;
                            case 0:
                                break;
                            default:
                                break;
                        }
                        break;
                        default:
                            break;
                    }

                    return 0;

            }
        }
    }
        return 0;
}

int Menu::RemoveSpecificPipeStation(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade) {
    std::vector<string> codes;
    std::vector<string> codes1;
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
    int i = 1;
    for (auto station: hashStation.stationTable) {
        cout << "\033[1;36m[ " << i << " ]\033[0m" << station.second.get_code() << endl;
        codes.push_back(station.second.get_code());
        i++;
    }
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision1;
    cin >> decision1;
    cout << endl;
    if (decision1 == 0) {
        Menu::Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    } else {
        auto chosen = supplyNetwork.supply_network.findVertex(codes[decision1 - 1]);
        cout << endl;
        cout << "\033[1;34mPlease choose the Water Reservoir you desire to remove:\033[0m\n";
        int i = 1;
        for (auto destino: chosen->getAdj()) {
            cout << "\033[1;36m[ " << i << " ]\033[0m" << destino->getDest()->getInfo().get_code() << endl;
            codes1.push_back(destino->getDest()->getInfo().get_code());
            i++;
        }
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        int decision2;
        cin >> decision2;
        cout << endl;

        Pipe.push_back(pair(codes[decision1 - 1], codes1[decision2 - 1]));

        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Remove more pipes" << endl;
        cout << "\033[1;36m[ 0 ]\033[0m" << " Finish process" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        int decision;
        cin >> decision;
        cout << endl;

        while (true) {

            switch (decision) {
                case 1:
                    Menu::RemoveSpecificPipe(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                    break;
                case 0:
                    cout << "LIBERTEM O MACACO! \n";
                    Pipe.clear();

                    cout << endl;
                    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                    cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    while (true) {

                        switch (decision) {
                            case 1:
                                Menu::Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                                break;
                            case 0:
                                break;
                            default:
                                break;
                        }
                        break;
                        default:
                            break;
                    }

                    return 0;

            }
        }
    }
    return 0;
}

    int Menu::AmbienteTeste(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                            HashCidade &hashCidade) {
        /*
        auto reservatorio = hashReservatorio.reservatorioTable.find("R_1");
        reservatorio->second.print();

        auto cidade = hashCidade.cidadeTable.find("C_10");
        cidade->second.print();

        auto it = supplyNetwork.supply_network.findVertex(reservatorio->first);

        pair<string , int> p_1 = {"Vasco", 100};
        pair<string , int> p_2 = {"Diogo", 2};

        vector<pair<string , int>> vec;

        vec.push_back(p_1);
        vec.push_back(p_2);

        new_one.supply_network = supplyNetwork.supply_network;

        auto res = supplyNetwork.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
        //functions::file_ouput(res);



        auto vec_2 = functions::file_input();


        int sum = 0;

        for(auto v : supplyNetwork.supply_network.getVertexSet()){
            if(v->getInfo().get_type() == 'R'){
                for(auto e : v->getAdj()){
                    sum += e->getFlow();
                }
                cout << v->getInfo().get_code() << " " << sum << endl;
                sum = 0;
            }

        }

        //functions::print_result(res, hashCidade);
        //supplyNetwork.station_deativation(hashStation);

        double avg = supplyNetwork.average();
        double varience = supplyNetwork.variance();

        vector<edge> vec_t_1;
        vector<edge> vec_t_2;

        auto e = supplyNetwork.max_difference(vec_t_1, vec_t_2);

        vector<edge> v1;
        vector<edge> v2;

        edge max = supplyNetwork.max_difference(v1, v2);
        */


        auto t_1 = supplyNetwork.station_desativation(hashReservatorio, hashCidade);
        auto t_2 = functions::cities_most_affected_stations(t_1);

        functions::print_cities_station(t_2, hashCidade);
        functions::print_stations_affected(t_1, hashCidade);


        auto t_3 = supplyNetwork.pipes_desativation(hashReservatorio, hashCidade);
        auto t_4 = functions::cities_most_affected_pipes(t_3, hashCidade);

        functions::print_pipes_affected(t_3, hashCidade);
        functions::print_cities_pipes(t_4, hashCidade);


        auto t_5 = supplyNetwork.reservoir_desativation(hashReservatorio, hashCidade);
        functions::print_cities_reservoir(t_5, hashCidade);

        auto t_6 = supplyNetwork.reservoir_desativation(hashReservatorio, hashCidade);
        functions::print_cities_reservoir(t_6, hashCidade);


        auto t_7 = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade, "R_1");
        functions::print_cities_reservoir(t_7, hashCidade);

        auto t_8 = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade, "R_4");
        auto t_9 = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade, "R_1");

        auto t_10 = supplyNetwork.reservoir_desativation_specific(hashReservatorio, hashCidade, "R_1");
        functions::print_cities_reservoir(t_10, hashCidade);

        pipe p_1 = {Stations("PS_10"), Stations("C_5")};
        pipe p_2 = {Stations("PS_9"), Stations("C_5")};

        vector<pipe> pipes = {p_1, p_2};
        auto t_11 = supplyNetwork.pipes_desativation_specific(hashReservatorio, hashCidade, pipes);
        auto t_12 = functions::cities_most_affected_pipes(t_11, hashCidade);

        functions::print_pipes_affected(t_11, hashCidade);
        functions::print_cities_pipes(t_12, hashCidade);

        auto t_13 = supplyNetwork.station_desativation_specific(hashReservatorio, hashCidade, Stations("PS_78"));
        auto t_14 = functions::cities_most_affected_stations(t_13);

        functions::print_stations_affected(t_13, hashCidade);
        functions::print_cities_station(t_14, hashCidade);


        abort();
    }
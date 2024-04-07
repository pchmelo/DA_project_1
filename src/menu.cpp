//
// Created by pchmelo on 07-03-2024.
//

#include "menu.h"
#include "functions.h"
#include <ctype.h>
#include <stdio.h>

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
std::vector<pipe> Pipes;


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
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }if(decision_1 == "3"){
            decision = 3;
        }
    }
    while (true) {

        switch (decision) {
            case 1:
                BasicServiceMetrics(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 2:
                ReliabilityAndSensitivityToFailures(supplyNetwork, hashReservatorio, hashStation, hashCidade);
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
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "2")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }
    }

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
    cout << "\033[1;36m[ 1 ]\033[0m" << " For each city" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " For a specific city" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "2")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }
    }

    while (true) {

        switch (decision) {
            case 1:
                new_one.supply_network = supplyNetwork.supply_network;
                max_flow = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
                functions::file_output(max_flow);
                functions::print_result(max_flow, hashCidade);
                cout << endl;
                cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
                cout << "\033[1;36m[ 1 ]\033[0m" << " Back to Main Menu" << endl;
                cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                int decision;
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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Select by ID" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Select by Name" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Select by Code" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    string decision_1;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }if(decision_1 == "3"){
            decision = 3;
        }
    }

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


    vector<pair<string, City>> vec_lines_vec(hashCidade.cidadeTable.begin(), hashCidade.cidadeTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, City>& a, pair<string, City>& b) {
        return a.second.get_id() < b.second.get_id();
    });

    for(auto city: vec_lines_vec){
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

    vector<pair<string, City>> vec_lines_vec(hashCidade.cidadeTable.begin(), hashCidade.cidadeTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, City>& a, pair<string, City>& b) {
        int num_a = stoi(a.first.substr(2));
        int num_b = stoi(b.first.substr(2));
        return num_a < num_b;
    });

    for(auto city: vec_lines_vec){
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
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "1")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }
    }

    while (true) {

        switch (decision) {
            case 1:
               water_suply = functions::file_input();
                if(water_suply.size() == 0){
                    new_one.supply_network = supplyNetwork.supply_network;
                    water_suply = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
                    functions::file_output(water_suply);
                }
                deficit = functions::water_Deficit(water_suply, hashCidade);
                functions::print_Deficit(deficit, hashCidade);
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
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }if(decision_1 == "3"){
            decision = 3;
        }
    }

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
    cout << "\033[1;36m[ 1 ]\033[0m" << " For each water reservoir" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " For a specific water reservoir" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "2")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }
    }

    while (true) {

        switch (decision) {
            case 1:
                remove_reservoir = supplyNetwork.reservoir_deactivation(hashReservatorio, hashCidade);
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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Select by ID" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Select by Name" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Select by Code" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }if(decision_1 == "3"){
            decision = 3;
        }
    }

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
        remove_reservoir_by_ID = supplyNetwork.reservoir_deactivation_specific(hashReservatorio, hashCidade,
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
        remove_reservoir_by_name = supplyNetwork.reservoir_deactivation_specific(hashReservatorio, hashCidade,
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

    vector<pair<string, Reservoir>> vec_lines_vec(hashReservatorio.reservatorioTable.begin(), hashReservatorio.reservatorioTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, Reservoir>& a, pair<string, Reservoir>& b) {
        int num_a = stoi(a.first.substr(2));
        int num_b = stoi(b.first.substr(2));
        return num_a < num_b;
    });

    for(auto reservoir: vec_lines_vec) {
        cout << "\033[1;36m[ " <<  i << " ] \033[0m" << reservoir.second.get_code() << endl;
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
        remove_reservoir_by_code = supplyNetwork.reservoir_deactivation_specific(hashReservatorio, hashCidade,
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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Cities affected for each pumping station" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Most affected cities" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " For a specific pumping station" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }if(decision_1 == "3"){
            decision = 3;
        }
    }

    while (true) {

        switch (decision) {
            case 1:
                station_affect = supplyNetwork.station_deactivation(hashReservatorio, hashCidade);
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
                station_affect = supplyNetwork.station_deactivation(hashReservatorio, hashCidade);
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

    vector<pair<string, Stations>> vec_lines_vec(hashStation.stationTable.begin(), hashStation.stationTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, Stations>& a, pair<string, Stations>& b) {
        return a.second.get_id() < b.second.get_id();
    });


    for(auto station: vec_lines_vec) {
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
        auto station_chosen = hashStation.stationTable.at(codes[decision - 1]);
        station_affect = supplyNetwork.station_deactivation_specific(hashReservatorio, hashCidade, station_chosen);
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

    vector<pair<string, Stations>> vec_lines_vec(hashStation.stationTable.begin(), hashStation.stationTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, Stations>& a, pair<string, Stations>& b) {
        int num_a = stoi(a.first.substr(3));
        int num_b = stoi(b.first.substr(3));
        return num_a < num_b;
    });

    for(auto station: vec_lines_vec) {
        cout << "\033[1;36m[ " <<  i << " ] \033[0m" << station.second.get_code() << endl;
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
        auto station_chosen = hashStation.stationTable.at(codes[decision - 1]);
        station_affect = supplyNetwork.station_deactivation_specific(hashReservatorio, hashCidade, station_chosen);
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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Cities affected for each pipe" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Most affected cities" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " For a specific pipe" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }if(decision_1 == "3"){
            decision = 3;
        }
    }

    while (true) {

        switch (decision) {
            case 1:
                pipe_affect = supplyNetwork.pipes_deactivation(hashReservatorio, hashCidade);
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
                pipe_affect = supplyNetwork.pipes_deactivation(hashReservatorio, hashCidade);
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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Select by ID" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Select by Code" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;


    if((decision_1 < "0") || (decision_1 > "2")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }
    }

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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Select from Reservoir" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Select from Station" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Back to Main Menu" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "2")){
        cout << "INVALID OPTION! \n";
        Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    }
    else{
        if(decision_1 == "0"){
            decision = 0;
        }if(decision_1 == "1"){
            decision = 1;
        }if(decision_1 == "2"){
            decision = 2;
        }
    }

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

    vector<pair<string, Reservoir>> vec_lines_vec(hashReservatorio.reservatorioTable.begin(), hashReservatorio.reservatorioTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, Reservoir>& a, pair<string, Reservoir>& b) {
        int num_a = stoi(a.first.substr(2));
        int num_b = stoi(b.first.substr(2));
        return num_a < num_b;
    });

    for (auto reservoir: vec_lines_vec) {
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

        pipe p_1 = {Stations(codes[decision1 - 1]), Stations(codes1[decision2 - 1])};
        Pipes.push_back(p_1);

        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Remove more pipes" << endl;
        cout << "\033[1;31m[ 0 ]\033[0m" << " Finish process" << endl;
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
                    auto pipe_chosen = supplyNetwork.pipes_deactivation_specific(hashReservatorio, hashCidade, Pipes);
                    functions::print_pipes_affected(pipe_chosen, hashCidade);
                    Pipes.clear();

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

    vector<pair<string, Stations>> vec_lines_vec(hashStation.stationTable.begin(), hashStation.stationTable.end());
    sort(vec_lines_vec.begin(), vec_lines_vec.end(), [](pair<string, Stations>& a, pair<string, Stations>& b) {
        int num_a = stoi(a.first.substr(3));
        int num_b = stoi(b.first.substr(3));
        return num_a < num_b;
    });

    for (auto station: vec_lines_vec) {
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

        pipe p_1 = {Stations(codes[decision1 - 1]), Stations(codes1[decision2 - 1])};
        Pipes.push_back(p_1);

        cout << endl;
        cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Remove more pipes" << endl;
        cout << "\033[1;31m[ 0 ]\033[0m" << " Finish process" << endl;
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
                    auto pipe_chosen = supplyNetwork.pipes_deactivation_specific(hashReservatorio, hashCidade, Pipes);
                    functions::print_pipes_affected(pipe_chosen, hashCidade);
                    Pipes.clear();

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
                    }

                    return 0;

            }
        }
    }
    return 0;
}

//
// Created by pchmelo on 07-03-2024.
//

#include "menu.h"
#include "functions.h"

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
    cout << "\033[1;36m[ 1 ]\033[0m" << " Max-Flow" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Water Suply" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Pipes capacity reduction" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Remove a Water Reservoir" << endl;
    cout << "\033[1;36m[ 5 ]\033[0m" << " Remove Pumping Stations" << endl;
    cout << "\033[1;36m[ 6 ]\033[0m" << " Remove Pipes" << endl;
    cout << "\033[1;36m[ 7 ]\033[0m" << " Ambiente de Teste" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
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
            case 3:
                PipesReduction(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 4:
                RemoveWaterReservoir(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 5:
                RemovePumpingStation(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 6:
                RemovePipes(supplyNetwork, hashReservatorio, hashStation, hashCidade);
                break;
            case 7:
                AmbienteTeste(supplyNetwork, hashReservatorio, hashStation, hashCidade);
            case 0:
                break;
            default:
                break;
        }

        return 0;

    }
}

int Menu::MaxFlow(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                        HashCidade hashCidade) {
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
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                //imprimir os max-flows de todas cidades
                break;
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


int Menu::MaxFlowForSpecificCity(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                             HashCidade hashCidade) {
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
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
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

int Menu::MaxFlowForSpecificCityByID(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                                 HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease insert the ID of your city!\033[0m\n";
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string city;
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                //imprimir max-flow para a cidade escolhida
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

int Menu::MaxFlowForSpecificCityByName(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                                     HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease insert the name of your city!\033[0m\n";
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string city;
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                //imprimir max-flow para a cidade escolhida
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

int Menu::MaxFlowForSpecificCityByCode(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                                     HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease insert the code of your city!\033[0m\n";
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;
    cout << "\033[1;34mDecision: \033[0m";
    string city;
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                //imprimir max-flow para a cidade escolhida
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

int Menu::WaterSuply(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                  HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Cities with water deficit" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "For a specific city" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
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
                AmbienteTeste(supplyNetwork, hashReservatorio, hashStation, hashCidade);
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

int Menu::PipesReduction(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                     HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << "Pipes that can be reducted" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << "For a specific city" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
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
                AmbienteTeste(supplyNetwork, hashReservatorio, hashStation, hashCidade);
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

int Menu::RemoveWaterReservoir(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                         HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";


    cout << "Insert the Water Reservoir you would wish to remove!" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string input;
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case -1:
                if(0)
                MaxFlow(supplyNetwork, hashReservatorio, hashStation, hashCidade);
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

int Menu::RemovePumpingStation(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                         HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "Insert the Pumping Station you would wish to remove!" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
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
                AmbienteTeste(supplyNetwork, hashReservatorio, hashStation, hashCidade);
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

int Menu::RemovePipes(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                         HashCidade hashCidade) {
    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "Insert the Pipe you would wish to remove!" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
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
                AmbienteTeste(supplyNetwork, hashReservatorio, hashStation, hashCidade);
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

int Menu::AmbienteTeste(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation,
                        HashCidade &hashCidade) {

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

    Supply_Network new_one;
    new_one.supply_network = supplyNetwork.supply_network;

    auto res = new_one.processAllCitiesMaxFlow(hashCidade, hashReservatorio);
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

    abort();
}

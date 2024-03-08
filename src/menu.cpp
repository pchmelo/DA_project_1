//
// Created by pchmelo on 07-03-2024.
//

#include "menu.h"

int Menu::Terminal(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                   HashCidade hashCidade) {

    cout << endl;
    cout << "\033[1;34m      ___    _____     _______\033[0m\n";
    cout << "\033[1;34m    /   |  |  ___ |   |  ___  |\033[0m\n";
    cout << "\033[1;34m   / _  |  |  | | |   |  |_|  |\033[0m\n";
    cout << "\033[1;34m  / /_| |  |  | | |   |  _____|\033[0m\n";
    cout << "\033[1;34m / ___  |  |  |_/ /   |  |\033[0m\n";
    cout << "\033[1;34m/_/  |__|  |_____/    |__|\033[0m\n\n";

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Statistics" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Ambiente de Teste" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    while (true) {

        switch (decision) {
            case 1:
                break;
            case 2:
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

int Menu::AmbienteTeste(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation,
                        HashCidade hashCidade) {
    auto reservatorio = hashReservatorio.reservatorioTable.find(Reservoir(1));
    reservatorio->print();

    auto station = hashStation.stationTable.find(Stations(1));
    station->print();

    auto cidade = hashCidade.cidadeTable.find(City(1));
    cidade->print();

    return 0;
}

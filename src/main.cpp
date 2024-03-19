//
// Created by pchmelo on 05-03-2024.
//

#include "menu.h"

using namespace std;

int main(){
    Supply_Network supplyNetwork;
    vector<Stations> stations;

    HashReservatorio hashReservatorio;
    hashReservatorio.readLines(stations);

    HashStation hashStation;
    hashStation.readLines(stations);

    HashCidade hashCidade;
    hashCidade.readLines(stations);

    supplyNetwork.add_vertex(stations);
    supplyNetwork.read_lines();

    Menu::Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    return 0;
}

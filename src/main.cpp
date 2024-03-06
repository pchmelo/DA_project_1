//
// Created by pchmelo on 05-03-2024.
//

#include "iostream"
#include "structs/data_type/Reservoir.h"
#include "structs/data_type/City.h"
#include "structs/data_type/Stations.h"

using namespace std;

int main(){

    HashReservatorio hashReservatorio;
    hashReservatorio.readLines();

    HashStation hashStation;
    hashStation.readLines();

    HashCidade hashCidade;
    hashCidade.readLines();

    auto reservatorio = hashReservatorio.reservatorioTable.find(Reservoir(1));
    reservatorio->print();

    auto station = hashStation.stationTable.find(Stations(1));
    station->print();

    auto cidade = hashCidade.cidadeTable.find(City(1));
    cidade->print();

    cout << "Hello World!\n";
    return 0;
}

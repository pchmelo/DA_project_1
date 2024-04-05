#include "menu.h"

using namespace std;

int main(){
    bool data_set = true;

    Supply_Network supplyNetwork;
    vector<Stations> stations;

    HashReservatorio hashReservatorio;
    hashReservatorio.readLines(stations, data_set);



    HashStation hashStation;
    hashStation.readLines(stations, data_set);

    HashCidade hashCidade;
    hashCidade.readLines(stations, data_set);

    supplyNetwork.add_vertex(stations);
    supplyNetwork.read_lines(data_set);

    Menu::Terminal(supplyNetwork, hashReservatorio, hashStation, hashCidade);
    return 0;
}

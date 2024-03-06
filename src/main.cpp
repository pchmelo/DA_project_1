//
// Created by pchmelo on 05-03-2024.
//

#include "iostream"
#include "structs/data_type/Reservoir.h"
#include "structs/data_type/City.h"
#include "structs/data_type/Stations.h"
#include "structs/data_type/Supply_Network.h"

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

    for(Vertex<Stations>* v : supplyNetwork.supply_network.getVertexSet()){
        for(Edge<Stations>* e : v->getAdj()){
            int i = 0;
        }
    }

    auto reservatorio = hashReservatorio.reservatorioTable.find(Reservoir(1));
    reservatorio->print();

    auto station = hashStation.stationTable.find(Stations(1));
    station->print();

    auto cidade = hashCidade.cidadeTable.find(City(1));
    cidade->print();

    cout << "Hello World!\n";
    return 0;
}

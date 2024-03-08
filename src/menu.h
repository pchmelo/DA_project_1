//
// Created by pchmelo on 07-03-2024.
//

#ifndef PROJETO_1_MENU_H
#define PROJETO_1_MENU_H

#include "structs/data_type/Supply_Network.h"
#include "structs/data_type/Stations.h"
#include "structs/data_type/Reservoir.h"
#include "structs/data_type/City.h"

using namespace std;

class Menu {
public:
    static int Terminal(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation, HashCidade hashCidade);
    static int AmbienteTeste(Supply_Network supplyNetwork, HashReservatorio hashReservatorio, HashStation hashStation, HashCidade hashCidade);
};

#endif //PROJETO_1_MENU_H

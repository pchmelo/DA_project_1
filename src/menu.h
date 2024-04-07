#ifndef PROJETO_1_MENU_H
#define PROJETO_1_MENU_H

#include "structs/data_type/Supply_Network.h"
#include "structs/data_type/Stations.h"
#include "structs/data_type/Reservoir.h"
#include "structs/data_type/City.h"
#include "functions.h"

using namespace std;

struct pipe;

class Menu {
public:
    //Function for Basic Service Metrics
    static int BasicServiceMetrics(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);

    //Functions for Max-Flow
    static int MaxFlow(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int MaxFlowForSpecificCity(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int MaxFlowForSpecificCityByID(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int MaxFlowForSpecificCityByName(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int MaxFlowForSpecificCityByCode(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);

    //Function for Water Suply
    static int WaterSuply(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);

    //Function for Reliability and Sensitivity to Failures
    static int ReliabilityAndSensitivityToFailures(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);

    //Function to Remove a Water Reservoir
    static int RemoveWaterReservoir(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificWaterReservoir(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificWaterReservoirByName(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificWaterReservoirByID(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificWaterReservoirByCode(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);

    //Functions to Remove Pumping Stations
    static int RemovePumpingStation(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPumpingStation(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPumpingStationByID(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPumpingStationByCode(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    //Function to Remove Pipes
    static int RemovePipes(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPipe(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPipeReservoir(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPipeStation(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
    static int RemoveSpecificPipeCity(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);

    //Terminal
    static int Terminal(Supply_Network &supplyNetwork, HashReservatorio &hashReservatorio, HashStation &hashStation, HashCidade &hashCidade);
};

#endif //PROJETO_1_MENU_H

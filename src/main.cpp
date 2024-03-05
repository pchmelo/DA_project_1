//
// Created by pchmelo on 05-03-2024.
//

#include "iostream"
#include "structs/data_type/reservatorio.h"
#include "structs/data_type/cidade.h"

using namespace std;

int main(){

    HashReservatorio hashReservatorio;
    hashReservatorio.readLines();

    HashCidade hashCidade;
    hashCidade.readLines();

    auto reservatorio = hashReservatorio.reservatorioTable.find(Reservatorio(1));
    reservatorio->print();

    auto cidade = hashCidade.cidadeTable.find(Cidade(1));
    cidade->print();

    cout << "Hello World!\n";
    return 0;
}

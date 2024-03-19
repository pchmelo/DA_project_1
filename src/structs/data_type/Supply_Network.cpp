//
// Created by pchmelo on 06-03-2024.
//

#include "Supply_Network.h"
#include "string"
#include "fstream"
#include "sstream"

using namespace std;

void Supply_Network::add_vertex(std::vector<Stations> stations) {
    for(Stations s : stations){
        this->supply_network.addVertex(s);
    }
}

void Supply_Network::read_lines() {
    string input = "../src/Project1DataSetSmall/Project1DataSetSmall/Pipes_Madeira.csv";
    ifstream MyReadFile(input);

    string line;
    Stations station;

    getline(MyReadFile, line);

    while (std::getline(MyReadFile, line)) {
        vector<std::string> values;
        stringstream ss(line);

        while (ss.good()) {
            std::string subtr;
            getline(ss, subtr, ',');
            values.push_back(subtr);
        }
        auto it_1 = this->supply_network.findVertex(values[0]);
        auto it_2 = this->supply_network.findVertex(values[1]);

        this->supply_network.addEdge(values[0], values[1], stod(values[2]));

        if(values[3][0] == '0'){
            this->supply_network.addEdge(values[1], values[0], stod(values[2]));
        }

    }
}

void Supply_Network::create_super_source(HashReservatorio &hashReservatorio) {
    Stations super_reservoir = Stations(0, "super_source", 'O');
    this->supply_network.addVertex(super_reservoir);

    for(auto reservoir : hashReservatorio.reservatorioTable){
        this->supply_network.addEdge(super_reservoir, Stations(reservoir.second.get_code()), numeric_limits<int>::max());
    }
}

void Supply_Network::create_super_target(HashCidade &hashCidade) {
    Stations super_target = Stations(0, "super_target", 'D');
    this->supply_network.addVertex(super_target);

    for(auto city : hashCidade.cidadeTable){
        this->supply_network.addEdge(Stations(city.second.get_code()), super_target, numeric_limits<int>::max());
    }
}

void Supply_Network::edmondsKarp(Stations source, Stations target, HashReservatorio &hashReservatorio) {
    Vertex<Stations>* s = this->supply_network.findVertex(source);
    Vertex<Stations>* t = this->supply_network.findVertex(target);

    if (s == nullptr || t == nullptr || s == t){
        throw std::logic_error("Invalid source and/or target vertex");
    }

    for(Vertex<Stations>* v : this->supply_network.getVertexSet()){
        for(Edge<Stations>* e : v->getAdj()){
            e->setFlow(0);
        }
    }

    while(findAugmentingPath(s, t, hashReservatorio)){
        double f = findMinResidualAlongPath(s, t, hashReservatorio);
        augmentFlowAlongPath(s, t, f);
    }
}

bool Supply_Network::findAugmentingPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio) {
    for(Vertex<Stations>* v : this->supply_network.getVertexSet()){
        v->setVisited(false);
    }

    s->setVisited(true);
    queue<Vertex<Stations>*> q;
    q.push(s);

    while(!q.empty() && !t->isVisited()){
        Vertex<Stations>* v = q.front();
        q.pop();

        for(Edge<Stations>* e : v->getAdj()){
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow(), hashReservatorio);
        }

        for(Edge<Stations>* e : v->getIncoming()){
            testAndVisit(q, e, e->getOrig(), e->getFlow(), hashReservatorio);
        }
    }

    return t->isVisited();
}

void Supply_Network::testAndVisit(std::queue<Vertex<Stations> *> &q, Edge<Stations> *e, Vertex<Stations> *w,
                                  double residual, HashReservatorio &hashReservatorio) {

    if(!w->isVisited() && residual > 0){
        if(w->getInfo().get_type() == 'R'){
            auto reserv = hashReservatorio.reservatorioTable.find(w->getInfo().get_code());
            if(reserv->second.get_maxDelivery() > 0){
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
        else{
            w->setVisited(true);
            w->setPath(e);
            q.push(w);
        }
    }
}

double Supply_Network::findMinResidualAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, HashReservatorio &hashReservatorio) {
    double f = INF;
    Vertex<Stations>* v = t;

    while(v != s){
        Edge<Stations> * e = v->getPath();
        if(e->getDest() == v){
            f = min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();

            if(v->getInfo().get_type() == 'R'){
                auto rev = hashReservatorio.reservatorioTable.at(v->getInfo().get_code());
                f = min(f, (double) rev.get_maxDelivery());
                hashReservatorio.reservatorioTable.at(rev.get_code()).set_maxDelivery(rev.get_maxDelivery() - f);
            }
        }
        else{
            f = min(f, e->getFlow());
            v = e->getDest();

        }
    }

    return f;
}

void Supply_Network::augmentFlowAlongPath(Vertex<Stations> *s, Vertex<Stations> *t, double f) {
    Vertex<Stations>* v = t;

    while (v != s){
        Edge<Stations>* e = v->getPath();
        double flow = e->getFlow();
        if(e->getDest() == v){
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else{
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

vector<pair<string , double>> Supply_Network::processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio) {
    vector<pair<string , double>> res;

    create_super_source(hashReservatorio);
    create_super_target(hashCidade);

    Stations source = Stations("super_source");
    Stations target = Stations("super_target");

    this->edmondsKarp(source, target, hashReservatorio);
    res = calculeMaxFlow(hashCidade);

    return  res;
}

vector<std::pair<std::string, double>> Supply_Network::calculeMaxFlow(HashCidade &hashCidade) {
    vector<pair<string , double>> res;

    pair<string, int> p_res;
    double sum = 0;

    for(auto target : hashCidade.cidadeTable){
        Vertex<Stations>* t = this->supply_network.findVertex(target.first);
        for(Edge<Stations>* e: t->getIncoming()){
            sum += e->getFlow();
        }
        p_res.first = target.second.get_code();
        p_res.second = sum;

        res.push_back(p_res);
        sum = 0;
    }
    return res;
}


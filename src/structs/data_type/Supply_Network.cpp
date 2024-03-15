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

void Supply_Network::create_super_sink(HashReservatorio hashReservatorio) {
    Stations super_reservoir = Stations(0, "super", 'I');
    this->supply_network.addVertex(super_reservoir);

    for(auto reservoir : hashReservatorio.reservatorioTable){
        this->supply_network.addEdge(super_reservoir, Stations(reservoir.get_code()), numeric_limits<int>::max());
    }

}

void Supply_Network::edmondsKarp(Stations source, Stations target) {
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

    while(findAugmentingPath(s, t)){
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

bool Supply_Network::findAugmentingPath(Vertex<Stations> *s, Vertex<Stations> *t) {
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
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }

        for(Edge<Stations>* e : v->getIncoming()){
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }

    return t->isVisited();
}

void Supply_Network::testAndVisit(std::queue<Vertex<Stations> *> &q, Edge<Stations> *e, Vertex<Stations> *w,
                                  double residual) {
    if(!w->isVisited() && residual > 0){
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

double Supply_Network::findMinResidualAlongPath(Vertex<Stations> *s, Vertex<Stations> *t) {
    double f = INF;
    Vertex<Stations>* v = t;

    while(v != s){
        Edge<Stations> * e = v->getPath();
        if(e->getDest() == v){
            f = min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
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

vector<pair<string , double>> Supply_Network::processAllCitiesMaxFlow(HashCidade hashCidade, HashReservatorio hashReservatorio) {
    vector<pair<string , double>> res;

    create_super_sink(hashReservatorio);
    Stations source = Stations("super");

    for(auto c : hashCidade.cidadeTable){
        Stations target = Stations(c.get_code());

        this->edmondsKarp(source, target);
        res.push_back(calculeMaxFlow(target));
    }

    return  res;

}

std::pair<std::string, double> Supply_Network::calculeMaxFlow(Stations target) {
    pair<string, int> res;
    double sum = 0;

    Vertex<Stations>* t = this->supply_network.findVertex(target);

    for(Edge<Stations>* e: t->getIncoming()){
        sum += e->getFlow();
    }

    res.first = target.get_code();
    res.second = sum;

    return res;
}


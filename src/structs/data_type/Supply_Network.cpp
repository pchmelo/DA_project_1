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

void Supply_Network::read_lines(bool data_set) {
    string input;

    if(data_set){
        input = "../src/Data/Project1LargeDataSet/Pipes.csv";
    }
    else{
        input = "../src/Data/Project1DataSetSmall/Pipes_Madeira.csv";
    }

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
        this->supply_network.addEdge(super_reservoir, Stations(reservoir.second.get_code()), reservoir.second.get_maxDelivery());
    }
}

void Supply_Network::create_super_target(HashCidade &hashCidade) {
    Stations super_target = Stations(0, "super_target", 'D');
    this->supply_network.addVertex(super_target);

    for(auto city : hashCidade.cidadeTable){
        //this->supply_network.addEdge(Stations(city.second.get_code()), super_target, numeric_limits<int>::max());
        this->supply_network.addEdge(Stations(city.second.get_code()), super_target, city.second.get_demand());
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
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
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

std::map<std::string, double> Supply_Network::processAllCitiesMaxFlow(HashCidade &hashCidade, HashReservatorio &hashReservatorio) {
    std::map<std::string, double> res;

    create_super_source(hashReservatorio);
    create_super_target(hashCidade);

    Stations source = Stations("super_source");
    Stations target = Stations("super_target");

    this->edmondsKarp(source, target, hashReservatorio);
    res = calculateMaxFlow(hashCidade);

    hashReservatorio.resetMaxDelivery();

    this->supply_network.removeVertex(source);
    this->supply_network.removeVertex(target);

    return res;
}

std::map<std::string, double>  Supply_Network::calculateMaxFlow(HashCidade &hashCidade) {
    std::map<std::string, double>  res;
    double sum = 0;

    for(auto target : hashCidade.cidadeTable){
        Vertex<Stations>* t = this->supply_network.findVertex(target.first);
        for(Edge<Stations>* e: t->getIncoming()){
            sum += e->getFlow();
        }

        res[target.first] = sum;
        sum = 0;
    }
    return res;
}

vector<stations_affected> Supply_Network::station_deactivation(HashReservatorio &hashReservatorio, HashCidade &hashCidade){
    vector<stations_affected> res;
    stations_affected t;
    save_station s;

    map<string, double> first_comp = functions::file_input();
    map<string, double>  second_comp;

    first_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    functions::file_output(first_comp);

    for(auto v : this->supply_network.getVertexSet()){
        if(v->getInfo().get_type() == 'S'){
            //s.save_1(v);
            s.save_2(v);

            t.stations = v->getInfo();

            //this->supply_network.removeVertex(v->getInfo());
            second_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);

            t.cities_affect = functions::calculate_difference(first_comp, second_comp);
            res.push_back(t);

            //s.restore_1(this->supply_network, 'S');
            s.restore_2(v);
        }
    }


    return res;
}

std::vector<stations_affected>
Supply_Network::station_deactivation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade,
                                              Stations stations) {
    vector<stations_affected> res;
    stations_affected t;
    save_station s;

    std::map<std::string, double> first_comp = functions::file_input();
    std::map<std::string, double>  second_comp;

    first_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    functions::file_output(first_comp);

    auto v = this->supply_network.findVertex(stations);

    //s.save_1(v);
    s.save_2(v);

    t.stations = v->getInfo();

    //this->supply_network.removeVertex(v->getInfo());
    second_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);

    t.cities_affect = functions::calculate_difference(first_comp, second_comp);
    res.push_back(t);

    //s.restore_1(this->supply_network, 'S');
    s.restore_2(v);

    return res;
}

std::map<std::string, pipes_affected>
Supply_Network::pipes_deactivation(HashReservatorio &hashReservatorio, HashCidade &hashCidade) {
    std::map<std::string, pipes_affected> res;
    pipes_affected t;

    std::map<std::string, double> first_comp = functions::file_input();
    std::map<std::string, double>  second_comp;

    first_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    functions::file_output(first_comp);

    for(auto v : this->supply_network.getVertexSet()){
        for(auto e : v->getAdj()){
            double  weight = e->getWeight();
            t.pipes = {pipe{Stations(e->getOrig()->getInfo().get_code()), Stations(e->getDest()->getInfo().get_code())}};
            e->setWeight(0);

            second_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
            t.cities_affect = functions::calculate_difference(first_comp, second_comp);

            if(t.cities_affect.size() != 0){
                res[t.pipes.at(0).orig.get_code()] = t;
            }

            e->setWeight(weight);
        }
    }

    return res;
}

std::map<std::string, pipes_affected>
Supply_Network::pipes_deactivation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade,
                                            std::vector<pipe> pipes) {
    std::map<std::string, pipes_affected> res;
    pipes_affected t;
    t.pipes = pipes;

    //this->directed_pipes(pipes);

    std::map<std::string, double> first_comp = functions::file_input();
    std::map<std::string, double>  second_comp;

    first_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    functions::file_output(first_comp);

    for(auto &itens : pipes){
        auto v = this->supply_network.findVertex(itens.orig);
        for(auto e : v->getAdj()){
            if(e->getDest()->getInfo() == itens.dest){
                itens.weight = e->getWeight();
                //this->supply_network.removeEdge(itens.orig, itens.dest);
                //e->setWeight(0);
                break;
            }
        }
    }

    for(auto &itens : pipes){
        this->supply_network.removeEdge(itens.orig, itens.dest);
    }

    second_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    t.cities_affect = functions::calculate_difference(first_comp, second_comp);

    /*
    for(auto &itens : pipes){
        auto v = this->supply_network.findVertex(itens.orig);
        for(auto e : v->getAdj()){
            if(e->getDest()->getInfo() == itens.dest){
                e->setWeight(itens.weight);
                break;
            }
        }
    }
     */
    for(auto &itens : pipes){
        this->supply_network.addEdge(itens.orig, itens.dest, itens.weight);
    }

    res[t.pipes.at(0).orig.get_code()] = t;

    return res;
}


std::vector<reservoir_affected>
Supply_Network::reservoir_deactivation(HashReservatorio &hashReservatorio, HashCidade &hashCidade) {
    vector<reservoir_affected> res;
    reservoir_affected t;
    save_station save;

    map<string, double> first_comp = functions::file_input();
    map<string, double>  second_comp;

    first_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    functions::file_output(first_comp);

    for(auto v : this->supply_network.getVertexSet()){
        if(v->getInfo().get_type() == 'R'){
            //save.save_1(v);
            save.save_2(v);

            t.reservoir = v->getInfo();

            //this->supply_network.removeVertex(v->getInfo());
            second_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);

            t.cities_affect = functions::calculate_difference(first_comp, second_comp);
            res.push_back(t);

            //save.restore_1(this->supply_network, 'R');
            save.restore_2(v);
        }
    }
    return res;
}

std::vector<reservoir_affected>
Supply_Network::reservoir_deactivation_specific(HashReservatorio &hashReservatorio, HashCidade &hashCidade, string code) {
    std::vector<reservoir_affected> res;
    reservoir_affected t;
    save_station save;

    std::map<std::string, double> first_comp = functions::file_input();
    std::map<std::string, double>  second_comp;

    first_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);
    functions::file_output(first_comp);

    auto v = this->supply_network.findVertex(code);
    t.reservoir = v->getInfo();

    //save.save_1(v);
    save.save_2(v);

    //this->supply_network.removeVertex(v->getInfo());
    second_comp = this->processAllCitiesMaxFlow(hashCidade, hashReservatorio);

    t.cities_affect = functions::calculate_difference(first_comp, second_comp);
    res.push_back(t);

    //save.restore_1(this->supply_network, 'R');
    save.restore_2(v);

    return res;

}
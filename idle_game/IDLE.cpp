#include "IDLE.hpp"

factory::factory() {
    cost = 0;
    factoryName = "";
    income = 0;
    quantity = 0;
}

factory::factory(std::string name, int _income, int _quantity, double _cost, double _multi) {
    cost = _cost;
    quantity = _quantity;
    income = _income;
    factoryName = name;
    multi = _multi;
}

void factory::costInc() {
    cost *= multi;
}

double factory::purchase() {
    quantity += 1;
    double _cost = cost;
    costInc();
    return _cost;
}

void factory::printFactory() const {
    std::cout << "   #" << quantity << "   " 
        << factoryName << "  :  $" << cost << '\n';
}

void print(std::vector<factory> buildings, double money) {
    std::cout << "\n\n\n   $" << money << "\n\n";
    int i = 1;
    for (auto it = buildings.begin(); it < buildings.end(); it++) {
        std::cout << i << ")";
        it->printFactory();
        i++;
    }
}
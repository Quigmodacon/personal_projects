#include "IDLE.hpp"

factory::factory() {
    cost = 0;
    factoryName = "";
    income = 0;
    quantity = 0;
}

factory::factory(std::string name, int _income, int _quantity, int _cost) {
    cost = _cost;
    quantity = _quantity;
    income = _income;
    factoryName = name;
}

void factory::costInc() {
    cost *= 2;
}

int factory::purchase() {
    quantity += 1;
    costInc();
    return cost;
}

void factory::printFactory() const {
    std::cout << "   #" << quantity << "   " 
        << factoryName << "  :  $" << cost << '\n';
}

void print(std::vector<factory> buildings, int money) {
    std::cout << "\n\n\n   $" << money << "\n\n";
    for (auto it = buildings.begin(); it < buildings.end(); it++) {
        int i = 1;
        std::cout << i << ")";
        it->printFactory();
        i++;
    }
}
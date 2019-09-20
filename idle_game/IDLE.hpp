#ifndef IDLE_HPP_
#define IDLE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

class factory {
public:
    factory();
    factory(std::string name, int _income, int _quantity, double _cost, double _multi);
    double purchase();
    int payDay() const {return income * quantity;}
    void printFactory() const;
    bool check(double money) const {return cost <= money;}
private:
    double multi;
    double cost;
    std::string factoryName;
    int income;
    int quantity;

    void costInc();
};

void print(std::vector<factory> buildings, double money);

#endif
#ifndef IDLE_HPP_
#define IDLE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

class factory {
public:
    factory();
    factory(std::string name, int _income, int _quantity, int _cost);
    int purchase();
    int payDay() const {return income * quantity;}
    void printFactory() const;
    bool check(int money) const {return cost <= money;}
private:
    int cost;
    std::string factoryName;
    int income;
    int quantity;

    void costInc();
};

void print(std::vector<factory> buildings, int money);

#endif
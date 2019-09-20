#include "IDLE.hpp"
#include "buildings.hpp"

int main() { // Main game controller
    char menuOption = '*';

    double money = 2;
    int multiplier = 1;

    while(true) {
        do {
            for (auto it = buildings.begin(); it < buildings.end(); it++)
                money += it->payDay();
            print(buildings, money);
            menuOption = _getch();
        } while(menuOption != '1' && menuOption != '2' 
            && menuOption != '3' && menuOption != '4');
        switch(menuOption) {
        case '1': if (buildings[0].check(money))
                money -= buildings[0].purchase();
            break;
        case '2': if (buildings[1].check(money))
                money -= buildings[1].purchase();
            break;
        case '3': if (buildings[2].check(money))
                money -= buildings[2].purchase();
            break;
        case '4': if (buildings[3].check(money))
                money -= buildings[3].purchase();
            break;
        }
    }
}

#ifndef CALC_HPP_
#define CALC_HPP_

#include <iostream>
#include <vector>
#include <cassert>
#include "../../kent-projects/cs23001/string/string.hpp"

double addi(double x = 0, double y = 0); // adds 2 nums (valx + valy)
double subt(double x = 0, double y = 0); // subtracts to numbers (valx - valy)
double mult(double x = 0, double y = 0); // multiplies 2 nums (valx * valy)
double divi(double n = 0, double d = 0); // divides 2 numbers;
double powe(double x = 0, double a = 0); // puts a number to a power (valx ^ vala)
int fact(int x); // does factorial
double loga(double a = 0, int b = 10); // puts a number to a log base ( log[base valb](vala))
double sin(double x = 0); // does sin of a value (sin(valx))
double cos(double x = 0); // does cos of a value (cos(valx))
double tan(double x = 0); // does tan of a value (tan(valx)
	
class graph {
public:
    graph();
    void redrawGraph();
    std::vector<char> splitFunction();
private:
    std::vector<std::vector<char> > graphField;
    int xSize = 10;
    int ySize = 10;
    bool floor_ceil = true;
};


#endif

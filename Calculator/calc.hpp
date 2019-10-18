
#ifndef CALC_HPP_
#define CALC_HPP_

#include <iostream>
#include <vector>
#include <../../kent_projects/string/string.hpp>

double addi(int x = 0, int y = 0); // adds 2 nums (valx + valy)
double subt(int x = 0, int y = 0); // subtracts to numbers (valx - valy)
double mult(int x = 0, int y = 0); // multiplies 2 nums (valx * valy)
double powe(int x = 0, int a = 0); // puts a number to a power (valx ^ vala)
double loga(int a = 0, int b = 10); // puts a number to a log base ( log[base valb](vala))
double sin(int x = 0); // does sin of a value (sin(valx))
double cos(int x = 0); // does cos of a value (cos(valx))
double tan(int x = 0); // does tan of a value (tan(valx)
	
class graph {
public:
    graph();
    void redrawGraph();
    std::vector<char> splitFunction();
private:
    std::vector<std::vector<char>> graph;
    int xSize = 10;
    int ySize = 10;
    bool floor_ceil = true;
}


#endif

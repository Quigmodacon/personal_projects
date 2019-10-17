

#ifndef CALC_HPP_
#define CALC_HPP_

#include <iostream>
#include <vector>

class functions {
public:
	functions();
	void addVal(double newValue); //adds new value to vector
	void changeVal(int valNumber, double newValue); //changes value in vector, or calls addVal if nonexistent.
	
	double addi(int x = 0, int y = 0); // adds 2 nums (valx + valy)
	double subt(int x = 0, int y = 0); // subtracts to numbers (valx - valy)
	double mult(int x = 0, int y = 0); // multiplies 2 nums (valx * valy)
	double powe(int x = 0, int a = 0); // puts a number to a power (valx ^ vala)
	double loga(int a = 0, int b = 10); // puts a number to a log base ( log[base valb](vala))
	double sin(int x = 0); // does sin of a value (sin(valx))
	double cos(int x = 0); // does cos of a value (cos(valx))
	double tan(int x = 0); // does tan of a value (tan(valx)
	
	void print(int rangeX = 0, int rangeY = values.size());	

private:
	int functionsRun = 0;
}



#endif

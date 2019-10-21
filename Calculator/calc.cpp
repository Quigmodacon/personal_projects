
#include "calc.hpp"

double addi(double x, double y) {
	return x + y;
}

double subt(double x, double y) {
	return x - y;
}

double mult(double x, double y) {
	double result = 0;
	double cureY = y;
	while (cureY >= 1) {
		result += x;
		cureY--;
	}
	if (cureY > 0) {
		result += x*cureY;
	}
	return result;
}

double divi(double n, double d) {
	return n/d;
}

double powe(double x, double a) {
	double result = x;
	double cureA = a - 1;	
	while (cureA >= 1) {
		result = mult(result, x);
		cureA--;
	}
	if (cureA > 0) {
		result = mult(result, mult(x, cureA));
	}
	return result;
}

int fact(int x) {
	int result = x;
	int cureX = x - 1;
	while (cureX != 0) {
		result = mult(result, cureX);
		cureX--;
	}
	return result;
}

double loga(double a, int b) {

}

double sin(double x) {

}

double cos(double x) {

}

double tan(double x) {

}

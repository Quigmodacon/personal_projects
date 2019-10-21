#include <iostream>
#include "calc.hpp"

int main() {
	{
		assert(addi(5, 5) == 10);
		assert(subt(10, 5) == 5);
		std::cout << mult(5, 5) << '\n';
		assert(mult(5, 5) == 25);
		std::cout << mult(10, 5.7) << '\n';
		assert(mult(10, 5.7) == 57);
		std::cout << divi(15, 4) << '\n';
		assert(divi(15, 4) == 3.75);
		std::cout << powe(5, 5) << '\n';
		assert(powe(5, 5) == 3125);
		std::cout << fact(5) << '\n';
		assert(fact(5) == 120);
	}	
}

#include "Classes.h"

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	for (int k = 1; k < 610; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		std::cout << k << " I want to be nice today!" << std::endl;
	}
}
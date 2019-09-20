#ifndef BUILDINGS_HPP_
#define BUILDINGS_HPP_

#include "IDLE.hpp"

// This file contains every building type.

factory employee("Employee", 1, 1, 2, 1.25);
factory shoes("Shoes", 4, 0, 8, 1.5);
factory coffee("Coffee", 8, 0, 16, 2);
factory tools("Tools", 16, 0, 32, 2.5);

std::vector<factory> buildings = {employee, shoes, coffee, tools};

#endif

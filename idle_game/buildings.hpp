#ifndef BUILDINGS_HPP_
#define BUILDINGS_HPP_

#include "IDLE.hpp"

// This file contains every building type.

factory employee("Employee", 1, 1, 2);
factory shoes("Shoes", 4, 0, 8);
factory coffee("Coffee", 8, 0, 16);
factory tools("Tools", 16, 0, 32);

std::vector<factory> buildings = {employee, shoes, coffee, tools};

#endif

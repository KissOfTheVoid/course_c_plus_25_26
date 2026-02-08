/*
    Source file separation.
    Uses functions plus(), minus(), multiply(), divide(), 
    which are declared in "./declares.h" 
    and defined in "./plus.cpp", "./minus.cpp", "./multiply.cpp", "./divide.cpp" respectively.
*/

#include <iostream>
#include "declares.h"

int main() {
    plus();
    minus();
    divide();
    multiply();
    /*
    depends on the input, assume it's as the following:
    ---input---
    1 2
    3 4
    5 6
    7 8
    ---output---
    3
    -1
    0
    56
    */
    return 0;
}
/*
    Works with iomanip library
    Calculates squared Heron's formula with three input sides of a triangle
*/

#include <iostream>
#include <iomanip>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    std::cout << std::fixed << std::setprecision(2) << p * (p - a) * (p - b) * (p - c) << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    2 3 2
    ---output---
    3.94
    */
    return 0;
}

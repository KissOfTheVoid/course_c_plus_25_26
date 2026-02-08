/*
    Works with iomanip library
    Computes the sum of squares of the two input numbers with two degits after the decimal point
*/

#include <iostream>
#include <iomanip>

int main() {
    double a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(2) << a * a + b * b << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    4.78 3.0986
    ---output---
    32.45
    */
    return 0;
}
/*
    Works with cmath and iomanip libraries
    Calculates the euclidean distance between the centre and the input data point with two digits after the decimal point
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(2) << sqrt(a*a + b*b);
    /*
    the output depends on the input data, assume it's as following
    ---input---
    4 3
    ---output---
    5
    */
    return 0;
}
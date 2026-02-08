/*
    Works with iomanip and cmath libraries
    Reads eps and finds π smaller than it using Leibniz formula
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double eps;
    std::cin >> eps;
    double pi = 0.0;
    double term;
    int sign = 1;
    int denom = 1;
    do {
        term = sign * 4.0 / denom;
        pi += term;
        sign = -sign;
        denom += 2;
    } while (std::fabs(term) >= eps);
    std::cout << std::fixed << std::setprecision(10) << pi << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    0.0001
    --output---
    3.1416426511
    */
    return 0;
}

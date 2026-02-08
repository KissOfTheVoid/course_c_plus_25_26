/*
    Works with iomanip and cmath libraries
    Reads eps and finds term in taylor expansion of e^x which is smaller than it and stops
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x, eps;
    std::cin >> x >> eps;
    double e_x = 1.0;
    double term = x;
    int n = 1;
    e_x += term;
    while (std::fabs(term) >= eps) {
        n++;
        term *= x / n;
        e_x += term;
    }
    std::cout << std::fixed << std::setprecision(10) << e_x << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    1 0.0001
    --output---
    2.7182787698
    */
    return 0;
}

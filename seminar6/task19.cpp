/*
    Works with iomanip and cmath libraries
    Reads eps and finds term in taylor expansion of sin(x) which is smaller than it and stops
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x, eps;
    std::cin >> x >> eps;
    x = std::fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    double sin_x = x;
    double term = x;
    int n = 1;
    while (std::fabs(term) >= eps) {
        n += 2;
        term *= -x * x / (n * (n - 1));
        sin_x += term;
    }
    std::cout << std::fixed << std::setprecision(10) << sin_x << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    1.57 0.0001
    --output---
    0.9999996270
    */
    return 0;
}

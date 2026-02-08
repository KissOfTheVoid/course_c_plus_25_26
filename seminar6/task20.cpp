/*
    Works with iomanip library
    Demonstrates nested loops and finds double sum: sum from i = 1 to n sum from j = 1 to n of 1/i*j
*/

#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += 1.0 / (i * j);
        }
    }
    std::cout << std::fixed << std::setprecision(6) << sum << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    10
    --output---
    8.578855
    */
    return 0;
}

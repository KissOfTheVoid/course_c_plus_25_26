/*
    Works with iomanip library.
    Demonstrates how setprecision, fixed, hex, oct, and dec work
*/

#include <iostream>
#include <iomanip>

int main() {
    float a = 4567.2984;
    int b = 12;
    std::cout << std::fixed << std::setprecision(3) << a << '\n';
    std::cout << std::oct << a << ' ' << b << '\n';
    std::cout << std::dec << a << ' ' << b << std::endl;
    /*
    ---output---
    4567.298
    4567.298 14
    4567.298 12
    */
    return 0;
}
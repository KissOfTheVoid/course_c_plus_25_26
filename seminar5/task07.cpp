/*
    Works with cmath library
    Reads a number and prints its square root, sin of it, cos of it and its square
*/

#include <iostream>
#include <cmath>

int main() {
    double n;
    std::cin >> n;
    std::cout << n << '\n' << sqrt(n) << '\n' << sin(n) << '\n' << cos(n) << '\n' << pow(n, 2); 
    /*
    the output depends on the input data, assume it's as following
    ---input---
    3.14159265359
    ---output---
    3.14159
    1.77245
    -2.06823e-13
    -1
    9.8696
    */
    return 0;
}
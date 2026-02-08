/*
    Determines an integer's parity using bitwise operations
*/

#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if (a & 1) std::cout << "odd";
    else std::cout << "even";
    /*
    the output depends on the input data, assume it's as following
    ---input---
    12
    ---output---
    even
    */
    return 0;
}
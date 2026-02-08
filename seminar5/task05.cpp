/*
    Reads two integers and prints the results of bitwise operations with them
*/

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << (a | b) << '\n' << (a & b) << '\n' << (a ^ b) << '\n' << (a >> 1) << '\n' << (a << 1) << '\n' << (~a);
    /*
    the output depends on the input data, assume it's as following
    ---input---
    12 3
    ---output---
    15
    0
    15
    6
    24
    -13
    */
    return 0;
}
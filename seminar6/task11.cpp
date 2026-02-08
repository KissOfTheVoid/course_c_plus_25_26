/*
    Uses ternary for finding the largest out of two numbers
*/

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    (a > b) ? std::cout <<  a << std::endl : std::cout << b << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    1 2
    ---output---
    2
    */
    return 0;
}

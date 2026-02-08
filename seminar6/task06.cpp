/*
    Demonstrates short-cut logic in && and || ensuring safe division
*/

#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    (y != 0) && std::cout << x / y << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    10 0
    ---output---
    ---input---
    10 2
    ---output---
    5
    ---input---
    0 3
    ---output---
    0
    */
    return 0;
}

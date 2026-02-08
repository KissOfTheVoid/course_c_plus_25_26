/*
    Uses ternary operator ? :
*/

#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    (y != 0) ? std::cout << x / y << std::endl : std::cout << "Error" << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    2 1
    ---output---
    2
    */
    return 0;
}

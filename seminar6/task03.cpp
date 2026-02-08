/*
    Uses nested condition operators if/else for finding maximum
*/

#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a >= b) {
        if (a >= c) {
            std::cout << a << std::endl;
        } else {
            std::cout << c << std::endl;
        }
    } else {
        if (b >= c) {
            std::cout << b << std::endl;
        } else {
            std::cout << c << std::endl;
        }
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    2 1 3
    ---output---
    3
    */
    return 0;
}

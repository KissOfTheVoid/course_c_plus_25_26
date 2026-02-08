/*
    Reads a four-digit number and prints the sum of its digits
*/

#include <iostream>

int main() {
    int a, s = 0;
    std::cin >> a;
    if (a < 0) a = -a;
    while (a > 0) {
        s += a % 10;
        a /= 10;
    }
    std::cout << s;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    -123
    ---output---
    6
    */
    return 0;
}
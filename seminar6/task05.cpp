/*
    Demonstrates the basic difference between prefix and postfix increments
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a = n;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    5
    ---output---
    5
    7
    */
    return 0;
}

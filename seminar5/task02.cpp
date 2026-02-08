/*
    Reads 4 integers, computes and prints the result of some math expressio of them
*/

#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (a + b) * c - d;
    /*
    the output depends on the input data, assume it's as following 
    ---input---
    1 2 3 4
    ---output---
    5
    */
    return 0;
}
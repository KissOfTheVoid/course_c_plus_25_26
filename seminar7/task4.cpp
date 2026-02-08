/*
    Generates a multiplication table for a given number N (from 1 to 10) using pointers and nested loops
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* pN = &n;
    for (int i = 0; i < 1; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << n << " x " << j << " = " << (*pN * j) << '\n';
        }
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    7
    --output---
    7 x 1 = 7
    7 x 2 = 14
    7 x 3 = 21
    7 x 4 = 28
    7 x 5 = 35
    7 x 6 = 42
    7 x 7 = 49
    7 x 8 = 56
    7 x 9 = 63
    7 x 10 = 70
    */
    return 0;
}
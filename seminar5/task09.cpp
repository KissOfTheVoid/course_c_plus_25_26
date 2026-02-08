/*
    Swaps two variables without a temporary value (and without using pointers)
*/

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    a ^= b;
    b ^= a;
    a ^= b;
    std::cout << a << ' ' << b;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    1 2
    --output---
    2 1
    */
    return 0;
}
/*
    Finds the smallest odd number strictly greater than the input one using only arithmetic
*/

#include <iostream>

int main() {
    int a;
    std::cin >> a;
    std::cout << ((a + 1) | 1)  << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    -1
    ---output---
    1
    */
    return 0;
}

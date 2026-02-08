/*
    Demonstrates bitwise tricks. Toggles the k-th bit of input number
*/

#include <iostream>

int main() {
    int x, k;
    std::cin >> x >> k;
    x ^= (1 << k);    
    std::cout << x << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    13 1
    ---output---
    15
    */
    return 0;
}

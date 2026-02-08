/*
    Demonstrates bitwise tricks (if the integer is a power of 2)
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n > 0 && (n & (n - 1)) == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    16
    ---output---
    YES
    */
    return 0;
}

/*
    Demonstrates bitwise tricks. Calculates the number of 1s in binary represenation
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    std::cout << count << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    13
    ---output---
    3
    */
    return 0;
}

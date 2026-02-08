/*
    Uses conditions and cycles
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    std::cout << steps << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    1
    ---output---
    0
    ---input---
    2
    ---output---
    1
    ---input---
    3
    ---output---
    7
    */
    return 0;
}

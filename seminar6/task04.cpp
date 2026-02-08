/*
    Uses a while loop with postfix decrement for printing numbers from n-1 to 0
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::cout << n << std::endl;
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    3
    ---output---
    2
    1
    0
    */
    return 0;
}

/*
    Uses while for computing the sum from 1 to input value
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }
    std::cout << sum << std::endl;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    10
    --output---
    55
    */
    return 0;
}

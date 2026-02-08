/*
    Shows examples of floating-point infinity and NaN numbers, NaN fails self-equality
*/

#include <iostream>

int main() {
    double x = 1.0/0.0;
    double y = 0.0/0.0;
    std::cout << (x > 0) << " " << (x == x) << " " << (y == y) << '\n';
    // ---output--- 1 1 0
    return 0;
}
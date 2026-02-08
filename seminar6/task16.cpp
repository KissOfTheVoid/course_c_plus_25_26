/*
    Works with iomanip library
    Finds the sum of 1 + 1/2 + 1/3 + 1/4 + ...
*/

#include <iostream>
#include <iomanip>

int main() {
    double sum = 0.0;
    int i = 1;
    while (i <= 1000000) {
        sum += 1.0 / i;
        i++;
    }
    std::cout << std::fixed << std::setprecision(10) << sum << std::endl;
    /*
    ---output---
    14.3927267229
    */
    return 0;
}

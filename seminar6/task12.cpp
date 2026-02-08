/*
    Works with iomanip library
    Finds the smallest positive double z such that dividing by 2 gives 0.0
*/

#include <iostream>
#include <iomanip>

int main() {
    double z = 1.0;
    double last_nonzero;
    while (z / 2.0 != 0.0) {
        last_nonzero = z;
        z /= 2.0;
    }
    std::cout << std::scientific << std::setprecision(15) << last_nonzero << std::endl << z << std::endl;
    /*
    ---output---
    9.881312916824931e-324
    4.940656458412465e-324
    clang MacOS
    */
    return 0;
}

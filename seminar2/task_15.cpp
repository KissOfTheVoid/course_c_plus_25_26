/*
    Shows an example of overflow: converts signed int b to unsigned int (UINT_MAX + 1 - 800)
*/

#include <iostream>

int main() {
    unsigned int a = 12;
    int b = -800;
    std::cout << a + b;
    // ---output--- 4294966508
    return 0;
}
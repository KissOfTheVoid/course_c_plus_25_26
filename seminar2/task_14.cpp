/*
    Compares the sizes of INT(4), BOOL(1), LONG(8), and LONG_LONG(8)
*/

#include <iostream>

int main() {
    bool s = 1;
    std::cout << sizeof(0) << " " << sizeof(s) << " " << sizeof(0L) << " " << sizeof(0LL) << "\n"; 
    /* ---output--- 4 1 8 8
    clang MacOs
    */
    return 0;
}
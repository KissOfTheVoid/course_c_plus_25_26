/*
    Works with string library
    Takes an integer as input and displays its digits in reverse order using pointers and loops
*/

#include <iostream>
#include <string>

int main() {
    std::string i;
    std::cin >> i;
    std::cout << "Original: " << i << ", Reversed: ";
    if (i[0] == '-') {
        std::cout << '-';
        i.erase(0, 1);
    }
    for (int j = i.length() - 1; j >= 0; --j) {
        std::cout << i[j];
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    12345
    --output---
    Original: 12345, Reversed: 54321
    */
    return 0;
}
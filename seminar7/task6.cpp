/*
    Works with string library
    Calculates the sum of all digits in a given number using pointers and a loop
*/

#include <iostream>
#include <string>

int main() {
    std::string i, initiall;
    int s = 0;
    std::cin >> i;
    initiall = i;
    std::cout << "Sum of digits in " << i << ": ";
    if (i[0] == '-') i.erase(0, 1);
    for (int j = 0; j <= i.length() - 1; ++j) {
        s += i[j] - '0';
        std::cout << i[j];
        if (j != i.length() - 1) std::cout << '+';
    }
    std::cout << " = " << s;
    /*
    the output depends on the input data, assume it's as following
    ---input---
    1234
    --output---
    Sum of digits in 1234: 1+2+3+4 = 10
    ---input---
    -567
    --output---
    Sum of digits in -567: 5+6+7 = 18
    */
    return 0;
}
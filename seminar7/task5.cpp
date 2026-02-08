/*
    Counts the number of digits in a given integer using pointers and a loop
*/

#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    int l = s.length();
    if (s[0] == '-') --l;
    std::cout << "Number " << s << " has " << l << " digit";
    if (l > 1) std::cout << 's';
    /*
    the output depends on the input data, assume it's as following
    ---input---
    12345
    --output---
    Number 12345 has 5 digits
    ---input---
    -987
    --output---
    Number -987 has 3 digits
    ---input---
    0
    --output---
    Number 0 has 1 digit
    */
    return 0;
}
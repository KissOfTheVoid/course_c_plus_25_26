/*
    Reads 3 characters as chars and outputs their codes in the format <<char>> <<char code>>
*/

#include <iostream>

int main() {
    char a, b, c;
    int a1, b1, c1;
    std::cout << "input 3 characters: " << std::endl;
    std::cin >> a >> b >> c;
    a1 = a;
    b1 = b;
    c1 = c;
    std::cout << a << ' ' << a1 << '\n' << b << ' ' << b1 << '\n' << c << ' ' << c1 << '\n';
    /*
    the output depends on the input data, assume it's as following
    ---input---
    a b c
    ---output---
    a 97
    b 98
    c 99
    */
    return 0;
}
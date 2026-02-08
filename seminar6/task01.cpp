/*
    Demonstrates variables in different scopes
*/

#include <iostream>

int x = 10;

int main() {
    int x = 20;
    {
        int x = 30;
        std::cout << ::x << ' ' << x << ' ' << x << '\n';
    }
    std::cout << ::x << ' ' << x << std::endl;
    /*
    ---output---
    10 30 30
    10 20
    */
    return 0;
}

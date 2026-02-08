/*
    Uses nested conditions if/else
*/

#include <iostream>

int main() {
    int score;
    std::cin >> score;
    if (score >= 90) {
        std::cout << "A" << std::endl;
    } else if (score >= 80) {
        std::cout << "B" << std::endl;
    } else if (score >= 70) {
        std::cout << "C" << std::endl;
    } else if (score >= 60) {
        std::cout << "D" << std::endl;
    } else {
        std::cout << "F" << std::endl;
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    59
    ---output---
    F
    */
    return 0;
}

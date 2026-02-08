/*
    Creates a template functuon swapValues for swapping two values of any type
*/

#include <iostream>

template<typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
    std::cout << "Swapped" << std::endl;
}

int main() {
    int a = 2, b = 20000000;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swapValues(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    double c = 3.14, d = 2.71;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    swapValues(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::string e = "Smth1", f = "Smth2";
    std::cout << "e = " << e << ", f = " << f << std::endl;
    swapValues(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    /*
    ---output---
    a = 2, b = 20000000
    Swapped
    a = 20000000, b = 2
    c = 3.14, d = 2.71
    Swapped
    c = 2.71, d = 3.14
    e = Smth1, f = Smth2
    Swapped
    e = Smth2, f = Smth1
    */
    return 0;
}

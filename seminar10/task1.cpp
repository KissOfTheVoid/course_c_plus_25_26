/*
    Works with string, cstddef, concepts, and type_traits libraries
    Demonstrates templates. 
    Templates here are used for creation of a function, which works with several datatypes that have operator > and returns maximum element
*/

#include <iostream>
#include <cstddef>
#include <concepts>
#include <type_traits>
#include <string>

template<class T, std::size_t N> 
//requires(std::integral<T> || std::floating_point<T>) //doesnt work with std::string
T findMax(const T(&a)[N]) {
    T maxi = a[0];
    for (std::size_t i = 1; i < N; ++i) {
        if (a[i] > maxi) {
            maxi = a[i];
        }
    }
    return maxi;
}

int main() {
    int test1[] = {1, 2, 3, 4, 3};
    std::string test2[] = {"ett", "f"};
    std::cout << findMax(test1) << ' ' << findMax(test2) << std::endl;
    /*
    ---output---
    4 f
    */
    return 0;
}
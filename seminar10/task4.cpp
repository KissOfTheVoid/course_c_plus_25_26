/*
    Works with cstddef, concepts, type_traits, string libraries
    Template function calculateAverage that calculates average and can only work with integers or floats
*/

#include <iostream>
#include <cstddef>
#include <concepts>
#include <string>
#include <type_traits>

template<class T> 
concept Member = std::integral<T> || std::floating_point<T>;
template<Member T>
T calculateAverage(const T* a, std::size_t n) {
    T sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum / static_cast<T>(n);
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string arr3[] = {"str", "skrrrrr"};
    std::size_t n = sizeof(arr1)/sizeof(arr1[0]);
    std::size_t m = sizeof(arr2)/sizeof(arr2[0]);
    std::cout << calculateAverage(arr1, n)  << '\n' << calculateAverage(arr2, m) << std::endl;
    //int error = calculateAverage(arr3, 4);
    /*
    ---output---
    3
    3.3
    */
    return 0;
}
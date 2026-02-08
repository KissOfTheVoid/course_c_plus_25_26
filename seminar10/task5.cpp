/*
    Works with string library
    Template function findElement, which find an element and returns its index (or -1)
    Has a specialization for strings
*/

#include <iostream>
#include <string>


template<typename T>
int findElement(const T* arr, std::size_t n, const T& value) {
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

template<>
int findElement<std::string>
                            (const std::string* arr, std::size_t n,
                            const std::string& value) {
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    int arr1[] = {1, 3, 5, 4, 9};
    std::string arr2[] = {"skrr", "str", "swag"};

    std::size_t n = sizeof(arr1)/sizeof(arr1[0]);
    std::size_t m = sizeof(arr2)/sizeof(arr2[0]);

    std::cout << findElement(arr1, n, 4) << std::endl;
    std::cout << findElement(arr2, m, std::string("skrrr")) << ' ' << findElement(arr2, m, std::string("skrr")) << std::endl;
    /*
    ---output---
    3
    -1 0
    */
    return 0;
}



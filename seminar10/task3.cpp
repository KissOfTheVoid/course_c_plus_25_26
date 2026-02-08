/*
    Works with functional library
    Template function bubbleSort that has a default comparator std::less<>
*/

#include <iostream>
#include <functional>

template<typename T, typename Compare = std::less<T>>
void bubbleSort(T* arr, size_t size, Compare comp = Compare{}) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
void printArray(T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 5, 4, 11, 10, 7, 8, 9};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    std::cout << "Sorted (default): ";
    printArray(arr, n);
    
    int arr2[] = {5, 3, 8, 4, 2};
    size_t m = sizeof(arr2) / sizeof(arr2[0]);
    
    bubbleSort(arr2, m, std::greater<int>{});
    std::cout << "Descending order: ";
    printArray(arr2, m);
    
    /*
    ---output---
    Sorted (default): 1 2 3 4 5 7 8 9 10 11 
    Descending order: 8 5 4 3 2
    */

    return 0;
}
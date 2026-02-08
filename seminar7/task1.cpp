/*
    Generates the first input terms of the Fibonacci sequence using pointers
*/

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    arr[0] = 0; arr[1] = 1; arr[2] = 1;
    for (int i = 3; i < n; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    for (int j = 0; j < n; ++j) {
        std::cout << arr[j] << ' ';
    }
    /*
    the output depends on the input data, assume it's as following
    ---input---
    7
    --output---
    0 1 1 2 3 5 8 
    */
    return 0;
}
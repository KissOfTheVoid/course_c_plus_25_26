/*
    Works with cstdlib, ctime, thread, chrono, and vector libraries
    Generates a dynamic matrix with random numbers as elements
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>

int main() {
    int n = 5, m = 5;
    int delay = 100; 
    srand(time(0));

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (auto &row : matrix)
        for (auto &val : row)
            val = rand() % 10;

    while (true) {
        system("clear");

        for (const auto &row : matrix) {
            for (int val : row)
                std::cout << val << ' ';
            std::cout << '\n';
        }

        for (int i = 0; i < n - 1; ++i)
            matrix[i] = matrix[i + 1];

        for (int j = 0; j < m; ++j)
            matrix[n - 1][j] = rand() % 10;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    /*
    the output is dynamic, example
    8 7 2 1 8 
    2 3 6 1 0 
    4 4 9 8 6 
    7 7 1 0 2 
    2 1 2 1 2 
    2 3 6 1 0 
    4 4 9 8 6 
    7 7 1 0 2 
    2 1 2 1 2 
    0 7 3 7 5 
    */
   return 0;
}

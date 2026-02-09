/*
    Works with memory, casset libraries
    Matrix class that manages a 2D array using unique_ptr<double[]>.
        Constructor takes rows and cols parameters
        Uses single contiguous allocation (new double[rows * cols])
        Provides operator()(size_t row, size_t col) for element access
        Automatically calls delete[] (not delete) on destruction
*/

#include <memory>
#include <cassert>
#include <iostream>

class Matrix {
    size_t rows_, cols_;
    std::unique_ptr<double[]> data_;
public:
    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_(std::make_unique<double[]>(rows * cols)) {}

    double& operator()(size_t row, size_t col) {
        assert(row < rows_ && col < cols_);
        return data_[row * cols_ + col];
    }

    double operator()(size_t row, size_t col) const {
        assert(row < rows_ && col < cols_);
        return data_[row * cols_ + col];
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
};

int main() {
    Matrix m(3, 4);
    for (size_t i = 0; i < m.rows(); ++i) {
        for (size_t j = 0; j < m.cols(); ++j) {
            m(i, j) = i * 10 + j;
        }
    }
    for (size_t i = 0; i < m.rows(); ++i) {
        for (size_t j = 0; j < m.cols(); ++j) {
            std::cout << m(i, j) << " ";
        }
        std::cout << "\n";
    }
    /*
    ---output---
    0 1 2 3 
    10 11 12 13 
    20 21 22 23 
    */
    return 0;
}
/*
    Works with vector, string, chrono, and utility libraries
    Demonstrates std::swap with and without move semantics. Creates and works with 
    class NoMoveBuffer, which is non-movable but has a custom swap
    class MoveBuffer, which is movable and works with swap
    template function benchmark_swap, which evaluates the running time of completing required number of swaps
*/

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <utility>

class NoMoveBuffer {
    std::vector<char> c1;
public:
    NoMoveBuffer() = default;
    explicit NoMoveBuffer(size_t size) : c1(size) {}
    NoMoveBuffer(std::initializer_list<char> init) : c1(init) {}
    NoMoveBuffer(const NoMoveBuffer& other) : c1(other.c1) {}
    NoMoveBuffer& operator=(const NoMoveBuffer& other) {
        c1 = other.c1;
        return *this;
    }
    NoMoveBuffer(NoMoveBuffer&&) = delete;
    NoMoveBuffer& operator=(NoMoveBuffer&&) = delete;
    friend void swap(NoMoveBuffer& a, NoMoveBuffer& b) noexcept {
        NoMoveBuffer tmp = a;
        a = b;
        b = tmp;
    }
    size_t size() const { return c1.size(); }
    const char* data() const { return c1.data(); }
};

class MoveBuffer {
    std::vector<char> c2;
public:
    MoveBuffer() = default;
    explicit MoveBuffer(size_t size) : c2(size) {}
    MoveBuffer(std::initializer_list<char> init) : c2(init) {}
    MoveBuffer(const MoveBuffer& other) : c2(other.c2) {}
    MoveBuffer& operator=(const MoveBuffer& other) {
        c2 = other.c2;
        return *this;
    }
    MoveBuffer(MoveBuffer&& other) noexcept
        : c2(std::move(other.c2)) {}

    MoveBuffer& operator=(MoveBuffer&& other) noexcept {
        if (this != &other) {
            c2 = std::move(other.c2);
        }
        return *this;
    }
    friend void swap(MoveBuffer& a, MoveBuffer& b) noexcept {
        using std::swap;
        swap(a.c2, b.c2);
    }
    size_t size() const { return c2.size(); }
    const char* data() const { return c2.data(); }
};

template<class T>
void benchmark_swap(const std::string ttype, const T& nomove, const T& move, size_t number) {
    T buf1 = nomove;
    T buf2 = move;
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < number; ++i) {
        using std::swap;
        swap(buf1, buf2);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << ttype << '\n' << "Buffer's size = " << buf1.size() << "\nNumber of iterations of swapping = " << number << "\nThe duration = " << duration.count() << '\n';
}

int main() {
    const size_t buffer_size = 10000;
    const size_t num_swaps = 100;
    NoMoveBuffer no_move(buffer_size);
    MoveBuffer move_buf(buffer_size);
    benchmark_swap("NoMoveBuffer", no_move, no_move, num_swaps);
    benchmark_swap("MoveBuffer", move_buf, move_buf, num_swaps);
    /*
    ---output---
    NoMoveBuffer
    Buffer's size = 10000
    Number of iterations of swapping = 100
    The duration = 2855
    MoveBuffer
    Buffer's size = 10000
    Number of iterations of swapping = 100
    The duration = 0
    */
    return 0;
}

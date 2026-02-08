/*
    Works with vector library
    The huge demonstration of noexcept and why its important
*/

#include <iostream>
#include <vector>


//without noexcept
struct BufferNoNoexcept {
    static int copy_count;
    static int move_count;

    std::vector<int> data;

    BufferNoNoexcept() = default;
    explicit BufferNoNoexcept(int n) : data(n, 0) {}

    BufferNoNoexcept(const BufferNoNoexcept& other)
        : data(other.data)
    {
        ++copy_count;
    }

    BufferNoNoexcept(BufferNoNoexcept&& other)
        : data(std::move(other.data))
    {
        ++move_count;
    }

    BufferNoNoexcept& operator=(const BufferNoNoexcept& other) {
        if (this != &other) {
            data = other.data;
            ++copy_count;
        }
        return *this;
    }

    BufferNoNoexcept& operator=(BufferNoNoexcept&& other) {
        if (this != &other) {
            data = std::move(other.data);
            ++move_count;
        }
        return *this;
    }
};

int BufferNoNoexcept::copy_count = 0;
int BufferNoNoexcept::move_count = 0;

//with it
struct BufferNoexcept {
    static int copy_count;
    static int move_count;

    std::vector<int> data;

    BufferNoexcept() = default;
    explicit BufferNoexcept(int n) : data(n, 0) {}

    BufferNoexcept(const BufferNoexcept& other)
        : data(other.data)
    {
        ++copy_count;
    }

    BufferNoexcept(BufferNoexcept&& other) noexcept
        : data(std::move(other.data))
    {
        ++move_count;
    }

    BufferNoexcept& operator=(const BufferNoexcept& other) {
        if (this != &other) {
            data = other.data;
            ++copy_count;
        }
        return *this;
    }

    BufferNoexcept& operator=(BufferNoexcept&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            ++move_count;
        }
        return *this;
    }
};

int BufferNoexcept::copy_count = 0;
int BufferNoexcept::move_count = 0;

int main() {
    {
        std::vector<BufferNoNoexcept> v;
        for (int i = 0; i < 1000; ++i) {
            v.push_back(BufferNoNoexcept(100));
        }
        std::cout << "BufferNoNoexcept:\n";
        std::cout << "  copies = " << BufferNoNoexcept::copy_count << "\n";
        std::cout << "  moves  = " << BufferNoNoexcept::move_count << "\n\n";
    }

    {
        std::vector<BufferNoexcept> v;
        for (int i = 0; i < 1000; ++i) {
            v.push_back(BufferNoexcept(100));
        }
        std::cout << "BufferNoexcept:\n";
        std::cout << "  copies = " << BufferNoexcept::copy_count << "\n";
        std::cout << "  moves  = " << BufferNoexcept::move_count << "\n";
    }
    /*
    ---output---
    BufferNoNoexcept:
    copies = 1023
    moves  = 1000

    BufferNoexcept:
    copies = 0
    moves  = 2023
    */
    return 0;
}

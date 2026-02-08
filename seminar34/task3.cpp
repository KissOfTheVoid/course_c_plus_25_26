/*
    Works with cstring, memory libraries
    Buber class that:
        Manages a dynamically allocated char array using std::unique_ptr<char[]>
        Has constructor taking size parameter
        Provides operator[] for element access
        Includes a reset(size_t new_size) method that reallocates buber
        Uses a custom delete that logs deallocation size before freeing memor
*/

#include <memory>
#include <iostream>
#include <cstring>

struct deleter {
    size_t size;
    
    deleter(size_t s = 0) : size(s) {}
    
    void operator()(char* ptr) const {
        if (ptr) {
            std::cout << "deleter is running" << std::endl;
            delete[] ptr;
        }
    }
};

class Buffer {
private:
    std::unique_ptr<char[], deleter> buffer_;
    size_t current_size_;

public:
    explicit Buffer(std::size_t n)
        : buffer_(n ? new char[n] : nullptr, deleter{n}),
          current_size_(n)
    {
        std::cout << "constructor" << std::endl;
    }
    
    char& operator[](size_t index) {
        return buffer_[index];
    }
    
    const char& operator[](size_t index) const {
        return buffer_[index];
    }
    
    void reset(size_t new_size) {
        std::unique_ptr<char[], deleter> newData(
            new_size ? new char[new_size] : nullptr,
            deleter{new_size}
        );
    }
    
};

int main() {
    std::cout << "0" << std::endl;
    Buffer buf(1024);
    std::cout << "1" << std::endl;
    buf[0] = 'H';
    std::cout << "2" << std::endl;
    buf[1] = 'i';
    std::cout << "3" << std::endl;
    buf.reset(2048);
    std::cout << "4" << std::endl;
    /*
    ---output---
    0
    constructor
    1
    2
    3
    deleter is running
    4
    deleter is running
    */
}
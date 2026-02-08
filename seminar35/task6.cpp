/*
    Works with memory, stdexcept libraries
    Demonstrates exception safety and RAII through 
*/

#include <memory>
#include <iostream>
#include <stdexcept>

class Resource {
    int id_;
public:
    explicit Resource(int id) : id_(id) {
        std::cout << "Resource " << id_ << " acquired\n";
        if (id_ == 3) {
            throw std::runtime_error("Resource 3 acquisition failed!");
        }
    }
    ~Resource() {
        std::cout << "Resource " << id_ << " released\n";
    }
};

class Transaction {
    // TODO: Store resources using unique_ptr
    std::unique_ptr<Resource> r1;
    std::unique_ptr<Resource> r2;
    std::unique_ptr<Resource> r3;
public:
    Transaction() : 
    r1(std::make_unique<Resource>(1)), 
    r2(std::make_unique<Resource>(2)), 
    r3(std::make_unique<Resource>(3)) 
    {}
};

int main() {
    try {
        Transaction tx;
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    std::cout << "Correctly\n";
    /*
    ---output---
    Resource 1 acquired
    Resource 2 acquired
    Resource 3 acquired
    Resource 2 released
    Resource 1 released
    Resource 3 acquisition failed!
    Correctly
    */
    return 0;
}

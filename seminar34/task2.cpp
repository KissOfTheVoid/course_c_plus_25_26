/*
    Works with memory, vector, stdexcept libraries
    a ResourceManager class that:
        Stores a std::vector<std::unique_ptr<int>> of resources
        Has acquire(int value) method that creates and stores a new resource
        Has release(size_t index) method that transfers ownership of resource at index to caller (returns std::unique_ptr<int>)
        Handles edge cases (invalid index, empty manager)
        release() should use std::move to transfer ownership
        After release(), the vector slot should contain nullptr
*/

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>

class ResourceManager {
private:
    std::vector<std::unique_ptr<int>> resources_;
public:
    void acquire(int value) {
        resources_.emplace_back(std::make_unique<int>(value));
    }

    std::unique_ptr<int> release(size_t index) {
        if (index >= resources_.size()) {
            throw std::out_of_range("Invalid resource index");
        }
        std::unique_ptr<int> ptr = std::move(resources_[index]);
        return ptr;
    }

    size_t size() const { return resources_.size(); }
};

int main() {
    ResourceManager mgr;
    mgr.acquire(10);
    mgr.acquire(20);
    mgr.acquire(30);

    auto res = mgr.release(1);
    std::cout << *res << "\n";
    std::cout << mgr.size() << "\n";
    /*
    ---output---
    20
    3
    */
    return 0;
}

/*
    Works with vector, string, cstddef, algorithm
    Demonstration of the use of the rule of five through 
    class ResourceHolder
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>

class ResourceHolder {
    int* data;
    size_t size;
public:
    explicit ResourceHolder(size_t n) : data(new int[n]()), size(n) {}
    ~ResourceHolder() { delete[] data; }
    ResourceHolder(const ResourceHolder& other) : data(new int[other.size]), size(other.size)
    { 
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }
    ResourceHolder& operator=(const ResourceHolder& other) {
        if (this == &other) return *this;
        int* newData = new int[other.size];
        for (size_t i = 0; i < other.size; ++i) { newData[i] = other.data[i]; }
        delete[] data;
        data = newData;
        size = other.size;
        return *this;
    }
    ResourceHolder(ResourceHolder&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }
    ResourceHolder& operator=(ResourceHolder&& other) noexcept {
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        return *this;
    }
    size_t getSize() const { return size; }
    int* getData() { return data; }
    const int* getData() const { return data; }
};



int main() {
    ResourceHolder r(1000);
    ResourceHolder re(7);
    // testing move-constructor
    ResourceHolder res(std::move(r));
    std::cout << "Size of r after move-ctor = " << r.getSize() << '\n' << "Data of r after move-ctor = " << r.getData() << std::endl;
    // testing move-assignment
    ResourceHolder reso(42);
    reso = std::move(re);
    std::cout << "Size of re after move-ctor = " << re.getSize() << '\n' << "Data of re after move-ctor = " << re.getData() << std::endl;


    std::vector<ResourceHolder> vec;
    vec.reserve(3); // why?
    // we need reservation to pre-allocate space for future insertions (push_back)
    vec.push_back(ResourceHolder(1000));
    vec.push_back(ResourceHolder(2000));
    vec.push_back(ResourceHolder(500));
    std::cout << "Vectr size: " << vec.size() << "\n";
    std::cout << "Element sizes: " << vec[0].getSize() << ", " << vec[1].getSize() << ", " << vec[2].getSize() << "\n";
    /*
    ---output---
    Size of r after move-ctor = 0
    Data of r after move-ctor = 0x0
    Size of re after move-ctor = 0
    Data of re after move-ctor = 0x0
    Vectr size: 3
    Element sizes: 1000, 2000, 500
    */
    return 0;
}
/*
    Works with string, vector, algorithm, numeric
    Demonstrates the inheritance and slicing
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Base {
protected:
    std::string name;
public:
    Base(const std::string& n) : name(n) {}
    Base(const Base& other) : name(other.name) {}
    Base(Base&& other) noexcept : name(std::move(other.name)) {}
    Base& operator=(const Base& other) {
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }
    Base& operator=(Base&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
        }
        return *this;
    }
    virtual ~Base() {
        std::cout << "The destructor for the base class was called" << std::endl;
    }
    virtual void test() {}
};

class Derived : public Base {
protected:
    std::vector<int> data;
    
public:
    Derived(const std::string& n) : Base(n), data(1000) {}
    
    Derived(const Derived& other) : Base(other), data(other.data) {}
    
    Derived(Derived&& other) noexcept : Base(std::move(other)), data(std::move(other.data)) {}
    
    Derived& operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other);
            data = other.data;
        }
        return *this;
    }
    
    Derived& operator=(Derived&& other) noexcept {
        if (this != &other) {
            Base::operator=(std::move(other));
            data = std::move(other.data);
        }
        return *this;
    }
    
    ~Derived() {
        std::cout << "The destructor for the derived class was called" << std::endl;
    }
    void test() override {
        std::cout << "test is called";
    }
};


void processByValue(Base b) {
    b.test();
}

int main() {
    Derived d("Sliced");
    processByValue(d);
    /*
    ---output---
    The destructor for the base class was called
    The destructor for the derived class was called
    The destructor for the base class was called
    */
    return 0;
}
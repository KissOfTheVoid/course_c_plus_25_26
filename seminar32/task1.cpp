/*
    Demonstrates template structs. 
    Creates a struct TypeInfo that has was simple function print which depends on the type of the input
*/


#include <iostream>

template<typename T>
struct TypeInfo {
public:
    static void print() {
        std::cout << "Type is generic\n";
    }
};

template<>
struct TypeInfo<int> {
public:
    static void print() {
        std::cout << "Type is integer\n";
    }
};

template<>
struct TypeInfo<double> {
public:
    static void print() {
        std::cout << "Type is double\n";
    }
};

template<>
struct TypeInfo<float*> {
public:
    static void print() {
        std::cout << "Type is floating-point\n";
    }
};

template<>
struct TypeInfo<int*> {
public:
    static void print() {
        std::cout << "Type is int-point\n";
    }
};

int main() {
    TypeInfo<char>::print();
    TypeInfo<int>::print();
    TypeInfo<double>::print();
    TypeInfo<float*>::print();
    TypeInfo<int*>::print();
    /*
    ---output---
    Type is generic
    Type is integer
    Type is double
    Type is floating-point
    Type is int-point
    */
    return 0;
}
/*
    Works with string
    Demonstrates the usage of template stack: 
    creates the struct Stack, which have push, pop, top, size, and empty functions
*/

#include <iostream>
#include <string>

template<class T, size_t N>
class Stack {
protected:
    T data[N];
    size_t c = 0;
public:
    void push(const T& item) {
        if (c < N) data[c++] = item;
    }
    void pop() {
        if (c > 0) --c;
    }
    T& top() {
        return data[c - 1];
    }
    size_t size() const {
        return c;
    }
    bool empty() const {
        return c == 0;
    }
};


int main() {
    Stack<int, 5> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << intStack.top() << std::endl;
    std::cout << intStack.size() << std::endl;
    Stack<std::string, 3> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.pop();
    std::cout << strStack.top() << std::endl;
    /*
    ---output---
    20
    2
    Hello
    */
return 0;
}
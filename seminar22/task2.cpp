/*
    Works with vector library
    Class of arithmetic progression with operator overloading
*/

#include <iostream>
#include <vector>

class ArithmeticProgression {
    double start;
    double step;
    size_t size;
    std::vector<double> sequence;

public:
    ArithmeticProgression() : start(0), step(1), size(0) {}
    
    ArithmeticProgression(double s, double st, size_t sz) 
        : start(s), step(st), size(sz) {
        sequence.resize(sz);
        for (size_t i = 0; i < sz; ++i) {sequence[i] = start + i * step;}
    }
    
    size_t getSize() const {return size;}
    
    double operator[](int index) const {
        if (index >= 0 && static_cast<size_t>(index) < size) {return sequence[index];}
        return 0.0;
    }
};

int main() {
    ArithmeticProgression test1(3, 3.5, 45);
    std::cout << "Size: " << test1.getSize() << std::endl;
    for (int i = 0; i < 7; ++i) {std::cout << test1[i] << std::endl;}
    /*
    ---output---
    Size: 45
    3
    6.5
    10
    13.5
    17
    20.5
    24
    */
    return 0;
}

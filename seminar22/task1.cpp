/*
    Works with cmath, vector, algorithm, string libraries
    Complex numbers class with several methods and copy constructor
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

class Complex {
    double real;
    double imag;
public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}
    double getReal() const { return real; }
    double getImag() const { return imag; }
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }
    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) out << "+";
        out << c.imag << "i";
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }
};

int main() {
    Complex a(1, 2), b(3, -4), c(-5, 6);
    std::cout << a << '\n' << b << '\n' << c.modulus() << std::endl;
    std::cout << a + (b * c) << std::endl;
    /*
    ---output---
    1+2i
    3-4i
    7.81025
    10+40i
    */
    return 0;
}
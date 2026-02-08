/*
    Works with type_traits
    class Number<T> that
        has a universal reference constructor template<class U> Number(U&& value),
        disables this constructor when U is the same type as Number<T> (to avoid interfering with copy/move constructors)
*/

#include <iostream>
#include <type_traits>

template <class T>

class Number {
    T val;
public:
    Number(const Number& other): val(other.val) {
        std::cout << "Copy const" << std::endl;
    }

    Number(Number&& other) noexcept : val(std::move(other.val)) {
        std::cout << "Move constr" << std::endl;
    }

    template <
                class U, 
                class = std::enable_if_t<
                !std::is_same_v<std::decay_t<U>, Number>&&
                std::is_constructible_v<T, U&&>
                >>

    Number(U&& val) : val(std::forward<U>(val)) {
        std::cout << "Template constr" << std::endl;
    } 

};


int main() {
    Number<int> a(10);
    Number<int> b(a); // call copy constructor
    Number<int> c(std::move(a)); // call move constructor
    Number<double> d(3.14); // uses template constructor
    Number<int> e(42); // uses template constructor
    /*
    ---output---
    Template constr
    Copy const
    Move constr
    Template constr
    Template constr
    */
    return 0;
}
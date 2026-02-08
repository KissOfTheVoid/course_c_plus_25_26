/*
    Works with type_traits, concepts
    Template class IntAccumulator<T> that can only be instantiated with integer types that support the + operator
*/

#include <iostream>
#include <type_traits>
#include <concepts>

template<typename T>
concept IntAddable =
    std::is_integral_v<T> &&
    requires(T a, T b) { a + b; };

template<IntAddable T> 
class IntAccumulator {
    T value;
public:
    explicit IntAccumulator(T v) : value(v) {}

    T add(T x) const {
        return value + x;
    }
};

int main() {
    IntAccumulator<int> a(10);
    std::cout << a.add(5) << '\n';

    IntAccumulator<char> b('A');
    std::cout << b.add(1) << '\n';

    // IntAccumulator<double> c(3.14);     
// ^^^ error: double не IntAddable (not integral)
    // IntAccumulator<std::string> d('x'); 
// ^^^ error: string is not integral
    /*
    ---output---
    15
    B
    */
    return 0;
}

/*
    Works with type_traits, utility, string libraries
    Wrapper class `Box<T>` that has copy/move and a generic constructor, but the generic **must not** intercept copy/move of `Box<T>`
*/

#include <iostream>
#include <type_traits>
#include <utility>
#include <string>

template<class T>
class Box {
    T value;
public:
    Box(const Box& other) : value(other.value) {
        std::cout << "copy" << std::endl;
    }

    Box(Box&& other) noexcept : value(std::move(other.value)) {
        std::cout << "move" << std::endl;
    }

    template<class U,
        typename std::enable_if_t<
            !std::is_same_v<std::remove_cvref_t<U>, Box> &&
            std::is_constructible_v<T, std::remove_reference_t<U>&&>
        , int> = 0
    >
    Box(U&& arg) : value(std::forward<U>(arg)) {
        std::cout << "templ" << std::endl;
    }
};

int main() {
    Box<int> a(10);
    Box<int> b(a);
    Box<int> c(std::move(a));
    Box<std::string> s("hi");
    /*
    ---output---
    templ
    copy
    move
    templ
    */
    return 0;
}

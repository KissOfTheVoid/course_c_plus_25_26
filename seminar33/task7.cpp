/*
    Works with vector, type_traits, utility, initializer_list libraries
    Demonstrates conflict between generic constructor and `initializer_list` and shows how to resolve it correctly
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include <utility>
#include <initializer_list>

template<class T>
class VectorLike {
    std::vector<T> data;

public:
    VectorLike(std::initializer_list<T> ilist) : data(ilist) {
        std::cout << "ilist" << std::endl;
    }

    VectorLike(const VectorLike& other) : data(other.data) {
        std::cout << "copy" << std::endl;
    }

    VectorLike(VectorLike&& other) noexcept : data(std::move(other.data)) {
        std::cout << "move" << std::endl;
    }

    template<class U,
        typename std::enable_if_t<
            !std::is_same_v<std::remove_cvref_t<U>, VectorLike> &&
            !std::is_same_v<std::remove_cvref_t<U>, std::initializer_list<T>>,
            int> = 0
    >
    VectorLike(U&& arg) : data(1, std::forward<U>(arg)) {
        std::cout << "templ" << std::endl;
    }
};

int main() {
    VectorLike<int> a{1,2,3};
    VectorLike<int> b(a);
    VectorLike<int> c(std::move(a));
    VectorLike<int> d(5);
    /*
    ---output---
    ilist
    copy
    move
    templ
    */
    return 0;
}

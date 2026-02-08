#include <iostream>
#include <algorithm>
#include <utility>
#include <cstddef>
#include <new>
#include <memory>

template <typename T>
class Myvector {
    T* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
public:
    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    Myvector() noexcept;
    Myvector& operator=(const Myvector &rhs);
    Myvector& operator=(Myvector &&rhs) noexcept;

    size_t Size() const noexcept;
    size_t Capacity() const noexcept;
    void Reserve(size_t new_capacity);
    void Resize(size_t new_size);

    template <typename... Args>
    T& EmplaceBack(Args&&... args);
    T& PushBack(const T &value);
    T& PushBack(T &&value);
    void PopBack() noexcept;
};

template<typename T>
typename Myvector<T>::iterator Myvector<T>::begin() noexcept {
    return _data;
}

template<typename T>
typename Myvector<T>::iterator Myvector<T>::end() noexcept {
    return _data + _size;
}

template<typename T>
typename Myvector<T>::const_iterator Myvector<T>::begin() const noexcept {
    return _data;
}

template<typename T>
typename Myvector<T>::const_iterator Myvector<T>::end() const noexcept {
    return _data + _size;
}

template<typename T>
typename Myvector<T>::const_iterator Myvector<T>::cbegin() const noexcept {
    return _data;
}

template<typename T>
typename Myvector<T>::const_iterator Myvector<T>::cend() const noexcept {
    return _data + _size;
}

template<typename T>
Myvector<T>::Myvector() noexcept : _data(nullptr), _size(0), _capacity(0) {}

template<typename T>
void Myvector<T>::Reserve(size_t new_capacity) {
    if (new_capacity > _capacity) {
        T* new_data = new T[new_capacity];
        std::uninitialized_copy(_data, _data + _size, new_data);
        for (size_t i = 0; i < _size; ++i) {
            (_data + i)->~T();
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }
}

template<typename T>
void Myvector<T>::Resize(size_t new_size) {
    if (new_size > _size) {
        if (new_size > _capacity) { Reserve(new_size); }
        std::uninitialized_fill(_data + _size, _data + new_size, T{});
        _size = new_size;
    } else if (new_size < _size) {
        for (size_t i = new_size; i < _size; ++i) {
            (_data + i)->~T();
        }
        _size = new_size;
    }
}

template<typename T>
size_t Myvector<T>::Size() const noexcept {
    return _size;
}

template<typename T>
size_t Myvector<T>::Capacity() const noexcept {
    return _capacity;
}

template<typename T>
template<typename... Args>
T& Myvector<T>::EmplaceBack(Args&&... args) {
    if (_size == _capacity) {Reserve(_capacity == 0 ? 1 : _capacity * 2);}
    new (_data + _size) T(std::forward<Args>(args)...);
    return _data[_size++];
}

template<typename T>
T& Myvector<T>::PushBack(const T& value) {
    if (_size == _capacity) {Reserve(_capacity == 0 ? 1 : _capacity * 2);}
    _data[_size] = value;
    return _data[_size++];
}

template<typename T>
T& Myvector<T>::PushBack(T&& value) {
    if (_size == _capacity) {Reserve(_capacity == 0 ? 1 : _capacity * 2);}
    _data[_size] = std::move(value);
    return _data[_size++];
}

template<typename T>
void Myvector<T>::PopBack() noexcept {
    if (_size > 0) {
        --_size;
        (_data + _size)->~T();
    }
}
/*
    Works with stdexcept, utility libraries
    Custom dynamic array with default constructor (capacity=10), constructor with capacity parameter, destructor;
        `size() const`, `capacity() const` methods;
        `operator[]` (const and non-const versions);
        `push_back()` with automatic widening;
        copy constructor, assignment operator, output operator `<<`;
*/

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class SimpleVector {
public:
    SimpleVector()
        : _size(0), _capacity(10), _data(new T[_capacity]) {}

    explicit SimpleVector(std::size_t capacity)
        : _size(0), _capacity(capacity ? capacity : 1), _data(new T[_capacity]) {}

    SimpleVector(const SimpleVector& other)
        : _size(other._size), _capacity(other._capacity), _data(new T[_capacity]) {
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    SimpleVector& operator=(const SimpleVector& other) {
        if (this == &other) return *this;
        SimpleVector tmp(other);
        swap(tmp);
        return *this;
    }

    ~SimpleVector() {
        delete[] _data;
    }

    std::size_t size() const { return _size; }
    std::size_t capacity() const { return _capacity; }

    T& operator[](std::size_t index) {
        if (index >= _size) throw std::out_of_range("index out of range");
        return _data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= _size) throw std::out_of_range("index out of range");
        return _data[index];
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            reserve(_capacity * 2);
        }
        _data[_size++] = value;
    }

    void swap(SimpleVector& other) noexcept {
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
        std::swap(_data, other._data);
    }

private:
    std::size_t _size;
    std::size_t _capacity;
    T* _data;

    void reserve(std::size_t newCapacity) {
        if (newCapacity <= _capacity) return;
        T* newData = new T[newCapacity];
        for (std::size_t i = 0; i < _size; ++i)
            newData[i] = _data[i];
        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SimpleVector<T>& v) {
    os << "[";
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i > 0) os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

int main() {
    SimpleVector<int> v;
    for (int i = 0; i < 15; ++i)
        v.push_back(i * 2);

    std::cout << "v = " << v << "\n";
    std::cout << "size = " << v.size() << ", capacity = " << v.capacity() << "\n";

    SimpleVector<int> v2(3);
    v2.push_back(42);
    v2.push_back(7);
    std::cout << "v2 = " << v2 << "\n";

    SimpleVector<int> v3 = v;

    v2 = v;
    std::cout << "v2(after =) = " << v2 << "\n";
    /*
    ---output---
    v = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28]
    size = 15, capacity = 20
    v2 = [42, 7]
    v2(after =) = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28]
    */
    return 0;
}

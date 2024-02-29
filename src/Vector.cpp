#include "Vector.hpp"

template<typename T>
Vector<T>::Vector() {
    _objects = nullptr;
    _size = 0;
    _capacity = 0;
}

template<typename T>
Vector<T>::Vector(const Vector& vec) {

    _objects = new T[vec._capacity];
    for (int i = 0; i < vec._size; i++) {
        _objects[i] = vec._objects[i];
    }
    
    _size = vec._size;
    _capacity = vec._capacity;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] _objects;
}

template<typename T>
void Vector<T>::reserve(int newCapacity) {
    if (newCapacity < _size)
        return;
    
    T *newArray = new T[newCapacity];

    for (int i = 0; i < _size; i++) {
        newArray[i] = std::move(_objects[i]);
    }
    std::swap(_objects, newArray);

    delete [] newArray;
    _capacity = newCapacity;
}

template<typename T>
void Vector<T>::push_back(const T& object) {
    if (_size == _capacity)
        reserve(2 * _capacity);

    _objects[_size++] = object;
}


template<typename T>
int Vector<T>::size() const {
    return _size;
}

template<typename T>
int Vector<T>::capacity() const {
    return _capacity;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec) {
    os << "[";
    for (int i = 0; i < vec._size; ++i) {
        if (i > 0) os << ", ";
        os << vec._objects[i];
    }
    os << "]";
    return os;
}
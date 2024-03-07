#include "Vector.hpp"

template<typename T>
Vector<T>::Vector() {
    _objects = nullptr;
    _size = 0;
    _capacity = 0;
}

template<typename T>
Vector<T>::Vector(const Vector& vec) {
    copy(vec);
}

template<typename T>
Vector<T>::~Vector() {
    delete[] _objects;
}

/* Privates functions */

template <typename T>
void Vector<T>::updateObjects(size_t newCapacity)
{
    T *newArray = new T[newCapacity];

    for (size_t i = 0; i < _size; i++)
        newArray[i] = _objects[i];

    std::swap(_objects, newArray);
    _capacity = newCapacity;

    delete [] newArray;
}

template <typename T>
void Vector<T>::copy(const Vector<T> &vec)
{
    _objects = new T[vec._capacity];

    for (int i = 0; i < vec._size; i++)
    {
        _objects[i] = vec._objects[i];
    }

    _size = vec._size;
    _capacity = vec._capacity;
}

/* Public functions */

template<typename T>
void Vector<T>::push_back(const T& object) {
    if (_size == _capacity)
        reserve(std::pow(_capacity, 2));

    _objects[_size++] = object;
}


template<typename T>
T& Vector<T>::at(const size_t pos) {
    if (pos < 0 || pos >= _size )
        throw std::out_of_range("Index out of bounds");

    return _objects[pos];
}


template<typename T>
void Vector<T>::resize(const size_t count, const T& value) {
    if (count == _size)
        return;
    if (count < _size) {
        _size = count;
        _capacity = count;
    } else {
        reserve(count);
        for (size_t i = _size; i < count; ++i) {
            _objects[i] = value;
        }
        _size = count;
    }
}

template<typename T>
int Vector<T>::size() const {
    return _size;
}

template<typename T>
void Vector<T>::reserve(const size_t newCapacity) {
    if (newCapacity < _size)
        return;
    updateObjects(newCapacity == 0 ? 2 : newCapacity);
}

template<typename T>
int Vector<T>::capacity() const {
    return _capacity;
}

/* Override operators*/

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec) {
    os << "[";
    for (int i = 0; i < vec._size; ++i) {
        if (i > 0) os << ", ";
        os << vec._objects[i];
    }
    os << "]\n";
    os << "SIZE: " << vec._size << "\n";
    os << "CAPACITY: " << vec._capacity;
    return os;
}

template<typename T>
T& Vector<T>::operator[](const size_t index) {
    return this->at(index);
}

template<typename T>
void Vector<T>::operator=(const Vector<T>& vec) {
    copy(vec);
}

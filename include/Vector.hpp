#pragma once

#include <utility>
#include <iostream>
#include <ostream>
#include <cmath>


template<typename T>
class Vector {
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

private:
    T* _objects;
    int _size;
    int _capacity;
    /*Set _objects as a new array with the given newCapacity*/
    void updateObjects(size_t newCapacity);
    void copy(const Vector<T>& vec);

public:
    Vector();
    Vector(const Vector&);
    ~Vector();

    void push_back(const T&);
    T& at(const size_t);

    void resize(const size_t count, const T& value = T());
    int size() const;

    void reserve(const size_t newCapacity);
    int capacity() const;

    T& operator[](const size_t index);
    void operator=(const Vector<T> &vec);
};
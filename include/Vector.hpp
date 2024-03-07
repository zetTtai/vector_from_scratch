#pragma once

#include <utility>
#include <iostream>
#include <ostream>
#include <cmath>


template<typename T>
class Vector {
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);
    template<typename U>
    friend bool operator==(const Vector<U> &left_vector, const Vector<U> &right_vector);
    template<typename U>
    friend bool operator!=(const Vector<U> &left_vector, const Vector<U> &right_vector);

private:
    T* _objects;
    int _size;
    int _capacity;
    /*Set _objects as a new array with the given newCapacity*/
    void updateObjects(size_t newCapacity);
    void copy(const Vector<T>& vec);
    T &getObject(const size_t index) const;

public:
    Vector();
    Vector(const Vector&);
    ~Vector();

    void push_back(const T&);
    T& at(const size_t);
    T &at(const size_t) const;

    void resize(const size_t count, const T &value = T());
    int size() const;

    void reserve(const size_t newCapacity);
    int capacity() const;

    T& operator[](const size_t index);
    T& operator[](const size_t index) const;
    void operator=(const Vector<T> &vec);
};
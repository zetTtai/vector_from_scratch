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
    /* Create a new array with the given capacity*/
    void updateObjects(size_t newCapacity);

public:
    Vector();
    Vector(const Vector&);
    ~Vector();

    void push_back(const T&);
    T& at(const size_t);

    // void resize(int count);
    void resize(size_t count, const T& value = T());
    int size() const;

    void reserve(size_t newCapacity);
    int capacity() const;
};
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

public:
    Vector();
    Vector(const Vector&);
    ~Vector();

    void push_back(const T&);
    T& at(const int);

    void resize(int count);
    void resize(int count, const T& value);
    int size() const;
    
    void reserve(int newCapacity);
    int capacity() const;

};
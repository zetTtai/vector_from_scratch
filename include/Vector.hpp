#pragma once

#include <utility>
#include <iostream>
#include <ostream>


template<typename T>
class Vector {
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

private:
    T* _objects;
    int _size;
    int _capacity;

    void reserve(int newCapacity);

public:
    Vector();
    Vector(const Vector&);
    ~Vector();

    void push_back(const T&);

    int size() const;
    int capacity() const;

};
#include <iostream>
#include "Vector.cpp"

int main() {
    std::cout << "Hello world" << std::endl;
    Vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(7);

    Vector<int> v2(v1);

    std::cout << v1 << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << v2 << std::endl;

    return 0;
}
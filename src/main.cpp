#include <iostream>
#include "Vector.cpp"

int main() {
    Vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(7);

    Vector<int> v2(v1);

    std::cout << v1 << std::endl;
    std::cout << v1.at(1) << std::endl;
    try {
        std::cout << v1.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Expected Error: " << e.what() << std::endl;
    }


    std::cout << "----------" << std::endl;

    v2.at(1) = 3;

    std::cout << v2 << std::endl;

    v2.resize(1);

    std::cout << v2 << std::endl;

    v2.resize(3);

    std::cout << v2 << std::endl;

    v2.resize(5, 3);

    std::cout << v2 << std::endl;

    return 0;
}
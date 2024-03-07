#include <iostream>
#include "Vector.cpp"
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


class Printer {
    private:
        int _cont = 0;
    public:

        void header(std::string msg) {
            int width = 20;
            std::cout << std::setfill('-') << std::setw(width) << "" << std::endl;
            std::cout << GREEN << msg << RESET << std::endl;
            std::cout << std::setfill('-') << std::setw(width) << "" << std::endl;
            std::cout << std::endl;

        }
        void testTitle(std::string msg) {
            int width = 70;
            std::cout << std::endl;
            std::cout << BLUE << ">> Test_" << ++_cont << ": " << msg << RESET << std::endl;
            std::cout << BLUE << std::setfill('-') << std::setw(width) << "" << RESET << std::endl;
        }
};

int main() {
    Printer print;

    print.header("Initial state");

    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(7);

    Vector<int> v3;
    v3.push_back(20);

    Vector<int> v2(v1);

    std::cout << "V1: " << v1 << std::endl;
    std::cout << "V2: " << v2 << std::endl;
    std::cout << "V3: " << v3 << std::endl;

    print.testTitle("v1.at(1) Happy path");

    std::cout << v1.at(1) << std::endl;

    print.testTitle("v1.at(5) out of range");

    try {
        std::cout << v1.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Expected Error: " << e.what() << std::endl;
    }

    print.testTitle("v2.at(1) = 3 modify vector");

    v2.at(1) = 3;

    std::cout <<  "V2: " << v2 << std::endl;

    print.testTitle("v2.resize(1)");

    v2.resize(1);

    std::cout <<  "V2: " << v2 << std::endl;

    print.testTitle("v2.resize(3)");

    v2.resize(3);

    std::cout <<  "V2: " << v2 << std::endl;

    print.testTitle("v2.resize(5, 3)");

    v2.resize(5, 3);

    std::cout <<  "V2: " << v2 << std::endl;

    print.testTitle("v3 = v1");

    v3 = v1;

    std::cout <<  "V1: " << v1 << std::endl;
    std::cout <<  "V3: " << v3 << std::endl;

    print.testTitle("v3[0] = 100");

    v3[0] = 100;
    std::cout <<  "V3: " << v3 << std::endl;



    return 0;
}
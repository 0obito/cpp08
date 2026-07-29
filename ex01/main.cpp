#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void printTitle(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  "<< title << "  \n";
    std::cout << "========================================\n";
}

int main() {
    std::srand(std::time(NULL));

    printTitle("test 1: Subject page tests");
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan() << "\n";

    printTitle("test 2: Empty container");
    try {
        Span emptySpan(5);
        std::cout << "Trying shortestSpan on an empty container...\n";
        emptySpan.shortestSpan();
    }
    catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << "\n";
    }

    printTitle("test 3: One number container");
    try {
        Span oneSpan(5);
        oneSpan.addNumber(42);
        std::cout << "Trying longestSpan on a 1 element container...\n";
        oneSpan.longestSpan();
    }
    catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << "\n";
    }

    printTitle("test 4: Capacity testing");
    try {
        Span twoSpan(2);
        twoSpan.addNumber(1);
        twoSpan.addNumber(2);
        std::cout << "Trying to add a 3rd number, where capacity = 2...\n";
        twoSpan.addNumber(3);
    }
    catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << "\n";
    }

    printTitle("test 5: Container with duplicate number");
    try {
        Span dupSpan(6);
        dupSpan.addNumber(-100);
        dupSpan.addNumber(-50);
        dupSpan.addNumber(0);
        dupSpan.addNumber(50);
        dupSpan.addNumber(100);
        dupSpan.addNumber(-50);
        std::cout << "Shortest: " << dupSpan.shortestSpan() << "\n";
        std::cout << "Longest: " << dupSpan.longestSpan() << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "FAIL: " << e.what() << "\n";
    }

    printTitle("test 6: Range of numbers testing");
    try {
        Span rangeSpan(10);

        int intArr[] = {10, 13, 20, 30, 42};
        rangeSpan.addRangeOfNumbers(intArr, intArr + 5);
        std::cout << "Successfully added from a C array\n";

        std::vector<int> intVec;
        intVec.push_back(50);
        intVec.push_back(60);
        intVec.push_back(66);
        rangeSpan.addRangeOfNumbers(intVec.begin(), intVec.end());
        std::cout << "Successfully added from std::vector\n";

        std::cout << "Shortest: " << rangeSpan.shortestSpan() << "\n";
        std::cout << "Longest: " << rangeSpan.longestSpan() << "\n";

        std::cout << "Trying to insert 10 more numbers, and there's no enough space...\n";
        std::vector<int> bigVec(10, 99);
        rangeSpan.addRangeOfNumbers(bigVec.begin(), bigVec.end());
    }
    catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << "\n";
    }

    printTitle("test 7: 100 000 random numbers");
    try {
        Span hugeSpan(100000);

        std::vector<int> hugeVec;
        hugeVec.reserve(100000);
        for (int i = 0; i < 100000; ++i) {
            hugeVec.push_back(std::rand() % 1000000);
        }

        std::cout << "Loading 100 000 numbers into our container...\n";
        hugeSpan.addRangeOfNumbers(hugeVec.begin(), hugeVec.end());

        std::cout << "Shortest Span: " << hugeSpan.shortestSpan() << "\n";
        std::cout << "Longest Span:  " << hugeSpan.longestSpan() << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "FAIL: " << e.what() << "\n";
    }

    std::cout << "\n========================================\n";
    std::cout << "        all tests are done\n";
    std::cout << "========================================\n";

    return 0;
}

// #include "Span.hpp"
// #include <iostream>
// #include <stdexcept>
// #include <climits>

// int main()
// {
//     try {
//         Span sp = Span(10);
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(-1117);
//         sp.addNumber(0);
//         sp.addNumber(INT_MIN);
//         sp.addNumber(-22222);
//         sp.addNumber(3223232);
//         sp.addNumber(5212);
//         sp.addNumber(981800);
//         sp.addNumber(INT_MAX);
//         sp.printVec(sp.getVec());
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (std::out_of_range& e) {
//         std::cout<<"caught exception: "<<e.what()<<"\n";
//     }
//     return 0;
// }


// int main()
// {
//     std::cout<<"========== Subject page tests: ==========\n\n";
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

//     std::cout<<"\n========== My own tests: ==========\n\n";
//     try {
//         Span sp = Span(10);
//         sp.addNumber(7);
//         sp.addNumber(3);
//         sp.addNumber(3);
//         sp.addNumber(1);
//         sp.addNumber(-42);
//         sp.addNumber(INT_MIN);
//         sp.addNumber(-22222);
//         sp.addNumber(0);
//         sp.addNumber(-6969);
//         sp.addNumber(INT_MAX);
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (std::out_of_range& e) {
//         std::cout<<"caught exception: "<<e.what()<<"\n";
//     }

//     std::cout<<"\n========== End of tests: ==========\n";
//     return 0;
// }


#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// Helper function for terminal dividers
void printTitle(std::string title) {
    std::cout << "\n========================================\n";
    std::cout << " 🔥 " << title << " 🔥\n";
    std::cout << "========================================\n";
}

int main() {
    std::srand(std::time(NULL)); // Seed for randomness

    // ---------------------------------------------------------
    printTitle("TEST 1: The Subject Baseline");
    // ---------------------------------------------------------
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest (Expected 2): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest  (Expected 14): " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "FAIL: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    printTitle("TEST 2: The Void (Exceptions on 0 or 1 elements)");
    // ---------------------------------------------------------
    try {
        Span emptySpan(5);
        std::cout << "Trying shortestSpan on empty container..." << std::endl;
        emptySpan.shortestSpan();
    } catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << std::endl;
    }

    try {
        Span lonelySpan(5);
        lonelySpan.addNumber(42);
        std::cout << "Trying longestSpan on 1-element container..." << std::endl;
        lonelySpan.longestSpan();
    } catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    printTitle("TEST 3: The Overflow (Capacity Limits)");
    // ---------------------------------------------------------
    try {
        Span tinySpan(2);
        tinySpan.addNumber(1);
        tinySpan.addNumber(2);
        std::cout << "Span is full. Trying to force a 3rd number..." << std::endl;
        tinySpan.addNumber(3);
    } catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    printTitle("TEST 4: The Deep Freeze (Negatives & Duplicates)");
    // ---------------------------------------------------------
    // This tests if your subtraction math prevents underflow 
    // and if your early-exit (span == 0) optimization works.
    try {
        Span coldSpan(6);
        coldSpan.addNumber(-100);
        coldSpan.addNumber(-50);
        coldSpan.addNumber(0);
        coldSpan.addNumber(50);
        coldSpan.addNumber(100);
        coldSpan.addNumber(-50); // Duplicate! Shortest span MUST be 0.

        std::cout << "Shortest (Expected 0 due to duplicate -50): " << coldSpan.shortestSpan() << std::endl;
        std::cout << "Longest  (Expected 200 [-100 to 100]): " << coldSpan.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "FAIL: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    printTitle("TEST 5: The Iterator Invasion (Raw C-Arrays & Vectors)");
    // ---------------------------------------------------------
    try {
        Span rangeSpan(10);

        // 1. Adding from a raw C-array (proving 'typename' handles raw pointers)
        int rawArray[] = {10, 20, 30};
        rangeSpan.addRangeOfNumbers(rawArray, rawArray + 3);
        std::cout << "Successfully added from raw C-Array." << std::endl;

        // 2. Adding from a std::vector
        std::vector<int> srcVec;
        srcVec.push_back(40);
        srcVec.push_back(50);
        rangeSpan.addRangeOfNumbers(srcVec.begin(), srcVec.end());
        std::cout << "Successfully added from std::vector." << std::endl;

        std::cout << "Shortest (Expected 10): " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "Longest  (Expected 40): " << rangeSpan.longestSpan() << std::endl;

        // 3. Testing range capacity overflow
        std::cout << "Trying to insert 10 more numbers into a Span with only 5 slots left..." << std::endl;
        std::vector<int> bigVec(10, 99); // Vector of ten 99s
        rangeSpan.addRangeOfNumbers(bigVec.begin(), bigVec.end());

    } catch (std::exception& e) {
        std::cout << "Caught Expected Exception: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    printTitle("TEST 6: The 100,000 Random Payload (Volume Stress Test)");
    // ---------------------------------------------------------
    try {
        Span massiveSpan(100000);
        std::vector<int> ammoBox;
        ammoBox.reserve(100000); // Pre-allocate to make generation faster

        for (int i = 0; i < 100000; ++i) {
            // Generate numbers between 0 and 1,000,000
            ammoBox.push_back(std::rand() % 1000000);
        }

        std::cout << "Loading 100,000 numbers into Span using range iterators..." << std::endl;
        massiveSpan.addRangeOfNumbers(ammoBox.begin(), ammoBox.end());
        
        std::cout << "Calculating spans..." << std::endl;
        // Because of the volume and randomness, shortest is almost guaranteed to be 0 or 1
        std::cout << "Shortest Span: " << massiveSpan.shortestSpan() << std::endl; 
        std::cout << "Longest Span:  " << massiveSpan.longestSpan() << std::endl;
        std::cout << "Volume test SURVIVED." << std::endl;

    } catch (std::exception& e) {
        std::cerr << "FAIL: " << e.what() << std::endl;
    }

    std::cout << "\n========================================\n";
    std::cout << " 🎉 ALL TESTS COMPLETE 🎉\n";
    std::cout << "========================================\n";

    return 0;
}

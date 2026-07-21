#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>

int main() {
    std::vector<int> vec;
    vec.reserve(5);
    vec.push_back(0);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);

    std::cout<<"========== Test 1: int vector (element doesn't exist) ==========\n\n";
    try {
        easyfind(vec, 1);
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }

    std::cout<<"\n========== Test 2: int vector (element exists) ==========\n\n";
    try {
        easyfind(vec, 4);
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }

    std::list<int> l;
    l.push_back(2);
    l.push_back(1);
    l.push_back(4);
    l.push_back(3);
    l.push_back(6);
    l.push_back(5);

    std::cout<<"\n========== Test 3: int list (element exists) ==========\n\n";
    try {
        easyfind(l, 5);
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }

    std::cout<<"\n========== Test 4: int list (element doesn't exist) ==========\n\n";
    try {
        easyfind(l, 9);
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }
    std::cout<<"\n========== End of tests ==========\n";
}

#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec;
    vec.reserve(5);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);

    std::cout<<"========== Test 1: int vector (element doesn't exist) ==========\n\n";
    try {
        std::vector<int>::iterator it;
        it = easyfind(vec, 1);
        std::cout<<"the value: "<<*it<<" was found at index: "<<vec.begin() - it<<"\n";
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }

    std::cout<<"\n========== Test 2: int vector (element exists) ==========\n\n";
    try {
        std::vector<int>::iterator it;
        it = easyfind(vec, 6);
        std::cout<<"the value: "<<*it<<" was found at index: "<<it - vec.begin()<<"\n";
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }

    std::cout<<"\n========== Test 3: int  (element exists) ==========\n\n";
    try {
        std::vector<int>::iterator it;
        it = easyfind(vec, 6);
        std::cout<<"the value: "<<*it<<" was found at index: "<<it - vec.begin()<<"\n";
    }
    catch (std::out_of_range& e) {
        std::cout<<"Caught Exception: "<<e.what()<<"\n";
    }

    std::cout<<"\n========== End of tests ==========\n";
}

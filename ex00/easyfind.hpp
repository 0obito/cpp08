#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
void easyfind(T& t, int i) {
    typename T::iterator it;
    it = std::find(t.begin(), t.end(), i);
    if (it == t.end())
        throw std::out_of_range("element was not found in the container.");
    std::cout<<"value: "<<*it<<" was found at index: "<<std::distance(t.begin(), it)<<"\n";
}

#endif /*EASYFIND_HPP*/

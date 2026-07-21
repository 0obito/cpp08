#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
// #include <iterator>
#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>
void easyfind(T t, int i) {
    T::iterator it;
    it = std::find(T.begin(), T.end(), i);
    if (it == T.end())
        return 
    if (it == T.end())
        throw std::out_of_range();
    std::cout<<*it<<"\n";
}

#endif /*EASYFIND_HPP*/

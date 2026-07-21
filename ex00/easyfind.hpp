#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& t, int i) {
    typename T::iterator it;
    it = std::find(t.begin(), t.end(), i);
    if (it == t.end())
        throw std::out_of_range("element was not found in the container.");
    return it;
}

#endif /*EASYFIND_HPP*/

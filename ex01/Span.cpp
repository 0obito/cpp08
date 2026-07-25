#include "Span.hpp"
#include <iostream>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {
    _intVec.reserve(N);
}

Span::Span(const Span& other) : _N(other._N), _intVec(other._intVec) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _intVec = other._intVec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_N == 0 || _intVec.size() == _N)
        throw std::out_of_range("No enough space to add number.");
    _intVec.push_back(num);
}

// maybe use long instead of unsigned int?
unsigned int Span::shortestSpan() {
    std::vector<int> copyVec = _intVec;

    if (_intVec.size() < 2)
        throw std::out_of_range("Not enough members to calculate the shortest span.");

    std::sort(copyVec.begin(), copyVec.end());
    unsigned int shortest = *(copyVec.begin() + 1) - *(copyVec.begin());
    for (std::vector<int>::iterator it = copyVec.begin(); it < copyVec.end() - 1; it++) {
        if (shortest == 0) {
            return shortest;
        }
        if (static_cast<unsigned int>(*(it + 1) - *it) < shortest)
            shortest = static_cast<unsigned int>(*(it + 1) - *it);
    }

    return shortest;
}

unsigned int Span::longestSpan() {
    if (_intVec.size() < 2)
        throw std::out_of_range("Not enough members to calculate the longest span.");

    int minVal = *(std::min_element(_intVec.begin(), _intVec.end()));
    int maxVal = *(std::max_element(_intVec.begin(), _intVec.end()));

    return (maxVal - minVal);
}

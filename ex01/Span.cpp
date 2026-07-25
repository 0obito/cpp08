#include "Span.hpp"
#include <iostream>

Span::Span() : _size(0), _filled(0) {}

Span::Span(unsigned int N) : _size(N), _filled(0) {
    _intVect.reserve(N);
}

Span::Span(const Span& other) : _size(other._size), _filled(other._filled), _intVect(other._intVect) {
    _intVect.reserve(_size);
    for (unsigned int i = 0; i < _filled; i++) {
        _intVect[i] = other._intVect[i];
    }
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _size = other._size;
        _filled = other._filled;
        _intVect = other._intVect;
    }
    return *this;
}

Span::~Span() {
    // nothing to delete, since the container manages itself.
    // delete[] _intVect;
}

void Span::addNumber(int num) {
    if (_size == 0 || _filled == _size) {
        throw std::out_of_range("No enough space to add number.");
    }
    _intVect[_filled] = num;
    _filled++;
}

// maybe use long instead of unsigned int?
unsigned int Span::shortestSpan() {
    std::vector<int> copyVec = _intVect;

    if (_size < 2)
        throw std::out_of_range("Not enough members to calculate the shortest span.");

    // wait i didnt use the copy!
    // wait i didnt use the copy!
    // wait i didnt use the copy!

    std::sort(copyVec.begin(), copyVec.end());
    std::cout<<"copyVec was sorted\n";
    printVec(copyVec);
    unsigned int shortest = *(copyVec.begin() + 1) - *(copyVec.begin());
    for (std::vector<int>::iterator it = copyVec.begin(); it < copyVec.end() - 1; it++) {
        if (shortest == 0) {
            std::cout<<"''holy optimization!''\n";
            return shortest;
        }
        if (static_cast<unsigned int>(*(it + 1) - *it) < shortest)
            shortest = static_cast<unsigned int>(*(it + 1) - *it);
    }

    return shortest;
}

unsigned int Span::longestSpan() {
    if (_size < 2)
        throw std::out_of_range("Not enough members to calculate the longest span.");

    int minVal = *(std::min_element(_intVect.begin(), _intVect.end()));
    int maxVal = *(std::max_element(_intVect.begin(), _intVect.end()));

    std::cout<<"min value found: "<<minVal<<"\n";
    std::cout<<"max value found: "<<maxVal<<"\n";
    // I'd test later with INTMAX - INTMIN
    return (maxVal - minVal);
}





const std::vector<int> &Span::getVec() const {
    return _intVect;
}

void Span::printVec(const std::vector<int> &vec) {
    size_t vecSize = sizeof(vec) / sizeof(vec[0]);
    for(size_t i = 0; i < vecSize; i++) {
        std::cout<<"[ "<<vec[i]<<" ]";
        if (i + 1 < vecSize)
            std::cout<<", ";
    }
    std::cout<<"\n";
}

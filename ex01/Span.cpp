#include "Span.hpp"

Span::Span() : _size(0), _filled(0) {}

Span::Span(unsigned int N) : _size(N), _filled(0) {
    _intVect.reserve(N);
}

Span::Span(const Span& other) : _size(other._size), _filled(other._filled) {
    _intVect.reserve(_size);
    for (unsigned int i = 0; i < _filled; i++) {
        _intVect[i] = other._intVect[i];
    }
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        Span tmpSpan(other);
        int* tmpHolder = _intVect;
        _intVect = tmpSpan._intVect;
        tmpSpan._intVect = tmpHolder;
        _size = tmpSpan._size;
        _filled = tmpSpan._filled;
    }
    return *this;
}

Span::~Span() {
    delete[] _intVect;
}

void Span::addNumber(int num) {
    if (_intVect == NULL || _filled == _size) {
        throw std::out_of_range("No enough space to add number.");
    }
    _intVect[_filled] = num;
    _filled++;
}

// maybe use long instead of unsigned int?
unsigned int Span::shortestSpan() {
    ;
}

unsigned int Span::longestSpan() {
    ;
}

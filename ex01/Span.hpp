#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span {
    private:
        unsigned int _size;
        unsigned int _filled;
        std::vector<int> _intVect;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int num);
        // maybe use long instead of unsigned int?
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif /*SPAN_HPP*/

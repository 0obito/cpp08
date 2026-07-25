#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _intVec;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int num);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        template <typename Iterator>
        void addRangeOfNumbers(Iterator start, Iterator finish) {
            if (std::distance(start, finish) + _intVec.size() > _N)
                throw std::out_of_range("No enough space to add the range of numbers.");
            _intVec.insert(_intVec.end(), start, finish);
        }
};

#endif /*SPAN_HPP*/

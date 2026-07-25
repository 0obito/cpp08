#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>

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


        const std::vector<int> &getVec() const;
        void printVec(const std::vector<int> &vec);
};

#endif /*SPAN_HPP*/

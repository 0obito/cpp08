#include "Span.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printVec(sp.getVec());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::out_of_range& e) {
        std::cout<<"caught exception: "<<e.what()<<"\n";
    }
    return 0;
}

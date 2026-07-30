#include <iostream>
#include <list>
#include "MutantStack.hpp"

void printTitle(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  " << title << "  \n";
    std::cout << "========================================\n";
}


int main() {

    printTitle("test 1: Subject page tests");

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // ===========================================================================================================

    printTitle("test 2: Subject page tests but this time using std::list");

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator itt = mlist.begin();
    std::list<int>::iterator itte = mlist.end();
    ++itt;
    --itt;
    while (itt != itte)
    {
        std::cout << *itt << std::endl;
        ++itt;
    }
    std::list<int> l(mlist);

    // ===========================================================================================================

    printTitle("test 3: Reverse Iterators");

    MutantStack<int> ms;
    for (int i = 1; i <= 5; ++i)
        ms.push(i * 10);

    std::cout << "Normal iteration:  ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Reverse iteration:  ";
    for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // ===========================================================================================================

    printTitle("test 4: Orthodox Canonical Form");

    MutantStack<int> original;
    original.push(100);
    original.push(200);

    MutantStack<int> copy(original);
    MutantStack<int> assigned;
    assigned = original;

    copy.push(300);
    assigned.pop();

    std::cout << "Original size: " << original.size() << "\n";
    std::cout << "Copy size:     " << copy.size() << "\n";
    std::cout << "Assigned size: " << assigned.size() << "\n";

    // ===========================================================================================================

    printTitle("test 5: String stack testing");

    MutantStack<std::string> strStack;
    strStack.push("AAA");
    strStack.push("BBBBB");
    strStack.push("CCCCC");
    strStack.push("DDDDDDDDDD");

    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "\n========================================\n";
    std::cout << "        all tests are done\n";
    std::cout << "========================================\n";

    return 0;
}

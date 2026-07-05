#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <string>

static void separator(const std::string &title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
    // --- Test 1: the exact example from the subject ---
    // expected: shortestSpan == 2, longestSpan == 14
    separator("subject example");
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortestSpan (expected 2): " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan  (expected 14): " << sp.longestSpan() << std::endl;

    // --- Test 2: shortest gap is NOT between the two smallest values ---
    separator("shortest span is not always between the two smallest values");
    Span sp2 = Span(4);
    sp2.addNumber(1);
    sp2.addNumber(50);
    sp2.addNumber(51);
    sp2.addNumber(100);
    std::cout << "shortestSpan (expected 1): " << sp2.shortestSpan() << std::endl;
    std::cout << "longestSpan  (expected 99): " << sp2.longestSpan() << std::endl;

    // --- Test 3: duplicate values -> shortest span should be 0 ---
    separator("duplicate values");
    Span sp3 = Span(3);
    sp3.addNumber(5);
    sp3.addNumber(5);
    sp3.addNumber(100);
    std::cout << "shortestSpan (expected 0): " << sp3.shortestSpan() << std::endl;

    // --- Test 4: adding past capacity N must throw ---
    separator("capacity exceeded via addNumber");
    Span sp4 = Span(2);
    sp4.addNumber(1);
    sp4.addNumber(2);
    try
    {
        sp4.addNumber(3);
        std::cout << "BUG: no exception thrown!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "correctly threw: " << e.what() << std::endl;
    }

    // --- Test 5: empty Span -> shortest/longestSpan must throw ---
    separator("empty Span");
    Span sp5 = Span(5);
    try { sp5.shortestSpan(); std::cout << "BUG: no exception!" << std::endl; }
    catch (std::exception &e) { std::cout << "correctly threw: " << e.what() << std::endl; }
    try { sp5.longestSpan(); std::cout << "BUG: no exception!" << std::endl; }
    catch (std::exception &e) { std::cout << "correctly threw: " << e.what() << std::endl; }

    // --- Test 6: only one element stored (capacity larger) -> must throw ---
    separator("single element, capacity larger than 1");
    Span sp6 = Span(10); // capacity 10, but we only add ONE number
    sp6.addNumber(42);
    try { sp6.shortestSpan(); std::cout << "BUG: no exception!" << std::endl; }
    catch (std::exception &e) { std::cout << "correctly threw: " << e.what() << std::endl; }

    // --- Test 7: addRange from a std::vector ---
    separator("addRange from std::vector");
    std::vector<int> vals;
    vals.push_back(2);
    vals.push_back(4);
    vals.push_back(6);
    vals.push_back(8);
    Span sp7 = Span(4);
    sp7.addRange(vals.begin(), vals.end());
    std::cout << "shortestSpan (expected 2): " << sp7.shortestSpan() << std::endl;
    std::cout << "longestSpan  (expected 6): " << sp7.longestSpan() << std::endl;

    // --- Test 8: addRange from a std::list ---
    separator("addRange from std::list");
    std::list<int> lvals;
    lvals.push_back(10);
    lvals.push_back(1);
    lvals.push_back(100);
    Span sp8 = Span(3);
    sp8.addRange(lvals.begin(), lvals.end());
    std::cout << "longestSpan (expected 99): " << sp8.longestSpan() << std::endl;

    // --- Test 9: addRange exceeding capacity must throw ---
    separator("addRange exceeding capacity");
    Span sp9 = Span(2);
    try
    {
        sp9.addRange(vals.begin(), vals.end()); // 4 values into capacity 2
        std::cout << "BUG: no exception!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "correctly threw: " << e.what() << std::endl;
    }

    // --- Test 10: 10,000 random numbers, as required by the subject ---
    separator("10,000 random numbers");
    std::srand(static_cast<unsigned int>(std::time(0)));
    Span big(10000);
    std::vector<int> bigVals;
    for (int i = 0; i < 10000; ++i)
        bigVals.push_back(std::rand());
    big.addRange(bigVals.begin(), bigVals.end());
    std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
    std::cout << "longestSpan:  " << big.longestSpan() << std::endl;

    // --- Test 11: copy constructor and operator= actually copy contents ---
    separator("copy constructor / assignment correctness");
    Span original = Span(3);
    original.addNumber(1);
    original.addNumber(2);
    original.addNumber(3);

    Span copyCtor(original);          // copy constructor
    Span assigned = Span(3);          // SAME capacity as `original` on purpose:
    assigned.addNumber(100);          // this exposes the old "_size didn't differ" bug
    assigned = original;              // assignment must still overwrite contents

    std::cout << "copyCtor longestSpan (expected 2): " << copyCtor.longestSpan() << std::endl;
    std::cout << "assigned longestSpan (expected 2): " << assigned.longestSpan() << std::endl;

    return 0;
}
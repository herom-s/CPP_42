#include "easyfind.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

int main()
{
    int              val;

    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i)
        vec.push_back(i * 10);

    std::cout << "--- vector test ---" << std::endl;
    std::cout << "vec: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Test 1: search for a value that exists in the vector
    try
    {
        val = 30;
        std::vector<int>::iterator it = easyfind(vec, val);
        std::cout << "Found value: " << *it << std::endl;
        std::cout << "Position (index): " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: search for a value that does NOT exist -> must throw
    try
    {
        val = 999;
        std::vector<int>::iterator it = easyfind(vec, val);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << " " << val << std::endl;
    }

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    std::cout << "\n--- list test ---" << std::endl;
    std::cout << "list: ";
    std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Test 3: search for a value that exists in a list (non-random-access container,
    try
    {
        val = 200;
        std::list<int>::iterator it = easyfind(lst, val);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << " " << val << std::endl;
    }

    // Test 4: search for a value that does NOT exist in a list -> must throw
    try
    {
        val = 42;
        std::list<int>::iterator it = easyfind(lst, val);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << " " << val << std::endl;
    }

    // Test 5: the returned iterator must be mutable - verify we can write through it
    std::cout << "\n--- mutation test ---" << std::endl;
    std::vector<int>::iterator it = easyfind(vec, 40);
    *it = 4000;
    std::cout << "vec now contains: ";
    for (std::vector<int>::iterator vit = vec.begin(); vit != vec.end(); ++vit)
        std::cout << *vit << " ";
    std::cout << std::endl;

    // Test 6: const overload - easyfind on a const container must return a
    std::cout << "\n--- const container test ---" << std::endl;
    const std::vector<int> cvec(vec);
    std::cout << "const vec: ";
    std::copy(cvec.begin(), cvec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    try
    {
        val = 4000;
        std::vector<int>::const_iterator cit = easyfind(cvec, val);
        std::cout << "Found value in const vector: " << *cit << std::endl;
        // *cit = 1; // error const_iterator is read-only
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << " " << val << std::endl;
    }

    return 0;
}
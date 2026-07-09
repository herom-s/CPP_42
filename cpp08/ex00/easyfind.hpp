#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
    typename T::iterator founded = std::find(haystack.begin(), haystack.end(), needle);

    if (founded != haystack.end())
        return (founded);
    else
        throw std::runtime_error("Value not found");
}

template<typename T>
typename T::const_iterator easyfind(const T &haystack, int needle)
{
    typename T::const_iterator founded = std::find(haystack.begin(), haystack.end(), needle);

    if (founded != haystack.end())
        return (founded);
    else
        throw std::runtime_error("Value not found");
}
#endif
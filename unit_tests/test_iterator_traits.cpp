#include <iostream>
#include <cassert>
#include <iterator>
#include <typeinfo>
#include <vector>
#include <list>
#include "ft_iterator.hpp"

static void test1()
{
    typedef std::iterator_traits<int*> traits;
    std::string std_str;
    if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
        std_str = "int* is a random-access iterator";

    typedef ft::iterator_traits<int*> ft_traits;
    std::string ft_str;
    if (typeid(ft_traits::iterator_category) == typeid(ft::random_access_iterator_tag))
        ft_str = "int* is a random-access iterator";
    
    assert(std_str==ft_str);
}

void test_iterator_traits()
{
    test1();
}
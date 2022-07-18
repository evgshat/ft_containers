#include "ft_containers.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <cassert>

template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
is_odd_stl(T i) {return bool(i%2);}

template < class T,
		class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even_stl(T i) {return !bool(i%2);}

template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
is_odd_ft(T i) {return bool(i%2);}

template < class T,
		class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_even_ft(T i) {return !bool(i%2);}

void test_enable_if()
{
	int num = 1;
	assert(is_odd_stl(num) == is_odd_ft(num));
	assert(is_even_stl(num) == is_even_ft(num));
}

void test_iterator_traits()
{
	typedef ft::iterator_traits<int*> traits;

	if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator";
}

void test1()
{
	// int a;
	std::deque<int> d(1);
	d.push_back(44);
	std::cout<< d[1] <<std::endl;

	ft_stack<int> st;
	st.ft_push(222);
	std::cout<< st.ft_top() <<std::endl;
}

int main()
{
	test1();
	test_iterator_traits();
	test_enable_if();
	return 0;
}

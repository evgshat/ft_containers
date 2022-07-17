#include "ft_containers.hpp"
#include <iostream>
#include <vector>
#include <deque>

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
	return 0;
}

#include "ft_stack.hpp"
#include <iostream>
#include <vector>
#include <deque>

void test0()
{
	std::cout<< "aaa" <<std::endl;
}

void test1()
{
	// int a;
	std::deque<int> d(1);
	d.push_back(44);
	std::cout<< d[1] <<std::endl;

	ft_stack<int> st;
	st.push(222);
	std::cout<< st.top() <<std::endl;
}

int main()
{
	// std::cout<< "ft_stack.val" <<std::endl;
	test1();
	// test0();
}

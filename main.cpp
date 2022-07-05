#include "ft_containers.hpp"
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
	st.ft_push(222);
	std::cout<< st.ft_top() <<std::endl;
}

int main()
{
	// test for stack
}

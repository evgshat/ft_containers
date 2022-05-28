#include "ft_stack.hpp"
#include <iostream>
#include <vector>

void test1()
{
	int value = 42;
	std::vector<float> cont(value);
	ft_stack<int, std::vector<int> > my_stack(value);
	std::cout<< my_stack.val <<std::endl;
}

int main()
{
	// std::cout<< "ft_stack.val" <<std::endl;
	test1();
}

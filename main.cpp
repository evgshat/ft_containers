#include "ft_vector.hpp"

void test1()
{
	int a;
	std::cout << a << "\n";
	ft_vector<int> my_arr; // по умолчанию
}

void test2()
{
	int arr[3] = {1, 2, 3};
	ft_vector<int> my_arr(arr);
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << this->arr << "\n";
		arr++;
	}

}

int main()
{
	test2();
}

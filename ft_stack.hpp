// Знаменитый контейнер, который реализуется минут за 10.
// Единственное приватное поле - это _container
// (vector, deque и т.д.).
// Каждый из методов стэка дергает методы _container.
// Метод push использует _container.push_back,
// top использует _container.back и т.д.

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include <vector>
#include <stack>

template <class _T, class _Container>
class ft_stack : public std::vector<int>
{
	public:
		_T val;
	public:
		// ft_stack(_T type, _Container& container): val(type) {};
		ft_stack(_T type): val(type) {};
};

#endif

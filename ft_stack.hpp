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
#include <deque>

template <class _T, class _Container = std::deque<_T> >
class ft_stack
{
	public:
		typedef _T			value_type;
		typedef _Container	container_type;
	protected:
		container_type c;
	public:
		ft_stack() {}
		void push(const value_type& other) { c.push_back(other); }
		bool empty() const { c.empty(); }
		value_type top() {return c.back();} // обязательна ссылка в возвращаемом значении?
		// ft_stack(const ft_stack &other) : c(other.c) {}
		size



};

#endif

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

// надо ли везде добавлять ft?
template <class _T, class _Container = std::deque<_T> >
class ft_stack
{
	public:
		typedef _T			value_type;
		typedef _Container	container_type;
		typedef size		size_type;
		// нужны ли reference и const_reference?
	protected:
		container_type c;
	public:
		// что такое explicit?
		explicit ft_stack(const container_type& ct = container_type()): c(ct) {}
		bool ft_empty() const
		{
			return c.empty();
		}
		size_type ft_size() const
		{
			return c.size();
		}
		value_type& ft_top() const
		{
			return c.back();
		}
		// почему два метода?
		const value_type& ft_top() const
		{
			return c.back();
		}
		void ft_push(const value_type& el)
		{
			return c.push_back(el);
		}
		void ft_pop ()
		{
			return c.pop_back();
		}

		template <class _T1, class _Container1>
		// что такое friend?
		friend bool operator== (const stack<_T1, _Container1>& st1, const stack<_T1, _Container1>& st2);

		template <class _T1, class _Container1>
		friend bool operator< (const stack<_T1, _Container1>& st1, const stack<_T1, _Container1>& st2);
};

// почему внутри класса писали те же шаблонные ф-ии? потому что там friend - зачем он?
// точно ли надо ставить "_" перед T1 и Container? Для чего это вообще?
// что значат шаблонные ф-ии внутри класса и вне? - вне - чтобы вне класса использовать...
// разве ф-ии не должны быть константными?

template <class _T1, class _Container1>
bool operator== (const ft_stack<_T1, _Container1>& st1, const ft_stack<_T1, _Container1>& st2)
{
	return st1 == st2; // (.c) -- ? у меня неправильный вариант
}

template <class _T1, class _Container1>
bool operator!= (const ft_stack<_T1, _Container1>& st1, const ft_stack<_T1, _Container1>& st2)
{
	return !(st1 == st2);
}

template <class _T1, class _Container1>
bool operator< (const ft_stack<_T1, _Container1>& st1, const ft_stack<_T1, _Container1>& st2)
{
	return st1 < st2; // (.c) -- ? у меня неправильный вариант
}

template <class _T1, class _Container1>
bool operator<= (const ft_stack<_T1, _Container1>& st1, const ft_stack<_T1, _Container1>& st2)
{
	return st1 < st2; // перепроверить
}

template <class _T1, class _Container1>
bool operator> (const ft_stack<_T1, _Container1>& st1, const ft_stack<_T1, _Container1>& st2)
{
	return st1 > st2; // перепроверить
}

template <class _T1, class _Container1>
bool operator>= (const ft_stack<_T1, _Container1>& st1, const ft_stack<_T1, _Container1>& st2)
{
	return st1 > st2; // перепроверить
}

#endif

//деструктор?

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <vector>

template <typename T>
class ft_vector
{
	public:
		T	*arr; // массив значений
		size_t	size; // размер массива
		size_t	cap; // кол-во выделенной памяти
	public:
		ft_vector(): arr(NULL), size(0), cap(0){}; // конструктор по умолчанию
		ft_vector(T *Arr)
		{
			this->arr = new T(Arr.size());
			for (int i = 0; i < Arr.size(); ++i)
				this->arr[i] = Arr[i];
		}
		// ~ft_vector(); // деструктор
};

#endif

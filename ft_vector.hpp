#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>

// залезть в std::allocator
template <class T, class Allocator = std::allocator<T> >
class ft_vector
{
	public:
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type; // могу использовать int?
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef typename Allocator::pointer			pointer; // или правильнее написать allocator_type::pointer pointer? есть ли разница?
		typedef typename Allocator::const_pointer	const_pointer;
		// добавить итераторы

										// constructors
// почему у них нет возвращаемого значения?
		// default constructor
		// что такое explicit
		// pbegin, pend и т.д. - что это?
		explicit ft_vector(const allocator_type& alloc = allocator_type()): pbegin(0), pend(0), pcapacity(0), alloc(alloc) {}
		// range construction
		// fill construction
		explicit ft_vector(size_type n, const value_type& el = value_type(), const allocator_type& alloc = allocator_type());
		// copy construction
		ft_vector (const ft_vector& x);

										// capacity
		size_type ft_size() const;
		size_type ft_max_size() const;
		void ft_resize(size_type n, value_type val = value_type());
		size_type ft_capacity() const;
		bool ft_empty() const;
		void ft_reserve(size_type n);

										// access to elements
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n); // ? const_reference?
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;



		private:
			pointer			pbegin;
			pointer			pend;
			pointer			pcapacity;
			allocator_type	alloc;

		void ft_vallocate(size_type n); // точно надо?
		void ft_construct_at_end(size_type n, const_reference val); // точно надо?
		void ft_vdeallocate(size_type n); // точно надо?

};

									// realisation
									// constructions
// default construction
// range construction
// fill construction
// copy construction
	template <class T, class Allocator>
	ft_vector<T, Allocator>::ft_vector(const ft_vector& v): pbegin(0), pend(0), pcapacity(0), alloc(v.alloc)
	{
		size_type size_v = v.size();
		pointer v_begin = v.pbegin;

		if (size_v > 0)
		{
			this->vallocate(size_v);
			for (size_type i = 0; i < size_v; ++i, ++this->pend, ++v_begin)
				this->alloc.construct(this->pend, *v_begin);
		}
	}


									// capacity
	// ft_size
	// почему не пишем возвращаемое значение? или оно в typename?
	template <class T, class Allocator>
	typename ft_vector<T, Allocator>::size_type
	ft_vector<T, Allocator>::ft_size() const
	{
		// почему static_cast?
		return static_cast<size_type>(this->pend - this->pbegin);
	}
	// ft_max_size
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::size_type
	ft_vector<T, Allocator>::ft_max_size() const
	{
		return std::min<T>(this->alloc.max_size(), std::numeric_limits<difference_type>::max());
	}
	// ft_resize
	template<class T, class Allocator>
	void ft_vector<T, Allocator>::ft_resize(size_type n, value_type val)
	{
		size_t size = this->pend - this->pbegin;
		if (size == n)
			return ;
		if (n > this->ft_capacity())
			this->ft_reserve(n);
		// pointer pend_new;
		// pend_new = this->pbegin + n;
		// this->pend = pend_new;
		for (pointer it = this->pend; it < this->pbegin + n; ++it)
			this->alloc.construct(it, val);
		if (n < static_cast<size_type>(this->pend - this->pbegin))
			for (pointer it = this->pbegin + n; it < this->pend; ++it)
				this->alloc.destroy(it);
			this->pend = this->pbegin + n;
	}
	// ft_capacity
	template <class T, class Allocator>
	typename ft_vector<T, Allocator>::size_type
	ft_vector<T, Allocator>::ft_capacity() const
	{
		return static_cast<size_type>(this->pcapacity - this->pbegin);
	}
	// ft_empty - Test whether vector is empty
	template<class T, class Allocator>
	bool ft_vector<T, Allocator>::ft_empty() const
	{
		return this->pbegin == this->pend;
		// можно ли сделать через проверку начального указателя на налл? или при выделении памяти указатель уже указывает куда-то
	}
	// ft_reserve - Request a change in capacity
	template<class T, class Allocator>
	void ft_vector<T, Allocator>::ft_reserve(size_type n)
	{
		if (n > this->capacity()) // разница между capacity, capacity()
		{
			if (n > this->ft_capacity())
			{
				size_t size = this->pend - this->pbegin;
				pointer new_begin;
				new_begin = this->alloc.allocate(n);
				for (size_t i = 0; i < size; ++i)
					this->alloc.construct(new_begin + i, *(this->pbegin + i));
				this->vdeallocate(this->pcapacity - this->pbegin); // что это значит?
				this->pbegin = new_begin;
				this->pend = this->pegin + size;
				this->pcapacity = this->pbegin + n;
			}
		}
	}

									// access to elements
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::reference
	ft_vector<T, Allocator>::operator[](size_type n)
	{
		if (n > this->size()) // у Дани так: this->pend - this->pbegin
			throw std::out_of_range("vector[] index out of bounds");
		return *(this->pbegin + n);
	}
	//
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::const_reference
	ft_vector<T, Allocator>::operator[](size_type n) const
	{
		if (n > this->size()) // у Дани так: this->pend - this->pbegin
			throw std::out_of_range("vector[] index out of bounds");
		return *(this->pbegin + n);
	}
	// at - ?
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::reference
	ft_vector<T, Allocator>::at(size_type n)
	{
		if (n >= static_cast<size_type>(this->pend - this->pbegin))
			throw std::out_of_range("vector");
		return this->pbeginp[n]; // как работает?
	}
	//
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::reference
	ft_vector<T, Allocator>::front()
	{
		 return *(this->pbegin);
	}
	//
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::const_reference
	ft_vector<T, Allocator>::front() const
	{
		 return *(this->pbegin);
	}
	//
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::reference
	ft_vector<T, Allocator>::back()
	{
		 return *(this->pend - 1);
	}
	//
	template<class T, class Allocator>
	typename ft_vector<T, Allocator>::const_reference
	ft_vector<T, Allocator>::back() const
	{
		 return *(this->pend - 1);
	}
									// allocator
	template<class T, class Allocator>
	void ft_vector<T, Allocator>:: ft_vallocate(size_type n)
	{
		if (2 * n > ft_max_size())
			throw std::length_error("vector");
		this->pbegin = this->pend = this->alloc.allocate(2 * n);
		pcapacity = pbegin + 2 * n;
	}
	//
	template<class T, class Allocator>
	void ft_vector<T, Allocator>::ft_construct_at_end(size_type n, const_reference val)
	{
		do
		{
			this->alloc.construct(this->pend, val);
			--n;
			++this->pend;
		} while (n > 0);
	}
	//
	template<class T, class Allocator>
	void ft_vector<T, Allocator>::ft_vdeallocate(size_type n)
	{
		for (size_type i = 0; i < n; ++i)
			this->alloc.destroy(this->pbegin + i);
		this->alloc.deallocate(this->pegin, n);
	}





#endif

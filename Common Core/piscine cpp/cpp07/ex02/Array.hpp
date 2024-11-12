/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:28 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:25 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <iomanip>

template<typename T>
class Array
{
    public:
        Array() : _array(new T[0]), _n(0) {};
        Array(unsigned int n) : _array(new T[n]), _n(n) {};
        Array(const Array& other) : _array(new T[other.size()]), _n(other.size())
		{
			for (unsigned int i = 0; i < _n; i++)
				_array[i] = other._array[i];
		};
        ~Array() {delete[] _array;};

        Array<T>&	operator=(const Array<T>& other)
		{
			delete[] _array;
			_n = other.size();
			_array = new T[_n];

			for (unsigned int i = 0; i < _n; i++)
				_array[i] = other[i];

			return (*this);
		}
		T&			operator[](unsigned int index)
		{
			if (index >= size())
				throw Array::index_exception();
			return (_array[index]);
		}

        unsigned int    size(void) const
		{
			return(_n);
		}

		class index_exception : public std::exception
		{
			public :
			virtual const char * what() const throw()
			{
				return ("Bad index");
			}
		};

    private:
        T				*_array;
		unsigned int	_n;
};
#endif

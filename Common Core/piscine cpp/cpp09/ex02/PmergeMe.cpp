/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:00 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:39 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    _vector = other._vector;
    return *this;
}

	// +-------------------------------------------------+
	// |                    VECTOR                       |
	// +-------------------------------------------------+

void PmergeMe::vector_init(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
        _vector.push_back(std::atoi(argv[i]));
}

int PmergeMe::vector_is_sort()
{
	for (size_t i = 0; i < _vector_b.size(); i++)
    	if (i > 0 && _vector_b[i] < _vector_b[i - 1])
			return 0;
	return 1;
}

void PmergeMe::vector_sort()
{
	int	max = _vector.size();
	for (int i = 0; i < max - 1; i += 2)
		if (_vector[i] > _vector[i + 1])
			vector_swap(i, i + 1);

	for (int j=0;j<max;j+=2)
	{
		_vector_b.push_back(_vector[j]);
		if (j + 1 < max)
			_vector_a.push_back(_vector[j + 1]);
	}

	for (size_t i=0;i<_vector_b.size();i++)
	{
		for (size_t j=i;j<_vector_b.size();j++)
		{
			if (_vector_b[j] < _vector_b[i])
				vector_swap_b(j, i);
		}
	}
	gen_v_jacobsthal(_vector_a.size());
	for (size_t i = 0; i < _vector_a.size(); i++)
	{
		int n = _vector_a[_v_jacobsthal[i] - 1];
		size_t j;
		for (j = 0; j < _vector_b.size() && _vector_b[j] < n; j++)
			;

		_vector_b.insert(_vector_b.begin() + j, n);
	}
}

void PmergeMe::vector_swap(int a, int b)
{
	int	c = _vector[a];
	_vector[a] = _vector[b];
	_vector[b] = c;
}

void PmergeMe::vector_swap_b(int a, int b)
{
	int	c = _vector_b[a];
	_vector_b[a] = _vector_b[b];
	_vector_b[b] = c;
}

void PmergeMe::vector_print()
{
	for (size_t i = 0; i < _vector_b.size(); i++)
        std::cout << _vector_b[i] << " ";
    std::cout << std::endl;
}

	// +-------------------------------------------------+
	// |                    DEQUE                        |
	// +-------------------------------------------------+

void PmergeMe::deque_init(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
        _deque.push_back(std::atoi(argv[i]));
}

int PmergeMe::deque_is_sort()
{
	for (size_t i = 0; i < _deque_b.size(); i++)
    	if (i > 0 && _deque_b[i] < _deque_b[i - 1])
			return 0;
	return 1;
}

void PmergeMe::deque_sort()
{
	int	max = _deque.size();
	for (int i = 0; i < max - 1; i += 2)
		if (_deque[i] > _deque[i + 1])
			deque_swap(i, i + 1);

	for (int j=0;j<max;j+=2)
	{
		_deque_b.push_back(_deque[j]);
		if (j + 1 < max)
			_deque_a.push_back(_deque[j + 1]);
	}

	for (size_t i=0;i<_deque_b.size();i++)
	{
		for (size_t j=i;j<_deque_b.size();j++)
		{
			if (_deque_b[j] < _deque_b[i])
				deque_swap_b(j, i);
		}
	}
	gen_d_jacobsthal(_deque_a.size());
	for (size_t i = 0; i < _deque_a.size(); i++)
	{
		int n = _deque_a[_d_jacobsthal[i] - 1];
		size_t j;
		for (j = 0; j < _deque_b.size() && _deque_b[j] < n; j++)
			;

		_deque_b.insert(_deque_b.begin() + j, n);
	}
}

void PmergeMe::deque_swap(int a, int b)
{
	int	c = _deque[a];
	_deque[a] = _deque[b];
	_deque[b] = c;
}

void PmergeMe::deque_swap_b(int a, int b)
{
	int	c = _deque_b[a];
	_deque_b[a] = _deque_b[b];
	_deque_b[b] = c;
}

void PmergeMe::deque_print()
{
	for (size_t i = 0; i < _deque_b.size(); i++)
        std::cout << _deque_b[i] << " ";
    std::cout << std::endl;
}

	// +-------------------------------------------------+
	// |                  JACOBSTHAL                     |
	// +-------------------------------------------------+

int PmergeMe::get_jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (get_jacobsthal(n-1) + 2 * get_jacobsthal(n - 2));
}

void PmergeMe::gen_v_jacobsthal(int lenght)
{
	int i = 2;
	int last = 0;
	while (_v_jacobsthal.size() != static_cast<size_t>(lenght))
	{
		int n = get_jacobsthal(i);
		if (n > lenght)
			n = lenght;
		while (last != n)
		{
			_v_jacobsthal.push_back(n);
			n--;
		}
		last = get_jacobsthal(i);
		i++;
	}
}

void PmergeMe::gen_d_jacobsthal(int lenght)
{
	int i = 2;
	int last = 0;
	while (_d_jacobsthal.size() != static_cast<size_t>(lenght))
	{
		int n = get_jacobsthal(i);
		if (n > lenght)
			n = lenght;
		while (last != n)
		{
			_d_jacobsthal.push_back(n);
			n--;
		}
		last = get_jacobsthal(i);
		i++;
	}
}

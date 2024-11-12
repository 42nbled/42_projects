/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:32 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:22 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) { }

Span::Span(unsigned int n) : _n(n) { }

Span::Span(const Span& other) : _vector(other._vector), _n(other._n) { }

Span::~Span() { }

Span& Span::operator=(const Span& other)
{
    _vector = other._vector;
    _n = other._n;
    return *this;
}

void Span::addNumber(int i)
{
    if (_vector.size() < _n)
        _vector.push_back(i);
    else
        throw (Span::class_full());
}

void	Span::addRangeNumber(unsigned int n)
{
	std::srand(std::time(NULL));
	for (unsigned int i = 0; i < n; i++)
		this->addNumber(rand() % n);
}

void	Span::print_vec()
{
	for (unsigned int i = 0; i < _n; i++)
		std::cout << _vector[i] << " ";
	 std::cout << std::endl;
}

unsigned int Span::shortestSpan()
{
    if (this->_vector.size() > 1)
    {
        std::vector<int> sortedVector = _vector;
        std::sort(sortedVector.begin(), sortedVector.end());
        unsigned int shortest = static_cast<unsigned int>(sortedVector[1] - sortedVector[0]);
        for (size_t i = 1; i < sortedVector.size() - 1; ++i)
        {
            unsigned int currentSpan = static_cast<unsigned int>(sortedVector[i + 1] - sortedVector[i]);
            if (currentSpan < shortest)
            {
                shortest = currentSpan;
            }
        }

        return shortest;
    }
    else
        throw (Span::not_enough());
}

unsigned int Span::longestSpan()
{
    if (this->_vector.size() > 1)
    {
        std::vector<int> sortedVector = _vector;
        std::sort(sortedVector.begin(), sortedVector.end());
        unsigned int longest = static_cast<unsigned int>(sortedVector.back() - sortedVector.front());
        return longest;
    }
    else
    {
        throw (Span::not_enough());
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:59:09 by nbled             #+#    #+#             */
/*   Updated: 2023/09/03 23:22:17 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

// ----------------------------------------------------------------------------------
//  CONSTRUCTEUR + DESTRUCTEUR
// ----------------------------------------------------------------------------------

Fixed::Fixed()
{
    std::cout << END << "-Default constructor called-" << GRAY << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const Fixed & cpy)
{
    std::cout << END << "-Copy constructor called-" << GRAY << std::endl;
    *this = cpy;
}

Fixed::Fixed(int i)
{
    std::cout << END << "-Int constructor called-" << GRAY << std::endl;
    n = (i << bits);
}

Fixed::Fixed(const float i)
{
    std::cout << END << "-Float constructor called-" << GRAY << std::endl;
    n = roundf(i * (1 << bits));
}

Fixed::~Fixed()
{
    std::cout << END << "-Destructor called-" << GRAY << std::endl;
}

// ----------------------------------------------------------------------------------
//  SURCHARGE D'OPERATEUR
// ----------------------------------------------------------------------------------

void Fixed::operator=(const Fixed & copy)
{
    setRawBits(copy.getRawBits());
}

bool Fixed::operator>(const Fixed & other)const
{
    return (n > other.getRawBits());
}

bool Fixed::operator<(const Fixed & other)const
{
    return (n < other.getRawBits());
}

bool Fixed::operator>=(const Fixed & other)const
{
    return (n >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed & other)const
{
    return (n <= other.getRawBits());
}

bool Fixed::operator==(const Fixed & other)const
{
    return (n == other.getRawBits());
}

bool Fixed::operator!=(const Fixed & other)const
{
    return (n != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed & other)const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed & other)const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed & other)const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed & other)const
{
    return Fixed(toFloat() / other.toFloat());
}

Fixed Fixed::operator++(int)
{
        Fixed temp(*this);
        n += 256;
        return temp;
}

Fixed& Fixed::operator++()
{
    n += 256;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    n -= 256;
    return temp;
}

Fixed& Fixed::operator--()
{
    n -= 256;
    return *this;
}

std::ostream& operator<<(std::ostream & stream, const Fixed & fixed)
{
    stream << fixed.toFloat();
    return (stream);
}

// ----------------------------------------------------------------------------------
//  FONCTIONS
// ----------------------------------------------------------------------------------

int Fixed::getRawBits(void)const
{
    return (n);
}

void Fixed::setRawBits(int const raw)
{
    n = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)n / (1 << bits));
}

int Fixed::toInt( void ) const
{
    return ((int)n >> bits);
}

const Fixed &Fixed::min(const Fixed & rhs, const Fixed & lhs)
{
    return (rhs <= lhs) ? rhs : lhs ;
}

Fixed &Fixed::min(Fixed & rhs,Fixed & lhs)
{
    return (rhs <= lhs) ? rhs : lhs ;
}

const Fixed &Fixed::max(const Fixed & rhs, const Fixed & lhs)
{
    return (rhs >= lhs) ? rhs : lhs ;
}

Fixed &Fixed::max(Fixed & rhs, Fixed & lhs)
{
    return (rhs >= lhs) ? rhs : lhs ;
}

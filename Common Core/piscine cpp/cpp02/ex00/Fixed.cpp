/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:57:58 by nbled             #+#    #+#             */
/*   Updated: 2023/09/03 23:32:42 by nbled            ###   ########.fr       */
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

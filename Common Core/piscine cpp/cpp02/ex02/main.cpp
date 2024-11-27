/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:58:49 by nbled             #+#    #+#             */
/*   Updated: 2023/09/03 23:20:27 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

int	main(void)
{
	Fixed		a;
	Fixed const	aa;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed		bb(Fixed(5.05f) * Fixed(2));

    std::cout << GRAY;
	std::cout << (a > b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
    std::cout << std::endl;

	std::cout << a + b << std::endl;
	std::cout << b - a << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
    std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
    std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, bb) << std::endl;
	std::cout << Fixed::min(a, bb) << std::endl;
    std::cout << END;
	return (0);
}

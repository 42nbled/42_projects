/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:10 by nbled             #+#    #+#             */
/*   Updated: 2023/10/20 09:37:03 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void ft_upper(char &c)
{
	c = toupper(c);
}

void ft_printchar(char& c)
{
	std::cout << c;
}

void ft_printint(int& i)
{
	std::cout << i;
}

int main(void)
{
	int	i[] = {72,101,108,108,111,32,87,111,114,108,100,33};
	char str[] = "Hello World!";
	std::cout << std::endl;

	std::cout << "printint : " << std::endl << std::endl;
	iter(i, 12, ft_printint);
	std::cout << std::endl << std::endl;

	std::cout << "printchar : " << std::endl << std::endl;
	iter(str, 12, ft_printchar);
	std::cout << std::endl << std::endl ;

	std::cout << "upper : " << std::endl << std::endl;
	iter(str, 12, ft_upper);
	iter(str, 12, ft_printchar);
	std::cout << std::endl;

	return (0);
}

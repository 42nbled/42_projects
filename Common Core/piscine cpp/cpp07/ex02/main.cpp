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

#include "Array.hpp"

int	main(void)
{
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|                   INT TEST                     |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	try
	{
		Array<int> int_array(10);
		int_array[0] = 42;
		int_array[1] = 42;
		int_array[2] = 42;
		int_array[3] = 42;
		int_array[4] = 42;
		int_array[5] = 42;
		int_array[6] = 42;
		int_array[7] = 42;
		int_array[8] = 42;
		int_array[9] = 42;

		std::cout << "size of int_array : " << int_array.size() << std::endl;
		std::cout << "value of int_array : ";
		for (unsigned int i = 0; i < int_array.size(); i++)
			std::cout << int_array[i] << ", ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < int_array.size(); i++)
			int_array[i] = 0;
		std::cout << "int_array has been set to 0" << std::endl;
		std::cout << "value of int_array : ";
		for (unsigned int i = 0; i < int_array.size(); i++)
			std::cout << int_array[i] << ", ";
		std::cout << std::endl;
		std::cout << "index erreur test :" << std::endl;
		int_array[int_array.size() + 1] = 0;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|                  STRING TEST                   |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	try
	{
		Array<std::string> str_array(3);
		str_array[0] = "Hello";
		str_array[1] = "World";
		str_array[2] = "!";

		std::cout << "size of str_array : " << str_array.size() << std::endl;
		std::cout << "value of str_array : ";
		for (unsigned int i = 0; i < str_array.size(); i++)
			std::cout << str_array[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < str_array.size(); i++)
			str_array[i] = "0";
		std::cout << "str_array has been set to 0" << std::endl;
		std::cout << "value of str_array : ";
		for (unsigned int i = 0; i < str_array.size(); i++)
			std::cout << str_array[i] << " ";
		std::cout << std::endl;
		std::cout << "index erreur test :" << std::endl;
		str_array[str_array.size() + 1] = "0";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

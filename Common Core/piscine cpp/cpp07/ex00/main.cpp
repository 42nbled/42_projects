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

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "+------------------------------------------------+" << std::endl;
		std::cout << "|                     SWAP                       |" << std::endl;
		std::cout << "+------------------------------------------------+" << std::endl;
		std::cout << std::endl;
		{
			int int_A = 0;
			int int_B = 1;

			std::cout << " int_A = " << int_A << std::endl;
			std::cout << " int_B = " << int_B << std::endl;
			swap(int_A, int_B);
			std::cout << " SWAP" << std::endl;
			std::cout << " int_A = " << int_A << std::endl;
			std::cout << " int_B = " << int_B << std::endl;
		}
		std::cout << std::endl;
		{
			std::string string_A = "0";
			std::string string_B = "1";

			std::cout << " string_A = " << string_A << std::endl;
			std::cout << " string_B = " << string_B << std::endl;
			swap(string_A, string_B);
			std::cout << " SWAP" << std::endl;
			std::cout << " string_A = " << string_A << std::endl;
			std::cout << " string_B = " << string_B << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+------------------------------------------------+" << std::endl;
		std::cout << "|                     MIN                        |" << std::endl;
		std::cout << "+------------------------------------------------+" << std::endl;
		std::cout << std::endl;
		{
			int int_A = 0;
			int int_B = 1;
			int int_C = min(int_A, int_B);

			std::cout << " int_A = " << int_A << std::endl;
			std::cout << " int_B = " << int_B << std::endl;
			std::cout << " min = " << int_C << std::endl;
		}
		std::cout << std::endl;
		{
			float float_A = 0.5;
			float float_B = 1.5;
			float float_C = min(float_A, float_B);

			std::cout << " float_A = " << float_A << std::endl;
			std::cout << " float_B = " << float_B << std::endl;
			std::cout << " min = " << float_C << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "+------------------------------------------------+" << std::endl;
		std::cout << "|                     MAX                        |" << std::endl;
		std::cout << "+------------------------------------------------+" << std::endl;
		std::cout << std::endl;
		{
			int int_A = 0;
			int int_B = 1;
			int int_C = max(int_A, int_B);

			std::cout << " int_A = " << int_A << std::endl;
			std::cout << " int_B = " << int_B << std::endl;
			std::cout << " max = " << int_C << std::endl;
		}
		std::cout << std::endl;
		{
			float float_A = 0.5;
			float float_B = 1.5;
			float float_C = max(float_A, float_B);

			std::cout << " float_A = " << float_A << std::endl;
			std::cout << " float_B = " << float_B << std::endl;
			std::cout << " max = " << float_C << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}

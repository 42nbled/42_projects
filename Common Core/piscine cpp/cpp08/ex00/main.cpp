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

#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	std::cout << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|                INT VECTOR TEST                 |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	try
	{
		int intVectorData[] = {0, 1, 42, 3, 4};
    	std::vector<int> intVector(intVectorData, intVectorData + sizeof(intVectorData) / sizeof(intVectorData[0]));

		std::cout << "working : ";
		easyfind(intVector, 42);
		std::cout << "fail : ";
		easyfind(intVector, 21);
	}
	catch (std::exception &e)
	{
		std::cerr << "Occurence not found" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|                 INT LIST TEST                  |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	try
	{
		int intListData[] = {0, 1, 42, 3, 4};
    	std::list<int> intList(intListData, intListData + sizeof(intListData) / sizeof(intListData[0]));

		std::cout << "working : ";
		easyfind(intList, 42);
		std::cout << "fail : ";
		easyfind(intList, 21);
	}
	catch (std::exception &e)
	{
		std::cerr << "Occurence not found" << std::endl;
	}
	std::cout << std::endl;
    return 0;
}

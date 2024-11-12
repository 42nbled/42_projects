/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:32 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:21:18 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	is_num(char **argv)
{
	for (int i = 1; argv[i]; i++)
		for (int y = 0; argv[i][y]; y++)
			if (!isdigit(argv[i][y]))
				return 0;
	return 1;
}

int main(int argc, char **argv)
{
	PmergeMe FordJohnson;
	clock_t timer;
	double	vector_time;
	double	deque_time;

	if (argc < 2 || !is_num(argv))
		return 1;
	{
		timer = clock();
		FordJohnson.vector_init(argc, argv);
		FordJohnson.vector_sort();
		vector_time = static_cast<float>(clock() - timer) / CLOCKS_PER_SEC * 1000;
	}
	{
		timer = clock();
		FordJohnson.deque_init(argc, argv);
		FordJohnson.deque_sort();
		deque_time = static_cast<float>(clock() - timer) / CLOCKS_PER_SEC * 1000;
	}
	std::cout << "Before :";
	for (int i = 1; i < argc; i++)
		std::cout << " " << argv[i];
	std::cout << std::endl;
	std::cout << "After : ";
	FordJohnson.vector_print();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "<< vector_time << " ms"<< std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : "<< deque_time << " ms" << std::endl;
	if (!FordJohnson.vector_is_sort())
		std::cout << "vector is not sort" << std::endl;
	if (!FordJohnson.deque_is_sort())
		std::cout << "deque is not sort" << std::endl;
	return 0;
}

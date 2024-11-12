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

#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
		return 1;
	try
	{
		rpn.calculation(argv[1]);
	}
	catch(RPN::bad_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(RPN::division_zero& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

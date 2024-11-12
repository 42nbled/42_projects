/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:32 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:22 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <stdlib.h>

Base *	generate(void)
{
	int	rng;
	srand(time(0));
	rng = rand() % 3;
	if (rng == 0)
		return (new A());
	if (rng == 1)
		return (new B());
	return (new C());
}

void	identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base & p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception & e)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception & e)
			{
				
			}
		}
	}
}

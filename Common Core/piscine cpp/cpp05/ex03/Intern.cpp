/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:32 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:22 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "-Intern default constructor called-" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
    std::cout << "-Intern copy constructor called-" << std::endl;
}

Intern::~Intern()
{
    std::cout << "-Intern destructor called-" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
    return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	int i;
	const char *array_ptr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (i = 0; i < 3 && name.compare(array_ptr[i]) != 0 ; i++);
	switch (i)
	{
		case (0):
			return (new ShrubberyCreationForm(target));
		case (1):
			return (new RobotomyRequestForm(target));
		case (2):
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::Doesnt_match();
	}
}

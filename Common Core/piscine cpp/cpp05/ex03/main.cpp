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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

int    main()
{
	try
	{
		Intern	bob;
        AForm* garden = bob.makeForm("ShrubberyCreationForm", "../");
		AForm* garage = bob.makeForm("RobotomyRequestForm", "intern");
		AForm* president = bob.makeForm("PresidentialPardonForm", "me");
		std::cout << GRAY << std::endl;
		std::cout << *garden << std::endl << std::endl;
		std::cout << *garage << std::endl << std::endl;
        std::cout << *president << std::endl << std::endl;
		std::cout << END;
		delete garden;
		delete garage;
		delete president;
	}
	catch(Intern::Doesnt_match& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Intern	bob;
        AForm* oui = bob.makeForm("oui", "oui");
		delete oui;
	}
	catch(Intern::Doesnt_match& e)
	{
		std::cerr << e.what() << '\n';
	}
    return 0;
}

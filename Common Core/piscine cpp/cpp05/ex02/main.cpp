/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:10 by nbled             #+#    #+#             */
/*   Updated: 2023/10/20 05:11:46 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

int    main()
{
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << "|                Shrubbery                 |" << std::endl;
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "working :" << std::endl;
    std::cout << std::endl;

    {
        Bureaucrat    bob("Bob", 1);
        ShrubberyCreationForm Shrubbery("Garden");
        std::cout << GRAY;
        std::cout << bob << std::endl;
        std::cout << Shrubbery << std::endl;
        std::cout << std::endl;
        bob.signForm(Shrubbery);
        bob.executeForm(Shrubbery);
        std::cout << END;
    }

    std::cout << std::endl;
    std::cout << "Fail :" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat    bob("Bob", 1);
        ShrubberyCreationForm Shrubbery("Garden");
        std::cout << GRAY;
        std::cout << bob << std::endl;
        std::cout << Shrubbery << std::endl;
        std::cout << std::endl;
        std::cout << END;
        bob.executeForm(Shrubbery);
    }
    catch (AForm::Cant_execute &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Fail :" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat    obo("obo", 1);
        Bureaucrat    bob("Bob", 150);
        ShrubberyCreationForm Shrubbery("Garden");
        std::cout << GRAY;
        std::cout << obo << std::endl;
        std::cout << bob << std::endl;
        std::cout << Shrubbery << std::endl;

        obo.signForm(Shrubbery);
        std::cout << END;
        bob.executeForm(Shrubbery);
    }
    catch (AForm::Cant_execute &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << "|                  Robotomy                |" << std::endl;
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "working :" << std::endl;
    std::cout << std::endl;

    {
        Bureaucrat    bob("Bob", 1);
        RobotomyRequestForm Robotomy("Garage");
        std::cout << GRAY;
        std::cout << bob << std::endl;
        std::cout << Robotomy << std::endl;
        std::cout << std::endl;
        bob.signForm(Robotomy);
        bob.executeForm(Robotomy);
        std::cout << END;
    }

    std::cout << std::endl;
    std::cout << "Fail :" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat    bob("Bob", 1);
        RobotomyRequestForm Robotomy("Garage");
        std::cout << GRAY;
        std::cout << bob << std::endl;
        std::cout << Robotomy << std::endl;
        std::cout << std::endl;
        std::cout << END;
        bob.executeForm(Robotomy);
    }
    catch (AForm::Cant_execute &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Fail :" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat    obo("obo", 1);
        Bureaucrat    bob("Bob", 150);
        RobotomyRequestForm Robotomy("Garage");
        std::cout << GRAY;
        std::cout << obo << std::endl;
        std::cout << bob << std::endl;
        std::cout << Robotomy << std::endl;

        obo.signForm(Robotomy);
        std::cout << END;
        bob.executeForm(Robotomy);
    }
    catch (AForm::Cant_execute &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << "|                Presidential              |" << std::endl;
    std::cout << "+------------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "working :" << std::endl;
    std::cout << std::endl;

    {
        Bureaucrat    bob("Bob", 1);
        //PresidentialPardonForm president("Tower");
        AForm* president = new PresidentialPardonForm("Tower");
		std::cout << GRAY;
        std::cout << bob << std::endl;
        std::cout << president << std::endl;
        std::cout << std::endl;
        bob.signForm(*president);
        bob.executeForm(*president);
        std::cout << END;
		delete president;
    }

    std::cout << std::endl;
    std::cout << "Fail :" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat    bob("Bob", 1);
        PresidentialPardonForm president("Tower");
        std::cout << GRAY;
        std::cout << bob << std::endl;
        std::cout << president << std::endl;
        std::cout << std::endl;
        std::cout << END;
        bob.executeForm(president);
    }
    catch (AForm::Cant_execute &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Fail :" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat    obo("obo", 1);
        Bureaucrat    bob("Bob", 150);
        PresidentialPardonForm president("Tower");
        std::cout << GRAY;
        std::cout << obo << std::endl;
        std::cout << bob << std::endl;
        std::cout << president << std::endl;

        obo.signForm(president);
        std::cout << END;
        bob.executeForm(president);
    }
    catch (AForm::Cant_execute &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

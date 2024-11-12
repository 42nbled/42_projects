/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:25:53 by nbled             #+#    #+#             */
/*   Updated: 2023/10/20 05:07:43 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy", 72, 45)
{
    std::cout << "-RobotomyRequestForm default constructor called-" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy", 72, 45), target(target)
{
    std::cout << "-RobotomyRequestForm constructor called-" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("Robotomy", 72, 45), target(other.target)
{
    std::cout << "-RobotomyRequestForm copy constructor called-" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "-RobotomyRequestForm destructor called-" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    target = other.target;
    return *this;
}

void    RobotomyRequestForm::action(void)const
{
    std::cout << "-some drilling noises-" << std::endl;
    srand(time(0));
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized succesfully" << std::endl;
    else
        std::cout << target << " robotomy failed" << std::endl;
}

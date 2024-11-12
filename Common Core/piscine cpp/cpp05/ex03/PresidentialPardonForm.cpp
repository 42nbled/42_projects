/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:26:15 by nbled             #+#    #+#             */
/*   Updated: 2023/10/20 09:28:14 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "-PresidentialPardonForm default constructor called-" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "-PresidentialPardonForm constructor called-" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm("PresidentialPardonForm", 25, 5), target(other.target)
{
    std::cout << "-PresidentialPardonForm copy constructor called-" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "-PresidentialPardonForm destructor called-" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    target = other.target;
    return *this;
}

void    PresidentialPardonForm::action(void)const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

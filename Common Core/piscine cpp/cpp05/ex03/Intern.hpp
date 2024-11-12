/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:28 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:25 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstring>

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();

        Intern& operator=(const Intern& other);

		AForm*	makeForm(std::string name, std::string target);

        class Doesnt_match : std::exception
        {
            public:
                const char  *what(void) const throw()
                {
                    return ("Error: Doesnt_match");
                }
        };
};

#endif

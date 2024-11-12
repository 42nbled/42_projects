/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:10 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 17:24:38 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int    main()
{
    try
    {
        Bureaucrat    bob("Bob", 2);
    
        std::cout << bob << std::endl;
        bob.upGrade();
        std::cout << bob << std::endl;
        bob.upGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat    bob("Bob", 149);

        std::cout << bob << std::endl;
        bob.downGrade();
        std::cout << bob << std::endl;
        bob.downGrade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
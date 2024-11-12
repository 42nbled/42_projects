/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:10 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 17:38:09 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int    main()
{
    try
    {
        Bureaucrat    bob("Bob", 1);
        Form form;
        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        bob.signForm(form);

        Form form2("hard", 1, 1);
        Bureaucrat    marley("Marley", 150);
        std::cout << form2 << std::endl;
        marley.signForm(form2);
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
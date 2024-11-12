/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:40:26 by nbled             #+#    #+#             */
/*   Updated: 2023/10/15 18:02:02 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string name, int sign_grade, int execute_grade);
        Form(const Form& other);
        ~Form();

        Form& operator=(Form& other);

        void        beSigned(Bureaucrat& Bureaucrat);
        std::string GetName(void)const;
        bool        GetStatus(void)const;
        int         GetSign_grade(void)const;
        int         GetExecute_grade(void)const;

        class GradeTooHighException : std::exception
        {
            public:
                const char  *what(void) const throw()
                {
                    return ("Error: Grade Too High");
                }
        };

        class GradeTooLowException : std::exception
        {
            public:
                const char  *what(void) const throw()
                {
                    return ("Error: Grade Too Low");
                }
        };

    private:
        const std::string   name;
        bool                is_signed;
        const int           sign_grade;
        const int           execute_grade;
};
std::ostream& operator<<(std::ostream& out, Form const &target);

#endif

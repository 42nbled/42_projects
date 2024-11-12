/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:40:26 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:06 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(std::string name, int sign_grade, int execute_grade);
        AForm(const AForm& other);
        virtual ~AForm();

        AForm& operator=(AForm& other);

        virtual void        beSigned(const Bureaucrat& Bureaucrat);
        virtual std::string GetName(void)const;
        virtual bool        GetStatus(void)const;
        virtual int         GetSign_grade(void)const;
        virtual int         GetExecute_grade(void)const;
        virtual void        action(void)const;
        virtual void        execute(const Bureaucrat& Bureaucrat)const;

        class Cant_execute : std::exception
        {
            public:
                virtual const char  *what(void) const throw()
                {
                    return ("Error: Cant execute");
                }
        };

        class GradeTooHighException : std::exception
        {
            public:
                virtual const char  *what(void) const throw()
                {
                    return ("Error: Grade Too High");
                }
        };

        class GradeTooLowException : std::exception
        {
            public:
                virtual const char  *what(void) const throw()
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
std::ostream& operator<<(std::ostream& out, AForm const &target);

#endif

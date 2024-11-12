/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:40:22 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 16:53:53 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : name("Unspecified name"), is_signed(false), sign_grade(150), execute_grade(150)
{
    std::cout << "-Form default constructor called-" << std::endl;
}

Form::Form(const std::string new_name, int sign_grade, int execute_grade)
    : name(new_name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
    std::cout << "-Form constructor called-" << std::endl;

    if (sign_grade > 150)
        throw Form::GradeTooLowException();
    if (sign_grade < 1)
        throw Form::GradeTooHighException();
    if (execute_grade > 150)
        throw Form::GradeTooLowException();
    if (execute_grade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& other)
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{
    std::cout << "-Form copy constructor called-" << std::endl;
}

Form::~Form()
{
    std::cout << "-Form destructor called-" << std::endl;
}

Form& Form::operator=(Form& other)
{
    is_signed = other.is_signed;
    return *this;
}

std::ostream& operator<<(std::ostream& out, Form const &target)
{
    if (target.GetStatus())
        out << target.GetName() << " is signed. It can be signed by a bureaucrat with a grade of " << target.GetSign_grade() << " and can be executed by a bureaucrat with a grade of " << target.GetExecute_grade() << ".";
    else
        out << target.GetName() << " isn't signed. It requires a bureaucrat with a grade of " << target.GetSign_grade() << " to sign and a bureaucrat with a grade of " << target.GetExecute_grade() << " to execute.";
    return out;
}

void    Form::beSigned(Bureaucrat& Bureaucrat)
{
    if (Bureaucrat.getGrade() <= sign_grade)
        is_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::string Form::GetName(void)const
{
    return (name);
}

bool        Form::GetStatus(void)const
{
    return (is_signed);
}

int   Form::GetSign_grade(void)const
{
    return (sign_grade);
}

int   Form::GetExecute_grade(void)const
{
    return (execute_grade);
}

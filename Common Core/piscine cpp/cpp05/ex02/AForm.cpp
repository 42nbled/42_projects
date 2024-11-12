/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:40:22 by nbled             #+#    #+#             */
/*   Updated: 2023/10/15 19:58:27 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
    : name("Unspecified name"), is_signed(false), sign_grade(150), execute_grade(150)
{
    std::cout << "-AForm default constructor called-" << std::endl;
}

AForm::AForm(const std::string new_name, int sign_grade, int execute_grade)
    : name(new_name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
    std::cout << "-AForm constructor called-" << std::endl;

    if (sign_grade > 150)
        throw AForm::GradeTooLowException();
    if (sign_grade < 1)
        throw AForm::GradeTooHighException();
    if (execute_grade > 150)
        throw AForm::GradeTooLowException();
    if (execute_grade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other)
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{
    std::cout << "-AForm copy constructor called-" << std::endl;
}

AForm::~AForm()
{
    std::cout << "-AForm destructor called-" << std::endl;
}

AForm& AForm::operator=(AForm& other)
{
    is_signed = other.is_signed;
    return *this;
}

std::ostream& operator<<(std::ostream& out, AForm const &target)
{
    if (target.GetStatus())
    {
        out << target.GetName() << " is signed. It can be signed by a bureaucrat with a grade of " << target.GetSign_grade() << " and can be executed by a bureaucrat with a grade of " << target.GetExecute_grade() << ".";
    }
    else
    {
        out << target.GetName() << " isn't signed. It requires a bureaucrat with a grade of " << target.GetSign_grade() << " to sign and a bureaucrat with a grade of " << target.GetExecute_grade() << " to execute.";
    }
    return out;
}

void    AForm::beSigned(const Bureaucrat& Bureaucrat)
{
    if (Bureaucrat.getGrade() <= sign_grade)
        is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::string AForm::GetName(void)const
{
    return (name);
}

bool        AForm::GetStatus(void)const
{
    return (is_signed);
}

int   AForm::GetSign_grade(void)const
{
    return (sign_grade);
}

int   AForm::GetExecute_grade(void)const
{
    return (execute_grade);
}

void    AForm::action(void)const
{

}

void    AForm::execute(const Bureaucrat& Bureaucrat)const
{
    if (Bureaucrat.getGrade() < execute_grade && GetStatus())
        action();
    else
        throw Cant_execute();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:32 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 17:18:51 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name("Unspecified name")
{
    std::cout << "-Bureaucrat default constructor called-" << std::endl;
    grade = 150;
}

Bureaucrat::Bureaucrat(const std::string new_name,int new_grade)
    : name(new_name)
{
    std::cout << "-Bureaucrat constructor called-" << std::endl;
    grade = new_grade;
    if (grade > 150)
    {
        grade = 150;
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade < 1)
    {
        grade = 1;
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name)
{
    std::cout << "-Bureaucrat copy constructor called-" << std::endl;
    grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "-Bureaucrat destructor called-" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    grade = other.grade;
    return *this;
}

std::ostream&   operator<<(std::ostream & out, Bureaucrat const &target)
{
    out << target.getName() << ", bureaucrat grade " << target.getGrade();
    return (out);
}

void        Bureaucrat::upGrade()
{
    if (grade > 1)
        grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void        Bureaucrat::downGrade()
{
    if (grade < 150)
        grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName()const
{
    return (name);
}

int         Bureaucrat::getGrade()const
{
    return (grade);
}
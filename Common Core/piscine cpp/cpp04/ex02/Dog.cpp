/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:07 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:14:12 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

Dog::Dog()
{
    std::cout << "-Dog constructor called-" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "-Dog copy constructor called-" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog::~Dog()
{
    std::cout << "-Dog destructor called-" << std::endl;
    delete(brain);
}

Dog& Dog::operator=(const Dog& other)
{
    type = other.type;
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

Brain* Dog::get_brain()const
{
    return(brain);
}

void Dog::makeSound()const
{
    if (type == "Unspecified species") 
        std::cout << GRAY << "\"Unspecidfied species sound\"" << END << std::endl;
    else if (type == "Dog") 
        std::cout << GRAY << "\"Wooof\"" << END << std::endl;
    else if (type == "Cat") 
        std::cout << GRAY << "\"Miaou\"" << END << std::endl;
}

std::string Dog::getType()const
{
    return (type);
}

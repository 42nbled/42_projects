/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:19 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:14:00 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

Cat::Cat()
{
    std::cout << "-Cat constructor called-" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "-Cat copy constructor called-" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Cat::~Cat()
{
    std::cout << "-Cat destructor called-" << std::endl;
    delete(brain);
}

Cat& Cat::operator=(const Cat& other)
{
    type = other.type;
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

Brain* Cat::get_brain()const
{
    return(brain);
}

void Cat::makeSound()const
{
    if (type == "Unspecified species") 
        std::cout << GRAY << "\"Unspecidfied species sound\"" << END << std::endl;
    else if (type == "Dog") 
        std::cout << GRAY << "\"Wooof\"" << END << std::endl;
    else if (type == "Cat") 
        std::cout << GRAY << "\"Miaou\"" << END << std::endl;
}

std::string Cat::getType()const
{
    return (type);
}

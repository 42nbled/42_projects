/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:59:05 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:01:37 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

Animal::Animal()
{
    std::cout << "-Animal constructor called-" << std::endl;
    type = "Unspecified species";
}

Animal::Animal(const Animal& other)
{
    std::cout << "-Animal copy constructor called-" << std::endl;
    type = other.type;
}

Animal::~Animal()
{
    std::cout << "-Animal destructor called-" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    type = other.type;
    return *this;
}

void Animal::makeSound()const
{
    if (type == "Unspecified species") 
        std::cout << GRAY << "\"Unspecidfied species sound\"" << END << std::endl;
    else if (type == "Dog") 
        std::cout << GRAY << "\"Wooof\"" << END << std::endl;
    else if (type == "Cat") 
        std::cout << GRAY << "\"Miaou\"" << END << std::endl;
}

std::string Animal::getType()const
{
    return (type);
}
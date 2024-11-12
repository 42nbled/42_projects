/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:40 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:14:36 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

WrongAnimal::WrongAnimal()
{
    std::cout << "-WrongAnimal constructor called-" << std::endl;
    type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "-WrongAnimal copy constructor called-" << std::endl;
    type = other.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "-WrongAnimal destructor called-" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    type = other.type;
    return *this;
}

void WrongAnimal::makeSound()const
{
    std::cout << GRAY << "\"Wrong sound\"" << END << std::endl;
}

std::string WrongAnimal::getType()const
{
    return (type);
}

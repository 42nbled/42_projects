/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:59:15 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:02:05 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "-Dog constructor called-" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "-Dog copy constructor called-" << std::endl;
    type = other.type;
}

Dog::~Dog()
{
    std::cout << "-Dog destructor called-" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    type = other.type;
    return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:05:41 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:07:56 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

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

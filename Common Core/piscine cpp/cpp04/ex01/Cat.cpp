/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:05:50 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:07:43 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:59:30 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:01:51 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "-Cat constructor called-" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "-Cat copy constructor called-" << std::endl;
    type = other.type;
}

Cat::~Cat()
{
    std::cout << "-Cat destructor called-" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    type = other.type;
    return *this;
}

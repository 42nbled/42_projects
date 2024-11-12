/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:06:09 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:08:48 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "-WrongCat constructor called-" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "-WrongCat copy constructor called-" << std::endl;
    type = other.type;
}

WrongCat::~WrongCat()
{
    std::cout << "-WrongCat destructor called-" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    type = other.type;
    return *this;
}

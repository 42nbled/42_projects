/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:19 by nbled             #+#    #+#             */
/*   Updated: 2023/11/23 16:30:00 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
    _type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    _type = other._type;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& other)
{
    (void) other;
    return *this;
}

Cure* Cure::clone(void)const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
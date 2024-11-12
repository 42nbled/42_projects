/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:00 by nbled             #+#    #+#             */
/*   Updated: 2023/11/23 14:02:43 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
    _type = type;
}

AMateria::AMateria(const AMateria& other)
{
    _type = other._type;
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
    _type = other._type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return(_type);
}

void AMateria::use(ICharacter& target)
{
    (void) target;
}
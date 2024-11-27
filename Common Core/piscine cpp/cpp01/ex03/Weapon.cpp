/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:00:02 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 20:36:50 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    type = "Default Weapon Type";
}
Weapon::Weapon(const std::string& newName)
{
    type = newName;
}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& newName)
{
    type = newName;
}

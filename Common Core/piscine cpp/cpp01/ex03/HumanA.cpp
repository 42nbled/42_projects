/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:00:23 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 21:58:57 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

HumanA::HumanA(const std::string& newName, Weapon& newWeapon) : myWeapon(newWeapon) 
{
    name = newName;
}

void HumanA::attack() const
{
    std::cout << GRAY << name << END << " attacks with their " << GRAY << myWeapon.getType() << END << std::endl;
}

void HumanA::setWeapon(Weapon& newWeapon)
{
    myWeapon = newWeapon;
}

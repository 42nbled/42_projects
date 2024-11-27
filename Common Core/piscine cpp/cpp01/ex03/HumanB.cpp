/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:02:20 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 21:52:52 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

HumanB::HumanB(const std::string& newName)
{
    name = newName;
    myWeapon = NULL;
}
void HumanB::attack() const
{
    if (myWeapon)
        std::cout << GRAY << name << END << " attacks with their " << GRAY << myWeapon->getType() << END << std::endl;
    else
        std::cout << GRAY << name << END << " attacks with their " << GRAY << "own hand" << END << std::endl;
}

void HumanB::setWeapon(const Weapon& newWeapon)
{
    myWeapon = &newWeapon;
}

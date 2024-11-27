/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:01:54 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:09:51 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

ClapTrap::ClapTrap()
{
    name = "unamed ClapTrap";
    Hit_point = 10;
    Energy_point = 10;
    Attack_damage = 0;
    std::cout << "-ClapTrap " GRAY << name << END " appeared !-" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & cpy)
{
    std::cout << "-Copy constructor called-" << std::endl;
    *this = cpy;
}

ClapTrap::ClapTrap(std::string str)
{
    name = str;
    Hit_point = 10;
    Energy_point = 10;
    Attack_damage = 0;
    std::cout << "-ClapTrap " GRAY << name << END " appeared !-" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "-ClapTrap " GRAY << name << END " disappeared !-" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap & copy)
{
    name = copy.name;
    Hit_point = copy.Hit_point;
    Energy_point = copy.Energy_point;
    Attack_damage = copy.Attack_damage;

    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_point <= 0)
    {
        std::cout << "-ClapTrap " GRAY << name << END " cant use this because he is dead !- " << std::endl;
        return;
    }
    if (Energy_point <= 0)
    {
        std::cout << "-ClapTrap " GRAY << name << END " cant use this because he is oom !- " << std::endl;
        return;
    }
    Energy_point--;
    std::cout << "-ClapTrap " GRAY << name << END " attacks " GRAY << target << END ", causing " GRAY << Attack_damage << END " points of damage !-"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_point <= 0)
    {
        std::cout << "-ClapTrap " GRAY << name << END " cant take more damage because is dead !- " << std::endl;
        return;
    }
    std::cout << "-ClapTrap " GRAY << name << END " take " GRAY << amount << END " damages ! passing from " GRAY << Hit_point;
    Hit_point -= amount;
    std::cout << END " to " GRAY << Hit_point << END "-" << std::endl;
    if (Hit_point <= 0)
        std::cout << "-ClapTrap " GRAY << name << END " fainted-" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit_point <= 0)
    {
        std::cout << "-ClapTrap " GRAY << name << END " cant use this because he is dead !- " << std::endl;
        return;
    }
    if (Energy_point <= 0)
    {
        std::cout << "-ClapTrap " GRAY << name << END " cant use this because he is oom !- " << std::endl;
        return;
    }
    std::cout << "-ClapTrap " GRAY << name << END " restore " GRAY << amount << END " Health Point , passing from " GRAY << Hit_point;
    Hit_point += amount;
    Energy_point--;
    std::cout << END " to " GRAY << Hit_point << END " !-" << std::endl;
}

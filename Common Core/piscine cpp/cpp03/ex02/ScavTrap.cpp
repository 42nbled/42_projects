/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:02:34 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:26:16 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

ScavTrap::ScavTrap()
{
    name = "unamed ScavTrap";
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
    std::cout << "•ScavTrap " GRAY << name << END " appeared !•" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & cpy)
{
    std::cout << "•Copy constructor called•" << std::endl;
    *this = cpy;
}

ScavTrap::ScavTrap(std::string str)
{
    name = str;
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
    std::cout << "•ScavTrap " GRAY << name << END " appeared !•" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "•ScavTrap " GRAY << name << END " disappeared !•" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap & copy)
{
    name = copy.name;
    Hit_point = copy.Hit_point;
    Energy_point = copy.Energy_point;
    Attack_damage = copy.Attack_damage;

    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit_point <= 0)
    {
        std::cout << "•ScavTrap " GRAY << name << END " cant use this because he is dead !• " << std::endl;
        return;
    }
    if (Energy_point <= 0)
    {
        std::cout << "•ScavTrap " GRAY << name << END " cant use this because he is oom !• " << std::endl;
        return;
    }
    Energy_point--;
    std::cout << "•ScavTrap " GRAY << name << END " attacks " GRAY << target << END ", causing " GRAY << Attack_damage << END " points of damage !•"<< std::endl;
}

void ScavTrap::call_guardgate()
{
    if (Hit_point <= 0)
    {
        std::cout << "•ScavTrap " GRAY << name << END " cant use this because he is dead !•" << std::endl;
        return;
    }
    guardGate();
}

void ScavTrap::guardGate()
{
    std::cout << "•ScavTrap " GRAY << name << END " use guardgate !•" << std::endl;
}

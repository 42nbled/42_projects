/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:02:51 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:26:54 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

FragTrap::FragTrap()
{
    name = "unamed FragTrap";
    Hit_point = 100;
    Energy_point = 100;
    Attack_damage = 30;
    std::cout << "♦FragTrap " GRAY << name << END " appeared !♦" << std::endl;
}

FragTrap::FragTrap(const FragTrap & cpy)
{
    std::cout << "♦Copy constructor called♦" << std::endl;
    *this = cpy;
}

FragTrap::FragTrap(std::string str)
{
    name = str;
    Hit_point = 100;
    Energy_point = 100;
    Attack_damage = 30;
    std::cout << "♦FragTrap " GRAY << name << END " appeared !♦" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "♦FragTrap " GRAY << name << END " disappeared !♦" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap & copy)
{
    name = copy.name;
    Hit_point = copy.Hit_point;
    Energy_point = copy.Energy_point;
    Attack_damage = copy.Attack_damage;

    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (Hit_point <= 0)
    {
        std::cout << "♦FragTrap " GRAY << name << END " cant use this because he is dead !♦ " << std::endl;
        return;
    }
    if (Energy_point <= 0)
    {
        std::cout << "♦FragTrap " GRAY << name << END " cant use this because he is oom !♦ " << std::endl;
        return;
    }
    Energy_point--;
    std::cout << "♦FragTrap " GRAY << name << END " attacks " GRAY << target << END ", causing " GRAY << Attack_damage << END " points of damage !♦"<< std::endl;
}

void FragTrap::call_highFives()
{
    if (Hit_point <= 0)
    {
        std::cout << "♦FragTrap " GRAY << name << END " cant use this because he is dead !♦" << std::endl;
        return;
    }
    highFivesGuys();
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "♦FragTrap " GRAY << name << END " ask for a highFives !♦" << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "♦nobody respond...♦" << std::endl;
}

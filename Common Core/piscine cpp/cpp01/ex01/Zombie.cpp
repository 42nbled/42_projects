/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:58:19 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 22:01:32 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

Zombie::Zombie()
{
    name = "Unnamed Zombie";
    std::cout << "- " << name << " spawned. -" << std::endl;
}

Zombie::Zombie(const std::string& newName)
{
    name = newName;
    std::cout << "- " << name << " spawned. -" << std::endl;
}

Zombie::~Zombie() 
{
    std::cout << "- " << name << " died. -" << std::endl;
}

void Zombie::setName(const std::string& newName)
{
    name = newName;
}

void Zombie::announce() const 
{
    std::cout << GRAY << name << ": BraiiiiiiinnnzzzZ..." << END << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:57:11 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 21:59:30 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
    {
        ClapTrap    Clap("oui");
        ClapTrap    Trap(Clap);
    }
    std::cout << std::endl;
    {
        ClapTrap    Clap("oui");
        ClapTrap    Trap;
        Trap = Clap;
    }
    std::cout << std::endl;
    {
        ClapTrap    Clap;
        ClapTrap    Trap("oui");

        Clap.attack("oui");
        Trap.takeDamage(0);
        Trap.attack("unnamed ClapTrap");
        Clap.takeDamage(0);
        Clap.attack("unnamed ClapTrap");
        Clap.takeDamage(0);
        Trap.beRepaired(5);
    }
    std::cout << std::endl;
    {
        ClapTrap    Clap;
        ClapTrap    Trap("oui");

        Clap.takeDamage(6);
        Clap.takeDamage(6);
        Clap.takeDamage(6);
        Clap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
        Trap.attack("the wind");
    }
	return (0);
}

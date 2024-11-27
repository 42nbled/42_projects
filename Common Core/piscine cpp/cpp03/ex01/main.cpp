/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:54 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 21:59:43 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
    {
        ScavTrap    Clap("oui");
        std::cout << std::endl;
        ScavTrap    Trap(Clap);
    }
    std::cout << std::endl << std::endl;
    {
        ScavTrap    Clap("oui");
        std::cout << std::endl;
        ScavTrap    Trap;
        std::cout << std::endl;
        Trap = Clap;
    }
    std::cout << std::endl << std::endl;
    {
        ClapTrap    Clap("non");
        ScavTrap    Trap("oui");

        std::cout << std::endl;
        Clap.attack("oui");
        Trap.attack("non");
        std::cout << std::endl;
        Clap.takeDamage(1);
        Trap.takeDamage(1);
        std::cout << std::endl;
        Clap.beRepaired(1);
        Trap.beRepaired(1);
        std::cout << std::endl;
        Trap.call_guardgate();
        std::cout << std::endl;
    }
	return (0);
}

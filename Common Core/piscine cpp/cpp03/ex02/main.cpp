/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:01:20 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:17:09 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
    {
        FragTrap    Clap("oui");
        std::cout << std::endl;
        FragTrap    Trap(Clap);
    }
    std::cout << std::endl << std::endl;
    {
        FragTrap    Clap("oui");
        std::cout << std::endl;
        FragTrap    Trap;
        std::cout << std::endl;
        Trap = Clap;
    }
    std::cout << std::endl << std::endl;

    ClapTrap    a("Clap");
    ScavTrap    b("Scav");
    FragTrap    c("Frag");


    std::cout << std::endl;
    a.attack("Scav");
    b.attack("Clap");
    c.attack("Clap");
    std::cout << std::endl;
    a.takeDamage(1);
    b.takeDamage(1);
    c.takeDamage(1);
    std::cout << std::endl;
    a.beRepaired(1);
    b.beRepaired(1);
    c.beRepaired(1);
    std::cout << std::endl;
    b.call_guardgate();
    c.call_highFives();
    std::cout << std::endl;

	return (0);
}

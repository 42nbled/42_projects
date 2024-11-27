/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:00:29 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:30:53 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string str);
        ScavTrap(const ScavTrap & cpy);
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap & copy);

        void attack(const std::string& target);
        void call_guardgate();

    private:
        void guardGate();
};

#endif
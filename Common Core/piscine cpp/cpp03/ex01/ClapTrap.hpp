/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:00:07 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:31:24 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string str);
        ClapTrap(const ClapTrap & cpy);
        ~ClapTrap();

        ClapTrap& operator=(const ClapTrap & copy);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string name;
        int Hit_point;
        int Energy_point;
        int Attack_damage;
};

#endif
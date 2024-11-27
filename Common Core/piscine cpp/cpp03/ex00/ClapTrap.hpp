/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:57:25 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 18:51:10 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    private:
        std::string name;
        int Hit_point;
        int Energy_point;
        int Attack_damage;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:00:30 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 22:04:42 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(const std::string& newName);

        void attack() const;
        void setWeapon(const Weapon& newWeapon);

    private:
        std::string name;
        const Weapon* myWeapon;
};

#endif

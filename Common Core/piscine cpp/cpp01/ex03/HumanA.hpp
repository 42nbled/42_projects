/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:00:17 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 21:59:31 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
    public:
        HumanA(const std::string& newName, Weapon& newWeapon);

        void attack() const;
        void setWeapon(Weapon& newWeapon);

    private:
        std::string name;
        Weapon& myWeapon;
};

#endif

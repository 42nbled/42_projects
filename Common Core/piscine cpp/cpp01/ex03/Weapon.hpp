/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:59:56 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 20:40:03 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    public:
        Weapon();
        Weapon(const std::string& newName);

        const std::string& getType() const;
        void setType(const std::string& newName);

    private:
        std::string type;
};

#endif

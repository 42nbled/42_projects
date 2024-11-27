/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:02:46 by nbled             #+#    #+#             */
/*   Updated: 2023/09/06 22:30:16 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string str);
        FragTrap(const FragTrap & cpy);
        ~FragTrap();

        FragTrap& operator=(const FragTrap & copy);

        void attack(const std::string& target);
        void call_highFives();

    private:
        void highFivesGuys(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:56:39 by nbled             #+#    #+#             */
/*   Updated: 2023/09/02 14:48:29 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie 
{
    public:
        Zombie();
        Zombie(const std::string& newName);
        ~Zombie();
        
        void announce();

    private:
        std::string name;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif
